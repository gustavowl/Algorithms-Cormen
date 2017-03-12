#lst:	receives the list to be merged. lst contains  only the left and right side to be merged, i.e. it is a sublist
#		example: input: [4, 3, 2, 1]. It may be the case that lst == input. However, lst may also be [4, 3] or [2, 1]
#		depending on the call
#
#start:	indicates the start of the sublist being treated.
#end:	indicates the end of the sublist beign treated. e.g. lst: [8, 7, 6, 5, 4, 3, 2, 1]; start = 2; end = 4
#		the sublist that will be processed is [6, 5]
#
#in order to merge to function properly, it is necessary that the elements at the left list are ordered. As well as
#the elements at the right list
def merge(lst, start, end):
	start = int(start)
	end = int(end)
	#creates copy of the sublist
	cp = lst[start:end]
	middle = int((start + end) / 2)
	#print("merge was called. Left side: [{}], right side: [{}]".format(lst[start:middle], lst[middle:end]))

	index = start
	#if middle = start, then the left list is empty.
	#if midle = end, then right list is empty
	while ( middle > start and end > middle ):
		if ((cp[0]) < (cp[middle - start] )):
			#removes left list element from cp and saves it at lst
			lst[index] = cp.pop(0)
			#Right list was moved one position to the left. Hence, it is necessary to update "middle"
			middle -= 1
		else: #cp[rls] > cp[0]
			#removes right list element from cp and saves it to lst
			lst[index] = cp.pop(middle - start)
		index += 1
		end -= 1

	#the remaining elements in cp are already ordered and greater than all elements [start:index]. Hence, it is
	#only necessary to save the remaining elements of cp in lst using the same order
	while (len(cp) > 0):
		#print(lst)
		lst[index] = cp.pop(0)
		index += 1

#lst:	reference of the list to be sorted
#start:	indicates the start of the sublist being sorted.
#end:	indicates the end of the sublist beign sorted. e.g. lst: [8, 7, 6, 5, 4, 3, 2, 1]; start = 2; end = 4
#		the sublist that will be processed is [6, 5]
def merge_sort(lst, start, end):
	#if length > 1
	start = int(start)
	end = int(end)
	if end - start > 1:
		#print("{} {}".format(start, end))
		merge_sort(lst, start, (start + end) / 2)
		merge_sort(lst, (start + end) / 2, end)
		merge(lst, start, end)
	#otherwise, already sorted 

#The user will type a list separated by the character "space". The list will be stored in lst
lst = [int(num) for num in input("Type the list. Elements are separated by space\n").split()]
#prints the original list
#print("The original list is: {}".format(lst))

#passes lst as reference in order to save processing time
merge_sort(lst, 0, len(lst))
print(">>>>>>>>>>>>>>>>>>>>>>>>....START")
print(lst)
f = open('output.txt', 'w')
f.write(' '.join(map(str, lst)))