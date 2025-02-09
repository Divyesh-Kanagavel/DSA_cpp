# recurse through array which contains numbers and array of numbers 
# and print all numbers in the array
array=[ 1, 2, 3,
               [4, 5, 6],
               7,
               [8,
                 [9, 10, 11,
                   [12, 13, 14]
] ],
               [15, 16, 17, 18, 19,
                 [20, 21, 22,
                   [23, 24, 25,
                     [26, 27, 29]
], 30, 31 ], 32
], 33 
]

def print_arrnum(arr):
    for num in arr:
        if isinstance(num, list):
            print_arrnum(num)
        else:
            print(num)
        
print_arrnum(array)
