#include <coroutine>
#include <exception>
#include <iostream>

struct Resumable {
  struct promise_type;
  using handle_type = std::coroutine_handle<promise_type>;

  Resumable(handle_type handle) : handle_(handle) {}

  ~Resumable() {
    if (handle_) {
      handle_.destroy();
    }
  }

  Resumable(const Resumable&) = delete;
  Resumable& operator=(const Resumable&) = delete;

  Resumable(Resumable&& other) : handle_(other.handle_) { other.handle_ = {}; }

  Resumable& operator=(Resumable&& other) {
    if (this != std::addressof(other)) {
      if (handle_) {
        handle_.destroy();
      }
      handle_ = other.handle_;
      other.handle_ = {};
    }
    return *this;
  }

  void resume() {
    if (handle_) {
      handle_.resume();
    }
  }

 private:
  handle_type handle_;
};

struct Resumable::promise_type {
  Resumable get_return_object() {
    return Resumable(handle_type::from_promise(*this));
  }

  // TODO : show suspend_always / suspend_never difference
  std::suspend_always initial_suspend() noexcept { return {}; }

  std::suspend_always final_suspend() noexcept { return {}; }

  // TODO : need for co_yield
  // std::suspend_always yield_value(T value) noexcept { }

  void unhandled_exception() { std::terminate(); }

  // TODO : ??
  void return_void() noexcept {}
};

Resumable foo() {
  std::cout << 'a' << std::endl;
  co_await std::suspend_always();
  std::cout << 'b' << std::endl;
  co_await std::suspend_always();
  std::cout << 'c' << std::endl;
}

int main() {
  Resumable res = foo();
  res.resume();
  res.resume();
  res.resume();
}
