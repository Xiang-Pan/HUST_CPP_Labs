/* FileName:	lab4.cpp
 * Author:		Hover
 * E-Mail:		hover@hust.edu.cn
 * GitHub:		HoverWings
 * Description:	The implementation of QUEUE 
 */
#include "lab4.h"
#include <iostream>
#include <cmath>
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
//判断素数，是素数返回true
bool is_prime(int n)
{
	for(int i=2; i<=sqrt(n); i++)
	{
        if(n%i == 0)
		{
            cout << n << " isn't a prime" << endl;
            return false;
        }
    }
    return true;
}


int dance_main(int argc, char *argv[])
{
	//male and female num
	int M = 0, F = 0;

	//male and female queue
	QUEUE *que_m=nullptr;
	QUEUE *que_f=nullptr;

	//male and female position
	int pos_m = 0;
	int pos_f = 0;
	int count = 0;

	cout << "Please enter the amount of male: ";
	cin >> M;
	cout << "Please enter the amount of female: ";
	cin >> F;
	if (!is_prime(M))
	{
		cerr << "ERROE:the Input number (amount of male) is not prime number!" << endl;
		return -1;
	}
	if (!is_prime(F))
	{
		cerr << "ERROE:the Input number (amount of female) is not prime number!" << endl;
		return -1;
	}
	if(M==F)
	{
		cerr << "ERROE:the amount of male and the amount of female should not be same" << endl;
		return -1;
	}
	cout << "Please enter the pos of man: ";
	cin >> pos_m;
	cout << "Please enter the pos of woman: ";
	cin >> pos_f;
	if (!(pos_m <= M&&pos_f <= F))
	{
		cerr << "ERROE:the pos out of the range" << endl;
		return -1;
	}
	// new queue
	que_m = new QUEUE(M);
	que_f = new QUEUE(F);
	for (int i = 0; i < M; i++) 
	{
		(*que_m) << (i + 1);
	}
	for (int i = 0; i < F; i++) 
	{
		(*que_f) << (i + 1);
	}
	int out_m=0;
	int out_f=0;
	for (int i = 0;; i++) 
		{
			count++;
			(*que_m)>>out_m;
			(*que_f)>>out_f;
			if (out_m == pos_m&&out_f == pos_f) 
			{
				cout << "They will dance with each other at Music No." << count << endl;
				delete que_m;
				delete que_f;
				que_m=nullptr;
				que_f=nullptr;
				return 0;
			}
			(*que_m) << out_m;
			(*que_f) << out_f;
		}
}

//Impletation QUEUE Fun
QUEUE::QUEUE(int m): STACK(m), s2(m)
{

}

QUEUE::QUEUE(const QUEUE &q): STACK(q), s2(q.s2)
{

}

int QUEUE::size() const 
{
    return STACK::size();
}

QUEUE::operator int(void) const 
{
    return STACK::operator int() + (int)s2;
}

int QUEUE::operator[](int x) const 
{
//	assert(0<=x&&x<=int(*this)-1);
	if(0<=STACK::operator int()&&STACK::operator int()<=STACK::size()-1&&s2.empty()) //state 1
	{

		if(x<=STACK::operator int())
		{
			return STACK::operator [](x);
		}
	}
	if(0==STACK::operator int()&&s2.full()) //state 2
	{
		if(x<=int(s2))
		{
			return s2[s2.getpos()-x-1];
		}
		else
        {
            return STACK::operator [](x-int(s2));
        }
	}
	if(1<=STACK::operator int()&&STACK::operator int()<=STACK::size()&&1<=int(s2)&&int(s2)<=STACK::size()) //state 3
	{
        if(x<=int(s2)-1)
        {
            return s2[s2.getpos()-x-1];
        }
        else
        {
            return STACK::operator [](x-int(s2));
        }
	}
    if(STACK::full()&&1<=int(s2)&&int(s2)<=s2.size()) //state 4
	{
		if(x<=int(s2))
		{
			return s2[s2.getpos()-x-1];
		}
		else
		{
			return STACK::operator [](x-int(s2));
		}
	}
}

QUEUE& QUEUE::operator<<(int e) 
{
	debug("s1:%d",STACK::operator int());
	debug("s2:%d",int(s2));
	debug("insert:%d",e);
    // // full check
    // if (this->size() <= (int)(*this)) return *this;
	if(0<=STACK::operator int()&&STACK::operator int()<=STACK::size()-1&&int(s2)==0) //state 1
	{
	    debug("state 1");
		STACK::operator <<(e); // s1 full
		if(STACK::full())
		{
			stack_dump_to_s2();
//            stack_dump_to_s2(); // to state 2
			debug("s1:%d",STACK::operator int());
			debug("s2:%d",int(s2));
			return *this;
		}
		debug("s1:%d",STACK::operator int());
		debug("s2:%d",int(s2));
		return *this;
	}
	if(0==STACK::operator int()&&s2.full()) //state 2
	{
        debug("state 2");
		STACK::operator <<(e); // to state 3
		debug("s1:%d",STACK::operator int());
		debug("s2:%d",int(s2));
		return *this;
	}
	if(1<=STACK::operator int()&&STACK::operator int()<=STACK::size()-1&&1<=int(s2)&&int(s2)<=s2.size()) //state 3
	{
        debug("state 3");
		STACK::operator <<(e);
		debug("s1:%d",STACK::operator int());
		debug("s2:%d",int(s2));
		if(STACK::full())
		{
			//to state 4
			return *this;
		}
		return *this;
	}
    if(STACK::full()&&1<=int(s2)&&int(s2)<=s2.size()) //state 4
	{
        debug("state 4");
		return *this;
	}
	cout<<"error!";
    return *this;
}


QUEUE& QUEUE::operator>>(int &e) 
{
	debug("s1:%d",STACK::operator int());
	debug("s2:%d",int(s2));
	if(0<=STACK::operator int()&&STACK::operator int()<=STACK::size()-1&&s2.empty()) //state 1
	{
		debug("state 1");
		stack_dump_to_s2();
		s2>>e;
		stack_dump_to_s1();// to state 1 
	}
	if(0==STACK::operator int()&&s2.full()) //state 2
	{
		s2>>e; // to state 1
		stack_dump_to_s1();
		return *this;
	}
	if(1<=STACK::operator int()&&STACK::operator int()<=STACK::size()&&1<=int(s2)&&int(s2)<=STACK::size()) //state 3
	{
		s2>>e;
		if(s2.empty())
		{
			if(0<=STACK::operator int()&&STACK::operator int()<=STACK::size()-1) //to state 1 
			{

			}
			if(STACK::full()) //to state 2
			{
				stack_dump_to_s2();
			}
		}
		return *this;
	}
    if(STACK::full()&&1<=int(s2)&&int(s2)<=s2.size()) //state 4
	{
		s2>>e;
		if(s2.empty())	// to state 1 
		{
			stack_dump_to_s2();
		}
		return *this;
	}
    return *this;
}

int QUEUE::full() const 
{
	// if(STACK::full()&&1<=int(s2)&&int(s2)<=s2.size())
	// {
	// 	return 1;
	// }
	// else
	// {
	// 	return 0;
	// }
	if(0<=int(*this)&&int(*this)<=this->size()-1&&s2.empty()) //state 1
	{
		return false;
	}
	if(0==int(*this)&&s2.full()) //state 2
	{
		return false;
	}
	if(1<=int(*this)&&int(*this)<=this->size()&&1<=int(s2)&&int(s2)<=this->size()) //state 3
	{
		return false;
	}
	if(this->full()&&1<=int(s2)&&int(s2)<=s2.size()) //state 4
	{
		return true;
	}
}

QUEUE& QUEUE::operator=(const QUEUE &q) 
{
    this->~QUEUE();
    new (this) QUEUE(q);
    return *this;
}

int QUEUE::operator==(const QUEUE &q) const
{
	// size or pos should equal
	if (this->size() != q.size() || (int)(*this) != (int)q) 
		return 0;
	// every single element should equal
	for (int i = 0; i < (int)(*this); i++)
	{
		if ((*this)[i] != q[i]) return 0;
	}

	return 1;
}

void QUEUE::print() const 
{
    for (int i = 0; i < (int)(*this); i++) 
	{
        cout<<"  "<<(*this)[i];
    }
    // cout<<"\n";
}

QUEUE::~QUEUE() 
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



void QUEUE::stack_dump_to_s2()
{
    if (STACK::operator int() <= s2.size()-int(s2))
    {
        int elem;
        while (STACK::operator int())
        {
            STACK::operator >>(elem);
            s2<<elem;
        }
    }
}

void QUEUE::stack_dump_to_s1()
{
    if (int(s2)<= STACK::size()-STACK::operator int())
    {
        int elem;
        while ((int)s2)
        {
            s2>>elem;
            STACK::operator <<(elem);
        }
    }
}






