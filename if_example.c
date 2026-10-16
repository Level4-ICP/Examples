#include <stdio.h>
int main()
{
    char buffer[100];
    int choice;

    // Display the menu
    printf("--- GAME MENU ---\n");
    printf("1. Start game\n");
    printf("2. Load game\n");
    printf("3. Settings\n");
    printf("Enter your choice (1-3): ");

    // read the line of input using fgets. The way C handles this looks a bit intimidating. You pass a buffer to take input, stdin is the standard input device (keyboard)
    fgets(buffer, sizeof(buffer), stdin);
    // Because we have received a string we must convert it to an integer
        if (sscanf(buffer, "%d", &choice) != 1)
        {
            printf("error in menu choice");
            return -1;
        }

    if (choice == 1)
    {
        printf("Starting game...\n");
    }
    else if (choice == 2)
    {
        printf("Loading game...\n");
    }
    else if (choice == 3)
    {
        printf("Settings...\n");
    }
    else
    {
        printf("Invalid choice. Please try again.\n");
    }



}