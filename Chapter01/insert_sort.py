#The user will type a list separated by the character "space". The list will be stored in lst
lst = [int(num) for num in input("Type the list. Elements are separated by space\n").split()]
#prints the original list
print("The original list is: {}".format(lst))

#starts insert sort
print("\nINSERT SORT BEGIN\n")

for i in range(1, len(lst)):
    val = lst[i]
    index = i - 1
    while (index >= 0 and val < lst[index]):
        lst[index + 1] = lst[index]
        index -= 1
    lst[index + 1] = val
    print("iteraction #{}: {}".format(i, lst))

print("\nINSERT SORT END\n")
#end of insert sort

#prints sorted list
print("The sorted list is: {}".format(lst))
