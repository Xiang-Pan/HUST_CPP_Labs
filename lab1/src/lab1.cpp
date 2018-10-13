#include "lab1.h"
#include "my_debug.h"
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

int stack_main(int argc, char *argv[]) 
{
	int num;//元素个数&&入栈数字
	int out;//接受出栈元素
	STACK *p = (STACK *)malloc(sizeof(STACK));
	STACK *s = (STACK *)malloc(sizeof(STACK));
	STACK *ss;
	int ch;
	bool fail=false;
	while ((ch = getopt(argc, argv, "S:I:O:CA:NG:")) != -1)
	{
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
				initSTACK(p, num);
				break;
			case 'I':
				debug("HAVE option: -I"); 
				debug("The argument of -I is %s", optarg);
				num=atoi(optarg);
				debug("%d",num);
				if(p->pos==p->max)
				{
					printf("  I");
					printf("  E");
					break;
				}
				p = push(p, num);
				// debug(argv[optind][0]);
				while(isdigit(argv[optind][0]))
				{
					num=atoi(argv[optind]);
					debug("%d",num);
					if(p->pos==p->max)
					{
						printf("  I");
						printf("  E");
						fail=true;
						break;
					}
					p = push(p, num);
					optind++;
					if(optind==argc)
					{
						break;
					}
				}
				printf("  I");
				if(fail)
				{
					printf("  E");
				}
				else
				{
					print(p);
				}
				break;
			case 'O':
				debug("HAVE option: -O");
				debug("The argument of -O is %s", optarg);
				num=atoi(optarg);
				debug("%d",num);
				for (int j = 0; j < num; j++)
				{
					if (p->pos == 0)
					{
						printf("  E");
						exit(0);
					}
					p = pop(p, out);
				}
				printf("  O");
				print(p);
				break;
			case 'C':
				debug("HAVE option: -C");
				printf("  C");
				ss = (STACK *)malloc(sizeof(STACK));
				initSTACK(ss, *p);
				destroySTACK(p);
				p = ss;
				print(p);
				break;
			case 'A':
				debug("HAVE option: -A");
				debug("The argument of -A is %s", optarg);
				num=atoi(optarg);
				printf("  A");
				initSTACK(s, num);
				s = assign(s, *p);	//将栈p赋值给新栈s
				destroySTACK(p);	//销毁旧栈
				p = s;
				print(p);			//打印当前栈
				break;
			case 'N':
				debug("HAVE option: -N");
				printf("  N");
				printf("  %d", howMany(p));
				break;
			case 'G':
				debug("HAVE option: -G");
				debug("The argument of -G is %s", optarg);
				num=atoi(optarg);
				printf("  G");
				printf("  %d", getelem(p,num));
				break;
			default:
				debug("Unknown option: %c",(char)optopt);
				break;
			}
	}
}

//Impletation Stack Fun

//Overload
//D:初始化p指向的栈：最多m个元素
void initSTACK(STACK *const p, int m)
{
	p->elems = (int *)malloc(m * sizeof(int));
	p->max = m;
	p->pos = 0;
}

//D:用栈s初始化p指向的栈
void initSTACK(STACK *const p, const STACK &s)
{
	p->elems = (int *)malloc(s.max * sizeof(int));
	for (int j = 0; j < s.pos; j++)
		p->elems[j] = s.elems[j];
	p->max = s.max;
	p->pos = s.pos;
}
//D:返回p指向的栈的最大元素个数max
int size(const STACK *const p)
{
	return p->max;
}

//D:返回p指向的栈的实际元素个数pos
int howMany(const STACK *const p)
{
	return p->pos;
}

//D:取下标x处的栈元素
int getelem(const STACK *const p, int x)
{
	return p->elems[x];
}

//D:将e入栈，并返回p
STACK *const push(STACK *const p, int e)
{
	p->elems[(p->pos)++] = e;
	return p;
}

//D:出栈到e，并返回p
STACK *const pop(STACK *const p, int &e)
{
	e = p->elems[--(p->pos)];
	return p;
}

//D:赋s给p指的栈，并返回p
STACK *const assign(STACK *const p, const STACK &s)
{
	free(p->elems);
	p->elems = (int *)malloc(s.max * sizeof(int));
	for (int j = 0; j < s.pos; j++)
		p->elems[j] = s.elems[j];
	p->max = s.max;
	p->pos = s.pos;
	return p;
}

//D:打印p指向的栈
void print(const STACK *const p)
{
	for (int j = 0; j < p->pos; j++)
	{
		printf("  %d", p->elems[j]);
	}
}

//D:销毁p指向的栈
void destroySTACK(STACK *const p)
{
	free(p->elems);
	free(p);
}

//D:将char转换为int,返回一个整数
int atoi_my(char *str)
{
	int s = 0;
	bool flag = false;
	while (*str == ' ') { str++; }
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = true;
		str++;
	}
	while (*str >= '0'&& *str <= '9')
	{
		s = s * 10 + *str - '0';
		str++;
		if (s < 0) {
			s = 2147483647;
			break;
		}
	}
	return s*(flag ? -1 : 1);
}




