/*
 * rowing_boat_linked_list.c
 * D Mullier 11/26
 * An example of a linked list using a rowing boat analogy
 * A line of boats are linked via rope (the pointer)
 * traversing from one boat to the next allows access
 * removing a boat involves untying the current boat and the one it is attached to
 * and retying the attached boat
 */

#include <stdio.h>
#include <stdlib.h>


//a boat has and id and a pointer to the next boat
//note that in reality an item in a linked list is going to have some data
//here we don't to keep it simple, but it wouldn't affect how the link list operates
struct Boat
{
    int id;
    struct Boat *next;
};

/// traverse linked list, displaying boat and what is connected to it
/// @param head  first boat
void inspect_boats(struct Boat *head)
{
    printf("\n=== Inspecting Line of Boats ===\n");
    struct Boat *current = head;
    printf("I am holding boat %d\n",head->id);
    while (current != NULL)
    {
        printf("Boat %d ", current->id);
        if (current->next != NULL)
            printf("connected to boat %d\n", current->next->id);
        else
            printf("is the last boat\n");
        current = current->next;
    }
}

/// passing the head and the boat id to remove
/// note you can pass pointers by reference by using ** i.e. Boat **head, then it wouldn't be necessary to return it
struct Boat *remove_boat(struct Boat *head, int id)
{
    struct Boat *current = head, *found = NULL, *previous = head;

    // Search the line for the matching boat
    while (current != NULL)
    {
        if (current->id == id) // found boat?
        {
            found = current;
            break; // stop searching once we find it
        }
        previous = current;          // keep track of the boat ahead of current
        current = current->next; // move down the rope to the next boat
    }

    // Untie and remove the boat if it was found
    if (found != NULL)
    {
        if (found == head)
        {
            // Case A: Removing the first boat -> tie the mooring post to the second boat
            head = found->next;
        }
        else
        {
            // Case B: Removing a middle/end boat -> tie the previous boat to the one behind 'found'
            previous->next = found->next;
        }

        free(found); // deallocate the removed boat's memory
    }

    return head; // return the (possibly updated) mooring post pointer
}

//free up memory for all boats
void deallocate_boats(struct Boat *head)
{
    while (head != NULL)
    {
        struct Boat *temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    struct Boat *head = NULL;
    int number;

    printf("How many boats? ");
    fflush(stdout); //make the output appear when using the debugger
    scanf("%d", &number);
    while (number>0)
    {
            struct Boat *newBoat = malloc(sizeof(struct Boat)); //allocate memory for a new boat
            newBoat->id = number;
            newBoat->next = head;   //connect the rope of the new boat to what is currently connected to head (make them the same)
            head = newBoat;         //connect head to newboat
            number--;
    }

    inspect_boats(head);
    printf("Which boat do you want to remove? ");
    scanf("%d", &number);
    head = remove_boat(head, number);
    inspect_boats(head);

    deallocate_boats(head);

    return 0;
}