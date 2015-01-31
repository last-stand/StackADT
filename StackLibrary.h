#include "linkedList.h"

typedef struct list Stack;
typedef struct list *Stack_ptr;
Stack createStack(void);
int push(Stack, void *);
void * pop(Stack );