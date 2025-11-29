#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

int main() {
  std::vector<int> num_list;

  while (true) {
    bool valid_input_given = false;
    std::string int_str;
    while (!valid_input_given) {
      std::cout << "Enter a number: ";
      std::getline(std::cin, int_str);
      if (int_str == "done") {
        if (num_list.size() == 0) {
          std::cout << "No values provided" << '\n';
          return 0;
        }
        std::cout << "Length: " << num_list.size() << '\n';
        std::cout << "Sum: "
                  << std::accumulate(num_list.begin(), num_list.end(), 0)
                  << '\n';
        std::cout << "Min: "
                  << *std::min_element(num_list.begin(), num_list.end())
                  << '\n';
        std::cout << "Max: "
                  << *std::max_element(num_list.begin(), num_list.end())
                  << '\n';
        return 0;
      }

      try {
        num_list.push_back(std::stoi(int_str));
        valid_input_given = true;
      } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << '\n';
      }
    }
  }
}
