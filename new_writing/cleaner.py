# remove whitespace and join together all lines

text=[]
newtext=""

with open("razz83.txt") as file:
    for line in file:
        line = line.rstrip()
        if line:
            text.append(line)

for lines in text:
    newtext=newtext+" "+lines
            
#print newtext

# how to get rid of non ascii?

onlymatch = ''.join([s for s in newtext if s in
              ' ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'])

print onlymatch
