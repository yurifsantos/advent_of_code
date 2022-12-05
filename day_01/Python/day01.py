#  Day 01 of Advent of Code, my first try on the challange

#  Getting the data from the txt file.
with open("../day01_input.txt") as file:
    data = [i for i in file.read().strip().split("\n")]

#  Creating a list of all elves in the expedition
elves = []

#  Initializing the variables for logic stuff
elfs_calories = 0
max_calories = 0

#  Variables for the second part
second_max = 0
third_max = 0

for calories in data:
    if calories == '':      
        elfs_calories = 0
    else:
        elfs_calories += int(calories)

    if elfs_calories > max_calories:
        third_max = second_max
        second_max = max_calories
        max_calories = elfs_calories
    elif elfs_calories > second_max:
        third_max = second_max
        second_max = elfs_calories
    elif elfs_calories > third_max:
        third_max = elfs_calories

total_calories = max_calories + second_max + third_max

print(f'The elf with the most calories is carrying {max_calories} calories.')
print(f'The elf with the second most calories is carrying {second_max} calories.')
print(f'The elf with the third most calories is carrying {third_max} calories.')
print(f'In total, the three of them are carrying {total_calories} calories!')