#include <iostream>
#include <string>
#include <fstream>

#include "./main.hpp"

#define CAESER_OFFSET 1

int main(int argc, char *argv[])
{
  if (argc < 4)
  {
    std::cout << "Please provide three parameters: action, input file and output file." << std::endl;
    std::cout << "Example: program.exe <encrypt|decrypt> <input> <output>" << std::endl;
    return 1;
  }

  const std::string action = argv[1];
  const std::string input_file = argv[2];
  const std::string output_file = argv[3];

  std::ifstream inp;
  inp.open(input_file);

  if (!inp.is_open())
  {
    std::cout << "Could not open input file." << std::endl;
    return 1;
  }

  std::string contents = "";
  inp >> contents;

  inp.close();

  std::string processed = "";

  if (action == "encrypt")
  {
    processed = encrypt(contents);
  }
  else if (action == "decrypt")
  {
    processed = decrypt(contents);
  }
  else
  {
    std::cout << "Unknown action. Please provide either 'encrypt' or 'decrypt'." << std::endl;
    return 1;
  }

  std::ofstream out;
  out.open(output_file);

  if (!out.is_open())
  {
    std::cout << "Could not open output file." << std::endl;
    return 1;
  }

  out << processed;

  out.close();

  return 0;
}

std::string encrypt(std::string raw)
{
  std::string encrypted = "";
  for (int i = 0; i < raw.length(); i++)
  {
    encrypted += raw[i] + CAESER_OFFSET;
  }
  return encrypted;
}

std::string decrypt(std::string encrypted)
{
  std::string decrypted = "";
  for (int i = 0; i < encrypted.length(); i++)
  {
    decrypted += encrypted[i] - CAESER_OFFSET;
  }
  return decrypted;
}
