#include <iostream>
#include"strategy.cpp"

using namespace std;
template < typename T >

[[nodiscard]] static auto GetFromUser() noexcept {
  T value = {};
  std::cin >> value;
  return value;
}

template <typename T>
[[nodiscard]]  auto AskForValue(const std::string &message) noexcept {
  std::cout << message << std::endl;
  return GetFromUser<T>();
}
template <typename T>
[[nodiscard]] auto AskPolitelyForValue(const std::string &value_name) noexcept {
  std::cout << "Please input " << value_name << " value" << std::endl;
  return GetFromUser<T>();
}


[[nodiscard]]  int AskForFuel() noexcept {
  return AskPolitelyForValue<int>("fuel");
}

[[nodiscard]]  int AskForCoordinate() noexcept {
  return AskPolitelyForValue<int>("coordinate");
}
  int main()
  {
   // auto n(std::make_unique<Question>());
    //n->compress();

   int x =0;
   x=AskForCoordinate();
  }

