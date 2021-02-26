#include "structs.h"

#ifndef __INTERFACES_H
#define __INTERFACES_H

void initDeque(struct Deque* dq);
void freeDeque(struct Deque* dq);
void addFrontDeque(struct Deque* dq, TYPE val);
void addBackDeque(struct Deque* dq, TYPE val);
void printDeque(struct Deque* dq);
void removeFront(struct Deque* dq);
void removeBack(struct Deque* dq);
int isEmpty(struct Deque* dq);
TYPE front(struct Deque* dq);
TYPE back(struct Deque* dq);

#endif