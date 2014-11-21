#include "Track.hpp"

class Platter{
	// Platter number
	int platter_no;

	// Number of tracks in the platter
	int size;
	
	// List of Tracks in the Platter
	Track * tracks;


public:
	Platter();
	Platter(int);

	bool write_data(char *, int, int);

	bool read_data(char *, int, int);
};
