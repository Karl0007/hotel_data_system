#pragma once
#include<bits/stdc++.h>
#include"Data.h"
using namespace std;



class Room
{
public:
	friend class Data;
	friend class Hotel;
public:
	Room(const int & num,const int & price,const string & type);
	Room(const string & s, int &i);
	Room(const string & s);

	~Room();
	
	const int & get_price() const;
	const string & get_type() const;
	const int & get_num() const;
	const Hotel* get_hotel() const;
	friend bool operator == (const ptr_room & a, const ptr_room & b);

private:
	void modify_price(int x);
	void modify_type(const string &s);
	void set_hotel(Hotel * h);


private:
	Hotel * hotel;
	string type;
	int price;
	int num;
};


bool operator < (const Room & a, const Room & b);

bool operator < (const ptr_room & a, const ptr_room & b);
