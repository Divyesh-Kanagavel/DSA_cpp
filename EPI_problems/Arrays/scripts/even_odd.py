# Your input is an array of integers, and you have to reorder its entries so that the even entries appear first.
# easier solution is to create a new array, parse the elements one by one and put the even in front and odd from back. O(n) space complexity and O(n) time compexity
# but this can be solved with time complexity of O(n) and space complexity O(1)
def even_odd(x):
    even_index, odd_index = 0, len(x)-1
    while even_index < odd_index:
        if x[even_index] % 2 == 0:
            even_index += 1
        else:
            x[even_index], x[odd_index] = x[odd_index], x[even_index]
            odd_index -= 1

if __name__ == "__main__":
    arr = [3,1,4,5,9,1,0,2]
    even_odd(arr)
    print(arr)

