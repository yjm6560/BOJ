
line = input()
ret = 0

if '-' not in line:
	arr = line.split('+')
#	sum = sum(list(map(int, arr)))
	arr = list(map(int, arr))
	ret = sum(arr)
	print(ret)
else:
	arr = line.split('-')
	ret = sum(list(map(int, arr[0].split('+'))))
	for i in range(1, len(arr)):
		ret -= sum(list(map(int, arr[i].split('+'))))
	print(ret)
