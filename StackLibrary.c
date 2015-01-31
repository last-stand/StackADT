#include "StackLibrary.h"
#include <stdio.h>

Stack createStack(void){
	Stack stack;
	LinkedList list = createList();
	stack.list = &list;
	stack.top = NULL;
	return stack;
};