#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{

	int ans = 0;
	for (int n = 1; n <= 100; n++) {
		ans++;
		int curr = 1;
		int j = 1;
		while (j <= n)
		{
			curr *= (n - j + 1);
			curr /= j;
			if (curr <= 1e6) ans++;
			else break;
			j++;
		}

		if (j == n + 1) continue;

		int k = n - 1;
		curr = 1;
		ans++;
		while (k > j)
		{
			curr *= (k + 1);
			curr /= (n - k);
			if (curr > 1e6) break;
			k--;
			ans++;
		}
	}
	cout << 5150 - ans << endl;
	return 0;
}
