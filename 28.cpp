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
	//+2 +4 +6 +8 +10 +12

	//1 , 5 , 9 , 17, 25, 41, 57
	//    +4,+4,+8,+8,+12,+12..


	int ans = 0;
	int curr = 1;

	int n;
	cin >> n;
	int add = 2;
	for (int i = 1; i < n; i++)
	{
		curr += add;
		add += 2;
		ans += curr;
	}
	curr = 1;
	add = 4;
	for (int i = 1; i < n; i++)
	{
		curr += add;
		ans += curr;
		curr += add;
		i++;

		if (i == n)
			break;
		ans += curr;
		add += 4;
	}
	cout << ans + 1 << endl;

	return 0;
}

