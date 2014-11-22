#include "HardDisk.hpp"
#include <set>

using namespace std;

HardDisk::HardDisk(){

}

HardDisk::HardDisk(int * t){
	rotation=0;
	trackno=0;
	platters = new Platter[3];
	stats = new Statistics();
	for(int i = 0; i < 3; i++) {
		platters[i] = *(new Platter(i, stats));
	}
	arm_dir = 0;
	arm_pos = 0;
	rot_speed = 150;
	timer = t;
}

bool HardDisk::write_data(char * d, int p, int t, int s) {
	return platters[p].write_data(d, t, s);
}

bool HardDisk::read_data(char * d, int p, int t, int s) {
	return platters[p].read_data(d, t, s);
}


buffer_entry::buffer_entry(){};
buffer_entry::buffer_entry(int rw, int p, int t, int s, char * d) {
	read_or_write = rw;
	platter_no = p;
	track_no = t;
	sector_no = s;
	data = d;
}

bool operator<(buffer_entry a, buffer_entry b) {
	return a.track_no < b.track_no;
}

buffer::buffer(){}

void buffer::addEntry(int rw, int p, int t, int s, char * d) {
	buffer_entry be = *(new buffer_entry(rw, p, t, s, d));
	this->content.insert(be);
}
