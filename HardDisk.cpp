#include "HardDisk.hpp"


HardDisk::HardDisk(){
	rotation=0;
	trackno=0;
	platters = new Platter[3];
}

bool HardDisk::write_data(char * d, int p, int t, int s) {
	return platters[p].write_data(d, t, s);
}


bool HardDisk::read_data(char * d, int p, int t, int s) {
	return platters[p].read_data(d, t, s);
}
