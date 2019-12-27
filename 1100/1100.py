count = 0
for i in range(0, 8):
	s = input()
	for j in range(0, 8):
		if (i+j)%2 == 0 and s[j] == "F":
			count += 1
print(count)
