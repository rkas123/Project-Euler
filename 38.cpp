#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{

	int g = 0;
	for (int j = 1; j < 1e5; j++) {
		string s = "";

		int i = 1;
		while (s.length() < 9 )
		{
			int val = j * i;
			s += to_string(val);
			i++;
		}
		if (s.length() > 9)
			continue;

		vector<bool> vis(10, false);

		bool pos = true;
		for (int i = 0; i < 9; i++)
		{
			if (vis[s[i] - '0'])
				pos = false;
			vis[s[i] - '0'] = true;
		}

		for (int i = 1; i < 10; i++)
		{
			pos = (pos && vis[i]);
		}
		if (pos)
		{
			int val = stol(s);
			g = max(g, val);
		}
	}
	cout << g << endl;
	return 0;
}
