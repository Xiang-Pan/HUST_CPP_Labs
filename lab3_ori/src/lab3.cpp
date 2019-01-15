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
	bool fail=false;
	while ((ch = getopt(argc, argv, "S:I:O:CA:NG:")) != -1)
	{
		if(fail)
		{
			debug("false");
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
				q = new QUEUE(num);
				// printf("S");
				// q->print();
				break;
			case 'I':
				debug("HAVE option: -I"); 
				debug("The argument of -I is %s", optarg);
				num=atoi(optarg);
				debug("%d",num);
				if(q->full())
				{
					fail=true;
					printf("  I");
					printf("  E");
					break;
				}
				(*q)<<num;
                if(optind==argc)
                {
                    printf("  I");
                    q->print();
                    break;
                }
				// debug(argv[optind][0]);
				while(isdigit(argv[optind][0]))
				{
					num=atoi(argv[optind]);
					debug("%d",num);
					if(q->full())
					{
						fail=true;
						printf("  I");
						printf("  E");
						break;
					}
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
						printf("  O  E");
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
				if(num>int(*q))
				{
					printf("  G  E");
					break;
				}
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


//D: return current stata's size
QUEUE::QUEUE(const QUEUE &q): s1(q.s1), s2(q.s2) 
{
}

int QUEUE::size() const 
{
	if(0<=int(s1)&&int(s1)<=s1.size()-1&&s2.empty()) //state 1
	{
		return s1.size();
	}
	if(0==int(s1)&&s2.full()) //state 2
	{
		return s2.size();
	}
	if(1<=int(s1)&&int(s1)<=s1.size()&&1<=int(s2)&&int(s2)<=s1.size()) //state 3
	{
        return s1.size()+s2.size()-1;
	}
    if(s1.full()&&1<=int(s2)&&int(s2)<=s2.size()) //state 4
	{
		return s1.size()+int(s2);
	}
}

int QUEUE::full() const 
{
	if(0<=int(s1)&&int(s1)<=s1.size()-1&&s2.empty()) //state 1
	{
		return false;
	}
	if(0==int(s1)&&s2.full()) //state 2
	{
		return false;
	}
	if(1<=int(s1)&&int(s1)<=s1.size()&&1<=int(s2)&&int(s2)<=s1.size()) //state 3
	{
		return false;
	}
	if(s1.full()&&1<=int(s2)&&int(s2)<=s2.size()) //state 4
	{
		return true;
	}
}

QUEUE::operator int() const 
{
    return (int)s1 + (int)s2;
}

int QUEUE::operator[](int x) const 
{
//	assert(0<=x&&x<=int(*this)-1);
	if(0<=int(s1)&&int(s1)<=s1.size()-1&&s2.empty()) //state 1
	{
		if(x<=int(s1))
		{
			return s1[x];
		}
	}
	if(0==int(s1)&&s2.full()) //state 2
	{
		if(x<=int(s2))
		{
			return s2[s2.getpos()-x-1];
		}
		else
        {
            return s1[x-int(s2)];
        }
	}
	if(1<=int(s1)&&int(s1)<=s1.size()&&1<=int(s2)&&int(s2)<=s1.size()) //state 3
	{
        if(x<=int(s2)-1)
        {
            return s2[s2.getpos()-x-1];
        }
        else
        {
            return s1[x-int(s2)];
        }
	}
    if(s1.full()&&1<=int(s2)&&int(s2)<=s2.size()) //state 4
	{
		if(x<=int(s2))
		{
			return s2[s2.getpos()-x-1];
		}
		else
		{
			return s1[x-int(s2)];
		}
	}
}

QUEUE& QUEUE::operator<<(int e) 
{
	debug("s1:%d",int(s1));
	debug("s2:%d",int(s2));
	debug("insert:%d",e);
    // // full check
	 if(this->full())
	 {
	 	debug("false!");
	 	return *this;
	 }
    // if (this->size() <= (int)(*this)) return *this;
	if(0<=int(s1)&&int(s1)<=s1.size()-1&&int(s2)==0) //state 1
	{
	    debug("state 1");
		s1<<e; // s1 full
		if(s1.full())
		{
			stack_dump(s1,s2); // to state 2 
			debug("s1:%d",int(s1));
			debug("s2:%d",int(s2));
			return *this;
		}
		debug("s1:%d",int(s1));
		debug("s2:%d",int(s2));
		return *this;
	}
	if(0==int(s1)&&s2.full()) //state 2
	{
        debug("state 2");
		s1<<e; // to state 3
		debug("s1:%d",int(s1));
		debug("s2:%d",int(s2));
		return *this;
	}
	if(1<=int(s1)&&int(s1)<=s1.size()-1&&1<=int(s2)&&int(s2)<=s2.size()) //state 3
	{
        debug("state 3");
		s1<<e;
		debug("s1:%d",int(s1));
		debug("s2:%d",int(s2));
		if(s1.full())
		{
			//to state 4
			return *this;
		}
		return *this;
	}
    if(s1.full()&&1<=int(s2)&&int(s2)<=s2.size()) //state 4
	{
        debug("state 4");
		return *this;
	}
    return *this;
}

QUEUE& QUEUE::operator>>(int &e) 
{
	debug("s1:%d",int(s1));
	debug("s2:%d",int(s2));
	if(0<=int(s1)&&int(s1)<=s1.size()-1&&s2.empty()) //state 1
	{
		debug("state 1");
		stack_dump(s1,s2);
		s2>>e;
		stack_dump(s2,s1);// to state 1 
	}
	if(0==int(s1)&&s2.full()) //state 2
	{
		s2>>e; // to state 1
		stack_dump(s2,s1);
		return *this;
	}
	if(1<=int(s1)&&int(s1)<=s1.size()&&1<=int(s2)&&int(s2)<=s1.size()) //state 3
	{
		s2>>e;
		if(s2.empty())
		{
			if(0<=int(s1)&&int(s1)<=s1.size()-1) //to state 1 
			{

			}
			if(s1.full()) //to state 2
			{
				stack_dump(s1,s2);
			}
		}
		return *this;
	}
    if(s1.full()&&1<=int(s2)&&int(s2)<=s2.size()) //state 4
	{
		s2>>e;
		if(s2.empty())	// to state 1 
		{
			stack_dump(s1,s2);
		}
		return *this;
	}
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

void QUEUE::print() const
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


void QUEUE::stack_dump(STACK& src,STACK& dst)
{
	// push all elements of src into dst
	if ((int)src <= dst.size()-int(dst)) 
	{
        int elem;
		while ((int)src) 
		{
			src>>elem;
			dst<<elem;
		}
    }
}



