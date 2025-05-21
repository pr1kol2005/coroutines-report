#include <iostream>
#include <vector>
#include <coroutine>
#include <generator>

template <typename T>
std::generator<const T&> MergeVectors(const std::vector<T>& lhs, const std::vector<T>& rhs) {
  for (const auto& elem : lhs) {
    co_yield elem;
  }
  for (const auto& elem : rhs) {
    co_yield elem;
  }
}

template <typename T>
std::generator<const T&> InterleaveVectors(const std::vector<T>& lhs, const std::vector<T>& rhs) {
  size_t n = std::max(lhs.size(), rhs.size());
  for (size_t i = 0; i < n; ++i) {
    if (i < lhs.size()) {
      co_yield lhs[i];
    }
    if (i < rhs.size()) {
      co_yield rhs[i];
    }
  }
}

int main() {
  std::vector<int> first{0, 0, 0};
  std::vector<int> second{1, 1, 1};

  for (const auto& val : MergeVectors(first, second)) {
    std::cout << val << ' ';
  }
  std::cout << '\n';

  for (const auto& val : InterleaveVectors(first, second)) {
    std::cout << val << ' ';
  }
  std::cout << '\n';
}
