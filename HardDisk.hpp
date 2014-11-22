#include "Platter.hpp"
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

	buffer_entry();
	buffer_entry(int rw, int p, int t, int s, char * d);
};



struct buffer{
	set<buffer_entry> content;

	buffer();

	void addEntry(int rw, int p, int t, int s, char * d);
};
