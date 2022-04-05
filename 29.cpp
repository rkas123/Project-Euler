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

	int a, b;
	cin >> a >> b;

	vector<int> powercnt(30, 0);
	vector<bool> Vis(30 * b + 1, false);

	for (int i = 1; i < 7; i++)
	{
		int cnt = 0;
		for (int j = 2; j <= b; j++)
		{
			if (!Vis[i * j]) {
				cnt++;
			}
			Vis[i * j] = true;
		}
		powercnt[i] = cnt + powercnt[i - 1];
	}


	vector<bool> vis(a + 1, false);

	int ans = 0;
	for (int i = 2; i <= a; i++)
	{
		if (!vis[i])
		{
			int pow = 0;
			int curr = i;
			while (curr <= a && !vis[curr])
			{
				vis[curr] = true;
				curr *= i;
				pow++;
			}
			ans += powercnt[pow];
		}
	}
	cout << ans << endl;

	return 0;
}

