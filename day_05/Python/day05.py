with open("../day05_input.txt", "r") as file:
    stack_string, move_string = [i.splitlines() for i in file.read().strip("\n").split("\n\n")]


stacks = {int(digit): [] for digit in stack_string[-1].replace(" ","")}
indexes = [index for index, char in enumerate(stack_string[-1]) if char != " "]
moves = {"amount": [], "from":[], "to":[]}

def loading_stacks():
    for string in stack_string[:-1]:
        stack_num = 1
        for index in indexes:
            if string[index] != " ":
                stacks[stack_num].insert(0, string[index])
            stack_num +=1


def parsing_moves():
    for move in move_string:
        move_parser = move.split(" ")
        move_parser.remove("move")
        move_parser.remove("from")
        move_parser.remove("to")
        moves["amount"].append(int(move_parser[0]))
        moves["from"].append(int(move_parser[1]))
        moves["to"].append(int(move_parser[2]))


def part_1():
    print('\nExecuting the rearrengement of the crates!\n')
    for i in range(len(move_string)):
        move_amout = moves["amount"][i]
        move_from = moves["from"][i]
        move_to = moves["to"][i]

        while move_amout > 0:
            stacks[move_to].append(stacks[move_from].pop())
            move_amout -=1

def part_2():
    print('\nExecuting the rearrengement of the crates!\n')
    for i in range(len(move_string)):
        move_amout = moves["amount"][i]
        move_from = moves["from"][i]
        move_to = moves["to"][i]

        while move_amout > 0:
            stacks[move_to].append(stacks[move_from].pop(-move_amout))
            move_amout-=1


def display():
    print('Current Stakc is:\n')
    for stack in stacks:
        print(stack, stacks[stack])

def final_answer():
    answer = ''
    for stack in stacks:
        answer += stacks[stack][-1]

    return answer

if __name__ == '__main__':
    loading_stacks()
    display()
    parsing_moves()
    part_2()
    display()
    print(final_answer())