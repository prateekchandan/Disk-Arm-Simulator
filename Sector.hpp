#include "pflayer/pf.h"
#include <cstring>
class Sector
{
	int sector_no;
	int size;
	char filename[100];
	char * data;
public:
	//Sector(){
		//PF_Init();
		//strcpy(filename,"qwdqwdqwdqw");
		//int a=PF_CreateFile(filename);
	//}
	
	Sector();
	Sector(int);

	void writefile();

	void _assign(char *);
	void _copy(char *);

	bool write_data(char *);
	bool read_data(char *);
	
	
};
