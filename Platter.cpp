#include "Platter.hpp"

Platter::Platter(){
	size = 100;
	tracks = new Track[size];
}


Platter::Platter(int n){
	platter_no = n;
	size = 100;
	tracks = new Track[size];
}


bool Platter::write_data(char * d, int t, int s) {
	return tracks[t].write_data(d, s);
}

bool Platter::read_data(char * d, int t, int s) {
	return tracks[t].read_data(d, s);
}
