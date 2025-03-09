'''
You’re creating software that analyzes the data of body temperature readings taken from hundreds of human patients. These readings are taken from healthy people and range from 97.0 degrees Fahrenheit to 99.0 degrees Fahrenheit. An important point: within this application, the decimal point never goes beyond the tenths place.
Here’s a sample array of temperature readings:
    [98.6, 98.0, 97.1, 99.0, 98.9, 97.8, 98.5, 98.2, 98.0, 97.1]
You are to write a function that sorts these readings from lowest to highest.'
'''
# with classic sorting algorithm like quicksort, time complexity = O(nlogn), space complexity = O(logn)
# but range is limited, so a time complexity of O(n) is possible with space complexity = O(m) where 0...m is the range of values

# here range is 97.0 to 99.0 with a resolution of 0.1 . so 20 bins

def range_based_sort(arr):
    bins = {}
    for num in arr:
        bins[num] = bins.get(num, 0) + 1
    
    sorted_arr = []

    i = 970 # multiplied by 10 to avoid floating point precision problems

    while i <= 990:

        if i/10 in bins:
            for j in range(bins[i/10]):
               sorted_arr.append(i/10)
        i+=1
    
    return sorted_arr

arr = [98.6, 98.0, 97.1, 99.0, 98.9, 97.8, 98.5, 98.2, 98.0, 97.1]

print(range_based_sort(arr))


