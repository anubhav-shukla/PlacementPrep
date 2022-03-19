#include <iostream>
 
int shrink(int arr[], int start, int end, int k)
{
    // Base case
    if (start > end) {
        return 0;
    }
 
    int result = 0;
 
    result = 1 + shrink(arr, start + 1, end, k);       
    for (int i = start + 1; i < end; i++)
    {
        for (int j = i + 1; j <= end; j++)
        {
            if (arr[i] == arr[start] + k && arr[j] == arr[i] + k)
            {
                if (!shrink(arr, start + 1, i - 1, k) && !shrink(arr, i + 1, j - 1, k))
                {
                    int n = shrink(arr, j + 1, end, k);
                    if (result > n) {
                        result = n;
                    }
                }
            }
        }
    }
 
    return result;
}
 
int main()
{
    int arr[] = { -1, 2, 5, 8, 2, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
 
    printf("The total number of elements in the resultant array is %d",
        shrink(arr, 0, n - 1, k));
 
    return 0;
}
