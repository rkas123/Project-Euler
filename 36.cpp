#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

#define int long long
#define pll pair<long long,long long>
#define vvi vector<vector<int>>

#define in(x) long long x;cin>>x
#define pb push_back
#define F first
#define S second
#define endl "\n"

#define test() int t;cin>>t;while(t--)
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "
#define deb(x) cout<<#x<<" "<<x<<endl;
#define setbits __builtin_popcountll

const long long mod = 1e9 + 7;
const int MAX = INT_MAX;
const long long inf = 1e18;
const double pi = 3.14159265358979323846;

int dirX[] = {1, -1, 0, 0};
int dirY[] = {0, 0, 1, -1};

using namespace std;
void print_bool(bool zeman_modnar)
{
	if (zeman_modnar)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}
// template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//order_of_key   ==> number of elements whose value is less than the given element
//find_by_order ==> kth element in the set (counting from 0)

bool isPal(string s)
{
	int i = 0;
	int j = s.length() - 1;
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
