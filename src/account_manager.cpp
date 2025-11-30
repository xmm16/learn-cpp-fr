#include <concepts>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace Bank {
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

template <typename T>
concept AccountType = requires(T acct, double amount) {
  { acct->print_balance() } -> std::same_as<void>;
  { acct->deposit(amount) } -> std::same_as<void>;
  { acct->withdraw(amount) } -> std::same_as<void>;
};

template <AccountType T> class AccountManager {
private:
  std::vector<T> accounts;

public:
  template <AccountType... Accounts>
  AccountManager(Accounts... given_accounts) {
    (accounts.push_back(std::move(given_accounts)), ...);
  }

  void deposit_all(const double amount) {
    for (const T &acct : accounts) {
      acct->deposit(amount);
    }
  }

  void withdraw_all(const double amount) {
    for (const T &acct : accounts) {
      acct->withdraw(amount);
    }
  }

  template <AccountType... Accounts>
  void deposit_all(Accounts... given_accounts, const double amount) {
    (given_accounts->deposit(amount), ...);
  }

  template <AccountType... Accounts>
  void withdraw_all(Accounts... given_accounts, const double amount) {
    (given_accounts->withdraw(amount), ...);
  }

  template <std::floating_point... Amounts>
  void deposit_all(T account, const Amounts... amounts) {
    (account->deposit(amounts), ...);
  }

  template <std::floating_point... Amounts>
  void withdraw_all(T account, const Amounts... amounts) {
    (account->withdraw(amounts), ...);
  }

  void print_all() {
    for (const T &acct : accounts) {
      acct->print_balance();
    }
  }
};
} // namespace Bank

int main() {
  std::unique_ptr<Bank::AccountManager<std::unique_ptr<Bank::Account>>>
      account_man = std::make_unique<
          Bank::AccountManager<std::unique_ptr<Bank::Account>>>(
          std::make_unique<Bank::Savings>("John", 27.56, 4.1),
          std::make_unique<Bank::Savings>("Jacob", 30.11, 3.8));

  account_man->print_all();
  return 0;
}
