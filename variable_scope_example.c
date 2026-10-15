#include <stdio.h>
float total_diff = 0; // a global variable, accessible everywhere

void diff(int first, int second)
{
// this local variable 'diff' is only accessible within this function
  int diff = second - first;
  printf("Difference is = %d\n", diff);
  fflush(stdout); //if running under the debugger the buffer needs flushing to make sure it displays
  total_diff += diff; // total_diff is global (shared by all)
}

void diff_float(float first, float second)
{
// this local variable 'diff' is different to the 'diff' in the other function
  float diff = second - first;
  printf("Difference is = %f\n", diff);
  total_diff += diff;
}

int main(void)
{
  diff(100, 200);
  diff(50, 75);
  diff_float(65.2, 100.2);
  printf("\nThe Total Difference is = %f", total_diff);
} 