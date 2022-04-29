#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1000005;
bool sieve[1000005];

void makeSieve()
{
	for (int i = 1; i < N; i++)
	{
		if (i & 1)
			sieve[i] = true;
		else
			sieve[i] = false;
	}
	sieve[1] = false;
	sieve[2] = true;

	for (int i = 3; i * i < N; i += 2)
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
	makeSieve();

	for (int i = 3; i < N; i += 2)
	{
		if (!sieve[i])
		{
			bool found = false;
			for (int j = 1; j < N; j++)
			{
				int sq = 2 * j * j;
				if (sq >= i)
					break;
				int left = i - sq;
				if (sieve[left])
				{
					found = true;
					break;
				}
			}
			if (!found)
			{
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}
