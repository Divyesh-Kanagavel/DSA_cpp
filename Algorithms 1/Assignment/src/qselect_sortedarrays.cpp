// given two sorted arrays, find the kth largest element among 
// the concatenation of both arrays. 

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Finds the element at index K_small in the merged sorted array (0-indexed)
// This element is the (K_small + 1)-th smallest, or the (N - K_small)-th largest.
int find_element_at_index(const vector<int>& a, const vector<int>& b, int K_small)
{
    int n1 = a.size();
    int n2 = b.size();
    int ptr_a = 0;
    int ptr_b = 0;
    int count = 0; // Represents the index of the element being considered

    while (ptr_a < n1 && ptr_b < n2)
    {
        int current_val;
        if (a[ptr_a] < b[ptr_b]) {
            current_val = a[ptr_a];
            ptr_a++;
        } else {
            // Handles both a[ptr_a] > b[ptr_b] and a[ptr_a] == b[ptr_b]
            current_val = b[ptr_b];
            ptr_b++;
        }

        if (count == K_small) {
            return current_val;
        }
        count++;
    }

    // Process remaining elements in array A
    while (ptr_a < n1) {
        if (count == K_small) {
            return a[ptr_a];
        }
        ptr_a++;
        count++;
    }

    // Process remaining elements in array B
    while (ptr_b < n2) {
        if (count == K_small) {
            return b[ptr_b];
        }
        ptr_b++;
        count++;
    }
    return -1; // Should not happen for valid K_small
}

int quick_select2(const vector<int>& a, const vector<int>& b, int k)
{
    int n1 = a.size();
    int n2 = b.size();
    int total_size = n1 + n2;

    // Edge case check for k (1-indexed for largest)
    if (k < 1 || k > total_size) {
        // Handle error: k is out of bounds
        return -1; 
    }

    return find_element_at_index(a, b, k);
}

// intuition:
// find a partition index in array a , i, and partition index at array b, j,
// such that i+j = k and a[i-1] <= b[j] and b[j-1] <= a[i]
// kth smallest element is then max(a[i-1], b[j-1])

int quick_select2faster(vector<int>& a, vector<int>& b, int k)
{
    int n1 = a.size();
    int n2 = b.size();
    // assumption n1 < n2
    if (n1 > n2)
        return quick_select2faster(b , a, k);
    // two core constraints
    // k-i >= 0 => i <= k
    // k-i <= n2-1 => i >= (k+1-n2)
    int low = max(0, k+1-n2);
    int high = min(n1,k);
    while (low <= high)
    {
        int i = low + (high-low)/2;
        int j = k + 1 -i; // invariant in all loop

        long L_A = (i==0 ? LONG_MIN : a[i-1]);
        long R_A = (i == n1 ? LONG_MAX : a[i]);
        long L_B = (j==0 ? LONG_MIN : b[j-1]);
        long R_B = (j == n2 ? LONG_MAX : b[j]);

        if (L_A <= R_B && L_B <= R_A)
            return max(L_A, L_B);
        else if (L_A > R_B)
        {
            high = i-1;
        }
        else
            low = i+1;
    }
    return -1; // if unable to find
}



int main()
{
    vector<int> a = {4,7,8,11};
    vector<int> b = {5,9,13,17};

    // 4,5,7,8,9,11,13,17

    int k = 6; //median

    cout << quick_select2faster(a,b, k) << endl;

    return 0;
}