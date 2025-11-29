#include <exception>
#include <iostream>
#include <optional>
#include <string>

std::optional<double> safe_stod(const std::string &str) {
  try {
    return std::stod(str);
  } catch (std::exception &e) {
    return {};
  }
}

double celsius_to_fahrenheit(double input) { return input * 9 / 5 + 32; }
double fahrenheit_to_celsius(double input) { return (input - 32) * 9 / 5; }

int main() {
  while (true) {
    bool break_on_quit = false;
    std::optional<double> temperature_stod_result = std::nullopt;
    std::string prompt = "Enter a temperature: ";

    while (!temperature_stod_result) {
      std::string temperature_str;
      std::cout << prompt;

      std::getline(std::cin, temperature_str);
      if (temperature_str == "quit") {
        break_on_quit = true;
        break;
      }

      temperature_stod_result = safe_stod(temperature_str);
      prompt = "Invalid temperature! Enter a new temperature: ";
    }

    if (break_on_quit)
      break;

    std::cout << "Enter a unit (C/F): ";
    std::string unit_string;
    std::getline(std::cin, unit_string);
    if (unit_string.length() != 1) {
      std::cout << "Invalid unit length";
      break;
    }

    const char unit = std::tolower(unit_string[0]);
    switch (unit) {
    case 'c':
      std::cout << "Result: " << celsius_to_fahrenheit(*temperature_stod_result)
                << '\n';
      break;

    case 'f':
      std::cout << "Result: " << fahrenheit_to_celsius(*temperature_stod_result)
                << '\n';
      break;

    default:
      std::cout << "Invalid unit\n";
    }
  }

  return 0;
}
