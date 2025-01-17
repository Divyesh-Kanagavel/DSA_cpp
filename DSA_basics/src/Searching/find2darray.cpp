/* find an element in a 2d sorted array*/

#include <cstdio>

void find2Darray(int arr[][3], int rows, int cols, int key, int& row_index, int &col_index)
{
    int row = 0;
    int col = cols-1;
    while(row < rows && col>=0)
    {
        if (arr[row][col] == key)
        {
            row_index = row;
            col_index = col;
            return;
        }

        if (arr[row][col] > key)
            col--;
        else
            row++;
    }
    row_index = -1;
    col_index = -1;
    return;
}

int main()
{
    int arr[][3] = {{2,4,9},{11,15,19},{21,23,26}};
    int cols = 3;
    int rows = 3;
    int key = 31;
    int row_index;
    int col_index;
    find2Darray(arr,rows, cols, key, row_index, col_index);
    if (row_index != -1 && col_index != -1)
        printf("the element %d found at row %d and col %d\n", key, row_index, col_index);
    else
        printf("element not found\n");
    
    return 0;
}