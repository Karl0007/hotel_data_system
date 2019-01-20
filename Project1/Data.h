#pragma once
#include<bits/stdc++.h>
#include"HEAD.h"
using namespace std;
class Data
{
public:
	friend class Room;
	friend class Hotel;
	friend class BookInfo;
public:
	Data();
	~Data();
	bool load_from_file(const string &s);
	bool save_to_file(const string &s);
	bool insert_hotel(const string &s);
	bool delete_hotel(const int &n);
	bool insert_room(const int &n, const string &s);
	bool delete_room(const int &n, const int &m);
	res_pair select_room(int low = 0,int high = 99999999,const vec_str & city = nul,const vec_str & hotel=nul,const vec_str & position=nul,const vec_str & type = nul);
	bool check_hotel(const int &n);
	pos_room ptr_to_pos(const ptr_room & ptr);
	ptr_room pos_to_ptr(const pos_room & pos);
	bool insert_book(MyTime st,MyTime ed,Room * p);
	vec_str get_book_info();
public:
	//int num;
	bool check_string_in(const vec_str & vs,const string & s);
	bool Waring_the_same_number(int num);
	void Warning_no_hotel_numbuer(int num);
	map <int, ptr_hotel> all_hotel;
	set <ptr_room> all_room;
	map <int, ptr_bok> all_book;
};

