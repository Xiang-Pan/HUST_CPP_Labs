#include <iostream>
#include <unistd.h>
#include <string.h>
#include "my_debug.h"
#include "lab3.h"


using namespace std;


//Helper Function
//Judge Funciton 


int main(int argc, char *argv[]) 
{
    if(strcmp(argv[1], "stack") == 0)
    {
        debug("stack!");
        stack_main(argc-1,argv+1);
    }
    else if(strcmp(argv[1], "queue") == 0)
    {
        debug("queue!");
        queue_main(argc-1,argv+1);
    }
    return 0;
}

