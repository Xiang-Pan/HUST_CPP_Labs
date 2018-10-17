#include <iostream>
#include <unistd.h>
#include <string.h>
#include "my_debug.h"
#include "lab4.h"
#include "osplatformutil.h"

using namespace std;


//Helper Function
const char *find_file_name(const char *name)
{
	char *name_start = NULL;
	int sep = '/';
	if (NULL == name) {
			printf("the path name is NULL\n");
	    return NULL;
	}
	name_start = (char *)strrchr(name, sep);

	return (NULL == name_start)?name:(name_start + 1);
}

//Judge Funciton 


int main(int argc, char *argv[]) 
{
    #if defined I_OS_LINUX
    const char* file_name;
    file_name=find_file_name(argv[0]);
    debug("this is linux");
    // cout<<argv[0];
    if(strcmp(file_name, "U201614898_1") == 0)
    {
        debug("stack!");
        stack_main(argc,argv);
    }
    else if(strcmp(file_name, "U201614898_2") == 0)
    {
        debug("stack!");
        stack_main(argc,argv);
    }
    else if(strcmp(file_name, "U201614898_3") == 0)
    {
        debug("queue!");
        queue_main(argc,argv);
    }
    else if(strcmp(file_name, "U201614898_4") == 0)
    {
        debug("queue!");
        queue_main(argc,argv);
    }
    #elif defined I_OS_WIN32
    // cout<<"this is windows"<<endl;
    #elif defined I_OS_CYGWIN
    debug("this is cygwin");
    const char* file_name;
    file_name=find_file_name(argv[0]);
    // printf("%s",file_name);
    if(strcmp(file_name, "U201614898_1") == 0)
    {
        debug("stack!");
        stack_main(argc,argv);
    }
    else if(strcmp(file_name, "U201614898_2") == 0)
    {
        debug("stack!");
        stack_main(argc,argv);
    }
    else if(strcmp(file_name, "U201614898_3") == 0)
    {
        debug("queue!");
        queue_main(argc,argv);
    }
    else if(strcmp(file_name, "U201614898_4") == 0)
    {
        debug("queue!");
        queue_main(argc,argv);
    }
    #endif
    return 0;
}

