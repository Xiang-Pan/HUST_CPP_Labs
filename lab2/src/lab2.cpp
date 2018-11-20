#include "lab2.h"
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

int stack_main(int argc, char *argv[]) 
{
	int num;//元素个数&&入栈数字
	int out;//接受出栈元素
	STACK *s;
	STACK *p;
	int ch;
	bool fail=false;
	while ((ch = getopt(argc, argv, "S:I:O:CA:NG:")) != -1)
	{
		if(fail)
		{
			cdebug("false");
			break;
		}
		fail=false;
		debug("optind: %d\n", optind);
		switch (ch) 
		{
			case 'S':
				debug("HAVE option: -S");   
				debug("The argument of -S is %s", optarg);
				num=atoi(optarg);
				debug("%d",num);
				printf("S  %d", num);
				s = new STACK(num);
				break;
			case 'I':
				debug("HAVE option: -I"); 
				debug("The argument of -I is %s", optarg);
				num=atoi(optarg);
				debug("%d",num);
				if(s->getpos()==s->getmax())
				{
					fail=true;
					printf("  I");
					printf("  E");
					break;
				}
				(*s)<<num;
				// debug(argv[optind][0]);
				while(isdigit(argv[optind][0]))
				{
					num=atoi(argv[optind]);
					debug("%d",num);
					if(s->getpos()==s->getmax())
					{
						fail=true;
						printf("  I");
						printf("  E");
						break;
					}
					(*s)<<num;
					optind++;
					if(optind==argc)
					{
						break;
					}
				}
				if(fail==false)
				{
					printf("  I");
					s->print();
				}
				break;
			case 'O':
				debug("HAVE option: -O");
				debug("The argument of -O is %s", optarg);
				num=atoi(optarg);
				debug("%d",num);
				for (int j = 0; j < num; j++)
				{
					if (int(*s)== 0)
					{
						printf("  O  E");
						exit(0);
					}
					(*s)>>out;
				}
				printf("  O");
				s->print();
				break;
			case 'C':
				debug("HAVE option: -C");
				printf("  C");
				p = s;
				s= p;
				s->print();
				break;
			case 'A':
				debug("HAVE option: -A");
				debug("The argument of -A is %s", optarg);
				num=atoi(optarg);
				printf("  A");
				s->print();			//打印当前栈
				break;
			case 'N':
				debug("HAVE option: -N");
				printf("  N");
				printf("  %d", int(*s));
				break;
			case 'G':
				debug("HAVE option: -G");
				debug("The argument of -G is %s", optarg);
				num=atoi(optarg);
				printf("  G");
				if(num>s->getpos())
				{
					printf("  E");
					break;
				}
				printf("  %d", (*s)[num]);
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

STACK::STACK(int m): elems(m > 0 ? new int[m] : new int[0]), max(m > 0 ? m : 0) 
{
    this->pos = 0;
    for (int i = 0; i < this->size(); i++)
	{
        this->elems[i] = 0;
    }
}

STACK::STACK(const STACK &s): elems(s.max > 0 ? new int[s.max] : new int[0]), max(s.max > 0 ? s.max : 0) 
{
    this->pos = 0;
    for (int i = 0; i < (int)s && i < this->size(); i++) 
	{
        (*this)<<s[i];
    }
}

int STACK::size() const 
{
    return this->max;
}

bool STACK::full() const 
{
    return (this->max==(int)(this->pos));
}

STACK::operator int(void) const 
{
    return (int)(this->pos);
}



int STACK::operator[](int x) const 
{
    // out of range check
    if (x < 0 || x >= (int)(*this)) return 0;
    return this->elems[x];
}

STACK& STACK::operator<<(int e) 
{
    // full check
    // if (this->size() <= (int)(*this)) return *this;
	cdebug(this->elems[this->pos]);
    this->elems[this->pos++] = e;
    return *this;
}

STACK& STACK::operator>>(int &e) 
{
    // empty check
    if ((int)(*this) <= 0) 
	{
        e = 0;
        return *this;
    }

    e = this->elems[--this->pos];
    return *this;
}

STACK& STACK::operator=(const STACK &s) 
{
    this->~STACK();
    new (this) STACK(s);
    return *this;
}

// int STACK::operator==(const STACK &s) const 
// {
//     // size or pos should equal
//     if (this->size() != s.size() || (int)(*this) != (int)s) return 0;

//     // every single element should equal
//     for (int i = 0; i < (int)(*this); i++) 
// 	{
//         if ((*this)[i] != s[i]) return 0;
//     }
//     return 1;
// }

void STACK::print(void) const 
{
    for (int i = 0; i < (int)(*this); i++) 
	{
        cout<<"  "<<(*this)[i];
    }
}

STACK::~STACK(void) 
{
    delete this->elems;
    this->pos = 0;
}



