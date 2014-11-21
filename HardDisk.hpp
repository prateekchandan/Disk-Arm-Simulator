#include "Platter.hpp"

class HardDisk
{

	// SPINDLE
	int rotation;
	// HEAD FOR DISK
	int trackno;

	Platter *platters;
public:
	HardDisk();

	bool write_data(char*, int, int, int);

	bool read_data(char *, int, int, int);
	
	
};
