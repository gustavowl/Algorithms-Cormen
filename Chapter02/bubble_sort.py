#The user will type a list separated by the character "space". The list will be stored in lst
lst = [int(num) for num in input("Type the list. Elements are separated by space\n").split()]
#prints the original list
#print("The original list is: {}".format(lst))

#starts bublle sort
#print("\nBUBBLE SORT BEGIN\n")
for j in range(len(lst), 1, -1):
	#this will guarantee that the last element is the largest of the list
	#last element = j-th element of the array
	print(j)
	for i in range(0, j - 1,):
		print("\t" + str(i))
		if (lst[i] > lst[i + 1]):
			#swap elements
			aux = lst[i + 1]
			lst[i + 1] = lst[i]
			lst[i] = aux

#print("\nBUBBLE SORT END\n")
#end of bublle sort

#prints sorted list
print("The sorted list is: {}".format(lst))
f = open('output.txt', 'w')
f.write(' '.join(map(str, lst)))