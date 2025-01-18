def insertion_sort(list):
    for index in range(1, len(list)):
        temp_val = list[index]
        position = index - 1
        while position >= 0:
            if (list[position] > temp_val):
                list[position + 1] = list[position]
                position = position - 1
            else:
                break
        list[position + 1] = temp_val
    return list

print(insertion_sort([4,0,3,9,6,2]))

# in the worst case: sorted in reverse order
# insertion sort has O(n^2) time complexity but is higher than selection sort if analyzed in detail
# O(n^2+2n-2)

# but on the average case, we see that it performs similar to selection sort O(n^2/2)

# in the best case, when the array is more or less sorted, due to the early stopping mechanism 
# in insertion sort, we see that it has time complexity close O(n) whereas for selection sort is always O(n^2)

# So, if array is already more or less sorted -> pick insertion sort
# average case -> pick either of them 
# reverse sorted (worst case) -> pick selection sort