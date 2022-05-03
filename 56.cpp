#include<bits/stdc++.h>
#define int long long
using namespace std;

string add(string a, string b)
{
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if (a.length() < b.length())
		swap(a, b);
	while (b.length() < a.length())
		b.push_back('0');

	int carry = 0;
	string ans = "";
	for (int i = 0; i < a.length(); i++)
	{
		int num = (a[i] - '0') + (b[i] - '0') + carry;
		carry = num / 10;
		num %= 10;
		ans += char('0' + num);
	}
	if (carry > 0)
		ans += to_string(carry);
	reverse(ans.begin(), ans.end());
	return ans;
}
string single_mult(string a, int d)
{
	string ans = "";
	int carry = 0;
	reverse(a.begin(), a.end());
	for (int i = 0; i < a.length(); i++)
	{
		int dig = a[i] - '0';
		int num = dig * d;
		num += carry;
		carry = num / 10;
		num %= 10;
		ans += char('0' + num);
	}
	if (carry > 0)
	{
		ans += to_string(carry);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
string mult(string a, string b)
{
	string ans = "";
	for (int i = 0; i < 205; i++)
	{
		ans.push_back('0');
	}
	reverse(b.begin(), b.end());

	for (int i = 0; i < b.length(); i++)
	{
		string halfsum = single_mult(a, b[i] - '0');
		for (int j = 0; j < i; j++)
			halfsum.push_back('0');
		ans = add(ans, halfsum);
	}
	reverse(ans.begin(), ans.end());
	while (ans.back() == '0')
		ans.pop_back();
	reverse(ans.begin(), ans.end());
	return ans;
}
string power(int a, int b)
{
	if (b == 1)
		return to_string(a);
	if (b & 1)
	{
		string temp = power(a, b / 2);
		return mult(mult(temp, temp), to_string(a));
	}
	string temp = power(a, b / 2);
	return mult(temp, temp);
}
int32_t main()
{
	int ans = 0;
	for (int a = 2; a < 100; a++)
	{
		for (int b = 2; b < 100; b++) {
			string s = power(a, b);
			int sum = 0;
			for (auto it : s)
			{
				sum += (it - '0');
			}
			ans = max(ans, sum);
		}
	}
	cout << ans << endl;
	return 0;
}
