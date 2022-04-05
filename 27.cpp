#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 10000005;
vector<bool> sieve(N, true);

void buildSieve()
{
	sieve[0] = false;
	sieve[1] = false;

	for (int i = 2; i * i < N; i++)
	{
		if (sieve[i])
		{
			for (int j = i * i; j < N; j += (2 * i))
				sieve[j] = false;
		}
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	buildSieve();
	int cnt = 1;
	int ans;
	for (int b = 1; b <= 1000; b++)
	{
		if (sieve[b])
		{
			for (int a = -1000; a <= 1000; a++)
			{
				int n = 0;
				while (1)
				{
					int num = n * n + a * n + b;
					if (num < 0)
						break;
					if (sieve[num])
						n++;
					else
						break;
				}
				if (n > cnt)
				{
					cnt = n;
					ans = a * b;
				}
			}
		}
	}
	cout << ans << endl;

	return 0;
}

