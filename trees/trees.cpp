#include <bits/stdc++.h>
#include "AVL.h"
using namespace std;

int main()
{
	ITree* t = new AVL();
	cout << "It's AVL tree tester. Enter \"+ <number>\" to add value and \"- <number>\" to remove.\nEnter \"? <number>\" to know if the tree contains the value.\n";
	cout << "As example: \"+ -2\".\n";
	while (true)
	{
		char c;
		long long x;
		cin >> c >> x;
		if (c == '+')
		{
			t = t->insert(x);
			cout << "added " << x << '\n';
		}
		else if (c == '-')
		{
			t = t->erase(x);
			cout << "removed " << x << " if it was there" << '\n';
		}
		else if (c == '?')
		{
			if (t->find(x))
				cout << "We have found " << x << " in the tree" << '\n';
			else cout << "We haven't found " << x << " in the tree" << '\n';
		}
	}
	delete t;
}