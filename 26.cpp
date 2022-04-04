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

	int Len = 0;
	int ans = 0;

	for (int i = 2; i < 1000; i++)
	{
		vector<int> visrem(i, -1);
		visrem[0] = 0;
		int curr = 1;
		int len = 0;

		while (1)
		{
			curr *= 10;
			while (curr < i)
			{
				curr *= 10;
				len++;
			}

			curr = curr % i;
			if (visrem[curr] != -1) {
				if (curr  == 0)
					break;
				len = (len - visrem[curr]);

				if (len > Len)
				{
					Len = len;
					ans = i;
				}
				break;
			}
			visrem[curr] = len;
			len++;
		}
	}

	cout << ans << " " << Len << endl;

	return 0;
}

