# footballv2.py
# V1.0 Simple list of matches
# V2.0 Added processing of matches to print out the match results in the correct format

matches =["england iran 3 0","wales usa 1 0","england wales x 0","usa iran 2 1","england usa 1","iran wales 0 5"]

print("List of matches:")
print(matches)
print(f"There are {len(matches)} matches in the list.")

#now process the matches individually.
for match in matches:
    print("================================")
    match_list = match.split(" ")
    print(f"{match_list[0]}  {match_list[2]} V {match_list[3]} {match_list[1]}")
# we get a run time error because not all of the matches have correct data, we need to check for this
