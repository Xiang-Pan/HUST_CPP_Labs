#include <stdio.h>

// FILE *fd;//文件指针
// strcat(fname,".txt");
// fd=fopen(fname,"w+");



#define ECHO_COLOR_NONE         "\033[0;0m"
#define ECHO_COLOR_GREEN        "\033[0;32m"


#define __DEBUG
#undef __DEBUG

#ifdef __DEBUG
#define debug(fmt,args...)     \
        printf(ECHO_COLOR_GREEN "\nDebug: " fmt "\n" ECHO_COLOR_NONE, ##args); 
// printf(ECHO_COLOR_GREEN "Debug: " fmt "(file: %s, func: %s, line: %d)\n" ECHO_COLOR_NONE, ##args, __FILE__, __func__, __LINE__); 
        // printf(ECHO_COLOR_GREEN fmt ECHO_COLOR_NONE);
        // printf(ECHO_COLOR_GREEN "Debug: " fmt "\n");
     
#else
#define debug(fmt, args...) 
#endif


#define __FILE
// #undef __FILE

#ifdef __FILE
#define my_printf(fmt,args...)  printf(fmt, ##args);
#else
#define my_printf(fmt)  fprintf(fd, fmt);
#endif