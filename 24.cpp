#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int N;
	cin >> N;
	vector<bool> vis(10, false);

	int factorial[10];
	factorial[0] = 1;
	for (int i = 1; i < 10; i++)
		factorial[i] = factorial[i - 1] * i;

	int curr = 0;
	vector<int> ans(10);
	for (int i = 0; i < 10; i++)
	{
		int left = 10 - i - 1;
		for (int j = 0; j < 10; j++)
		{
			if (vis[j])
				continue;
			if (curr + factorial[left] >= N)
			{
				ans[i] = j;
				vis[j] = true;
				break;
			}
			else
			{
				curr += factorial[left];
			}
		}
	}
	for (auto it : ans)
		cout << it;
	cout << endl;
}

