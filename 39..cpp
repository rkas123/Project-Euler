#include <bits/stdc++.h>
#define int long long
using  namespace std;

int32_t main()
{
	vector<int> cnt(1001, 0);
	map<int, int> root;

	for (int i = 1; i <= 1000; i++)
	{
		root[i * i] = i;
	}
	for (int l = 1; l <= 1000; l++)
	{
		for (int r = l; r <= 1000; r++)
		{
			int h = l * l + r * r;
			if (root.count(h) != 0)
			{
				int p = l + r + root[h];

				if (p <= 1000)
					cnt[p]++;
			}
		}
	}
	int ans = 0, great =  0;

	for (int i = 1; i <= 1000; i++)
	{
		if (cnt[i] > great)
		{
			ans = i;
			great = cnt[i];
		}
	}
	cout << ans << " " << cnt[ans] << endl;
	return 0;
}
