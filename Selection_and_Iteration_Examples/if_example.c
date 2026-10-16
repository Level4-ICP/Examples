//see switch_example.c for the equivalent functionality using a switch
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