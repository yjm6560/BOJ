n = (int)(input())
str_set = []
for i in range(0, n):
	s = input()
	str_set.append(s)
	if s[::-1] in str_set:
		print(f'{len(s)} {s[(int)(len(s)/2)]}')
