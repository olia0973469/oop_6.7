#include <iostream>

using namespace std;

template<class T>
class Predicate
{
public:
	virtual bool operator () (T x) = 0;
};

template<class T>
class Zero : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		T zero = T();
		return x == zero;
	}
};

template<class T>
class Positive : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x > 0;
	}
};

template<class T>
class Negative : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x < 0;
	}
};

template<class T>
class Even : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x % 2 == 0;
	}
};

template<class T>
class Odd : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x % 2 != 0;
	}
};

template<class T>
void copy(T * begin, T * end, T * to)
{
	for (T* from = begin; from < end; from++)
	{
		*to = *from;
		to++;
	}
}

template<class T>
int copy_if(T* begin, T* end, T* to, Predicate<T>& p)
{
	int n = 0;
	for (T* from = begin; from < end; from++)
		if (p(*from))
		{
			*to = *from;
			to++;
			n++;
		}
	return n;
}
int main()
{
	int a[5] = { 1, -2, 0, 4, -5 };
	int b[5], c[5], d[5];
	
	copy(&a[0], &a[5], &b[0]);
	for (int i = 0; i < 5; i++)
		cout << b[i] << ' ';
	cout << endl;

	Predicate<int>* zero = new Zero<int>();
	int n = copy_if(&a[0], &a[5], &c[0], *zero);
	for (int i = 0; i < n; i++)
		cout << c[i] << ' ';
	cout << endl;

	Predicate<int>* pos = new Positive<int>();
	int k = copy_if(&a[0], &a[5], &d[0], *pos);
	for (int i = 0; i < k; i++)
		cout << d[i] << ' ';
	cout << endl;
		system("pause");
	return 0;
}