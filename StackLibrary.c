#include "StackLibrary.h"
#include <stdio.h>
#include <stdlib.h>

Stack createStack(void){
	LinkedList *list=calloc(sizeof(LinkedList),1);
	Stack stack={list,&list->tail};
	return stack;
};

int push(Stack stack, void *data){
	Node_ptr node = create_node(data);
	add_to_list(stack.list, node);
	if(stack.list->count == 0) return -1;
	return stack.list->count;
};