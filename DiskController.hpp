#include "HardDisk.hpp"
#include "Cache.hpp"

struct DiskController{
	/// Implementation of RAID 1
	HardDisk h[TOTAL_DISK];
	HardDisk h_copy[TOTAL_DISK];

	Cache cache;

	int *timer;
	
public:
	DiskController(int*);

	void read_data(int addr,char data[DATA_SIZE],int time);
	void write_data(int addr,char data[DATA_SIZE],int time);

	void update();

	void print_stats();
};
