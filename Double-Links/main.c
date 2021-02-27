#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "interfaces.h"


int main(int argc, char const *argv[])
{
  struct Deque dq;
  struct Queue q;
  FILE* file;
  const char* fileName;
  int val;

  int quantity = 25;

  if (argc == 2)
  {
    fileName = argv[1];
  }
  else
  {
    fileName = "input.txt";
  } 

  file = fopen(fileName,"r");

  printf("\n--------------------------------------------\n");

  printf("\nHello! I'm here to generate simple visualizations of some basic data structures:\n");
  printf("- Deques\n- Queues\n- Stacks\n\n");

  /* --------------------------------------------
   *
   *                    DEQUE
   * 
   * --------------------------------------------
   */

  printf("Here are some Deque operations:\n\n");

  initDeque(&dq);

  printf("isEmpty: %d\n\n", isEmptyDeque(&dq));

  printf("Adding values from %s...\n\n", fileName);

  while ( !feof(file) && (quantity > 0) )
  {
    fscanf(file, "%d", &val);

    addFrontDeque(&dq, val);

    quantity--;
  }

  printf("isEmpty: %d\n\n", isEmptyDeque(&dq));

  printDeque(&dq);

  printf("\n");

  printf("- Link-front: { %d }\n", front(&dq));

  printf("- Link-back:  { %d }\n", back(&dq));

  freeDeque(&dq);

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

  quantity = 25;

  printf("\n");

  printf("Here are some Queue operations:\n\n");

  initQueue(&q);

  printf("isEmpty: %d\n\n", isEmptyQueue(&q));

  printf("Adding values from %s...\n\n", fileName);

  while ( !feof(file) && (quantity > 0) )
  {
    fscanf(file, "%d", &val);

    addQueue(&q, val);

    quantity--;
  }

  printf("isEmpty: %d\n\n", isEmptyQueue(&q));

  printQueue(&q);

  printf("\n");

  printf("- Link-front: { %d }\n", frontQueue(&q));

  freeQueue(&q);

  /* --------------------------------------------
   *
   *                  END QUEUE
   * 
   * --------------------------------------------
   */

  printf("\n--------------------------------------------\n");

  fclose(file);
  
  return 0;
}
