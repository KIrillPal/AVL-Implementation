#pragma once
#include "ITree.h"
class AVL : virtual public ITree
{
public:
	AVL(T value);
	AVL();
	virtual ~AVL();
	virtual ITree* insert(T value);
	virtual ITree* erase(T value);
	virtual bool find(T value);
private:
	char height_;
	long long value_;
	AVL* L_, * R_;
	bool isempty;
	friend char height(AVL* t);
	friend bool isempty(AVL* t);
	friend char factor(AVL* t);
	friend void balance(AVL*& t);
	friend void setheight(AVL* t);
	friend void rotation_r(AVL*& t);
	friend void rotation_l(AVL*& t);
	friend void insert_(AVL*& t, T value);
	friend void erase_(AVL*& t, T value);
	friend void erase_mr(AVL*& t, T& value);
	friend bool find_(AVL*& t, T value);
};

