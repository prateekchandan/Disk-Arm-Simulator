#include "Platter.hpp"
#include <set>
using namespace std;

struct HardDisk
{

	// SPINDLE
	int rotation;
	// HEAD FOR DISK
	int trackno;

	// Direction of motion of the Arm
	int arm_dir;

	// Position of arm - wrt track number
	int arm_pos;

	// rotation speed of platters int rotations per second
	double rot_speed;

	int * timer;

	// Statistics object
	Statistics *stats;

	Platter *platters;
public:
	HardDisk();

	HardDisk(int*);

	bool write_data(char*, int, int, int);

	bool read_data(char *, int, int, int);
	
	
};

struct buffer_entry{
	int read_or_write;
	int platter_no;
	int track_no;
	int sector_no;
	char * data;

	buffer_entry() {};
	buffer_entry(int rw, int p, int t, int s, char * d) {
		read_or_write = rw;
		platter_no = p;
		track_no = t;
		sector_no = s;
		data = d;
	}
};

bool operator<(buffer_entry a, buffer_entry b) {
	return a.track_no < b.track_no;
}

struct buffer{
	set<buffer_entry> content;

	buffer() {};

	void addEntry(int rw, int p, int t, int s, char * d) {
		buffer_entry be = *(new buffer_entry(rw, p, t, s, d));
		this->content.insert(be);
	}
};
