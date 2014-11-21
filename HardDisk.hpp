#include "Platter.hpp"

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

	// Statistics object
	Statistics *stats;

	Platter *platters;
public:
	HardDisk();

	bool write_data(char*, int, int, int);

	bool read_data(char *, int, int, int);
	
	
};
