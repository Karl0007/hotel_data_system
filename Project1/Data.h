#pragma once
#include<bits/stdc++.h>
#include"HEAD.h"
#include"Hotel.h"
#include"Room.h"
using namespace std;
class Data
{
public:
	friend class Room;
	friend class Hotel;
public:
	Data();
	~Data();
	bool insert_hotel(const string &s);
	bool delete_hotel(const int &n);
	//bool insert_room(const int &n,const string &s);
	//bool delete_room(const int &n,const int &m);
public:
	//int num;
	bool Waring_the_same_number();
	void Warning_no_hotel_numbuer();
	map <int, ptr_hotel> all_hotel;
	set <ptr_room> all_room;
};

