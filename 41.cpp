#include<bits/stdc++.h>
#define int long long

using namespace std;

int N = 1e8 + 5;
bool sieve[100000005];
void buildSieve()
{
	for (int i = 1; i < N; i++)
	{
		if (i & 1)
			sieve[i] = true;
		else
			sieve[i] = false;
	}
	sieve[2] = true;
	sieve[1] = false;

	for (int i = 3; i * i < N; i += 2)
	{
		if (sieve[i])
		{
			for (int j = i * i; j < N; j += (2 * i))
				sieve[j] = false;
		}
	}
}

bool pos(int n)
{
	vector<bool> vis(10, false);
	string s = to_string(n);
	int len = s.length();

	for (auto it : s)
	{
		if ((it - '0') > len)
			return false;
		if (vis[it - '0'])
			return false;
		vis[it - '0'] = true;
	}

	for (int i = 1; i <= len; i++)
	{
		if (!vis[i])
			return false;
	}
	return true;
}
int32_t main()
{
	buildSieve();

	int ans = 1;
	for (int i = 1; i < N; i++)
	{
		if (sieve[i] && pos(i))
		{
			ans = i;
		}
	}
	cout << ans << endl;
	return 0;
}
