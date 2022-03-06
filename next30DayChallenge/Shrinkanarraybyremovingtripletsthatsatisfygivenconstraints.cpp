#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int dp[MAX][MAX];

int minSizeRec(int arr[], int low, int high, int k)
{
	if (dp[low][high] != -1)
		return dp[low][high];

	if ( (high-low + 1) < 3)
		return high-low +1;

	int res = 1 + minSizeRec(arr, low+1, high, k);

	for (int i = low+1; i<=high-1; i++)
	{
		for (int j = i+1; j <= high; j++ )
		{
			if (arr[i] == (arr[low] + k) &&
				arr[j] == (arr[low] + 2*k) &&
				minSizeRec(arr, low+1, i-1, k) == 0 &&
				minSizeRec(arr, i+1, j-1, k) == 0)
			{
				res = min(res, minSizeRec(arr, j+1, high, k));
			}
		}
	}

	return (dp[low][high] = res);
}
int minSize(int arr[], int n, int k)
{
	memset(dp, -1, sizeof(dp));
	return minSizeRec(arr, 0, n-1, k);
}

int main()
{
	int arr[] = {2, 3, 4, 5, 6, 4};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 1;
	cout << minSize(arr, n, k) << endl;
	return 0;
}
