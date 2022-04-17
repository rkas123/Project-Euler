#include<bits/stdc++.h>
#define int long long
using namespace std;

bool isPal(string s)
{
	int i = 0,j = s.length() - 1;
	while (i < j)
	{
		if (s[i++] != s[j--])
			return false;
	}
	return true;
}

string bin(int n)
{
	string ans = "";

	while (n > 0)
	{
		ans += char('0' + (n & 1));
		n >>= 1;
	}
	return ans;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int sum = 0;
	for (int i = 1; i <= 1e6; i++)
	{
		if (isPal(to_string(i)) && isPal(bin(i))) {
			sum += i;
		}
	}
	cout << sum << endl;

	return 0;
}
