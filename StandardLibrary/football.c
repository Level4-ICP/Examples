/* football.c
 * V1
 * hard coded data
 * prints out matches in correct format
 */

#include <stdio.h>

int main(void)
{
  const char *matches[] = {
    "England", "1", "USA", "0",
    "Scotland", "2", "Wales", "1",
    "France", "3", "Germany", "2",
    "Spain", "1", "Italy", "1"
};

  int total_items = sizeof(matches) / sizeof(matches[0]);

  for (int i = 0; i < total_items; i += 4)
  {
    printf("%s %s V %s %s\n", matches[i], matches[i + 1], matches[i + 3], matches[i + 2]);
  }

  return 0;
}