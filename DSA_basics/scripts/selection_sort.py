def selection_sort(list):
    list_size = len(list)
    for i in range(list_size-1):
        lowest_index = i
        for j in range(i+1,list_size):
            if list[j] < list[lowest_index]:
                lowest_index = j
        if lowest_index != i:
            list[i],list[lowest_index] = list[lowest_index],list[i]
    return list

print(selection_sort([4,0,3,9,6,2]))

# though selection sort has a time complexity of O(n^2) like bubble sort, 
# it is twice as fast, due to just one comparison per iteraion of the outer loop