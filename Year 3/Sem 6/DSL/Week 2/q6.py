my_list = ['p', 'r', 'o', 'b', 'e']

print(my_list[0])  # p
print(my_list[-1])
print(my_list[1:3])

odd = [2, 4, 6, 8]
print(odd)

odd[1:4] = [3, 5, 7]  
print(odd)                   

odd.append(7)
print(odd)

odd.extend([9, 11, 13])
print(odd)

del my_list[2]

my_list = ['p', 'r', 'o', 'b', 'l', 'e', 'm']

print('p' in my_list)
print('a' in my_list)
print('c' not in my_list)