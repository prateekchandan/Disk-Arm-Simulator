#include "Track.hpp"

Track::Track(){
	track_no = 0;
	size = 50;
	sectors = new Sector[size];
}

Track::Track(int n) {
	track_no = n;
	size = track_no/2+50;
	sectors = new Sector[size];
}

bool Track::write_data(char *d, int s) {
	return sectors[s].write_data(d);
}

bool Track::read_data(char *d, int s) {
	return sectors[s].read_data(d);
}
