#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "structs.h"
#include "interfaces.h"

/* The following interfaces are implemented assuming double links are the base data structure. */

void initDeque(struct Deque* dq)
{
  assert(dq);

  dq->size = 0;

  struct DLink* senFront = (struct DLink*) malloc(sizeof(struct DLink));
  struct DLink* senBack = (struct DLink*) malloc(sizeof(struct DLink));

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
  assert(dq);

  struct DLink* curr, * temp;

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
  assert(dq);

  struct DLink* dLink = (struct DLink*) malloc(sizeof(struct DLink));

  assert(dLink);

  dLink->val = val;
  dLink->next = dq->head->next;
  dLink->prev = dq->head;
  
  dLink->next->prev = dLink;
  dq->head->next = dLink;
}

void addBackDeque(struct Deque* dq, TYPE val)
{
  assert(dq);

  struct DLink* dLink = (struct DLink*) malloc(sizeof(struct DLink));

  assert(dLink);

  dLink->val = val;
  dLink->next = dq->tail;
  dLink->prev = dq->tail->prev;
  
  dLink->prev->next = dLink;
  dq->tail->prev = dLink;
}

void printDeque(struct Deque* dq)
{
  assert(dq);

  int count = 0;
  struct DLink* curr;

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
  assert(dq);

  struct DLink* rmv;

  if ( isEmpty(dq) )
    return;
  
  rmv = dq->head->next;

  dq->head->next = rmv->next;
  rmv->next->prev = dq->head;

  free(rmv);
}

void removeBack(struct Deque* dq)
{
  assert(dq);

  struct DLink* rmv;

  if ( isEmpty(dq) )
    return;
  
  rmv = dq->tail->prev;

  dq->tail->prev = rmv->prev;
  rmv->prev->next = dq->tail;

  free(rmv);
}

int isEmpty(struct Deque* dq)
{
  assert(dq);

  if ((dq->head->next == dq->tail) && (dq->tail->prev == dq->head))
  {
    return 1;
  }

  return 0;
  
}

TYPE front(struct Deque* dq)
{
  TYPE returnVal = NULL;

  if ( isEmpty(dq) )
    return returnVal;

  returnVal = (TYPE) dq->head->next->val;

  return returnVal;
  
}

TYPE back(struct Deque* dq)
{
  TYPE returnVal = NULL;

  if ( isEmpty(dq) )
    return returnVal;

  returnVal = (TYPE) dq->tail->prev->val;

  return returnVal;
  
}