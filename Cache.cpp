#include "Cache.hpp"
#include <string.h>
Cache::Cache(){
	for (int i = 0; i < CACHE_SIZE; ++i)
	{
		valid[i]=0;
	}
}

// Linear Search to Read Data
bool Cache::read(long long address,char data_incoming[DATA_SIZE]){
	for (int i = 0; i < CACHE_SIZE; ++i)
	{
		if(valid[i] && addr[i]==address){
			cout<<data[i];
			data_incoming=data[i];
			return true;
		}
	}
	return false;
}

// Least Frequently User Replacement Policy
void Cache::update(long long int address,char data_incoming[DATA_SIZE]){
	long long int temp_addr=address,t1;
	char temp_data[DATA_SIZE],t2[DATA_SIZE];
	strcpy(temp_data,data_incoming);

	for (int i = 0; i < CACHE_SIZE; ++i)
	{
		if(!valid[i]){
			valid[i]=1;
			addr[i]=temp_addr;
			data[i]=temp_data;
			return;
		}
		if(addr[i]==address){
			addr[i]=temp_addr;
			data[i]=temp_data;
			return;
		}
		else{
			t1=addr[i];
			addr[i]=temp_addr;
			temp_addr=t1;

			strcpy(t2,data[i]);
			strcpy(data[i],temp_data);
			strcpy(temp_data,data[i]);
		}
	}
	
}