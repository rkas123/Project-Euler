#include <bits/stdc++.h>
#define int long long

using namespace std;
bool isPal(string s)
{
	int i = 0, j = s.length() - 1;
	while (i < j)
	{
		if (s[i] != s[j])
			return false;
		i++; j--;
	}
	return true;
}
string add(string a, string b)
{
	if (a.length() < b.length())
		swap(a, b);
	reverse(b.begin(), b.end());
	while (b.length() < a.length())
		b += '0';
	reverse(a.begin(), a.end());
	string ans = "";
	int carry = 0;

	int i = 0;
	while (i < a.length())
	{
		int num = (a[i] - '0') + (b[i] - '0') + carry;
		carry = num / 10;
		num %= 10;
		ans += char('0' + num);
		i++;
	}
	if (carry)
		ans += char('0' + carry);
	reverse(ans.begin(), ans.end());
	return ans;
}
string func(string s)
{
	string temp = s;
	reverse(temp.begin(), temp.end());
	s = add(s, temp);
	return s;
}
int32_t main()
{
	int ans = 0;
	for (int i = 1; i < 10000; i++)
	{
		string curr = to_string(i);
		bool flag = true;
		for (int iter = 1; iter <= 50; iter++)
		{
			curr = func(curr);
			if (isPal(curr))
			{
				flag = false;
				break;
			}
		}
		if (flag) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
