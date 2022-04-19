#include<bits/stdc++.h>
#define int long long

using namespace std;

int N = 2e6 + 5;
bool sieve[2000005];
void buildSieve()
{
	for (int i = 2; i < N; i++)
	{
		if (i & 1)
			sieve[i] = true;
		else
			sieve[i] = false;
	}
	sieve[1] = false;
	sieve[2] = true;

	for (int i = 2; i * i < N; i++)
	{
		if (sieve[i])
		{
			for (int j = i * i; j < N; j += (2 * i))
				sieve[j] = false;
		}
	}
}
bool lcheck(int i)
{
	string s = to_string(i);
	while (s.length() > 0)
	{
		int val = stol(s);
		if (!sieve[val])
			return false;
		s.pop_back();
	}
	return true;
}
int reverse(int n)
{
	int ans = 0;
	while (n > 0)
	{
		int rem = n % 10;
		ans *= 10;
		ans += rem;
		n /= 10;
	}
	return ans;
}
bool rcheck(int i)
{
	string s = to_string(i);

	for (int i = 0; i < s.length(); i++)
	{
		int curr = 0;
		for (int j = i; j < s.length(); j++)
		{
			int rem = s[j] - '0';
			curr *= 10;
			curr += rem;
		}
		if (!sieve[curr])
			return false;
	}
	return true;
}
int32_t main()
{
	int sum = 0;
	int cnt = 0;

	buildSieve();
	for (int i = 10; i < 1e6; i++)
	{
		if (sieve[i] && lcheck(i) && rcheck(i))
		{
			cnt++;
			sum += i;
		}
		if (cnt == 11)
			break;
	}
	cout << sum << endl;
	return 0;
}
