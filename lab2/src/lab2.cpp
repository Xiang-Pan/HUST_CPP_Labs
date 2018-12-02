/* FileName:	lab2.cpp
 * Author:		Hover
 * E-Mail:		hover@hust.edu.cn
 * GitHub:		HoverWings
 * Description:	The implementation of STACK 
 */
#include "lab2.h"
#include <iostream>
#include <cstdlib>
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
				s->push(num);
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
					s->push(num);
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
					if (s->howMany()== 0)
					{
						printf("  O  E");
						exit(0);
					}
					s->pop(out);;
				}
				printf("  O");
				s->print();
				break;
			case 'C':
				debug("HAVE option: -C");
				printf("  C");
				p = s;
				s = p;
				s->print();
				break;
			case 'A':
				debug("HAVE option: -A");
				debug("The argument of -A is %s", optarg);
				num=atoi(optarg);
				printf("  A");
				p = new STACK(num);
				p->assign(*s);		//assign p to s
				s = p;
				s->print();			//print current stack
				break;
			case 'N':
				debug("HAVE option: -N");
				printf("  N");
				printf("  %d", s->howMany());
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
				printf("  %d", s->getelem(num));
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
//STACK::STACK(int m) : elems(new int [m]), max(m), pos(0) {}

STACK::STACK(const STACK &s): elems(s.max > 0 ? new int[s.max] : new int[0]), max(s.max > 0 ? s.max : 0) 
{
    this->pos = 0;
    for (int i = 0; i < s.howMany() && i < this->size(); i++) 
	{
		int j=0;
        push(s.getelem(i));
    }
}


int STACK::howMany() const 
{
	return pos;
}

int STACK::size() const 
{
    return this->max;
}

int STACK::getelem(int x) const 
{
	if (x < 0 || x >= pos)
	{
		cerr<<"Index out of range!";
	}
	return elems[x];
}

STACK &STACK::push(int e) 
{
	if (pos == max)
	{
		cerr<<"Stack Full!";
	}
	elems[pos] = e;
	pos++;
	return *this;
}

STACK &STACK::pop(int &e) 
{
	if (pos == 0 && e != 0)
	{
		cerr<<"Stack Empty!";
	}
	e = elems[pos - 1];
	pos--;
	return *this;
}

STACK &STACK::assign(const STACK &s) 
{
	delete []this->elems;
	// malloc again
	int * const * cp_elems = &(elems);
	int ** p_elems = const_cast<int **>(cp_elems);
	*p_elems = new int[s.max];
	for(int i = 0;i < s.pos;i++)
	{
		elems[i] = s.elems[i];
	}
	const int * cp_max = &max;
	int * c_max = const_cast<int *>(cp_max);
	*c_max = s.max;
	pos = s.pos;
	return *this;
}


void STACK::print(void) const 
{
    for (int i = 0; i < pos; i++) 
	{
        cout<<"  "<<elems[i];
    }
}

STACK::~STACK(void) 
{
	if (this->elems)
	{
		delete [] this->elems;
	}
    this->pos = 0;
}



