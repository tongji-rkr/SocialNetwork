#pragma once
#include<iostream>
#include"vector.h"
using namespace std;


template<typename key, typename value>
class Dict
{
private:
	vector<key> _key;
	vector<value> _value;
	int flag;
public:
	Dict():_key(),_value()
	{
		flag = 0;
	}
	int size()
	{
		return _key.size();
	}
	value operator [] (key k)
	{
		flag = 0;
		for (int i = 0; i < _key.size(); i++)
		{
			if (k == _key[i])
			{
				flag = 1;
				return _value[i];
			}
		}
	}
	void insert(key k, value v)
	{
		flag = 0;
		for (int i = 0; i < _key.size(); i++)
		{
			if (k == _key[i])
			{
				flag = 1;
				_value.chang_value(i, v);
				break;
			}
		}
		if (!flag)
		{
			_key.push_back(k);
			_value.push_back(v);
		}
	}
};
