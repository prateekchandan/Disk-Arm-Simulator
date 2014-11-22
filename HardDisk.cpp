#include "HardDisk.hpp"

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
