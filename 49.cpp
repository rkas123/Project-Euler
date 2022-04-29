#include<bits/stdc++.h>
#define int long long
using namespace std;

int N = 10000;
vector<bool> sieve(10000);

void makeSieve()
{
	sieve = vector<bool>(10000, true);
	sieve[1] = false;
	for (int i = 4; i < N; i += 2)
		sieve[i] = false;

	for (int i = 3; i * i < N; i += 2)
	{
		if (sieve[i])
		{
			for (int j = i * i; j < N; j += (2 * i))
				sieve[j] = false;
		}
	}
}

int32_t main()
{
	makeSieve();
	for (int a = 1488; a < 10000; a++)
	{
		if (sieve[a])
		{
			for (int d = 1; d <= 3333; d++) {
				if (a + 2 * d >= 100000)
					continue;
				int b = a + d, c = a + 2 * d;
				string A = to_string(a);
				string B = to_string(b);
				string C = to_string(c);
				sort(A.begin(), A.end());
				sort(B.begin(), B.end());
				sort(C.begin(), C.end());
				if (A != B || B != C)
					continue;

				if (sieve[b] && sieve[c])
					cout << a << b << c << endl;
			}
		}
	}
	return 0;
}
