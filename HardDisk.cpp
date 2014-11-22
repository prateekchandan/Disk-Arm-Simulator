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
	buffer.current = buffer.content.end();
}

bool HardDisk::write_data(char * d, int p, int t, int s) {
	return platters[p].write_data(d, t, s);
}

bool HardDisk::read_data(char * d, int p, int t, int s) {
	return platters[p].read_data(d, t, s);
}

bool HardDisk::add_operation(int tm, int op, char * d, int p, int t, int s) {
	buffer.add_entry(tm, op, p, t, s, d);
}


buffer_entry::buffer_entry(){};
buffer_entry::buffer_entry(int tm, int rw, int p, int t, int s, char * d) {
	time = tm;
	read_or_write = rw;
	platter_no = p;
	track_no = t;
	data = d;
}

bool operator<(buffer_entry a, buffer_entry b) {
	if(a.track_no == b.track_no) return a.time < b.time;
	return a.track_no < b.track_no;
}

Buffer::Buffer(){
	current = content.end();
}

void Buffer::add_entry(int tm, int rw, int p, int t, int s, char * d) {
	buffer_entry be = *(new buffer_entry(tm, rw, p, t, s, d));
	content.insert(be);
}

buffer_entry Buffer::give_next(int direction) {
	if(current  == content.end()) {
		current = content.begin();
		return *current;
	}
	if(content.size() == 1){
		set<buffer_entry>::iterator temp = current;
		current++;
		content.erase(current);
		return *current;
	}
	if(direction == 1) {
		if(distance(current, content.end()) == 1)  direction = -1;
		else {
			set<buffer_entry>::iterator temp = current;
			current++;
			content.erase(temp);
			return *current;
		}
	}
	if(direction == -1) {
		if(current == content.begin()) {
			set<buffer_entry>::iterator temp = current;
			current++;
			content.erase(temp);
			return *current;
		}
		set<buffer_entry>::iterator temp = current;
		temp++;
		if(temp == content.end() || current->track_no != temp->track_no) {
			temp = current;
			current--;
			content.erase(temp);
			temp = current;
			temp--;
			if(current->track_no == content.begin()->track_no) {
				current = content.begin();
				return *current;
			}
			else{
				while(temp->track_no == current->track_no){
					temp--;
				}
				return *current;
			}
		}
		else {
			set<buffer_entry>::iterator temp = current;
			current++;
			content.erase(temp);
			return *current;
		}
	}
	/*
	 *if(current  == content.end()) {
	 *    cout << "here" << endl;
	 *    current = content.begin();
	 *    return *current;
	 *}
	 *if(direction == 1) {
	 *    if(distance(current, content.end()) == 1)  direction = -1;
	 *}
	 *else if(direction == -1) {
	 *    if(current == content.begin()) direction = 1;
	 *}
	 *if(direction == 1) {
	 *    set<buffer_entry>::iterator temp = current;
	 *    current++;
	 *    content.erase(temp);
	 *    return *current;
	 *}
	 *else if(direction == -1) {
	 *    set<buffer_entry>::iterator temp = current;
	 *    current--;
	 *    content.erase(temp);
	 *    return *current;
	 *}
	 */
}
