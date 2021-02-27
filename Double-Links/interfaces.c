#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "structs.h"
#include "interfaces.h"

/* The Deque interfaces are implemented assuming double links are the base data structure. */
/* --------------------------------------------
 *
 *                    DEQUE
 * 
 * --------------------------------------------
 */

void initDeque(struct Deque* dq)
{
  struct DLink* senFront;
  struct DLink* senBack;

  assert(dq);

  dq->size = 0;

  senFront = (struct DLink*) malloc(sizeof(struct DLink));
  senBack = (struct DLink*) malloc(sizeof(struct DLink));

  assert(senFront);
  assert(senBack);

  dq->head = senFront;
  dq->tail = senBack;

  dq->head->next = dq->tail;
  dq->tail->prev = dq->head;

  dq->head->prev = NULL;
  dq->tail->next = NULL;
}

void freeDeque(struct Deque* dq)
{
  struct DLink* curr, * temp;

  assert(dq);

  curr = dq->head;

  while (curr)
  {
    temp = curr;

    curr = curr->next;

    free(temp);
  }

}

void addFrontDeque(struct Deque* dq, TYPE val)
{
  struct DLink* dLink;

  assert(dq);

  dLink = (struct DLink*) malloc(sizeof(struct DLink));

  assert(dLink);

  dLink->val = val;
  dLink->next = dq->head->next;
  dLink->prev = dq->head;
  
  dLink->next->prev = dLink;
  dq->head->next = dLink;

  dq->size++;
}

void addBackDeque(struct Deque* dq, TYPE val)
{
  struct DLink* dLink;

  assert(dq);

  dLink = (struct DLink*) malloc(sizeof(struct DLink));

  assert(dLink);

  dLink->val = val;
  dLink->next = dq->tail;
  dLink->prev = dq->tail->prev;
  
  dLink->prev->next = dLink;
  dq->tail->prev = dLink;

  dq->size++;
}

void printDeque(struct Deque* dq)
{
  int count = 0;
  struct DLink* curr;

  assert(dq);

  printf("Front to Back:\n\n");

  curr = dq->head->next;

  while (curr && (curr != dq->tail))
  {
    count++;

    printf("- Link %d: { %d }\n", count, curr->val);

    curr = curr->next;
  }

  /*
  printf("\nBack to Front:\n\n");

  curr = dq->tail->prev;

  while (curr && (curr != dq->head))
  {
    printf("- Link %d: { %d }\n", count, curr->val);

    curr = curr->prev;

    count--;
  }
  */
 
}

void removeFront(struct Deque* dq)
{
  struct DLink* rmv;

  assert(dq);

  if ( isEmptyDeque(dq) )
  {
    return;
  }
  else
  {
    rmv = dq->head->next;

    dq->head->next = rmv->next;
    rmv->next->prev = dq->head;

    free(rmv);

    dq->size--;
  }
    
}

void removeBack(struct Deque* dq)
{
  struct DLink* rmv;

  assert(dq);

  if ( isEmptyDeque(dq) )
  {
    return;
  }
  else
  {
    rmv = dq->tail->prev;

    dq->tail->prev = rmv->prev;
    rmv->prev->next = dq->tail;

    free(rmv);

    dq->size--;
  }

}

int isEmptyDeque(struct Deque* dq)
{
  assert(dq);

  if (dq->size == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }

}

TYPE front(struct Deque* dq)
{
  TYPE returnVal = NULL;

  assert(dq);

  if ( isEmptyDeque(dq) )
  {
    return returnVal;
  }
  else
  {
    returnVal = (TYPE) dq->head->next->val;

    return returnVal;
  }

}

TYPE back(struct Deque* dq)
{
  TYPE returnVal = NULL;

  assert(dq);

  if ( isEmptyDeque(dq) )
  {
    return returnVal;
  }
  else
  {
    returnVal = (TYPE) dq->tail->prev->val;

    return returnVal;
  }

}

/* --------------------------------------------
 *
 *                  END DEQUE
 * 
 * --------------------------------------------
 */

/*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*/

/* --------------------------------------------
 *
 *                   QUEUE
 * 
 * --------------------------------------------
 */

void initQueue(struct Queue* q)
{
  struct Link* senFront;

  assert(q);

  q->size = 0;

  senFront = (struct Link*) malloc(sizeof(struct Link));

  assert(senFront);

  senFront->next = NULL;

  q->head = senFront;
  q->tail = senFront;
}

void freeQueue(struct Queue* q)
{
  struct Link* curr, * temp;

  assert(q);

  curr = q->head;

  while (curr)
  {
    temp = curr;

    curr = curr->next;

    free(temp);
  }

}

void addQueue(struct Queue* q, TYPE val)
{
  struct Link* link;

  assert(q);

  link = (struct Link*) malloc(sizeof(struct Link));

  assert(link);

  link->val = val;
  link->next = NULL;

  q->tail->next = link;
  q->tail = link;

  q->size++;
}

void printQueue(struct Queue* q)
{
  struct Link* curr;
  int count = 0;

  assert(q);

  printf("Front to Back:\n\n");

  curr = q->head->next;

  while (curr)
  {
    count++;

    printf("- Link %d: { %d }\n", count, curr->val);

    curr = curr->next;
  }
  
}

void removeQueue(struct Queue* q)
{
  struct Link* curr;

  assert(q);

  if ( isEmptyQueue(q) )
  {
    return;
  }
  else
  {
    curr = q->head->next;

    q->head->next = curr->next;

    if (curr == q->tail)
      q->tail = q->head;

    free(curr);

    q->size--;
  }
  
}

int isEmptyQueue(struct Queue* q)
{
  assert(q);

  if (q->size == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }

}

TYPE frontQueue(struct Queue* q)
{
  TYPE returnVal = NULL;

  assert(q);

  if ( isEmptyQueue(q) )
  {
    return returnVal;
  }
  else
  {
    returnVal = (TYPE) q->head->next->val;

    return returnVal;
  }

}

/* --------------------------------------------
 *
 *                  END QUEUE
 * 
 * --------------------------------------------
 */

/*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*/

/* --------------------------------------------
 *
 *                    STACK
 * 
 * --------------------------------------------
 */

void initStack(struct Stack* s)
{
  /* No sentinel in Stack */

  assert(s);

  s->size = 0;

  s->head = NULL;
}

void freeStack(struct Stack* s)
{
  assert(s);

  while ( !isEmptyStack(s) )
  {
    popStack(s);
  }
  
}

int isEmptyStack(struct Stack* s)
{
  assert(s);

  if (s->size == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
  
}

void pushStack(struct Stack* s, TYPE val)
{
  struct Link* link;

  assert(s);

  link = (struct Link*) malloc(sizeof(struct Link));

  link->val = val;
  link->next = s->head;

  s->head = link;

  s->size++;
}

TYPE popStack(struct Stack* s)
{
  struct Link* pop;
  TYPE returnVal = NULL;

  assert(s);

  if ( isEmptyStack(s) )
  {
    return returnVal;
  }
  else
  {
    pop = s->head;

    returnVal = (TYPE) pop->val;

    s->head = pop->next;

    free(pop);

    s->size--;

    return returnVal;
  }
  
}

TYPE peepStack(struct Stack* s)
{
  TYPE returnVal = NULL;

  assert(s);

  if ( isEmptyStack(s) )
  {
    return returnVal;
  }
  else
  {
    returnVal = s->head->val;

    return returnVal;
  }
  
}

/* --------------------------------------------
 *
 *                  END STACK
 * 
 * --------------------------------------------
 */