#  Day 03 of Advent of Code, my first try on the challange

#  Importing the ascii_letters string fomr the string module
from string import ascii_letters

#  Getting the data from the txt file.
with open("../day03_input.txt", "r") as file:
    data = [i for i in file.read().strip().split("\n")]


total_sum = 0

# for rucksack in data:
#     middle = int(len(rucksack)/2)
#     left_rucksack = rucksack[:middle]
#     right_rucksack = rucksack[middle:]
#     for letter in left_rucksack:
#         if letter in right_rucksack:
#            total_sum += ascii_letters.rfind(letter) + 1
#            break

for i in range(0, len(data), 3):
    rs1, rs2, rs3 = data[i], data[i+1], data[i+2]
    for letter in rs1:
        if letter in rs2 and letter in rs3:
            total_sum += ascii_letters.rfind(letter) + 1
            break

print(total_sum)