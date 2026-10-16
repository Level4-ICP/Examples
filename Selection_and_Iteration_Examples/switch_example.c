//see if_example.c for the equivalent functionality using an if
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

    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Starting game...\n");
            break; // Stops execution from falling through to the next case
        case 2:
            printf("Loading game...\n");
            break;
        case 3:
            printf("Settings...\n");
            break;
        default: // Acts like the final 'else'
            printf("Invalid choice. Please try again.\n");
            break;
    }

}