#include <stdio.h>

#include "BankAccount.h"

int main() {
  BankAccount a = {.name = "Jhon Doe", .num = "OWO1234", .balance = 42.42};
  printBankAccount(a);
  deposit(&a, 50);
  printBankAccount(a);
  withdraw(&a, 2.22);
  printBankAccount(a);
  return 0;
}
