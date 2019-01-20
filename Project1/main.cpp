#include<bits/stdc++.h>
#include"Data.h"
using namespace std;

void pus(Room &r) {
	cout << r.get_num() << endl;
	cout << r.get_price() << endl;
	cout << r.get_type() << endl ;
	//cout << r.hotel->get_num() << endl << endl;
}

int main(){
	Data d;
/*	ptr_room r(new Room("|123,141,abc|"));
	pus(*r);
	d.all_room.insert(r);
	d.all_room.erase(r);
	*/
	d.insert_hotel("001,rj,nj,hcz|1234,200,small|1235,300,middle|1234,500,large|");
	d.insert_hotel("002,rj,nj,hcz|1234,201,small|1235,302,middle|1234,504,large|");
	d.insert_hotel("002,rj,nj,hcz|1236,201,small!|1235,302,middle!|1234,504,large!|");
	//d.delete_hotel(001);
	//d.delete_hotel(002);
	for (auto &i : d.all_room) {
		pus(*i);
	}
	//d.delete_hotel(2);
	/*	int i = 0;
	Hotel d = Hotel("001,rj,nj,hcz|1234,200,small|1235,300,middle|1234,500,large|");
	Room r=Room("|123,141,abc|");
	pus(*(d.room[1234]));
*/	system("pause");
	return 0;
}