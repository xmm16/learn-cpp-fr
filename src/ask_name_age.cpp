#include <iostream>
#include <string>

int main() {
  std::string name;
  std::cout << "What's your name?: ";
  std::getline(std::cin, name);

  // std::string age_string;
  // std::cout << "What's your age?: ";
  // std::getline(std::cin, age_string);
  // const auto age = std::stoi(age_string);

  // more advanced way of doing it (less readable but fun conceptually)
  const auto age = [] {
    std::string age_string;
    std::cout << "What's your age?: ";
    std::getline(std::cin, age_string);
    return std::stoi(age_string);
  }();

  const int &age_ref = age;

  std::cout << "Hello " << name << ", you are " << age << " years old.\n";
  std::cout << "(age_ref value: " << age_ref << ")\n";

  return 0;
}
