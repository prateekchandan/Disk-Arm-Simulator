#include "Statistics.hpp"
#include <iostream>
using namespace std;

Statistics::Statistics() {
	seek_time = 4;
	write_latency = 4;

	cum_rot_latency = 0;
	cum_seek = 0;
	cum_write_latency = 0;
	cum_tot_time = 0;

	cur_rot_latency = 0;
	cur_seek = 0;
	cur_write_latency= 0;
	cur_tot_time = 0;
	cur_writes = 0;
	cur_reads = 0;
}

void Statistics::reinitialize_cur_stat() {
	cur_rot_latency = 0;
	cur_seek = 0;
	cur_write_latency = 0;
	cur_tot_time = 0;
}

void Statistics::add_rot_latency(double l) {
	cur_rot_latency += l;
	cum_rot_latency += l;
	cur_tot_time += l;
	cum_tot_time += l;
	return;
}

void Statistics::add_seek(int l) {
	cur_seek += l;
	cum_seek += l;
	cum_tot_time += seek_time*l;
	cur_tot_time += seek_time*l;
	return;
}

void Statistics::add_read(int l) {
	cur_reads+= l;
	return;
}

void Statistics::add_write_latency(int l) {
	cur_writes += l;
	cur_write_latency += l;
	cum_write_latency += l;
	cum_tot_time += write_latency*l;
	cur_tot_time += write_latency*l;
	return;
}

void Statistics::print_stats() {
	cerr << "no of seeks :           " << cur_seek << endl;
	cerr << "no of block transfers : " << cur_write_latency << endl;
	cerr << "no of reads :           " << cur_reads << endl;
	cerr << "no of writes :          " << cur_writes << endl;
	cerr << "total time :            "<< cur_tot_time << endl;
	//cerr << "cumulative rotational latency : " << cum_rot_latency << endl;
	//cerr << "cumulative seek time :          " << cum_seek << endl;
	//cerr << "cumulative write latency :      " << cum_write_latency << endl;
}
