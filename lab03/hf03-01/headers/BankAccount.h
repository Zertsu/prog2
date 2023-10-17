#pragma once

#include <stdio.h>

typedef struct {
  char name[64];
  char num[64];
  double balance;
} BankAccount;

void printBankAccount(BankAccount account);
void fprintBankAccount(FILE *file, BankAccount account);
void deposit(BankAccount *account, double amount);
void withdraw(BankAccount *account, double amount);
