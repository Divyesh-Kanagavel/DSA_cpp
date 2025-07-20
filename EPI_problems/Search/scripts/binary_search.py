# binary search implementation

def binary_search(arr,x):
    l,u = 0, len(arr)-1
    while l <= u:
        mid = l + (u-l)//2 # mid = (l+u)/2 is a bug , over flow issue
        if arr[mid] > x:
            u = mid - 1
        elif arr[mid] < x:
            l = mid + 1
        else:
            return mid
    return -1
        

if __name__ == "__main__":
    arr = [4,1,9,0,5,7,8]
    x = 8
    print(binary_search(arr,x))