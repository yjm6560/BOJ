import sys
import os
import shutil

cppForm = "FORMAT.cpp"
q_num = sys.argv[1]

try:
	if not(os.path.isdir(q_num)):
		os.makedirs(os.path.join(q_num))
	else:
		print(f"{q_num} directory already exists")
except OSError as e:
	print(f"Making {q_num} directory is failed")
	exit(0)

try:
	if not(os.path.isfile(q_num)):
		shutil.copy(cppForm, f"{q_num}/{q_num}.cpp")
	else :
		print(f"cpp format file doesn't exist")
except:
	print("Format copy error")
