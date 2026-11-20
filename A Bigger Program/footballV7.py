# footballv7.py
# V1.0 Simple list of matches
# V2.0 Added processing of matches to print out the match results in the correct format
# V3.0 Can now handle case where there aren't the correct number of fields.
# V4.0 determines who won/lost
# V5.0 Added error handling for invalid score data
# V6.0 totting up the points
# V7.0 read from a file instead of hard coding the matches in the program

matches = []  # blank list to store matches
# Dictionary to store each team's total points
points = {}
line = ""
try:
    f = open("../Session 7 Lists and Project Example/matches.txt")
except FileNotFoundError:
    print("file not found")
    exit(-1)  # exit program passing an error code
print("Reading file.")
for line in f:  # loop for every line in  the file
    matches.append(line.strip())
f.close()

print("File closed.")
print("List of matches:")
print(matches)
print(f"There are {len(matches)} matches in the list.")

#now process the matches individually.
for match in matches:
    print("================================")
    match_list = match.split(" ")
    if len(match_list) == 4:
        print(f"{match_list[0]}  {match_list[2]} V {match_list[3]} {match_list[1]}")
    else:
        print(f"Match data is invalid: {match}")
        continue
    try:
        home_score = int(match_list[2])
        away_score = int(match_list[3])
    except ValueError:
        print(f"Invalid score data for match: {match}")
        continue
    home_team = match_list[0]
    away_team = match_list[1]

# Ensure both teams exist in the dictionary even if they lose
    points[home_team] = points.get(home_team, 0)
    points[away_team] = points.get(away_team, 0)

    if home_score > away_score:
        print("home team won")
        points[home_team] += 3
    elif home_score < away_score:
        print("away team won")
        points[away_team] += 3
    else:
        print("match drawn")
        points[home_team] += 1
        points[away_team] += 1

print("\nFinal Points Table:")
#for team, team_points in sorted(points.items(), key=lambda item: item[1], reverse=True):
for team, team_points in points.items():
    print(f"{team}: {team_points}")