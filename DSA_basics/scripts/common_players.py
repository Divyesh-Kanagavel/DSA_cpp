# given two arrays of basketball and football players, find the common players
# a player is said to be in both the games if first and common names are same
# time complexity : O(n+m) , memory complexity : O(n)
basketball_players = [
      {"first_name": "Jill", "last_name": "Huang", "team": "Gators"},
      {"first_name": "Janko", "last_name": "Barton", "team": "Sharks"},
      {"first_name": "Wanda", "last_name": "Vakulskas", "team": "Sharks"},
      {"first_name": "Jill", "last_name": "Moloney", "team": "Gators"},
      {"first_name": "Luuk", "last_name": "Watkins", "team": "Gators"}
]

football_players = [
      {"first_name": "Hanzla", "last_name": "Radosti", "team": "32ers"},
      {"first_name": "Tina", "last_name": "Watkins", "team": "Barleycorns"},
      {"first_name": "Alex", "last_name": "Patel", "team": "32ers"},
      {"first_name": "Jill", "last_name": "Huang", "team": "Barleycorns"},
      {"first_name": "Wanda", "last_name": "Vakulskas", "team": "Barleycorns"}
]

def find_common_players(basketball_players, football_players):
    basketball_players_hash = {}
    for player in basketball_players:
        key = player["first_name"] + " " + player["last_name"]
        basketball_players_hash[key] = 1
    
    common_players = []
    for player in football_players:
        key = player["first_name"] + " " + player["last_name"]
        if basketball_players_hash.get(key):
            common_players.append(key)

    return common_players

print(find_common_players(basketball_players, football_players))


        
