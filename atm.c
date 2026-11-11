#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STORED_PIN    1234
#define MAX_ATTEMPTS  3

double balance = 1000.00;
void clearInput(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

bool login(void) {
    int pin;
    for (int attempt = 1; attempt <= MAX_ATTEMPTS; attempt++) {
        printf("Enter your PIN: ");
        if (scanf("%d", &pin) != 1) {
            clearInput();
            pin = -1;
        }
        if (pin == STORED_PIN) {
            printf("Login successful.\n");
            return true;
        }
        printf("Incorrect PIN. Attempts left: %d\n", MAX_ATTEMPTS - attempt);
    }
    printf("Too many failed attempts. Access denied.\n");
    return false;
}


void showMenu(void) {
    printf("\n===== ATM MENU =====\n");
    printf("1. Balance Inquiry\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}


void checkBalance(void) {
    printf("Your current balance is: $%.2f\n", balance);
}

void deposit(double amount) {
    if (amount <= 0) {
        printf("Invalid amount. Deposit must be a positive number.\n");
        return;
    }
    balance += amount;
    printf("Deposited $%.2f. New balance: $%.2f\n", amount, balance);
}

void withdraw(double amount) {
    if (amount <= 0) {
        printf("Invalid amount. Withdrawal must be a positive number.\n");
    } else if (amount > balance) {
        printf("Insufficient balance. Your balance is $%.2f\n", balance);
    } else {
        balance -= amount;
        printf("Withdrew $%.2f. New balance: $%.2f\n", amount, balance);
    }
}

double readAmount(const char *prompt) {
    double amount;
    printf("%s", prompt);
    if (scanf("%lf", &amount) != 1) {
        clearInput();
        return -1;
    }
    return amount;
}

int main(void) {
    int choice;

    printf("Welcome to the Simulated ATM\n");

    if (!login()) {
        return 1;
    }


    do {
        showMenu();
        if (scanf("%d", &choice) != 1) {
            clearInput();
            choice = 0;
        }

        switch (choice) {
            case 1:
                checkBalance();
                break;
            case 2:
                deposit(readAmount("Enter amount to deposit: "));
                break;
            case 3:
                withdraw(readAmount("Enter amount to withdraw: "));
                break;
            case 4:
                printf("Thank you for using the ATM. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select 1-4.\n");
        }
    } while (choice != 4);

    return 0;
}
