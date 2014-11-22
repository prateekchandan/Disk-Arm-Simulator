#include "DiskController.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

DiskController::DiskController(){
	
}

void DiskController::read_data(long long int addr,char data[DATA_SIZE]){
	
	srand (time(NULL));

	int disk_no=addr/DISK_SIZE;
	if(disk_no<0 || disk_no >= TOTAL_DISK){
		cout<<addr<<" Error:Read Operation Failed"<<endl;
		return;
	}
	if(cache.read(addr,data)){
		cout<<addr<<" "<<data<<endl;
		return;
	}

	cout<<addr<<" ";

	if(rand() % 2 ==0){
		// Read from h_disk
	}
	else{
		// Read from mirrored Disk
	}
	cout<<endl;



}

void DiskController::write_data(long long int addr,char data[DATA_SIZE]){
	srand (time(NULL));

	int disk_no=addr/DISK_SIZE;
	if(disk_no<0 || disk_no >= TOTAL_DISK){
		cout<<addr<<" Error:Read Operation Failed"<<endl;
		return;
	}

	// Write in disk

	// Write in mirrored disk
}