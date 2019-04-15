#include <iostream>
#include"strategy.cpp"
using namespace std;

  int main()
  {
    Compressor n(std::make_unique<Question>());
    n.compress();
  }

