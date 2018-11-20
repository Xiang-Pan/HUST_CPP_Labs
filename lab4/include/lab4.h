#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "my_debug.h"
#include "lab2.h"
int queue_main(int argc, char *argv[]);
int dance_main(int argc, char *argv[]);
class QUEUE:public STACK
{
    STACK s2;
    public:
    QUEUE(int m);                           //每个栈最多m个元素，要求实现的队列最多能入2m个元素
    QUEUE(const QUEUE&s); 			        //用队列s拷贝初始化队列
    virtual operator int ( ) const;			//返回队列的实际元素个数
    virtual int full () const;		        //返回队列是否已满，满返回1，否则返回0
    virtual int size(void) const;           //max size
    virtual int operator[ ](int x)const;    //取下标为x的元素，第1个元素下标为0
    virtual QUEUE& operator<<(int e);       //将e入队列,并返回队列
    virtual QUEUE& operator>>(int &e);	    //出队列到e,并返回队列
    virtual QUEUE& operator=(const QUEUE&s);//赋s给队列,并返回被赋值的队列
    virtual int operator==(const QUEUE &q) const;
    virtual void print( ) const;			//打印队列
    virtual ~QUEUE( );					    //销毁队列
    private:
	void stack_dump(STACK& src,STACK& dst);			//两个栈之间执行出入栈转换
    void stack_dump_to_s1();
    void stack_dump_to_s2();
};