#include <stdio.h>
#include "StackLibrary.h"
#include "expr_assert.h"
#include <string.h>

Stack stack;
void test_createStack_should_create_an_empty_stack(){
	stack = createStack();
	assert(stack.list->head == NULL);
	assert(stack.list->tail == NULL);
}

void test_createStack_should_create_stack_with_no_element_in_it(){
	stack = createStack();
	assertEqual(stack.list->count, 0); 
}

void test_createStack_should_create_stack_and_set_top_to_NULL(){
	stack = createStack();
	assert(*stack.top == NULL);
	assert(*stack.top == stack.list->tail); 
}

void test_push_should_return_number_of_pushed_elements_on_the_stack_for_INTEGER(){
	int a = 10, b = 20;
	stack = createStack();
	assertEqual(push(stack, &a), 1);
	assertEqual(push(stack, &b), 2);
}

void test_push_should_return_number_of_pushed_elements_on_the_stack_for_CHAR(){
	char a = 'a', b = 'b', c = 'c';
	stack = createStack();
	assertEqual(push(stack, &a), 1);
	assertEqual(push(stack, &b), 2);
	assertEqual(push(stack, &b), 3);
}

void test_push_pushes_three_CHAR_ARRAY_in_the_stack(){
	char first_node_data[]={'a','k','s','\0'},second_node_data[]={'q','w','e','\0'},third_node_data[]={'z','x','c','\0'};
	Stack stack = createStack();
	assertEqual(push(stack,first_node_data), 1);
	assertEqual(push(stack,second_node_data), 2);
	assertEqual(push(stack,third_node_data), 3);
	assertEqual(strcmp((char *)(stack.list->tail->data), third_node_data), 0);
	assertEqual(strcmp((char *)(*stack.top)->data, third_node_data), 0);
}

void test_push_should_push_data_reference_of_int_data_on_the_stack_for_INTEGER(){
	int a = 10, b = 20;
	stack = createStack();
	assertEqual(push(stack, &a),1);
	assertEqual(push(stack, &b),2);
	assert(*(int*)stack.list->head->data == a);
	assert(*(int*)stack.list->tail->data == b);
	assertEqual(*(int *)(*stack.top)->data, b);
}

void test_push_should_push_data_reference_of_int_data_on_the_stack_for_CHAR(){
	char a = 'a', b = 'b';
	stack = createStack();
	assertEqual(push(stack, &a),1);
	assertEqual(push(stack, &b),2);
	assert(*(char*)stack.list->head->data == a);
	assert(*(char*)stack.list->tail->data == b);
	assertEqual(*(char *)(*stack.top)->data, b);
}

void test_push_should_push_data_reference_of_int_data_on_the_stack_for_FLOAT(){
	float a = 99.12345, b = 31.242409;
	stack = createStack();
	assertEqual(push(stack, &a),1);
	assertEqual(push(stack, &b),2);
	assert(*(float*)stack.list->head->data == a);
	assert(*(float*)stack.list->tail->data == b);
	assertEqual(*(float *)(*stack.top)->data, b);
}

void test_push_should_push_data_reference_of_int_data_on_the_stack_for_DOUBLE(){
	double a = 99.12345, b = 31.242409;
	stack = createStack();
	assertEqual(push(stack, &a),1);
	assertEqual(push(stack, &b),2);
	assert(*(double*)stack.list->head->data == a);
	assert(*(double*)stack.list->tail->data == b);
	assertEqual(*(double *)(*stack.top)->data, b);
}

void test_push_should_push_data_reference_of_int_data_on_the_stack_for_STRING(){
	char *a = "Age of Empires", b[] = "Call of Duty";
	stack = createStack();
	assertEqual(push(stack, a), 1);
	assertEqual(push(stack, b), 2);
	assert((char*)stack.list->head->data == a);
	assert((char*)stack.list->tail->data == b);
	assertEqual(strcmp((char *)(*stack.top)->data, b), 0);
}

void test_top_should_point_to_the_latest_pushed_element_on_stack_for_STRING(){
	char a[] = "Age of Empires", b[] = "Call of Duty", c[] = "Prince of Persia";
	stack = createStack();
	assertEqual(push(stack, a), 1);
	assertEqual(push(stack, b), 2);
	assertEqual(push(stack, c), 3);
	assertEqual(strcmp((char *)(*stack.top)->data, c), 0);
}

void test_top_should_point_to_the_latest_pushed_element_on_stack_for_STRUCTURE(){
	Employee a = {1,"Jai"}, b = {2,"Ram"}, c = {3,"Jiya"};
	stack = createStack();
	assertEqual(push(stack, &a), 1);
	assertEqual(push(stack, &b), 2);
	assertEqual(push(stack, &c), 3);
	assert((*stack.top)->data == &c);
	assertEqual(((Employee*)(*stack.top)->data)->id, 3);
	assertEqual(strcmp(((Employee*)(*stack.top)->data)->name, c.name),0);
}