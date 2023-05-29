#pragma once
#pragma once
#include<iostream>
#include<stdlib.h>
using namespace std;

const int _add = 10;
template<class T>
class vector
{
public:
	typedef T* Iterator;
	Iterator _array;
	int _num, _buffer;
	vector()
	{
		_num = 0;
		_buffer = _add;
		/*_array = (Iterator)malloc(sizeof(T) * _buffer);*/
		_array = new T[_buffer]();
	}
	~vector()
	{
		if(_array)delete[]_array;
	}
	Iterator begin()
	{
		return _array;
	}
	Iterator end()
	{
		return &_array[_num - 1];
	}
	void expand()
	{
		Iterator tmp = new T[_buffer]();
		for (int i = 0; i < _buffer; i++)
		{
			tmp[i] = _array[i];
		}
		delete[]_array;
		_buffer += _add;
		_array = new T[_buffer]();
		for (int i = 0; i < _buffer - _add; i++)
		{
			_array[i] = tmp[i];
		}
		delete[]tmp;
	}
	void narrow()
	{
		_buffer -= _add;
		Iterator tmp = new T[_buffer]();
		for (int i = 0; i < _buffer; i++)
		{
			tmp[i] = _array[i];
		}
		delete[]_array;
		_array = new T[_buffer]();
		for (int i = 0; i < _buffer; i++)
		{
			_array[i] = tmp[i];
		}
		delete[]tmp;
	}
	void push_back(const T& x)
	{
		if (_num >= _buffer)
			expand();
		_array[_num++] = x;
	}
	void pop_back()
	{
		_num--;
		if (_num <= _buffer - _add)
			narrow();
	}
	void chang_value(int i, T& v)
	{
		if(i<_num)_array[i] = v;
	}
	int size()
	{
		return _num;
	}
	void clear()
	{
		if (_array)delete[]_array;
		_num = 0;
	}
	T& operator [](int sit)const
	{
		return _array[sit];
	}
	void operator =(const vector<T>& v)
	{
		if (_array)delete[]_array;
		_num = v._num;
		_buffer = v._buffer;
		_array = new T[_buffer]();
		for (int i = 0; i < _num; i++)
		{
			_array[i] = v._array[i];
		}
	}
};
