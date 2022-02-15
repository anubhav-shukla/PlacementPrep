#include<bits/stdc++.h>
#include <algorithm>

int getMedian(vector<vector<int>> &matrix)
{

    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> data;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            data.push_back(matrix[i][j]);
        }
    }
    sort(data.begin(), data.end());
    return data[(n * m) / 2];
}
