#include <iostream>
#include <vector>

int sum_vector(const std::vector<int> &num_list) {
  int sum = 0;
  for (int n : num_list) {
    sum += n;
  }

  return sum;
}

int min_in_vector(const std::vector<int> &num_list) {
  std::vector<int>::const_iterator it = num_list.cbegin() + 1;
  int min = num_list[0];

  for (; it != num_list.cend(); ++it) {
    if (min > *it) {
      min = *it;
    }
  }

  return min;
}

int max_in_vector(const std::vector<int> &num_list) {
  std::vector<int>::const_iterator it = num_list.cbegin() + 1;
  int max = num_list[0];

  for (; it != num_list.cend(); ++it) {
    if (max < *it) {
      max = *it;
    }
  }

  return max;
}

int main() {
  std::vector<int> num_list;

  while (true) {
    bool valid_input_given = false;
    std::string int_str;
    while (!valid_input_given) {
      std::cout << "Enter a number: ";
      std::getline(std::cin, int_str);
      if (int_str == "done") {
        std::cout << "Length: " << num_list.size() << '\n';
        std::cout << "Sum: " << sum_vector(num_list) << '\n';
        std::cout << "Min: " << min_in_vector(num_list) << '\n';
        std::cout << "Max: " << max_in_vector(num_list) << '\n';
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
