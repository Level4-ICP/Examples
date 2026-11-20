#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  const char *matches[] = {"england iran 3 0",  "wales usa 1 0",
                           "england wales x 0", "usa iran 2 1",
                           "england usa 1",     "iran wales 0 5"};
  size_t count = sizeof(matches) / sizeof(matches[0]);

  printf("List of matches:\n");
  for (size_t i = 0; i < count; i++)
  {
    printf("%s\n", matches[i]);
  }
  printf("There are %zu matches in the list.\n", count);

  for (size_t i = 0; i < count; i++)
  {
    char buffer[128];
    char *parts[4];
    int part_count = 0;
    char *endptr = NULL;
    long home_score;
    long away_score;

    printf("================================\n");
    snprintf(buffer, sizeof(buffer), "%s", matches[i]);
    parts[part_count++] = strtok(buffer, " ");
    while ((parts[part_count] = strtok(NULL, " ")) != NULL && part_count < 4)
    {
      part_count++;
    }

    if (part_count != 4)
    {
      printf("Match data is invalid: %s\n", matches[i]);
      continue;
    }

    printf("%s  %s V %s %s\n", parts[0], parts[2], parts[3], parts[1]);

    home_score = strtol(parts[2], &endptr, 10);
    if (*endptr != '\0')
    {
      printf("Invalid score data for match: %s\n", matches[i]);
      continue;
    }

    away_score = strtol(parts[3], &endptr, 10);
    if (*endptr != '\0')
    {
      printf("Invalid score data for match: %s\n", matches[i]);
      continue;
    }

    if (home_score > away_score)
    {
      printf("home team won\n");
    }
    else if (home_score < away_score)
    {
      printf("away team won\n");
    }
    else
    {
      printf("match drawn\n");
    }
  }

  return 0;
}
