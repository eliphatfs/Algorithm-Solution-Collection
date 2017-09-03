import sys

line1 = input()
line2 = input()
line3 = input()
calc1 = line2.split(" ")
calc2 = line3.split(" ")

maxlen = 0
if len(calc1) > len(calc2):
	maxlen = len(calc1)
else:
	maxlen = len(calc2)
	
outlist = []

for i in range(len(calc1)+len(calc2)-1):
	outlist.append(0)

for i in range(len(calc1)):
	for j in range(len(calc2)):
		outlist[i+j] += int(calc1[i]) * int(calc2[j])

for i in range(len(calc1)+len(calc2)-1):
	print(outlist[i], end=" ")

sys.exit(0)