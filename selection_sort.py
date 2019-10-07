#The user will type a list separated by the character "space". The list will be stored in lst
lst = [int(num) for num in input("Type the list. Elements are separated by space\n").split()]
#prints the original list
#print("The original list is: {}".format(lst))

#starts selection sort
#print("\nSELECTION SORT BEGIN\n")

for i in range (0, len(lst)):
	index = i
 	#selects i-th element
	#searches for the smallest element in the subarray [i : len(lst)] and saves its
	#position in "index"
	for j in range(i, len(lst)):
		if (lst[j] < lst[index]):
			index = j

	if (i != index):
		#if there is an element lst[j] < lst[i] such that j > i, then
		#swaps the values of i and index
		aux = lst[index]
		lst[index] = lst[i]
		lst[i] = aux

#print("\nSELECTION SORT END\n")
#end of selection sort

#prints sorted list
print("The sorted list is: {}".format(lst))
f = open('output.txt', 'w')
f.write(' '.join(map(str, lst)))