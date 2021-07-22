#pragma once
#include <cmath>
#include <algorithm>
typedef long long T;
class ITree
{
public:
	ITree();
	virtual ~ITree();
	virtual ITree* insert(T value) = 0;
	virtual ITree* erase(T value) = 0;
	virtual bool find(T value) = 0;
};

