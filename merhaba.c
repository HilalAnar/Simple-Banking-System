#include <stdio.h>

void checkBalance(float balance);
  float deposit();
  float withdraw(float balance);

int main() {

int choice;
float balance = 0.0;

printf("Welcome to the Simple Banking System\n");

do {
        printf("\nMenu:\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Hata: Lutfen sadece sayi giriniz!\n");
            while (getchar() != '\n'); // Giriş tamponundaki hatalı karakterleri temizler
            choice = 0; // Geçersiz seçim yaparak döngüyü devam ettirir
            continue;
        }

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance += deposit();
                break;
            case 3:
                balance -= withdraw(balance);
                break;
            case 4:
                printf("Thank you for using the Simple Banking System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4); // DO-WHILE döngüsü burada biter (noktalı virgül şart)

    return 0; 
}


  void checkBalance(float balance) {
    printf("Your current balance is: $%.2f\n", balance);
}

    float deposit() {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount > 0) {
        printf("Successfully deposited $%.2f\n", amount);
        return amount;
    } else {
        printf("Invalid amount.\n");
        return 0;
    }
}


    float withdraw(float balance) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    
    if (amount > balance) {
        printf("Insufficient funds! You only have $%.2f\n", balance);
        return 0;
    } else if (amount <= 0) {
        printf("Invalid amount.\n");
        return 0;
    } else {
        printf("Successfully withdrew $%.2f\n", amount);
        return amount;
    }
}

