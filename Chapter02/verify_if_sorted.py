#reads file name 'output.txt'
file = open('output.txt', 'r')
lst = [int(num) for num in file.read().split(' ')]

sorted = 1
index = 1
print("List length: {}".format(len(lst)))
while (sorted == 1 and index < len(lst)):
	if lst[index] < lst[index - 1]:
		sorted = 0
		print("list is not sorted")
	index += 1

if sorted == 1:
	print("list is sorted")