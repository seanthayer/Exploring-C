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

int containsBST(struct BST* tree, TYPE val)
{
  assert(tree);
  
  if ( isEmptyBST(tree) )
  {
    return 0;
  }
  else
  {
    return _containsNode(tree->root, val);
  }
  
}

void addBST(struct BST* tree, TYPE val)
{
  assert(tree);

  tree->root = _addNode(tree->root, val);

  tree->size++;
}

void removeBST(struct BST* tree, TYPE val)
{
  assert(tree);

  if ( containsBST(tree, val) )
  {
    tree->root = _removeNode(tree->root, val);

    tree->size--;
  }
  
}

void printBST(struct BST* tree)
{
  assert(tree);

  _printInOrder(tree->root);
}

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

struct Node* _removeNode(struct Node* curr, TYPE val)
{
  struct Node* node;

  if ( EQ(val, curr->val) )
  {

    if (curr->right == NULL)
    {
      node = curr->left;

      free(curr);

      return node;
    }
    else
    {
      /* Finding leftmost descendant of the right child */
      /* { */
      node = curr->right;

      while (node->left)
      {
        node = node->left;
      }
      /* } */

      curr->val = node->val;
      curr->right = _removeLeftmost(curr->right);

    }
    
  }
  else
  {

    if ( LT(val, curr->val) )
    {
      curr->left = _removeNode(curr->left, val);
    }
    else
    {
      curr->right = _removeNode(curr->right, val);
    }

  }

  return curr;
}

struct Node* _removeLeftmost(struct Node* curr)
{
  struct Node* node;

  if(curr->left)
  {
    curr->left = _removeLeftmost(curr->left);

    return curr;
  }
  else
  {
    node = curr->right;

    free(curr);

    return node;
  }

}

int _containsNode(struct Node* curr, TYPE val)
{
  int flag = 0;

  if ( EQ(val, curr->val) )
  {
    flag = 1;
  }
  else if (curr != NULL)
  {
    
    if ( LT(val, curr->val) && curr->left)
    {
      flag = _containsNode(curr->left, val);
    }
    else if (curr->right)
    {
      flag = _containsNode(curr->right, val);
    }

  }
  
  return flag;
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