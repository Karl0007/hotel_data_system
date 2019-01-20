#pragma once
#include<bits/stdc++.h>
#include"HEAD.h"
using namespace std;

struct MyTime {
	string s;
	int year, month, day;
	MyTime(const string & s);

	MyTime(int a=2019, int b=1, int c=1);
};
int operator - (const MyTime &a, const MyTime & b);
bool operator < (const MyTime &a, const MyTime &b);
bool operator == (const MyTime &a, const MyTime &b);
bool operator <= (const MyTime &a, const MyTime &b);

class BookInfo
{
public:
	BookInfo();
	~BookInfo();
public:
	MyTime start_time;
	MyTime end_time;
	Room * room;
	int price;
	int num;
};

