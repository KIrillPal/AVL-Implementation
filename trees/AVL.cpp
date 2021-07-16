#include "AVL.h"



AVL::AVL(T value)
{
	value_ = value;
	L_ = R_ = nullptr;
	height_ = 1;
	isempty = 0;
}

AVL::AVL()
{
	L_ = R_ = nullptr;
	height_ = 0;
	isempty = 1;
}


AVL::~AVL()
{
	delete L_;
	delete R_;
}

ITree* AVL::insert(T value)
{
	auto p = this;
	insert_(p, value);
	return p;
}

ITree* AVL::erase(T value)
{
	auto p = this;
	erase_(p, value);
	return p;
}

char height(AVL* t)
{
	return t ? t->height_ : 0;
}

bool isempty(AVL* t)
{
	return t ? t->isempty : 0;
}

char factor(AVL* t)
{
	if (!t) return 0;
	return height(t->L_) - height(t->R_);
}

void balance(AVL*& t)
{
	if (!t) return;
	setheight(t);
	if (factor(t) == 2)
	{
		if (factor(t->L_) < 0)
			rotation_l(t->L_);
		setheight(t);
		rotation_r(t);
	}
	else if (factor(t) == -2)
	{
		if (factor(t->R_) > 0)
			rotation_r(t->R_);
		setheight(t);
		rotation_l(t);
	}
}

void setheight(AVL* t)
{
	t->height_ = std::max(height(t->L_), height(t->R_)) + 1;
}

void rotation_r(AVL*& t)
{
	if (!t || !(t->L_)) return;
	AVL* b = t->L_;
	t->L_ = b->R_;
	b->R_ = t;
	setheight(t);
	setheight(b);
	t = b;
}

void rotation_l(AVL*& t)
{
	if (!t || !(t->R_)) return;
	AVL * b = t->R_;
	t->R_ = b->L_;
	b->L_ = t;
	setheight(t);
	setheight(b);
	t = b;
}

void insert_(AVL*& t, T value)
{
	if (t->isempty) {
		t->value_ = value;
		t->height_ = 1;
		t->isempty = 0;
	}
	if (t->value_ == value) return;
	AVL * &p = (t->value_ < value) ? t->R_ : t->L_;
	if (!p) p = new AVL(value);
	else insert_(p, value);
	balance(t);
}



void erase_(AVL*& t, T value)
{
	if (!t || isempty(t)) return;
	if (t->value_ > value)
		erase_(t->L_, value);
	else if (t->value_ < value)
		erase_(t->R_, value);
	else if (!(t->R_))
	{
		AVL* d = t;
		t = t->L_;
		d->L_ = d->R_ = nullptr;
		delete d;
	}
	else erase_mr(t->R_, t->value_);
}

void erase_mr(AVL*& t, T& value)
{
	if (!t) return;
	if (t->L_) erase_mr(t->L_, value);
	else
	{
		std::swap(value, t->value_);
		delete t, t = nullptr;
	}
	if (t) balance(t);
}
