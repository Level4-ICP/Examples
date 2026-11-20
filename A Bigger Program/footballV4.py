# footballv4.py
# V1.0 Simple list of matches
# V2.0 Added processing of matches to print out the match results in the correct format
# V3.0 Can now handle case where there aren't the correct number of fields.
# V4.0 determines who won/lost

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
    home_score = int(match_list[2])
    away_score = int(match_list[3])
    if home_score > away_score:
        print("home team won")
    elif home_score < away_score:
        print("away team won")
    else:
        print("match drawn")
# note here I get a run-time error, a ValueError, because one of the matches has an invalid score, "x" instead of a number. I will need to add some error handling to catch this and continue processing the other matches.
