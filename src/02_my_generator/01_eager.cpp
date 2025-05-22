#include <iostream>

std::vector<int> FibonacciEager(size_t count) {
  std::vector<int> result;
  result.reserve(count);

  int a = 0;
  int b = 1;
  for (size_t i = 0; i < count; ++i) {
    result.push_back(a);
    int next = a + b;
    a = b;
    b = next;
  }

  return result;
}

void PrintFibonacci(size_t count, int limit) {
  auto sequence = FibonacciEager(count);

  for (int x : sequence) {
    if (x > limit) {
      break;
    }
    std::cout << x << ' ';
  }
  std::cout << '\n';
}

int main() { PrintFibonacci(20, 10); }
