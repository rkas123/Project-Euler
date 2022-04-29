#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1000005;
vector<int> leastPrime(1000005);

void makeSieve()
{
	for (int i = 1; i < N; i++) leastPrime[i] = i;
	for (int i = 2; i < N; i++)
		for (int j = i; j < N; j += i) leastPrime[j] = min(leastPrime[j], i);
}

int factorize(int n)
{
	set<int> factors;
	while (n != 1)
	{
		factors.insert(leastPrime[n]);
		n /= leastPrime[n];
	}
	return factors.size();
}
int32_t main()
{
	makeSieve();
	vector<int> cnt(N);
	for (int i = 2; i < N; i++) cnt[i] = factorize(i);
	for (int i = 2; i <= 1000000; i++)
	{
		bool found = true;
		for (int j = 0; j < 4; j++)
		{
			if (cnt[i + j] != 4)
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			cout << i << endl;
			break;
		}
	}
	return 0;
}
