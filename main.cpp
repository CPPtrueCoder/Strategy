#include <iostream>
#include"strategy.cpp"
using namespace std;

  int main()
  {
    auto n(std::make_unique<Question>());
    n->compress();
  }

