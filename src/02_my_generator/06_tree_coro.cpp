#include <cassert>
#include <coroutine>  
#include <iostream>

#include "generator.hpp"

// TODO : iterate tree with generator

template <typename T>
struct Tree {
  T value;
  Tree* left{};
  Tree* right{};
};

int main() {
}