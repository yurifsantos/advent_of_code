with open("../day04_input.txt", "r") as file:
    data = [i for i in file.read().strip().split("\n")]

count = 0

for sections in data:
    partition = sections.rfind(',')
    elf_asgn_1 = sections[:partition].split("-")
    elf_asgn_1 = [int(i) for i in elf_asgn_1]
    elf_asgn_2 = sections[partition+1:].split("-")
    elf_asgn_2 = [int(i) for i in elf_asgn_2]

    if elf_asgn_1[0] <= elf_asgn_2[0] and elf_asgn_2[0] <= elf_asgn_1[1]:
        count+=1
    elif elf_asgn_2[0] <= elf_asgn_1[0] and elf_asgn_1[0] <= elf_asgn_2[1]:
        count+=1

print(count)