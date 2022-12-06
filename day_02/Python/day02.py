#  Day 02 of Advent of Code, my first try on the challange

#  Getting the data from the txt file.
with open("../day02_input.txt") as file:
    data = [i for i in file.read().strip().split("\n")]

#  Creating a list for each player
player_me, player_opponent = [], []

#  Separating each choice into two list, one for me and the
#  other for the opponent for a more easy way to handle the 
#  lists.
for choice in data:
    player = choice.split()
    player_opponent.append(player[0])
    player_me.append(player[1])

#  Creating a dict to pair the value of each choice to it.
#  Done a part 1 and 2 due to the value changing between parts.
part1_points={
    "X": 1,
    "Y": 2,
    "Z": 3,
    "W": 6,
    "D": 3,
    "L": 0
}

part2_points={
    "X": 0,
    "Y": 3,
    "Z": 6,
    "R": 1,
    "P": 2,
    "S": 3
}

part1_score = 0

for i in range(len(data)):
    if player_me[i] == 'X':
        part1_score += part1_points.get("X")
        if player_opponent[i] == 'A':
            part1_score += part1_points.get("D")
        elif player_opponent[i] == 'B':
            part1_score += part1_points.get("L")
        else: 
            part1_score+= part1_points.get("W")
    if player_me[i] == 'Y':
        part1_score += part1_points.get("Y")
        if player_opponent[i] == 'A':
            part1_score += part1_points.get("W")
        elif player_opponent[i] == 'B':
            part1_score += part1_points.get("D")
        else: 
            part1_score+= part1_points.get("L")
    if player_me[i] == 'Z':
        part1_score += part1_points.get("Z")
        if player_opponent[i] == 'A':
            part1_score += part1_points.get("L")
        elif player_opponent[i] == 'B':
            part1_score += part1_points.get("W")
        else: 
            part1_score+= part1_points.get("D")

part2_score = 0

for i in range(len(data)):
    if player_me[i] == 'X':
        part2_score += part2_points.get("X")
        if player_opponent[i] == 'A':
            part2_score += part2_points.get("S")
        elif player_opponent[i] == 'B':
            part2_score += part2_points.get("R")
        else: 
            part2_score+= part2_points.get("P")
    if player_me[i] == 'Y':
        part2_score += part2_points.get("Y")
        if player_opponent[i] == 'A':
            part2_score += part2_points.get("R")
        elif player_opponent[i] == 'B':
            part2_score += part2_points.get("P")
        else: 
            part2_score+= part2_points.get("S")
    if player_me[i] == 'Z':
        part2_score += part2_points.get("Z")
        if player_opponent[i] == 'A':
            part2_score += part2_points.get("P")
        elif player_opponent[i] == 'B':
            part2_score += part2_points.get("S")
        else: 
            part2_score+= part2_points.get("R")

print(part2_score)