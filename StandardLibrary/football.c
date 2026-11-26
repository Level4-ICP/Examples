/* football.c
 * V3
 * hard coded data
 * prints out matches in correct format
 * Converts goals into integers
 * Added TeamEntry structure to record points for each team
 * and logic to allocate points
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEAMS 32

typedef struct
{
    char name[32];
    int points;
} TeamEntry;

/*
 * table[] to store details in
 * team_count how many teams are currently in it
 * team to search for or add if not found
 */
static int find_or_add_team(TeamEntry table[], int *team_count, const char *name)
{
    for (int i = 0; i < *team_count; i++)
    {
        if (strcmp(table[i].name, name) == 0)
        {
            return i;
        }
    }

    if (*team_count < MAX_TEAMS)
    {
        int idx = *team_count;
        strncpy(table[idx].name, name, sizeof(table[idx].name) - 1); //copy the name of the team into the table entry
        table[idx].name[sizeof(table[idx].name) - 1] = '\0'; //terminate the string
        table[idx].points = 0;
        (*team_count)++;
        return idx;
    }

    return -1;
}

int main(void)
{
    const char *matches[] = {
        "England", "1", "USA", "0",
        "England", "3", "USA", "2",
        "Scotland", "2", "Wales", "1",
        "France", "3", "Germany", "2",
        "Spain", "1", "Italy", "1"
    };

    int total_items = sizeof(matches) / sizeof(matches[0]);
    TeamEntry table[MAX_TEAMS] = {0};
    int team_count = 0;

    for (int i = 0; i < total_items; i += 4)
    {
        const char *home_team = matches[i]; //here we arent creating a new variable, we are pointing at an existing one
        int home_goals = atoi(matches[i + 1]);
        const char *away_team = matches[i + 2];
        int away_goals = atoi(matches[i + 3]);

        //find or add the teams to the league table
        int home_idx = find_or_add_team(table, &team_count, home_team);
        int away_idx = find_or_add_team(table, &team_count, away_team);

        printf("%s %d V %d %s -> ", home_team, home_goals, away_goals, away_team);

        if (home_goals > away_goals)
        {
            printf("%s won\n", home_team);
            if (home_idx >= 0)
            {
                table[home_idx].points += 3;
            }
        }
        else if (away_goals > home_goals)
        {
            printf("%s won\n", away_team);
            if (away_idx >= 0)
            {
                table[away_idx].points += 3;
            }
        }
        else
        {
            printf("Draw\n");
            if (home_idx >= 0)
            {
                table[home_idx].points += 1;
            }
            if (away_idx >= 0)
            {
                table[away_idx].points += 1;
            }
        }
    }

    printf("\n=== League Table ===\n");
    for (int i = 0; i < team_count; i++)
    {
        printf("%-12s %d pts\n", table[i].name, table[i].points);
    }

    return 0;
}