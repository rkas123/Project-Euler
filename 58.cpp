#include<bits/stdc++.h>
#define int long long

using namespace std;

bool isPrime(int n)
{
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;

	for (int i = 3; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int32_t main()
{
	int prime = 0, composite = 0;

	int curr = 1;
	int inc = 2;
	while (1)
	{
		for (int i = 0; i < 4; i++)
		{
			curr += inc;
			if (isPrime(curr))
				prime++;
			else
				composite++;
		}
		int tot = prime + composite + 1;
		if ((prime * 100) / tot < 10)
		{
			cout << inc + 1 << endl;
			break;
		}
		inc += 2;
	}
	return 0;
}
