#The user will type a list separated by the character "space". The list will be stored in lst
lst = [int(num) for num in input("Type the list. Elements are separated by space\n").split()]
#prints the original list
#print("The original list is: {}".format(lst))

#starts quick sort
#print("\nQUICK SORT BEGIN\n")

#the efficiency of quick sort depends on the chosen pivot.
#For didactic reasons, an arbitrary pivot is chosen
def order_pivot(lst, start, end):
	if (start < end): #verifies if not basis case
		pivot_pos = start #the first element is chosen as pivot
		for i in range (start + 1, end):
			if (lst[i] < lst[pivot_pos]):
				#then i-th element should be located at the left side of pivot. Swap
				if (i > pivot_pos + 1):
					#this means that the pivot_pos+1-th element should be located at
					#the right of the pivot; where it already is. Swap it with the i-th
					#element, that should be located at the left of the pivor
					aux = lst[pivot_pos + 1]
					lst[pivot_pos + 1] = lst[i]
					lst[i] = aux
				#because of the previous if, the element to be swapped with the pivot
				#is located right after it.
				aux = lst[pivot_pos + 1]
				lst[pivot_pos + 1] = lst[pivot_pos]
				lst[pivot_pos] = aux
				#now the pivot has moved one position to the right
				pivot_pos += 1

		return pivot_pos
	#then start == end, i.e. basis case (one element)
	return start

def quick_sort(lst, start, end):
	if (start < end):
		pivot_pos = order_pivot(lst, start, end)
		#pivot is already in the right position. All the elements to its left are
		#less than the pivot; and all elements to the right are greater or equal to it
		quick_sort(lst, start, pivot_pos) #sorts sublist at the left of the pivot
		quick_sort(lst, pivot_pos + 1, end) #sorts sublist at the right of the pivot


#print("\nQUICK SORT END\n")
#end of quick sort

quick_sort(lst, 0, len(lst))
#prints sorted list
print("The sorted list is: {}".format(lst))
f = open('output.txt', 'w')
f.write(' '.join(map(str, lst)))