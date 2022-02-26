#include <bits/stdc++.h>
using namespace std;

int validCoord(int x, int y, int n, int m)
{

	if (x < 0 || y < 0) {
		return 0;
	}
	if (x >= n || y >= m) {
		return 0;
	}
	return 1;
}

void bfs(int n, int m, int data[][8],
					int x, int y, int color)
{

int vis[101][101];

memset(vis, 0, sizeof(vis));

queue<pair<int, int> > obj;

obj.push({ x, y });

vis[x][y] = 1;

while (obj.empty() != 1)
{

	pair<int, int> coord = obj.front();
	int x = coord.first;
	int y = coord.second;
	int preColor = data[x][y];

	data[x][y] = color;
	
	// Popping front pair of queue
	obj.pop();

	// For Upside Pixel or Cell
	if (validCoord(x + 1, y, n, m)
		&& vis[x + 1][y] == 0
		&& data[x + 1][y] == preColor)
	{
	obj.push({ x + 1, y });
	vis[x + 1][y] = 1;
	}
	
	if (validCoord(x - 1, y, n, m)
		&& vis[x - 1][y] == 0
		&& data[x - 1][y] == preColor)
	{
	obj.push({ x - 1, y });
	vis[x - 1][y] = 1;
	}
	
	if (validCoord(x, y + 1, n, m)
		&& vis[x][y + 1] == 0
		&& data[x][y + 1] == preColor)
	{
	obj.push({ x, y + 1 });
	vis[x][y + 1] = 1;
	}
	
	if (validCoord(x, y - 1, n, m)
		&& vis[x][y - 1] == 0
		&& data[x][y - 1] == preColor)
	{
	obj.push({ x, y - 1 });
	vis[x][y - 1] = 1;
	}
}

for (int i = 0; i < n; i++)
{
	for (int j = 0; j < m; j++)
	{
	cout << data[i][j] << " ";
	}
	cout << endl;
}
cout << endl;
}

int main()
{
int n, m, x, y, color;
n = 8;
m = 8;

int data[8][8] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 0, 0 },
	{ 1, 0, 0, 1, 1, 0, 1, 1 },
	{ 1, 2, 2, 2, 2, 0, 1, 0 },
	{ 1, 1, 1, 2, 2, 0, 1, 0 },
	{ 1, 1, 1, 2, 2, 2, 2, 0 },
	{ 1, 1, 1, 1, 1, 2, 1, 1 },
	{ 1, 1, 1, 1, 1, 2, 2, 1 },
};

x = 4, y = 4, color = 3;

bfs(n, m, data, x, y, color);
return 0;
}
