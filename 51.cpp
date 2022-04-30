#include<bits/stdc++.h>
#define int long long
using namespace std;

int N = 1e6 + 5;
vector<bool> sieve(1000005);
vector<int> primes;
void buildSieve()
{
	sieve = vector<bool>(N, true);
	sieve[0] = false;
	sieve[1] = false;
	sieve[2] = true;
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
int get_num(string s)
{
	int ans = 0;
	for (auto it : s)
	{
		ans *= 10;
		ans += (it - '0');
	}
	return ans;
}
int32_t main()
{
	buildSieve();
	bool found = false;
	for (auto it : primes)
	{
		string curr = to_string(it);
		for (int i = 1; i < (1 << 6); i++)
		{
			vector<int> mask;
			for (int pos = 0; pos < 6; pos++)
			{
				if (i & (1 << pos))
					mask.push_back(pos);
			}

			int cnt = 0;
			int gdig = mask.back();
			if (gdig >= curr.length())
				continue;
			char dig = curr[mask[0]];
			bool corr = true;
			for (int j = 1; j < mask.size(); j++)
			{
				if (curr[mask[j]] != dig)
					corr = false;
			}
			if (!corr)
				continue;
			for (int num = 0; num < 10; num++)
			{
				if (mask[0] == 0 && num == 0)
					continue;
				string temp = curr;
				for (auto j : mask)
				{
					temp[j] = char('0' + num);
				}
				int number = get_num(temp);
				if (sieve[number])
					cnt++;
			}
			if (cnt == 8)
			{
				cout << it << endl;
				found = true;
				break;
			}
		}
		if (found)
			break;
	}

	return 0;
}
