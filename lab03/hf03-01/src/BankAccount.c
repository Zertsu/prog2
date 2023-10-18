#include "BankAccount.h"

void printBankAccount(BankAccount account) {
  fprintBankAccount(stdout, account);
}

void fprintBankAccount(FILE *file, BankAccount account) {
  fprintf(file, "%s (%s) %.2lf\n", account.name, account.num, account.balance);
}

void deposit(BankAccount *account, double amount) {
  account->balance += amount;
}

void withdraw(BankAccount *account, double amount) {
  account->balance -= amount;
}
