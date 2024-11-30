#include <algorithm>
#include <fmt/core.h>
#include <fmt/std.h>
#include <fmt/ranges.h>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cmath>
#include <tuple>
#include <functional>

using fmt::print;
using namespace std::literals::string_literals;

void foo() {
  print("invoked\n");
}

typedef void callableUnit();
std::reference_wrapper<callableUnit> refWrap(foo);


int main (){
  {
    auto v = {
      std::midpoint(10.0f, 20.0f),
      std::lerp(10.0f, 20.0f, 0.37f),
    };


    print("{}\n", v);

  }

  { // tuple tie ignore
    auto t = std::make_tuple(101, 2013, "blah", 222.22);
  
    int a{};
    std::string b{};
  
    std::tie(std::ignore, a, b, std::ignore) = t;
    print("{}\n", t);
    print("{} {}\n", a, b);
  }

  { // 
    refWrap();
  }

  { // ref 
    auto fn = [](const std::string& s) { print("{}", s);};
    auto double_it = [](auto t){ t*=2;}; 

    auto s{"string blah"s};
    fn(s);

    int i{1};
    double_it(i);
    print("{}", i);
    
    double_it(std::ref(i));
    print("{}", i);
  }
  
}
