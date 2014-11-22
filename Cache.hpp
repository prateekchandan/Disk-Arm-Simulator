#include "sizes.hpp"
#include <vector>

using namespace std;
class Cache
{
	bool valid[CACHE_SIZE];					// To store if a bit is valid
	vector<long long int> addr(CACHE_SIZE);		//To store all the addresses
	char data[CACHE_SIZE][DATA_SIZE];		// TO store data in cache

public:
	Cache();
	bool read(long long int address,char data_incoming[DATA_SIZE]);
	void update(long long int address,char data_incoming[DATA_SIZE]);
};