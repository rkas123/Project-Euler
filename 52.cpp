#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	for (int i = 1; i <= 1e7; i++)
	{
		string curr = to_string(i);
		sort(curr.begin(), curr.end());
		bool pos = true;
		for (int d = 2; d <= 6; d++)
		{
			string temp = to_string(i * d);
			sort(temp.begin(), temp.end());
			if (temp != curr)
			{
				pos = false;
				break;
			}
		}
		if (pos)
		{
			cout << i << endl;
			break;
		}
	}
	return 0;
}
