# footballv5.py
# V1.0 Simple list of matches
# V2.0 Added processing of matches to print out the match results in the correct format
# V3.0 Can now handle case where there aren't the correct number of fields.
# V4.0 determines who won/lost
# V5.0 Added error handling for invalid score data
matches =["england iran 3 0","wales usa 1 0","england wales x 0","usa iran 2 1","england usa 1","iran wales 0 5"]

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
    if home_score > away_score:
        print("home team won")
    elif home_score < away_score:
        print("away team won")
    else:
        print("match drawn")
# next instead of just saying who won, lets add points to a table