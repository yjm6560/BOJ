
def sort(ary):
	if not ary:
		return []
	pivot = ary[0]
	return sort([x for x in ary if x < pivot]) + [pivot] + sort([x for x in ary if x > pivot])

a = [int(i) for i in input().split()]
print(sort(a))
