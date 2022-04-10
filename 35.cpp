#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N = 1e6 + 5;

vector<bool> sieve(N, true);
void buildSieve()
{
	sieve[0] = false;
	sieve[1] = false;

	for (int i = 2; i * i < N; i++)
	{
		if (sieve[i])
		{
			for (int j = i * i; j < N; j +=  i)
				sieve[j] = false;
		}
	}
}
int len(int n)
{
	int ans = 0;
	while (n > 0)
	{
		ans++;
		n /= 10;
	}
	return ans;
}
int fastexp(int a, int b)
{
	int ans = 1;
	while (b > 0)
	{
		if (b & 1)
		{
			ans *= a;
		}
		a *= a;
		b >>= 1;
	}
	return ans;
}
int rev(int n)
{
	int rem = n % 10;
	n /= 10;
	int L = len(n);
	return n + rem * fastexp(10, L);
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
	int ans = 0;
	for (int i = 1; i < 1e6; i++)
	{
		if (sieve[i]) {
			int first = i;
			int temp  = i;
			bool pos = true;
			while (1)
			{
				temp = rev(temp);
				if (!sieve[temp])
				{
					pos = false;
					break;
				}
				if (temp == first)
					break;
			}
			if (pos)
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
