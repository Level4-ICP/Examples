#include <stdio.h>

// Define an enum named 'TrafficLight'
// By default, RED = 0, YELLOW = 1, and GREEN = 2
enum TrafficLight {
    RED,
    YELLOW,
    GREEN
};

int main(void) {
    // Declare a variable of type 'enum TrafficLight' and initialize it
    enum TrafficLight current_light = RED;

    // Use the enum values in a switch statement
    switch (current_light) {
        case RED:
            printf("The light is RED. Stop!\n");
            break;
            
        case YELLOW:
            printf("The light is YELLOW. Prepare to stop or proceed with caution.\n");
            break;
            
        case GREEN:
            printf("The light is GREEN. Go!\n");
            break;
            
        default:
            printf("Error: Invalid traffic light state.\n");
            break;
    }

    // You can also print the underlying integer value of an enum
    printf("The raw integer value of the current light is: %d\n", current_light);

    return 0;
}