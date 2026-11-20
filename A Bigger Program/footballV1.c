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

    printf("================================\n");
    printf("Processing match: %s\n", matches[i]);
    snprintf(buffer, sizeof(buffer), "%s", matches[i]);

    parts[part_count++] = strtok(buffer, " ");
    while ((parts[part_count] = strtok(NULL, " ")) != NULL && part_count < 4)
    {
      part_count++;
    }

    printf("Processing match: ");
    for (int j = 0; j < part_count; j++)
    {
      printf("%s%s", j > 0 ? " " : "", parts[j]);
    }
    printf(" has %d elements.\n", part_count);
  }

  return 0;
}
