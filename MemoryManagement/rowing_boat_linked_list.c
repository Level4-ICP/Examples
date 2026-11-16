/*
 * rowing_boat_linked_lists.c
 * @author D Mullier 11/2026
 * a simple linked list using a rowing boat analogy
*/

#include <stdio.h>

// What is inside the boat, including a passenger name
struct Cargo
{
    int boatNumber;
    char passengerName[50];
    float suppliesWeight;
};

// A single Rowing Boat (a node in our linked list)
struct Boat
{
    struct Cargo cargo;     // The data stored in this boat
    struct Boat *next;      // Pointer (rope) to the next boat in line
};

int main()
{
    // --- 1. Creating boats on the stack (no malloc yet!) ---

    // Create Boat 3 (The tail / last boat)
    struct Boat boat3 = {
        {3, "Alice", 15.5f},
        NULL // Reaches the end of the line
    };

    // Create Boat 2 and tie it to the address of boat3 using '&'
    struct Boat boat2 = {
        {2, "Bob", 25.0f},
        &boat3 // Tied to boat 3
    };

    // Create Boat 1 and tie it to the address of boat2
    struct Boat boat1 = {
        {1, "Charlie", 10.0f},
        &boat2 // Tied to boat 2
    };

    // The head pointer ties our mooring post to the first boat
    struct Boat *head = &boat1;


    // --- 2. Walking down the line to inspect each boat ---
    printf("=== Inspecting the Line of Boats (Stack-Allocated) ===\n");
    struct Boat *current = head;
    int index = 1;

    while (current != NULL)
    {
        printf("Boat %d -> Passenger: %s | ID: %d | Supplies: %.1f kg\n",
               index,
               current->cargo.passengerName,
               current->cargo.boatNumber,
               current->cargo.suppliesWeight);

        // Move down the rope to the next boat in line
        current = current->next;
        index++;
    }

    // No free() needed here! Stack memory is managed automatically.
    printf("\nEnd of trip. Stack memory cleans itself up automatically.\n");

    return 0;
}