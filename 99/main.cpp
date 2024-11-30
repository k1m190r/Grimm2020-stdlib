#include <fmt/ranges.h>
#include <iostream>
#include <chrono>
#include <fmt/chrono.h>


using fmt::print;
namespace ch = std::chrono;

int main(){
  auto now =  ch::system_clock::now();
  print("{}", now);

  std::cout << now ;
}
