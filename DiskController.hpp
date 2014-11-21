#include "HardDisk.hpp"
#include "Cache.hpp"

struct DiskController{
	/// Implementation of RAID 1
	HardDisk h[4];
	HardDisk h_copy[4];

	Cache cache;
	
public:
	DiskController();
};
