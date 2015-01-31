#include <stdio.h>
#include "StackLibrary.h"
#include "expr_assert.h"

void test_createStack_should_create_an_empty_stack(){
	Stack stack = createStack();
	assert(stack.head == NULL);
	assert(stack.tail == NULL); 
}

void test_createStack_should_create_stack_with_stackTop_set_to_minus_1(){
	Stack stack = createStack();
	assert(stack.count == -1); 
}