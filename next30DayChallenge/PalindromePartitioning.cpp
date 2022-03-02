#include <bits/stdc++.h>
using namespace std;
bool is_palindrome(string input, int start, int end)
{
	while (start < end) {
		if (input[start] != input[end])
			return false;
		start++;
		end--;
	}
	return true;
}
string convert(int a, int b)
{
	return to_string(a) + "" + to_string(b);
}
int minpalparti_memo(string input, int i, int j, unordered_map<string, int>& memo)
{
	if (i > j)
		return 0;
	string ij = convert(i, j);

	if (memo.find(ij) != memo.end()) {
		return memo[ij];
	}
	if (i == j) {
		memo[ij] = 0;
		return 0;
	}
	if (is_palindrome(input, i, j)) {
		memo[ij] = 0;
		return 0;
	}
	int minimum = INT_MAX;
	for (int k = i; k < j; k++) {
		int left_min = INT_MAX;
		int right_min = INT_MAX;
		string left = convert(i, k);
		string right = convert(k + 1, j);
		if (memo.find(left) != memo.end()) {
			left_min = memo[left];
		}
		if (memo.find(right) != memo.end()) {
			right_min = memo[right];
		}
		if (left_min == INT_MAX)
			left_min = minpalparti_memo(input, i, k, memo);
		if (right_min == INT_MAX)
			right_min = minpalparti_memo(input, k + 1, j, memo);
		minimum = min(minimum, left_min + 1 + right_min);
	}

	memo[ij] = minimum;
	return memo[ij];
}
int main()
{
	string input = "ababbbabbababa";
	unordered_map<string, int> memo;
	cout << minpalparti_memo(input, 0, input.length() - 1, memo) << endl;
	return 0;
}
