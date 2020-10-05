# finding an element in the array using binary search
def bin_search(lst,val):
	first = 0
	last = len(lst)-1
	flag = False
	while( first<=last and not flag):
		mid = (first + last)//2
		if lst[mid] == val :
			flag = True
		else:
			if val < lst[mid]:
				last = mid - 1
			else:
				first = mid + 1	
	return flag

# sample input test case
print(bin_search([8,7,3,12,11], 6))
print(bin_search([2,5,1,9,14], 14))
