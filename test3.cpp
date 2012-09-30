#include <string>
#include <sstream>
#include <iostream>

template <class T>
bool from_string(T& t, 
                 const std::string& s, 
                 std::ios_base& (*f)(std::ios_base&))
{
  std::istringstream iss(s);
  return !(iss >> f >> t).fail();
}

int main()
{
  int i;
  float f;
  
  // the third parameter of from_string() should be 
  // one of std::hex, std::dec or std::oct
  if(from_string<int>(i, std::string("ff"), std::hex))
  {
    std::cout << i << std::endl;
  }
  else
  {
    std::cout << "from_string failed" << std::endl;
  }
  
  if(from_string<float>(f, std::string("123.456"), std::dec))
  {
    std::cout << f << std::endl;
  }
  else
  {
    std::cout << "from_string failed" << std::endl;
  }
  return 0;
} 
