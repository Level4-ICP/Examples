/* football.c
 * V2
 * hard coded data
 * prints out matches in correct format
 * Converts goals into integers
 */

#include <stdio.h>
#include <stdlib.h>

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
    const char *home_team = matches[i];
    int home_goals = atoi(matches[i + 1]);
    const char *away_team = matches[i + 2];
    int away_goals = atoi(matches[i + 3]);

    printf("%s %d V %d %s -> ", home_team, home_goals, away_goals, away_team);

    if (home_goals > away_goals)
    {
      printf("%s won\n", home_team);
    }
    else if (away_goals > home_goals)
    {
      printf("%s won\n", away_team);
    }
    else
    {
      printf("Draw\n");
    }
  }

  return 0;
}