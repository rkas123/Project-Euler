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

	vector<int> denominations = {1, 2, 5, 10, 20, 50, 100, 200};

	vector<int> dp(201, 0);
	dp[0] = 1;

	for (auto it : denominations)
	{
		for (int i = it; i <= 200; i++)
		{
			dp[i] += dp[i - it];
		}
	}

	cout << dp[200] << endl;


	return 0;
}

