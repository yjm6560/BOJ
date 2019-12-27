n = input()
s = input()
if "LL" in s:
	ret = s.replace("LL","C")
	print(len(ret)+1)
else:
	print(len(s))
