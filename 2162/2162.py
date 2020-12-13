
def isCrossed(x1, y1, x2, y2, x3, y3, x4, y4):
	fn1 = x1*y2 - x2*y1 + x2*y3 - x3*y2 + x3*y1 - x1*y3
	fn2 = x1*y2 - x2*y1 + x2*y4 - x4*y2 + x4*y1 - x1*y4
	return (fn1*fn2 < 0)

n = int(input())

line_set = []
lines = []
for i in range(0,n) :
	lines.append(list(map(int, input().split())))

for new_line in lines:
	for check_lines in line_set:
		for check_line in check_lines:
			if isCrossed(new_line[0], new_line[1], new_line[2], new_line[3], check_line[0], check_line[1], check_line[2], check_line[3]):
				check_lines.append(new_line)
				
print()
