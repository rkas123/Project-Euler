#include<bits/stdc++.h>
#define int long long
using namespace std;

int root(int y)
{
	int r = sqrt(y);
	if (r * r == y)
		return r;
	return 0;
}
bool tri(int y)
{
	int sq = root(1 + 8 * y);
	if (sq == 0)
		return false;
	int num = -1 + sq;
	if (num % 2)
		return false;
	return true;
}
bool pent(int y)
{
	int sq = root(1 + 24 * y);
	if (sq == 0)
		return false;
	int num = 1 + root(1 + 24 * y);
	if (num % 6)
		return false;
	return true;
}

int32_t main()
{

	int thres = 40755;

	for (int i = 144; i <= 100000; i++)
	{
		int num = (i * (2 * i - 1));
		if (tri(num) && pent(num))
		{
			cout << i << " " << num << endl;
			break;
		}
	}
	return 0;
}
