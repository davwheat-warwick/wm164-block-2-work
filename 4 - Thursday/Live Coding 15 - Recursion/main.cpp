#include <iostream>
#include <string>
#include <fstream>

#include "./main.hpp"

int main(int argc, char *argv[])
{
  long long val;
  int remainingAdds;

  std::cout << "Please provide two numbers." << std::endl;
  std::cin >> val >> remainingAdds;

  long long result = add(val, remainingAdds);

  std::cout << "Result: " << result << std::endl;

  return 0;
}

long long add(long long val, int remainingAdds)
{
  if (remainingAdds == 0)
  {
    return 0;
  }

  return val + add(val, remainingAdds - 1);
}