import re

with open("homePage.html", "r") as file:
    lines = file.readlines()
    for line in lines:
        line = line.strip()
        if line.find('"') > -1:
            line = re.sub('"','\\"',line)
        line = '"' + line + '"'
        print(line)
