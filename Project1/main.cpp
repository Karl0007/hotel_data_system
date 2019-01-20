#include<bits/stdc++.h>
#include"HEAD.h"
using namespace std;

void pus(Room &r) {
	cout << r.get_num() << endl;
	cout << r.get_price() << endl;
	cout << r.get_type() << endl ;
	//cout << r.hotel->get_num() << endl << endl;
}

int main(){
	MyTime x(2011, 9, 1);
	MyTime y("2019/1/21");
	cout << y.year<<endl;
	cout << y.day << endl;
	cout <<  y-x ;
	Data d;
/*	ptr_room r(new Room("|123,141,abc|"));
	pus(*r);
	d.all_room.insert(r);
	d.all_room.erase(r);
	*/
/*	d.insert_hotel("001,rj,nj,hcz|1234,200,small|1235,300,middle|1233,500,large|");
	d.insert_hotel("002,jz,sh,hcz|1234,201,small|1235,302,middle|1232,504,large|");
	d.insert_hotel("003,lj,bj,hcz|1236,201,small!|1235,302,middle!|1234,504,large!|");
	d.insert_room(2,"|1237,1233,ooo|");
	d.delete_room(3,1234);
	d.save_to_file("hotel.txt");
*/	//d.delete_hotel(001);
	//d.delete_hotel(002);
	d.load_from_file("hotel.txt");
	vec_str s;
	s.push_back("sh");
	s.push_back("nj");
	auto a = d.select_room(100,500,s);
	for (auto &i : a.first) {
		cout << i << endl;
	}

	d.insert_book(MyTime("2019/1/21"), MyTime("2019/2/11"), a.second[3]);
	d.insert_book(MyTime("2019/1/24"), MyTime("2019/1/25"), a.second[2]);
	d.insert_book(MyTime("2019/2/16"), MyTime("2019/2/22"), a.second[3]);
	d.insert_book(MyTime("2019/1/30"), MyTime("2019/2/17"), a.second[3]);
	auto b = d.get_book_info();
	for (auto &i : b) {
		cout << i << endl;
	}
	//d.delete_hotel(2);
	/*	int i = 0;
	Hotel d = Hotel("001,rj,nj,hcz|1234,200,small|1235,300,middle|1234,500,large|");
	Room r=Room("|123,141,abc|");
	pus(*(d.room[1234]));
*/	system("pause");
	return 0;
}