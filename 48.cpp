#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 10000000000ll;

int fastexp(int a, int b)
{
	int ans = 1;
	for (int i = 1; i <= b; i++)
	{
		ans = (ans * a) % mod;
	}
	return ans;
}
int32_t main()
{
	int ans = 0;
	for (int i = 1; i <= 1000; i++)
	{
		ans += fastexp(i, i);
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}
