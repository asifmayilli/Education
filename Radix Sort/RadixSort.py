import random

def Radix(arr,base,length):
    counter = 0
    lists = []
    for i in range(base):
        lists.append([])
    #lists = [[],[],[],[],[],[],[],[],[],[]]

    for i in range(length):
        for item in arr:
            digit = item % int((base ** (i + 1))) // int((base ** i)) #current digit
            lists[digit].append(item)
            counter+=1

        #print(lists)
        arr = []
        for item in lists:
            arr = arr + item
            counter+=1
        #print(arr)
        for i in range(base):
            lists[i] = []
    print('steps: {} '.format(counter))
    return arr


array = [int(1000*random.random()) for i in range(10000)]
print('Initial array: ')
print(array)

print('Arrays length: ')
print(len(array))
print('Sorted array: ')
print(Radix(array,10,4))