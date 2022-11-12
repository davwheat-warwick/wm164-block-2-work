#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>

#include "./main.hpp"

int main(int argc, char *argv[])
{
  std::string fullName;
  int age = -1;
  bool ageEntered = false;
  std::string gender;
  std::string workForNhsStr;
  bool workForNhs;

  std::cout << "Please enter your full name: ";
  std::getline(std::cin, fullName);

  do
  {
    if (ageEntered)
    {
      std::cout << "Your age must be between 1 and 100." << std::endl;
    }

    std::cout << "Please enter your age: ";
    std::cin >> age;
    ageEntered = true;
  } while (age <= 0 || age > 100);

  std::cout << "Please enter your gender (Male/Female/Other): ";
  std::cin >> gender;

  // Transform to lower case
  std::transform(gender.begin(), gender.end(), gender.begin(), ::tolower);

  std::cout << "Do you work for the NHS? (true/false): ";
  std::cin >> workForNhsStr;

  while (interpretBoolEntry(workForNhsStr) == -1)
  {
    std::cout << "Please enter either true or false." << std::endl;
    std::cout << "Do you work for the NHS? (true/false): ";
    std::cin >> workForNhsStr;
  }

  workForNhs = interpretBoolEntry(workForNhsStr);

  bool qualifiesForPriorityVaccine = shouldGetPriorityVaccine(age, workForNhs);

  if (qualifiesForPriorityVaccine)
  {
    std::cout << "You qualify for the priority vaccine." << std::endl;
  }
  else
  {
    std::cout << "You do not qualify for the priority vaccine." << std::endl;
  }
}

int interpretBoolEntry(std::string str)
{
  std::transform(str.begin(), str.end(), str.begin(), ::tolower);

  if (str == "true")
  {
    return 1;
  }
  else if (str == "false")
  {
    return 0;
  }

  return -1;
}

bool shouldGetPriorityVaccine(int age, bool worksForNhs)
{
  return age > 65 || worksForNhs;
}
