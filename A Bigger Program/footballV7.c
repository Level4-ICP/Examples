#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  char name[32];
  int points;
} Team;

static int find_team(Team *teams, size_t count, const char *name)
{
  for (size_t i = 0; i < count; i++)
  {
    if (strcmp(teams[i].name, name) == 0)
    {
      return (int)i;
    }
  }
  return -1;
}

static void add_team_if_needed(Team *teams, size_t *count, const char *name)
{
  if (find_team(teams, *count, name) == -1)
  {
    snprintf(teams[*count].name, sizeof(teams[*count].name), "%s", name);
    teams[*count].points = 0;
    (*count)++;
  }
}

static int open_matches_file(FILE **file)
{
  const char *paths[] = {"matches.txt", "A Bigger Program/matches.txt",
                         "../A Bigger Program/matches.txt"};

  for (size_t i = 0; i < 3; i++)
  {
    *file = fopen(paths[i], "r");
    if (*file != NULL)
    {
      return 1;
    }
  }

  return 0;
}

int main(void)
{
  FILE *file = NULL;
  char line[128];
  Team teams[20];
  size_t team_count = 0;

  printf("Reading file.\n");
  if (!open_matches_file(&file))
  {
    printf("file not found\n");
    return -1;
  }

  printf("File closed.\n");
  printf("List of matches:\n");

  while (fgets(line, sizeof(line), file) != NULL)
  {
    char *parts[4];
    int part_count = 0;
    char *endptr = NULL;
    long home_score;
    long away_score;
    int home_index;
    int away_index;

    line[strcspn(line, "\r\n")] = '\0';
    if (line[0] == '\0')
    {
      continue;
    }

    printf("%s\n", line);

    parts[part_count++] = strtok(line, " ");
    while ((parts[part_count] = strtok(NULL, " ")) != NULL && part_count < 4)
    {
      part_count++;
    }

    if (part_count != 4)
    {
      printf("Match data is invalid: %s\n", line);
      continue;
    }

    printf("================================\n");
    printf("%s  %s V %s %s\n", parts[0], parts[2], parts[3], parts[1]);

    home_score = strtol(parts[2], &endptr, 10);
    if (*endptr != '\0')
    {
      printf("Invalid score data for match: %s\n", line);
      continue;
    }

    away_score = strtol(parts[3], &endptr, 10);
    if (*endptr != '\0')
    {
      printf("Invalid score data for match: %s\n", line);
      continue;
    }

    add_team_if_needed(teams, &team_count, parts[0]);
    add_team_if_needed(teams, &team_count, parts[1]);

    home_index = find_team(teams, team_count, parts[0]);
    away_index = find_team(teams, team_count, parts[1]);

    if (home_score > away_score)
    {
      printf("home team won\n");
      teams[home_index].points += 3;
    }
    else if (home_score < away_score)
    {
      printf("away team won\n");
      teams[away_index].points += 3;
    }
    else
    {
      printf("match drawn\n");
      teams[home_index].points += 1;
      teams[away_index].points += 1;
    }
  }

  fclose(file);
  printf("\nFinal Points Table:\n");
  for (size_t i = 0; i < team_count; i++)
  {
    printf("%s: %d\n", teams[i].name, teams[i].points);
  }

  return 0;
}
