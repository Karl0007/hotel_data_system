#include "Data.h"



Data::Data()
{
}


Data::~Data()
{
	all_hotel.clear();
}

bool Data::load_from_file(const string & s)
{
	ifstream is;
	string ss;
	is.open(s);
	if (is.is_open()) {
		while (is >> ss) {
			insert_hotel(ss);
		}
		return true;
	}
	else {
		cout << "读取失败" << endl;
		return false;
	}
}

bool Data::save_to_file(const string & s)
{
	ofstream os;
	os.open(s);
	for (auto &i : all_hotel) {
		os << i.second->num << ',' << i.second->hotel << ',' << i.second->city << ',' << i.second->position << "|";
		for (auto &j : i.second->get_room()) {
			os << j.second->num << ',' << j.second->price << ',' << j.second->type << '|';
		}
		os << endl;
	}
	return true;
}

bool Data::insert_hotel(const string & s)
{
	ptr_hotel tmp(new Hotel(s,this));
	if (this->all_hotel.count(tmp->get_num())) {
		if (!this->Waring_the_same_number(tmp->get_num())) {
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
		Warning_no_hotel_numbuer(n);
	}
	return false;
}

bool Data::insert_room(const int & n, const string & s)
{
	if (!check_hotel(n)) {
		Warning_no_hotel_numbuer(n);
		return false;
	}
	return all_hotel.find(n)->second->insert_room(s);	
}

bool Data::delete_room(const int & n, const int & m)
{
	if (!check_hotel(n)) {
		Warning_no_hotel_numbuer(n);
		return false;
	}
	return all_hotel.find(n)->second->delete_room(m);
}

res_pair Data::select_room(int low, int high, const vec_str & city, const vec_str & hotel, const vec_str & position, const vec_str & type)
{
	res_pair res;

	res.first.push_back("编号	名称	城市	地区	房间号	房型	价格");
	res.second.push_back(__nullptr);
	int cnt = 0;
	for (auto &i : all_room) {
		if (i->get_price() >= low && i->get_price() <= high) {
			if (check_string_in(city, i->get_hotel_city()) && check_string_in(hotel, i->get_hotel_name()) && check_string_in(position, i->get_hotel_position()) && check_string_in(type, i->get_type())) {
				res.first.push_back(to_string(++cnt) + "\t"+i->get_data()+ "\t" +to_string(i->get_price())+"元");
				res.second.push_back(&*i);
			}
		}
	}
	return res;
}

bool Data::check_hotel(const int & n)
{
	return all_hotel.count(n);
}

pos_room Data::ptr_to_pos(const ptr_room & ptr)
{
	return pos_room(ptr->get_hotel_num(),ptr->get_num());
}

ptr_room Data::pos_to_ptr(const pos_room & pos)
{
	return all_hotel[pos.first]->room[pos.second];
}

bool Data::insert_book(MyTime st, MyTime ed, Room * p)
{
	if (!(st < ed)) return false;
	ptr_bok tmp(new BookInfo);
	tmp->room = p;
	tmp->start_time = st;
	tmp->end_time = ed;
	vector<int> to_erase;
	for (auto &i : all_book) {
		if (i.second->room == p) {
			if (tmp->start_time <= i.second->end_time &&  i.second->start_time <= tmp->end_time || i.second->start_time <= tmp->end_time && tmp->start_time<=i.second->end_time) {
				tmp->start_time = min(tmp->start_time,i.second->start_time);
				tmp->end_time = max(tmp->end_time,i.second->end_time);
				to_erase.push_back(i.first);
			}
		}
	}
	for (auto &i : to_erase) {
		all_book.erase(i);
	}
	tmp->price=(tmp->end_time-tmp->start_time)*tmp->room->get_price();
	int num = rand() % 1000;
	while (all_book.count(num)) num = rand() % 1000;
	tmp->num = num;
	all_book[num] = tmp;
	return true;
}

vec_str Data::get_book_info()
{
	vec_str res;
	res.push_back("编号	名称	城市	地区	房间号	房型	价格	时间");
	for (auto &i : all_book) {
		res.push_back(to_string(i.first)+"\t"+i.second->room->get_data()+"\t"+to_string(i.second->price)+"\t"+i.second->start_time.s+"~~"+i.second->end_time.s);
	}
	return res;
}



bool Data::check_string_in(const vec_str & vs, const string & s)
{
	if (vs == nul) return true;
	for (auto & i : vs) {
		if (i == s) return true;
	}
	return false;
}

bool Data::Waring_the_same_number(int num)
{
	char x;
	cout << num << "号酒店信息已录入 是否要覆盖？ [y/n]" << endl;
	cin >> x;
	while (x != 'y' && x != 'n' && x != 'Y' && x != 'N') cin >> x;
	return x == 'y' || x == 'Y';
}

void Data::Warning_no_hotel_numbuer(int num)
{
	cout << num << "号酒店不存在！" << endl;
}
