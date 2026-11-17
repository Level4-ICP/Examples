#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Boat
{
    int id;

    struct Boat *next;
};

int main()
{
    struct Boat *head = NULL;
    char input[50];
    int number;

    printf("How many boats? ");
    scanf("%d", &number);
    while (number>0)
    {
            struct Boat *newBoat = malloc(sizeof(struct Boat));
            newBoat->id = number;
            number--;

            newBoat->next = head;
            head = newBoat;
    }


    printf("\n=== Inspecting Line of Boats ===\n");
    struct Boat *current = head;
    while (current != NULL)
    {
        printf("Boat %d\n", current->id);
        current = current->next;
    }

    while (head != NULL)
    {
        struct Boat *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}