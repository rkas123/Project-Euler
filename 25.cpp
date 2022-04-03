#include <bits/stdc++.h>
#define int long long
using namespace std;

string add(string a, string b)
{
	int carry = 0;
	if (a.length() < b.length())
		swap(a, b);
	while (a.length() > b.length())
		b += '0';

	string ans = "";
	for (int i = 0; i < a.length(); i++)
	{
		int tempsum = (a[i] - '0') + (b[i] - '0') + carry;
		int rem = tempsum % 10;
		carry = tempsum / 10;
		ans += char('0' + rem);
	}
	if (carry != 0)
		ans += char('0' + carry);
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

	string a = "1";
	string b = "1";

	int next = 3;

	while (1)
	{
		string c = add(a, b);
		a = b;
		b = c;
		if (b.length() == 1000)
			break;
		next++;
	}
	cout << next << endl;

}

