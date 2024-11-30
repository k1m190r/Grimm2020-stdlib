#include <iostream>
#include <format>
#include <memory>
#include <utility>
#include <fmt/format.h>
#include <fmt/ranges.h>

using std::cout, std::endl;

struct Int{
  Int(int i): i_{i} {
    std::cout << std::format("hello: {}\n", i);
  }
  ~Int(){
    std::cout << std::format("see ya: {}\n", i_);
  }
  int i_;
};


int main(){
  {
    using std::unique_ptr;

    unique_ptr<Int> ptr1{new Int(1998)};
    cout << ptr1.get() << endl;

    unique_ptr<Int> ptr2{std::move(ptr1)};
    cout << ptr1.get() << endl;
    cout << ptr2.get() << endl;

    {
      unique_ptr<Int> ptr3{new Int(2003)};
    }


    ptr2.reset(new Int(2011));
    auto int2 = ptr2.release();

    delete int2;
  
  }

  { // shared ptr
    using std::shared_ptr;
    auto ptr1 = std::make_shared<Int>(1998);
    cout << ptr1.use_count() << endl;
    {
      shared_ptr<Int> ptr2(ptr1);
      cout << ptr1.use_count() << endl;

    } 
  }

  { // weak PTR
    using std::weak_ptr;
    auto sh_ptr1 = std::make_shared<int>(2011);
   
    weak_ptr<int> weak_ptr1(sh_ptr1);

    if(std::shared_ptr<int> ptr = weak_ptr1.lock()){
      cout << *ptr << endl;
    }

  }

}
