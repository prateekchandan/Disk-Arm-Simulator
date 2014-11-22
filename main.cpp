#include "DiskController.hpp"
#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int timer=0;
	DiskController disk(&timer);

	char c[512];
	strcpy(c,"Hello I am an Indian");
	int next_op = 0;
	cin >> next_op;
	for(int i = 0; i < 100; i++) {
		cout << i << endl;
		if(next_op == i){
			cout << i << endl;
			int addr, rw;
			cin >> addr >> rw;
			cout << addr << " " << rw << endl;
			if(rw == 0) disk.read_data(98354,c,i);
			if(rw == 1) {
				cin.getline(c, 512);
				cin.getline(c, 512);
				disk.write_data(98354,c,i);
			}
			cin >> next_op;
		}
		disk.update();
	}
	return 0;


}
