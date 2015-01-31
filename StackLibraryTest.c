#include <stdio.h>
#include "StackLibrary.h"
#include "expr_assert.h"

Stack stack;
void test_createStack_should_create_an_empty_stack(){
	stack = createStack();
	assert(stack.list->head == NULL);
	assert(stack.list->tail == NULL);
}

void test_createStack_should_create_stack_with_no_element_in_it(){
	stack = createStack();
	assert(stack.list->count == 0); 
}

void test_createStack_should_create_stack_and_set_top_to_NULL(){
	stack = createStack();
	assert(stack.top == NULL); 
}