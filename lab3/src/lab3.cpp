#include "lab3.h"
#include <iostream>
#include <stdlib.h>
#include <ctype.h>
/*
“设定栈队或队列大小-S”
“入-I”、
“出-O”、
“深拷贝构造-C”、
“深拷贝赋值-A”、
“栈中剩余元素个数-N”
*/
using namespace std;

int queue_main(int argc, char *argv[]) 
{
	int num;		//元素个数&&入队数字
	int out;		//接受出队元素

	QUEUE *q;
	QUEUE *p;
	int ch;
	while ((ch = getopt(argc, argv, "S:I:O:CA:NG:")) != -1)
	{
		debug("optind: %d\n", optind);
		switch (ch) 
		{
			case 'S':
				debug("HAVE option: -S");   
				debug("The argument of -S is %s", optarg);
				num=atoi(optarg);
				debug("%d",num);
				// printf("S  %d", num);
				q = new QUEUE(num);
				printf("S");
				q->print();
				break;
			case 'I':
				debug("HAVE option: -I"); 
				debug("The argument of -I is %s", optarg);
				num=atoi(optarg);
				debug("%d",num);
				(*q)<<num;
				// debug(argv[optind][0]);
				while(isdigit(argv[optind][0]))
				{
					num=atoi(argv[optind]);
					debug("%d",num);
					(*q)<<num;
					optind++;
					if(optind==argc)
					{
						break;
					}
				}
				printf("  I");
				q->print();
				break;
			case 'O':
				debug("HAVE option: -O");
				debug("The argument of -O is %s", optarg);
				num=atoi(optarg);
				debug("%d",num);
				for (int j = 0; j < num; j++)
				{
					if (int(*q)== 0)
					{
						printf("  E");
						exit(0);
					}
					(*q)>>out;
				}
				printf("  O");
				q->print();
				break;
			case 'C':
				debug("HAVE option: -C");
				printf("  C");
				p = q;
				q->print();
				break;
			case 'A':
				debug("HAVE option: -A");
				debug("The argument of -A is %s", optarg);
				num=atoi(optarg);
				printf("  A");
				q->print();			
				break;
			case 'N':
				debug("HAVE option: -N");
				printf("  N");
				printf("  %d", int(*q));
				break;
			case 'G':
				debug("HAVE option: -G");
				debug("The argument of -G is %s", optarg);
				num=atoi(optarg);
				printf("  G");
				printf("  %d", (*q)[num]);
				break;
			default:
				debug("Unknown option: %c",(char)optopt);
				break;
			}
			
	}
	return 0;
}

//Impletation Stack Fun

//Overload


QUEUE::QUEUE(int m): s1(m), s2(m) 
{
}

QUEUE::QUEUE(const QUEUE &q): s1(q.s1), s2(q.s2) 
{
}

int QUEUE::size(void) const 
{
    return s1.size();
}

int QUEUE::full(void) const 
{
    return s1.size();
}

QUEUE::operator int(void) const 
{
    return (int)s1 + (int)s2;
}

int QUEUE::operator[](int x) const 
{
    if (x < (int)s2) 
	{
        return s2[int(s2)-x-1];
    }
	else
	{
        return s1[x-(int)s2];
    }
}

QUEUE& QUEUE::operator<<(int e) 
{
    // full check
    if (this->size() <= (int)(*this)) return *this;
    s1<<e;
    return *this;
}

QUEUE& QUEUE::operator>>(int &e) 
{
    if ((int)s2 <= 0) 
	{
        int elem;
        // push all elements of s1 into s2
        while ((int)s1) 
		{
            s1>>elem;
            s2<<elem;
        }
    }
    s2>>e;
    return *this;
}

QUEUE& QUEUE::operator=(const QUEUE &q) 
{
    this->~QUEUE();
    new (this) QUEUE(q);
    return *this;
}

// int QUEUE::operator==(const QUEUE &q) const 
// {
//     // size or pos should equal
//     if (this->size() != q.size() || (int)(*this) != (int)q) return 0;

//     // every single element should equal
//     for (int i = 0; i < (int)(*this); i++) {
//         if ((*this)[i] != q[i]) return 0;
//     }

//     return 1;
// }

void QUEUE::print(void) const 
{
    for (int i = 0; i < (int)(*this); i++) 
	{
		cout<<"  "<<(*this)[i];
    }
    // cout<<"\n";
}

QUEUE::~QUEUE(void) 
{
    // stack member will be destructed automatically when queue vanish
}




