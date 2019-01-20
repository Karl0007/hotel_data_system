#include "Room.h"





Room::Room(const int & num, const int & price, const string & type)
{
	this->num = num;
	this->price = price;
	this->type = type;
}

Room::Room(const string & s, int &i)
{
	while (!isdigit(s[i])) i++;
	this->num = 0, this->price = 0;
	this->type = "";
	while (s[i] != ',') {
		this->num = this->num * 10 + s[i] - '0';
		++i;
	}
	++i;
	while (s[i] != ',') {
		this->price = this->price * 10 + s[i] - '0';
		++i;
	}
	++i;
	while (s[i] != '|') {
		this->type += s[i];
		++i;
	}
	++i;
}

Room::Room(const string & s)
{
	int i = 0;
	while (!isdigit(s[i])) i++;
	this->num = 0, this->price = 0;
	this->type = "";
	while (s[i] != ',') {
		this->num = this->num * 10 + s[i] - '0';
		++i;
	}
	++i;
	while (s[i] != ',') {
		this->price = this->price * 10 + s[i] - '0';
		++i;
	}
	++i;
	while (s[i] != '|') {
		this->type += s[i];
		++i;
	}
	++i;

}

Room::~Room()
{
	//cout << this->hotel->get_num() <<" : "<< this->get_num() << " " << this->get_price() << " " << this->get_type() << "ÒÑÉ¾³ý\n";
}

const int & Room::get_price()const
{
	return this->price;
}

const string & Room::get_type()const
{
	return this->type;
}

const int & Room::get_num() const
{
	return this->num;
}

const Hotel * Room::get_hotel() const
{
	return this->hotel;
}

void Room::modify_price(int x) 
{
	this->price = x;
}

void Room::modify_type(const string & s)
{
	this->type = s;
}

void Room::set_hotel(Hotel * h)
{
	this->hotel = h;
}



bool operator < (const Room & a, const Room & b) {
	return a.get_price() < b.get_price() || a.get_price() == b.get_price() && a.get_num() < b.get_num();
}

bool operator < (const ptr_room & a, const ptr_room & b) {
	return a->get_price() < b->get_price() || a->get_price() == b->get_price() && a->get_num() < b->get_num() || a->get_price() == b->get_price() && a->get_num() == b->get_num() && a->get_hotel() < b->get_hotel();
}

bool operator==(const ptr_room & a, const ptr_room & b)
{
	return a->get_num() == b->get_num() && a->hotel==b->hotel;
}
