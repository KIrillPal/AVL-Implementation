#include <bits/stdc++.h>
#include "AVL.h"
using namespace std;

int main()
{
	ITree* t = new AVL();
	while (true)
	{
		char c;
		cin >> c;
		if (c == '+')
		{
			long long x;
			cin >> x;
			t = t->insert(x);
			cout << "added " << x << '\n';
		}
		else if (c == '-')
		{
			long long x;
			cin >> x;
			t = t->erase(x);
			cout << "removed " << x << '\n';
		}
		else if (c == '=')
			cout << "showed\n";
	}
	delete t;
}