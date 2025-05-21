#include <iostream>
#include <coroutine>

struct Resumable {
  struct promise_type;
  using handle_type = std::coroutine_handle<promise_type>;

  Resumable(handle_type h) : handle_(h) {}
  ~Resumable() { if (handle_) handle_.destroy(); }

  Resumable(const Resumable&) = delete;
  Resumable &operator=(const Resumable&) = delete;
  Resumable(Resumable&& o) : handle_(o.handle_) { o.handle_ = {};}
  Resumable& operator=(Resumable &&o) { if (handle_) handle_.destroy(); handle_ = o.handle_; o.handle_ = {}; return *this; }

  void resume() { if (handle_) handle_.resume(); }

  struct promise_type {
    Resumable get_return_object() { return Resumable(handle_type::from_promise(*this)); }
    std::suspend_always initial_suspend() { return {}; }
    std::suspend_always final_suspend() noexcept { return {}; }
    void unhandled_exception() {}
  };

private:
  handle_type handle_;
};

Resumable foo(){
  std:: cout << 'a' << std::endl;
  co_await std::suspend_always();
  std:: cout << 'b' << std::endl;
  co_await std::suspend_always(); 
  std:: cout << 'c' << std::endl;
}

int main(){
  Resumable res = foo();
  res.resume();
  res.resume();
  res.resume();
}