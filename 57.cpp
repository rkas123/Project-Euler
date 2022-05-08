#include<bits/stdc++.h>
using namespace std;

string add(string a, string b)
{
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	if (a.length() < b.length())
		swap(a, b);

	while (b.length() < a.length())
		b += '0';

	int carry = 0;

	string ans = "";
	for (int i = 0; i < a.length(); i++)
	{
		int num = carry + (a[i] - '0') + (b[i] - '0');
		carry = num / 10;
		num %= 10;

		ans += char('0' + num);
	}
	if (carry > 0)
		ans += char('0' + carry);
	reverse(ans.begin(), ans.end());
	return ans;
}
struct fraction
{
	string num, den;
	fraction()
	{
		num = "0";
		den = "1";
	}
	fraction(int num)
	{
		this->num = to_string(num);
		this->den = "1";
	}
	fraction(int num, int den)
	{
		this->num = to_string(num);
		this->den = to_string(den);
	}

	void addone()
	{
		string num = add(this->num, this->den);
		string den = this->den;
		this->num = num;
		this->den = den;
	}
	void reciprocal()
	{
		swap(this->num, this->den);
	}
};
int main()
{
	vector<fraction> ans(1000);
	ans[0] = fraction(3, 2);

	int cnt = 0;

	for (int i = 1; i < 1000; i++)
	{
		ans[i] = ans[i - 1];
		ans[i].addone();
		ans[i].reciprocal();
		ans[i].addone();
		if (ans[i].num.length() > ans[i].den.length())
			cnt++;
	}
	cout << cnt << endl;
	return 0;
}
