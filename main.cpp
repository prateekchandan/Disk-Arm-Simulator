#include "HardDisk.hpp"
#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
	HardDisk h;
	char data[512] = {'a'};
	for(int i = 0; i < 512; i++) data[i] = 'a';
	h.write_data(data, 0, 0, 0);
	char data1[512] = {'b'};
	for(int i = 0; i < 512; i++) data1[i] = 'b';
	h.read_data(data1, 0, 0, 0);
	for(int i = 0; i < 512; i++) cout << data1[i];
	cout << endl;
	h.stats->print_stats();

	return 0;


}
