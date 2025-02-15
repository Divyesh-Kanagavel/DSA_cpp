# given a index n, give the number in the triangular number sequence
# arr[num] = arr[num-1] + num => triangular number logic

def triangular_number(n):
    if n==0:
        return 0
    if n==1:
        return 1
    return triangular_number(n-1) + n


print(triangular_number(7))