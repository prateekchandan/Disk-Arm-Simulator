#define CaheSize 1000
class Cache
{
	bool valid[CaheSize];
	char *addr[1000];
	char data[1000][512];
public:
	Cache(){
		for (int i = 0; i < CaheSize; ++i)
		{
			valid[i]=0;
		}
	}

	
};