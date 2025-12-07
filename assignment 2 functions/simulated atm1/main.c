#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ATTEMPTS 3
#define CORRECT_PIN "1234"

bool login() {
    char userpin[10];
    int attempts = MAX_ATTEMPTS;

    while (attempts--) {
        printf("Please input your PIN: ");
        scanf("%s", userpin);

        if (strcmp(userpin, CORRECT_PIN) == 0) {
            printf("Access granted.\n");
            return true;
        }

        printf("Incorrect PIN.\n");
        if (attempts > 0) {
            printf("Try again. Attempts left: %d\n", attempts);
        }
    }

    printf("Maximum attempts exceeded. Access denied.\n");
    return false;
}

void checkBalance(double balance) {
    printf("Your current balance is: Ksh%.2f\n", balance);
}

double deposit(double balance) {
    double amount;
    printf("Enter amount to deposit: Ksh");

    if (scanf("%lf", &amount) != 1 || amount <= 0) {
        while (getchar() != '\n');
        printf("Invalid amount. Deposit must be positive.\n");
        return balance;
    }

    balance += amount;
    printf("Deposit successful. New balance: Ksh%.2f\n", balance);
    return balance;
}

double withdraw(double balance) {
    double amount;
    printf("Enter amount to withdraw: Ksh");

    if (scanf("%lf", &amount) != 1 || amount <= 0) {
        while (getchar() != '\n');
        printf("Invalid amount. Withdrawal must be positive.\n");
        return balance;
    }

    if (amount > balance) {
        printf("Insufficient balance.\n");
        return balance;
    }

    balance -= amount;
    printf("Withdrawal successful. New balance: Ksh%.2f\n", balance);
    return balance;
}

void showMenu() {
    printf("\n--- ATM MENU ---\n");
    printf("1. Balance inquiry\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    double balance = 1000.00;
    int choice;

    if (!login()) {
        return 0;
    }

    do {
        showMenu();
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance = deposit(balance);
                break;
            case 3:
                balance = withdraw(balance);
                break;
            case 4:
                printf("Thank you for using our ATM. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select 1-4.\n");
        }
    } while (choice != 4);

    return 0;
}
