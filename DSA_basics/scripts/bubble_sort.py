def bubble_sort(list):
    unsorted_index_till = len(list) - 1
    sorted = False

    while not sorted:
        sorted = True
        for i in range(unsorted_index_till):
            if list[i] > list[i+1]:
                list[i],list[i+1] = list[i+1],list[i]
                sorted = False
        unsorted_index_till -= 1
    
    return list

print(bubble_sort([4,0,3,9,6,2]))