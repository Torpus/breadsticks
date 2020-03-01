from sys import argv
import re

r = re.compile("breadsticks")
result = 0

with open(argv[1], "r") as f:
    for line in f:
        if r.match(line):
            result += int(line.split(" ")[1])

print(result)