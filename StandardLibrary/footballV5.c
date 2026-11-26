/* football.c
 * V5
 * hard coded data
 * prints out matches in correct format
 * Converts goals into integers
 * Added TeamEntry structure to record points for each team
 * and logic to allocate points
 * sort the table
 * reads data from a file
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEAMS 32
#define MAX_LINE_LEN 128

typedef struct
{
    char name[32];
    int points;
} TeamEntry;

static void strip_newline(char *line)
{
    size_t len = strlen(line);
    while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r'))
    {
        line[len - 1] = '\0';
        len--;
    }
}

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

static void sort_table(TeamEntry table[], int team_count)
{
    for (int i = 0; i < team_count - 1; i++)
    {
        int best_idx = i;

        for (int j = i + 1; j < team_count; j++)
        {
            if (table[j].points > table[best_idx].points)
            {
                best_idx = j;
            }
        }

        if (best_idx != i)
        {
            TeamEntry temp = table[i];
            table[i] = table[best_idx];
            table[best_idx] = temp;
        }
    }
}

int main(void)
{
    FILE *fp = fopen("matches.txt", "r");
    if (fp == NULL)
    {
        printf("Could not open matches.txt\n");
        return 1;
    }

    TeamEntry table[MAX_TEAMS] = {0};
    int team_count = 0;

    char home_team[MAX_LINE_LEN];
    char home_score_str[MAX_LINE_LEN];
    char away_team[MAX_LINE_LEN];
    char away_score_str[MAX_LINE_LEN];

    while (!feof(fp))
    {
        if (fgets(home_team, sizeof(home_team), fp) == NULL)
        {
            break;
        }
        if (fgets(home_score_str, sizeof(home_score_str), fp) == NULL)
        {
            break;
        }
        if (fgets(away_team, sizeof(away_team), fp) == NULL)
        {
            break;
        }
        if (fgets(away_score_str, sizeof(away_score_str), fp) == NULL)
        {
            break;
        }

        strip_newline(home_team); //we need to strip to get rid of the \n character that separates lines in a file
        strip_newline(home_score_str);
        strip_newline(away_team);
        strip_newline(away_score_str);

        int home_goals = atoi(home_score_str);
        int away_goals = atoi(away_score_str);

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
    fclose(fp);

    sort_table(table, team_count);

    printf("\n=== League Table ===\n");
    for (int i = 0; i < team_count; i++)
    {
        printf("%-12s %d pts\n", table[i].name, table[i].points);
    }

    return 0;
}