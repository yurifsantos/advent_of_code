with open("../day06_input.txt", "r") as file:
    data = [i for i in file.read()]

def part_1():
    for i in range(len(data)):
        if len(set(data[i:i+4])) == 4:
            return i + 4
        else:
            continue

print(part_1())
print(data[part_1():part_1()+4])