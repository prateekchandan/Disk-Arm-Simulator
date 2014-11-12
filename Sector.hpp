#include "pflayer/pf.h"
#include <cstring>
class Sector
{
	char filename[100];
public:
	Sector(){
		PF_Init();
		strcpy(filename,"qwdqwdqwdqw");
		int a=PF_CreateFile(filename);
	}

	void writefile();

	
	
};