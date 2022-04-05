#include <bits/stdc++.h>
#define int long long
using namespace std;

bool isValid(int x)
{
	string s = to_string(x);
	vector<bool> vis(10, false);

	for (auto it : s)
	{
		if (vis[it - '0'])
			return false;
		vis[it - '0'] = true;
	}
	return !vis[0];
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
		b >>= 1;
		a *= a;
	}
	return ans;
}
int digits(int n)
{
	int cnt = 0;
	while (n > 0)
	{
		cnt++;
		n /= 10;
	}
	return cnt;
}
bool isValidProd(int a, int b, int c)
{
	string A = to_string(a);
	string B = to_string(b);
	string C = to_string(c);

	vector<bool> vis(10, false);

	for (auto it : A)
	{
		if (vis[it - '0'])
			return false;
		vis[it - '0'] = true;
	}
	for (auto it : B)
	{
		if (vis[it - '0'])
			return false;
		vis[it - '0'] = true;
	}
	for (auto it : C)
	{
		if (vis[it - '0'])
			return false;
		vis[it - '0'] = true;
	}
	return !vis[0];
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	set<int> s;
	for (int i = 1; i < 9999; i++)
	{
		if (isValid(i))
		{
			for (int dig = digits(i); dig <= 9; dig++)
			{
				int upp = fastexp(10, dig) - 1;
				int low = fastexp(10, dig - 1);

				int maxlen = digits(upp * i);
				int minlen = digits(low * i);
				int reqlen = 9 - dig - digits(i);


				if (reqlen < minlen || reqlen > maxlen)
					continue;

				for (int j = low; j <= upp; j++)
				{
					if (j < i)
						continue;

					int prod = (j * i);
					if (digits(i) + dig + digits(prod) == 9)
					{
						if (isValidProd(i, j, prod)) {
							s.insert(prod);
						}
					}
				}

			}
		}
	}

	int ans = 0;
	for (auto it : s)
		ans += it;
	cout << ans << endl;


	return 0;
}

