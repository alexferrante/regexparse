#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

typedef struct Node *Tree;

struct Node {
  char info;
  Tree leftmost_child, right_sibling;
};

Tree zero_child_tree(char x) {
  Tree root;
  root = (Tree) malloc(sizeof(struct Node));
  root->info = x;
  root->leftmost_child = NULL;
  root->right_sibling = NULL;
  return root;
}

Tree one_child_tree(char x, Tree t) {
  Tree root;
  root = zero_child_tree(x);
  root->leftmost_child = t;
  return root;
}

Tree two_child_tree(char x, Tree t1, Tree t2) {
  Tree root;
  t1->right_sibling = t2;
  root = one_child_tree(x, t1);
  return root;
}

Tree three_child_tree(char x, Tree t1, Tree t2, Tree t3) {
  Tree root;
  root = one_child_tree(x, t1);
  t1->right_sibling = t2;
  t2->right_sibling = t3;
  return root;
}

char* production_str(char c) {
  switch(c) {
    case 'E': return "E"; break;
    case 'T': return "ET"; break;  // ET
    case 'C': return "C"; break;
    case 'P': return "CT"; break; // CT
    case 'S': return "S"; break;
    case 'B': return "ST"; break; // ST
    case 'A': return "A"; break;
    case 'X': return "X"; break;
    case '(': return "("; break;
    case ')': return ")"; break;
    case '|': return "|"; break;
    case '.': return "."; break;
    case '*': return "*"; break;
    case '3': return "eps"; break;
    case 'a': return "a"; break;
    case 'b': return "b"; break;
    case 'c': return "c"; break;
    case 'd': return "d"; break;
    case 'e': return "e"; break;
    case 'f': return "f"; break;
    case 'g': return "g"; break;
    case 'h': return "h"; break;
    case 'i': return "i"; break;
    case 'j': return "j"; break;
    case 'k': return "k"; break;
    case 'l': return "l"; break;
    case 'm': return "m"; break;
    case 'n': return "n"; break;
    case 'o': return "o"; break;
    case 'p': return "p"; break;
    case 'q': return "q"; break;
    case 'r': return "r"; break;
    case 's': return "s"; break;
    case 't': return "t"; break;
    case 'u': return "u"; break;
    case 'v': return "v"; break;
    case 'w': return "w"; break;
    case 'x': return "x"; break;
    case 'y': return "y"; break;
    case 'z': return "z"; break;
    default: return "NUL";
  }
}

void print_tree(Tree root, int ind) {
  if (root == NULL) {
    return;
  } else {
    for (int i = 1; i <= ind; i++) {
      printf("\t");
    }
    printf("%s\n", production_str(root->info));
  }
  print_tree(root->leftmost_child, ind+1);
  print_tree(root->right_sibling, ind);
}