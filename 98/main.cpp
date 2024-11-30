#include <algorithm>
#include <fmt/core.h>
#include <fmt/std.h>
#include <fmt/ranges.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>




using fmt::print;
using std::min, std::minmax, std::max;

void warnings(){
  std::ifstream f_in("warnings");
  std::ofstream f_out("warnings_2");
  for(std::string line; std::getline(f_in, line);){
    if (
        (line.find("enabled") != std::string::npos) || 
        (line.find("Fortran") != std::string::npos) ||
        (line.find("D")       != std::string::npos)
      ){
      continue;
    }
    print(f_out, "{}\n", line);
  } 
}


int main (){
  warnings();
  /*
  auto v = {
    min(2011, 2014),
    min({3, 1, 2001, 2014, -5}),
    max(234, 2342),
  };
 */
  //int _v1 = 2342; //, _v2 = 2343;
  auto v = minmax({342, 333});
  // std::cout << v.first;
  print("{}", v);

  // print("{}\n", v);
   
}
