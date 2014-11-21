#include "Sector.hpp"

class Track{
	// Track number
	int track_no;

	// Number of Sectors in the track
	int size;

	// List of Sectors in the Track
	Sector * sectors;


public:
	Track();
	Track(int);

	bool write_data(char *, int);
	bool read_data(char *, int);
};
