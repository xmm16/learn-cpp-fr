#include <iostream>
#include <string>

int main() {
  std::string num_one;
  std::string num_two;

  std::cout << "First number?: ";
  std::getline(std::cin, num_one);

  std::cout << "Second number?: ";
  std::getline(std::cin, num_two);

  int int_num_one = std::stoi(num_one);
  int int_num_two = std::stoi(num_two);

  int greater_out_of_one_and_two =
      (int_num_one > int_num_two) ? int_num_one : int_num_two;

  std::cout << "The sum: " << int_num_one + int_num_two
            << "\nThe product: " << int_num_one * int_num_two
            << "\nThe larger of the two numbers: " << greater_out_of_one_and_two
            << "\n";

  return 0;
}
