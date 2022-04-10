#include<bits/stdc++.h>
#define int long long

using namespace std;

int factorial[10];
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int ans = 0;
	factorial[0] = 1;
	for (int i = 1; i < 10; i++)
	{
		factorial[i] = factorial[i - 1] * i;
	}
	for (int i = 10; i <= 2540160; i++)
	{
		int res = 0;
		int temp = i;
		while (temp > 0)
		{
			int rem = temp % 10;
			temp /= 10;
			res += factorial[rem];
		}
		if (res == i) {
			ans += i;
		}
	}

	cout << ans << endl;
	return 0;
}
