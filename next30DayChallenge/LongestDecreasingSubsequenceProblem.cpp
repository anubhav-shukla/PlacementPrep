#include <iostream>
#include <vector>
using namespace std;
 
void findLDS(vector<int> const &nums)
{
    int n = nums.size();
 
    // base case
    if (n == 0) {
        return;
    }
 
 
    vector<vector<int>> LDS(n, vector<int>());
 
    LDS[0].push_back(nums[0]);
 
    for (int i = 1; i < n; i++)
    {
        
        for (int j = 0; j < i; j++)
        {
 
            if (nums[j] > nums[i] && LDS[j].size() > LDS[i].size()) {
                LDS[i] = LDS[j];
            }
        }
        LDS[i].push_back(nums[i]);
    }
 
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (LDS[j].size() < LDS[i].size()) {
            j = i;
        }
    }
 
    for (int i: LDS[j]) {
        cout << i << " ";
    }
}
 
int main()
{
    vector<int> nums = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
 
    findLDS(nums);
 
    return 0;
}