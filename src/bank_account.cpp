#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Account {
private:
  const std::string owner;

protected:
  double balance;

public:
  Account(const std::string &name, const double balance)
      : owner(name), balance(balance) {}
  virtual ~Account() = default;

  virtual void print_balance() const = 0;
  virtual void deposit(double amount) { balance += amount; }
  virtual void withdraw(double amount) { balance -= amount; }
};

class Savings : virtual public Account {
protected:
  const double interest_rate;

public:
  Savings(const std::string &name, const double balance,
          const double interest_rate)
      : Account(name, balance), interest_rate(interest_rate) {}
  virtual ~Savings() = default;

  virtual void print_balance() const override {
    std::cout << "Balance: " << balance << '\n';
    std::cout << "Interest rate: " << interest_rate << '\n';
  }
};

class Checking : virtual public Account {
protected:
  double overdraft_limit;

public:
  Checking(const std::string &name, const double balance,
           const double overdraft_limit)
      : Account(name, balance), overdraft_limit(overdraft_limit) {}
  virtual ~Checking() = default;

  virtual void withdraw(double amount) override {
    if (amount <= overdraft_limit) {
      balance -= amount;
    } else {
      std::cout << "Withdrawal is more than the overdraft limit" << '\n';
    }
  }

  virtual void print_balance() const override {
    std::cout << "Balance: " << balance << '\n';
    std::cout << "Overdraft limit: " << overdraft_limit << '\n';
  }
};

class PremiumAccount : public Savings, public Checking {
public:
  PremiumAccount(const std::string &name, const double balance,
                 const double overdraft_limit, const double interest_rate)
      : Account(name, balance), Savings(name, balance, interest_rate),
        Checking(name, balance, overdraft_limit) {}

  virtual void print_balance() const override {
    std::cout << "Balance: " << balance << '\n';
    std::cout << "Overdraft limit: " << overdraft_limit << '\n';
    std::cout << "Interest rate: " << interest_rate << '\n';
  }
};

int main() {
  std::vector<std::unique_ptr<Account>> account_directory;

  account_directory.push_back(std::make_unique<Savings>("John D.", 27.64, 2.1));
  account_directory.push_back(
      std::make_unique<Checking>("Webby R.", 405.10, 50));
  account_directory.push_back(
      std::make_unique<PremiumAccount>("George A.", 1132.07, 500, 10.5));

  std::for_each(account_directory.cbegin(), account_directory.cend(),
                [](const std::unique_ptr<Account> &n) {
                  n->deposit(10);
                  n->withdraw(20);
                  n->print_balance();
                });

  return 0;
}
