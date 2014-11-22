#include "DiskController.hpp"
#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
	DiskController disk;
	char c[512];
	strcpy(c,"Hello I am an Indian");
	disk.write_data(98354,c,1);
	disk.read_data(98354,c,2);
	disk.read_data(98354,c,2);
	return 0;


}
