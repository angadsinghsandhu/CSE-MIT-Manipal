def binary_search(lst, low, high, elem):
   if high >= low:
      mid = (high + low) // 2
      if lst[mid] == elem:
         return mid
      elif lst[mid] > elem:
         return binary_search(lst, low, mid - 1, elem)
      else:
         return binary_search(lst, mid + 1, high, elem)
   else:
      return -1
     
lst = [ 1, 9, 11, 21, 34, 54, 67, 90 ]
search_ele = 34
print("The list is : ", end="")
print(lst)

res = binary_search(lst, 0, len(lst)-1, search_ele)

if res != -1:
   print("Element found at index ", str(res), "\n")
else:
   print("Element not found!", "\n")