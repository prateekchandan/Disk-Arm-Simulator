#include "DiskController.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int cache_on = 0;
DiskController::DiskController(){
	
}

void DiskController::read_data(int addr,char data[DATA_SIZE],int tim){
	
	srand(time(NULL));

	// DEMULTIPLEXING
	int disk_size=DISK_SIZE;
	int platter_size=PLATTER_SIZE;
	int disk_no=addr/disk_size;
	
	if(disk_no<0 || disk_no >= TOTAL_DISK){
		cout<<addr<<" Error in Address :Read Operation Failed"<<endl;
		return;
	}
	if(cache_on && cache.read(addr,data)){
		cout<<addr<<" "<<data<<endl;
		return;
	}


	int address_in_disk=addr%disk_size;
	int platter_no=address_in_disk/platter_size;
	int address_in_platter=address_in_disk%platter_size;
	int track_no;

	for (int i = 0; i < NO_TRACKS; ++i)
	{
		if(address_in_platter >= (NO_SECTORS_MIN+i)){
			address_in_platter-=(NO_SECTORS_MIN+i);
		}
		else{
			track_no=i;
			break;
		}


	}
	int sector_no=address_in_platter;

	cout<<addr<<" ";
	// Read randomly from hard disk
	if(rand() % 2 ==0){
		h[disk_no].add_operation(tim,0,data,platter_no,track_no,sector_no);
	}
	else{
		h_copy[disk_no].add_operation(tim,0,data,platter_no,track_no,sector_no);
	}

	// Updated data
	cache.update(addr,data);
	cout<<endl;



}

void DiskController::write_data(int addr,char data[DATA_SIZE],int tim){

	// DEMULTIPLEXING
	int disk_size=DISK_SIZE;
	int platter_size=PLATTER_SIZE;
	int disk_no=addr/disk_size;
	
	if(disk_no<0 || disk_no >= TOTAL_DISK){
		cout<<addr<<" Error in Address:Write Operation Failed "<<endl;
		return;
	}

	int address_in_disk=addr%disk_size;
	int platter_no=address_in_disk/platter_size;
	int address_in_platter=address_in_disk%platter_size;
	int track_no;

	for (int i = 0; i < NO_TRACKS; ++i)
	{
		if(address_in_platter >= (NO_SECTORS_MIN+i)){
			address_in_platter-=(NO_SECTORS_MIN+i);
		}
		else{
			track_no=i;
			break;
		}


	}
	int sector_no=address_in_platter;

	// Write in mirrored disk
	h[disk_no].add_operation(tim,1,data,platter_no,track_no,sector_no);
	h_copy[disk_no].add_operation(tim,1,data,platter_no,track_no,sector_no);
	cache.update(addr,data);
}

void DiskController::update(){
	for (int i = 0; i < TOTAL_DISK; ++i)
	{
		h[i].operate();
		h_copy[i].operate();
	}
}