#include <coroutine>
#include <iostream>

void foo() {
  std::cout << 'a' << std::endl;
  std::cout << 'b' << std::endl;
  std::cout << 'c' << std::endl;
}

int main() {
  foo(); 
}
