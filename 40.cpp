#include <bits/stdc++.h>
#define int long long
using namespace std;

int fastexp(int a, int b)
{
	int ans = 1;

	while (b > 0)
	{
		if (b & 1)
			ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}
int32_t main()
{

	int ans = 1;

	vector<int> cnt(10, 0);

	for (int i = 1; i < 10; i++)
	{
		cnt[i] = (9 * fastexp(10, i - 1)) * i;
		cout << cnt[i] << endl;
	}

	for (int i = 2; i < 10; i++)
		cnt[i] += cnt[i - 1];

	vector<int> req = {1, 10, 100, 1000, 10000, 100000, 1000000};

	for (auto &it : req)
	{
		int index = prev(lower_bound(cnt.begin(), cnt.end(), it)) - cnt.begin();
		int len = index + 1;
		int low = fastexp(10, index);
		it--;
		int num = low + (it - cnt[index]) / len;
		int dig = (it - cnt[index]) % len;

		string s = to_string(num);
		ans *= (s[dig] - '0');
	}
	cout << ans << endl;
	return 0;
}
