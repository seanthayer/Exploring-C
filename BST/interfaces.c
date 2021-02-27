#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "structs.h"
#include "interfaces.h"


void initBST(struct BST* tree)
{
  assert(tree);

  tree->size = 0;
  tree->root = NULL;
}

void freeBST(struct BST* tree)
{
  assert(tree);

  _freePostOrder(tree->root);
}

/*int containsBST(struct BST* tree, TYPE val);*/

void addBST(struct BST* tree, TYPE val)
{
  assert(tree);

  tree->root = _addNode(tree->root, val);

  tree->size++;
}

/*void removeBST(struct BST* tree, TYPE val);*/

void printBST(struct BST* tree)
{
  assert(tree);

  _printInOrder(tree->root);
}

/*int sizeBST(struct BST* tree);*/

int isEmptyBST(struct BST* tree)
{
  assert(tree);

  if (tree->size == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
  
}

struct Node* _addNode(struct Node* curr, TYPE val)
{
  struct Node* node;

  if (curr == NULL)
  {
    node = (struct Node*) malloc(sizeof(struct Node));

    assert(node);

    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
  }
  else
  {

    if ( LT(val, curr->val) )
    {
      curr->left = _addNode(curr->left, val);
    }
    else
    {
      curr->right = _addNode(curr->right, val);
    }

  }
  
  return curr;
}

void _printInOrder(struct Node* curr)
{

  if (curr)
  {
    _printInOrder(curr->left);
    printf("Node with value: { %d }\n", curr->val);
    _printInOrder(curr->right);
  }
  
}

void _freePostOrder(struct Node* curr)
{

  if (curr)
  {
    _freePostOrder(curr->left);
    _freePostOrder(curr->right);
    free(curr);
  }
  
}