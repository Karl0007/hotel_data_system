#include "Data.h"



Data::Data()
{
}


Data::~Data()
{
	all_hotel.clear();
	cout << this->all_room.size() << ' ' << this->all_hotel.size() << endl;

/*	for (auto i : this->all_hotel) {
		this->delete_hotel(i.first);
	}*/
}

bool Data::insert_hotel(const string & s)
{
	ptr_hotel tmp(new Hotel(s,this));
	if (this->all_hotel.count(tmp->get_num())) {
		if (!this->Waring_the_same_number()) {
			return false;
		}
		else {
			this->delete_hotel(tmp->get_num());
			all_hotel[tmp->get_num()] = tmp;
			tmp->data = this;
		}
	}
	else {
		all_hotel[tmp->get_num()] = tmp;
		tmp->data = this;

	}
	return false;
}

bool Data::delete_hotel(const int & n)
{
	if (this->all_hotel.count(n)) {
		all_hotel.erase(n);
	}
	else {
		Warning_no_hotel_numbuer();
	}
	return false;
}

bool Data::Waring_the_same_number()
{
	char x;
	cout << "号房间信息已录入 是否要覆盖？ [y/n]" << endl;
	cin >> x;
	while (x != 'y' && x != 'n' && x != 'Y' && x != 'N') cin >> x;
	return x == 'y' || x == 'Y';
}

void Data::Warning_no_hotel_numbuer()
{
	cout << "No such hotel!" << endl;
}
