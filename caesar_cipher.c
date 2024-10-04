#include<stdio.h>
#include<string.h>

// Functions used
void encrypt(char *msg, int shft);
void decrypt(char *msg, int shft);
void getText(char *msg, int size);
int isValidShift(int shft);
void displayMenu();

int main() {
    char msg[256];  // Buffer for longer messages
    int shft;       // shift
    char choice;
    displayMenu();  // to display the menu
    scanf(" %c", &choice);  

    while (choice != 'q' && choice != 'Q')
     {
        getText(msg, sizeof(msg));  // getting input

        printf("Enter the shift value (0-25): ");  // input the shift value from the user
        scanf("%d", &shft);

        if (!isValidShift(shft)) 
        {
            printf("Invalid Shift Value. Please enter a number between 0 and 25.\n");
            continue;
        }

        if (choice == 'e' || choice == 'E') 
        {
            encrypt(msg, shft);
            printf("Encrypted Message: %s\n", msg);
        } 
        else if (choice == 'd' || choice == 'D') 
        {
            decrypt(msg, shft);
            printf("Decrypted Message: %s\n", msg);
        } 
        else 
        {
            printf("Invalid Choice. Please enter 'e' | 'E' for encrypting or 'd' | 'D' for decrypting.\n");
        }
        displayMenu();
        scanf(" %c", &choice);  
    }

    return 0;  
}

// Function for encrypting
void encrypt(char *msg, int shft) 
{
    for (int i = 0; msg[i] != '\0'; i++) 
    {
        char current = msg[i];

        // Uppercase Letter Encryption
        if (current >= 'A' && current <= 'Z') 
        {
            msg[i] = (current + shft - 'A') % 26 + 'A';
        }
        // Lowercase Letter Encryption
        else if (current >= 'a' && current <= 'z') 
        {
            msg[i] = (current + shft - 'a') % 26 + 'a';
        }
    }
}

// Function for decrypting
void decrypt(char *msg, int shft) 
{
    for (int i = 0; msg[i] != '\0'; i++) 
    {
        char current = msg[i];

        // Uppercase Letter Decryption
        if (current >= 'A' && current <= 'Z') 
        {
            msg[i] = (current - shft - 'A' + 26) % 26 + 'A';  
        }
        // Lowercase Letter Decryption
        else if (current >= 'a' && current <= 'z') 
        {
            msg[i] = (current - shft - 'a' + 26) % 26 + 'a'; 
        }
    }
}

// Receives User Input
void getText(char *msg, int size) 
{
    printf("Enter the message: ");
    getchar(); 
    fgets(msg, size, stdin);
    msg[strcspn(msg, "\n")] = '\0';  
}

// Checking for the validity of the shift
int isValidShift(int shft) 
{
    return (shft >= 0 && shft <= 25);
}

// Menu
void displayMenu() 
{
    printf("\n---------------Caesar Cipher Menu---------------\n");
    printf("Choose an option:\n");
    printf("  (e) Encrypt a message\n");
    printf("  (d) Decrypt a message\n");
    printf("  (q) Quit the program\n");
    printf("---------------------------------\n");
}