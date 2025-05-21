#pragma once

#include <coroutine>
#include <exception>
#include <memory>
#include <utility>

template <typename Ref>
class Generator {
  // using value_type = std::conditional_t<std::is_void_v<V>, std::remove_cvref_t<Ref>, V>;
  using value_type = std::remove_cvref_t<Ref>;
  // using reference = std::conditional_t<std::is_void_v<V>, Ref&&, Ref>;
  using reference = Ref&&;

 public:
  struct promise_type;

  using handle_type = std::coroutine_handle<promise_type>;

  explicit Generator(handle_type handle) : handle_(handle) {}

  Generator(const Generator&) = delete;
  Generator& operator=(const Generator&) = delete;

  Generator(Generator&& other) noexcept : handle_(other.handle_) {
    other.handle_ = nullptr;
  }

  Generator& operator=(Generator&& other) noexcept {
    if (this != std::addressof(other)) {
      if (handle_) {
        handle_.destroy();
      }
      handle_ = other.handle_;
      other.handle_ = nullptr;
    }
    return *this;
  }

  ~Generator() {
    if (handle_) {
      handle_.destroy();
    }
  }

  class iterator;

  iterator begin() {
    if (handle_) {
      handle_.resume();
    }
    return iterator{handle_};
  }

  std::default_sentinel_t end() noexcept { return {}; }

 private:
  handle_type handle_;
};

template <typename Ref>
struct Generator<Ref>::promise_type {
  value_type current_value;
  std::exception_ptr exception;

  Generator get_return_object() {
    return Generator(std::coroutine_handle<promise_type>::from_promise(*this));
  }

  std::suspend_always initial_suspend() noexcept { return {}; }

  std::suspend_always final_suspend() noexcept { return {}; }

  std::suspend_always yield_value(Ref value) noexcept {
    current_value = std::move(value);
    return {};
  }

  void unhandled_exception() { exception = std::current_exception(); }

  void return_void() noexcept {}
};

template <typename Ref>
class Generator<Ref>::iterator {
 public:
  using iterator_category = std::input_iterator_tag;

  iterator() : handle_(nullptr) {}
  explicit iterator(handle_type coro) : handle_(coro) {}

  iterator& operator++() {
    handle_.resume();
    if (handle_.done()) {
      if (handle_.promise().exception) {
        std::rethrow_exception(handle_.promise().exception);
      }
      handle_ = nullptr;
    }
    return *this;
  }

  reference operator*() const noexcept {
    return handle_.promise().current_value;
  }

  bool operator==(std::default_sentinel_t) const noexcept {
    return !handle_ || handle_.done();
  }

  bool operator!=(std::default_sentinel_t end) const noexcept {
    return !(*this == end);
  }

 private:
  handle_type handle_;
};
