#include<bits/stdc++.h>
#define int long long

using namespace std;
int val(vector<int>&v)
{
	int ans = 0;
	for (auto it : v)
	{
		ans *= 10;
		ans += it;
	}
	return ans;
}
int three(int a, int b, int c)
{
	return c + 10 * b + 100 * a;
}
bool pos(vector<int>&v)
{
	if (v[3] % 2) {
		return false;
	}
	int sum = v[2] + v[3] + v[4];
	if (sum % 3 != 0) {
		return false;
	}
	if (!(v[5] == 0 || v[5] == 5)) {
		return false;
	}
	int num;
	num = three(v[4], v[5], v[6]);
	if (num % 7) {
		return false;
	}
	num = three(v[5], v[6], v[7]);
	if (num % 11) {
		return false;
	}
	num = three(v[6], v[7], v[8]);
	if (num % 13) {
		return false;
	}
	num = three(v[7], v[8], v[9]);
	if (num % 17) {
		return false;
	}
	return true;
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> v = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};

	int ans = 0;

	do {
		if (v[0] != 0)
		{
			if (pos(v))
				ans += val(v);
		}
	} while (next_permutation(v.begin(), v.end()));

	cout << ans << endl;

	return 0;
}
