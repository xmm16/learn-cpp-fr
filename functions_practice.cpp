#include <iostream>
#include <string>

template <typename generic_number>
generic_number sum(const generic_number &a, const generic_number &b) {
  return a + b;
}

template <typename generic_number>
generic_number product(const generic_number &a, const generic_number &b) {
  return a * b;
}

template <typename generic_number>
// must be const & to send in a literal, otherwise only variables / something
// that has an address
generic_number max_num(const generic_number &a, const generic_number &b) {
  return (a > b) ? a : b;
}

int main() {
  std::string num_one_str;
  std::string num_two_str;

  std::cout << "First number: ";
  std::getline(std::cin, num_one_str);

  std::cout << "Second number: ";
  std::getline(std::cin, num_two_str);

  int num_one = std::stoi(num_one_str);
  int num_two = std::stoi(num_two_str);

  std::cout << "Sum: " << sum(num_one, num_two) << "\n";
  std::cout << "Product: " << product(num_one, num_two) << "\n";
  std::cout << "Max num: " << max_num(num_one, num_two) << "\n";

  return 0;
}
