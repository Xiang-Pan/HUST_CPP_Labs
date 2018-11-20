#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/// @brief the stack structure
typedef struct STACK 
{
	int *elems; //申请内存用于存放栈的元素
	int max;    //栈能存放的最大元素个数
	int pos;    //栈实际已有元素个数，栈空时pos=0
}STACK;

//Helper Function
int stack_main(int argc, char *argv[]);

// Stack Function


/// @brief initialize stack with size
/// @param[in] p the stack pointer
/// @param[in] m the size of the stack
void initSTACK(STACK *const p, int m);				//初始化p指向的栈：最多m个元素

/// @brief initialize a stack with another stack
/// @param[in] p the stack pointer to initialize
/// @param[in] s the stack to copy
void initSTACK(STACK *const p, const STACK&s); 		//用栈s初始化p指向的栈

/// @brief return the capacity of the stack
/// @param[in] p the stack pointer
/// @return the capacity of the stack
int  size (const STACK *const p);					//返回p指向的栈的最大元素个数max


/// @brief return the element number of the stack
/// @param[in] p the stack pointer
/// @return the element number of the stack
int  howMany (const STACK *const p);				//返回p指向的栈的实际元素个数pos

/// @brief get the element from the stack
/// @param[in] p the stack pointer
/// @param[in] x the index of the element
/// @return the element
int  getelem (const STACK *const p, int x);			//取下标x处的栈元素

/// @brief push an element to a stack
/// @param[in] p the the stack pointer
/// @param[in] e the element to push
/// @return the stack pointer
STACK *const push(STACK *const p, int e); 			//将e入栈，并返回p

/// @brief pop an element from a stack
/// @param[in]  p the stack pointer
/// @param[out] e the element to pop
/// @return the stack pointer
STACK *const pop(STACK *const p, int &e); 			//出栈到e，并返回p


/// @brief assign the elements in s to elements in p
/// @param[in] p the stack to assign
/// @param[in] s the stack to copy from
/// @return the stack after assigned
STACK *const assign(STACK*const p, const STACK&s);  //赋s给p指的栈,并返回p

/// @brief print elements in stack
/// @param[in] p the stack pointer
void print(const STACK*const p);					//打印p指向的栈


/// @brief de-construct the stack
/// @param[in] p the stack pointer
void destroySTACK(STACK*const p);					//销毁p指向的栈