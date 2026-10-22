#include <stdio.h>

struct point
{
    int x;
    int y;
    int z;
};


struct sphere
{
    struct point position;
    float radius;
};

typedef struct point point;
typedef struct sphere sphere;

struct point apply_offset(point p, int offset)
{
    point result = p;

    result.x += offset;
    result.y += offset;
    result.z += offset;

    return result;
}
int main()
{
    point p1;	// create a variable 'p1' of type point
    point p2 = {10, 2, 4};	// create and init variable 'p2' of type point

    // set the three members of 'p1' using '.' to identify each member
    p1.x = 0;
    p1.y = 10;
    p1.z = -32;


    printf("Point 1 coordinates: x = %d, y = %d, z = %d\n", p1.x, p1.y, p1.z);
    printf("Point 2 coordinates: x = %d, y = %d, z = %d\n", p2.x, p2.y, p2.z);
    fflush(stdout); //otherwise we won't see the console output in the debugger

    p1 = apply_offset(p1, 10);
    point p3;
    p3 = apply_offset(p2, 10);
    printf("Point 1 coordinates: x = %d, y = %d, z = %d\n", p1.x, p1.y, p1.z); //p1 had changed
    printf("Point 2 coordinates: x = %d, y = %d, z = %d\n", p2.x, p2.y, p2.z); //p2 has not
    printf("Point 3 coordinates: x = %d, y = %d, z = %d\n", p3.x, p3.y, p3.z); //p3 is an updated version of p2
    fflush(stdout); //otherwise we won't see the console output in the debugger

    sphere s1 = { {10,4,1}, 6.2f };
    float radius = s1.radius;
    int x,y,z;
    x = s1.position.x;
    y = s1.position.y;
    z = s1.position.z;

    printf("Sphere has radius %.2f coordinates: x = %d, y = %d, z = %d\n", radius, x, y, z);
    fflush(stdout); //otherwise we won't see the console output in the debugger
}