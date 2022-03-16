#include <iostream>
using namespace std;

int findMin(int arr[], int n)
{
    int count = 0;
 
    int i = 0, j = n - 1;
 
    while (i < j)
    {
        if (arr[i] < arr[j])
        {
            arr[i + 1] += arr[i];
            i++, count++;
        }
        else if (arr[i] > arr[j])
        {
            arr[j - 1] += arr[j];
            j--, count++;
        }
        else {
            i++, j--;
        }
    }
 
    return count;
}
 
int main(void)
{
    int arr[] = { 6, 1, 4, 3, 1, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    int min = findMin(arr, n);
    printf("The minimum number of operations required is %d", min);
 
    return 0;
}
