# Certain applications require arbitrary precision arithmetic. One way to achieve this is to use arrays
# to represent integers, e.9., with one digit per array entry with the most significant digit appearing
# first, and a negative leading digit denoting a negative integer. For example, <1,9,3,7,0,7,7,2,1>
# represents 193707721 and (-7,6,1.,8,3,8,2,5,7,2,8,7> represents -761838257287.

# time complexity -> m partial products each with n+1 digits -> O(mn)

def multiply(m,n):
    sign = -1 if (m[0]<0)^(n[0]<0) else 1
    m[0],n[0] = abs(m[0]), abs(n[0])
    result = [0] * (len(m) + len(n))

    for i in reversed(range(len(m))):
        for j in reversed(range(len(n))):
            result[i+j+1] += m[i] * n[j]
            result[i+j] += result[i+j+1] // 10
            result[i+j+1] %= 10
    # remove the trailing zeros
    result = result[next((i for i,n in enumerate(result) if n!=0), len(result)):] or [0]
    return [sign * result[0]] + result[1:]

# tests
if __name__ == "__main__":
    a = [-4,5]
    b = [0,0]
    print(multiply(a,b))
    print(-45*0)


