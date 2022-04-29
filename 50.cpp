#include<bits/stdc++.h>
#define int long long
using namespace std;

int N = 1000005;
vector<bool> sieve(1000005);
vector<int> primes;
void makeSieve()
{
	sieve = vector<bool>(1000005, true);
	sieve[1] = false;
	for (int i = 4; i < N; i += 2)
		sieve[i] = false;

	for (int i = 3; i * i < N; i += 2)
	{
		if (sieve[i])
		{
			for (int j = i * i; j < N; j += (2 * i))
				sieve[j] = false;
		}
	}
	for (int i = 2; i < N; i++)
	{
		if (sieve[i])
			primes.push_back(i);
	}
}

int cumsum(vector<int>&v, int l, int r)
{
	int ans = v[r];
	if (l - 1 >= 0)
		ans -= v[l - 1];
	return ans;
}

int32_t main()
{
	makeSieve();
	int ans = 2;
	int l = 1;
	for (int i = 1; i < primes.size(); i++)
		primes[i] += primes[i - 1];

	for (int len = 2; len <= 1000; len++) {
		for (int s = 0; s + len < primes.size(); s++)
		{
			int sum = cumsum(primes, s, s + len - 1);
			if (sum < 1e6 && sieve[sum])
			{
				ans = sum;
				l = len;
			}
		}
	}

	return 0;
}
