#include "StackLibrary.h"
#include "expr_assert.h"

Stack createStack(void){
	Stack stack = createList();
	stack.count = -1;
	return stack;
};