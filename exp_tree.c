#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tree.h"
#include "exp_tree.h"
#include "rd_parse.h"

int is_terminal(char x);
int is_char(char c);

typedef struct exp_tree_node {
  char data;
  struct exp_tree_node *left, *right;
} exp_tree_node;

typedef struct Node *Tree;

struct Node {
  char info;
  Tree leftmost_child, right_sibling;
};

char *result = "";
int n_parens = 0;

char* ch_to_str(char c) {
	switch(c) {
		case 'a': return "ATOMIC a"; break;
    case 'b': return "ATOMIC b"; break;
		case 'c': return "ATOMIC c"; break;
		case 'd': return "ATOMIC d"; break;
		case 'e': return "ATOMIC e"; break;
		case 'f': return "ATOMIC f"; break;
		case 'g': return "ATOMIC g"; break;
		case 'h': return "ATOMIC h"; break;
		case 'i': return "ATOMIC i"; break;
		case 'j': return "ATOMIC j"; break;
		case 'k': return "ATOMIC k"; break;
		case 'l': return "ATOMIC l"; break;
		case 'm': return "ATOMIC m"; break;
		case 'n': return "ATOMIC n"; break;
		case 'o': return "ATOMIC o"; break;
		case 'p': return "ATOMIC p"; break;
		case 'q': return "ATOMIC q)"; break;
		case 'r': return "ATOMIC r"; break;
		case 's': return "ATOMIC s"; break;
		case 't': return "ATOMIC t"; break;
		case 'u': return "ATOMIC u"; break;
		case 'v': return "ATOMIC v"; break;
		case 'w': return "ATOMIC w"; break;
		case 'x': return "ATOMIC x"; break;
		case 'y': return "ATOMIC y"; break;
		case 'z': return "ATOMIC z"; break;
    case '|': return "UNION"; break;
		case '*': return "CLOSURE"; break;
		case '.': return "CONCAT"; break;
		default: return ""; break;
	}
}

char *add(exp_tree_node **node, char *s) {
  if (*s == '\0') return "\0";
  while (1) {
    char *q = "null";
    if (*node == NULL) {
      exp_tree_node *new_node = (exp_tree_node*)malloc(sizeof(exp_tree_node));
      new_node->data = *s;
      new_node->left = NULL;
      new_node->right = NULL;
      *node = new_node;
    } else {
      if (is_char(*s) == 0) return s;
      q = add(&(*node)->left, s + 1);
      q = add(&(*node)->right, q + 1);
      return q;
    }
  }
}

void infix_exp(exp_tree_node* node) {
  if (node == NULL) {
    return; 
  } else { 
    infix_exp(node->left); 
    printf("(");
    printf("%s", ch_to_str(node->data)); 
    if (is_char(node->data)) {
      printf(")");
    } else {
      n_parens++;
    }
    infix_exp(node->right); 
  } 
}

void strcat_c(char *str, char c){
  size_t len = strlen(str);
  char *str2 = malloc(len + 1 + 1 );
  strcpy(str2, str);
  str2[len] = c;
  str2[len + 1] = '\0';
  result = str2;
}

void yield_traversal(Tree t) {
	if (t == NULL) return; 
  yield_traversal(t->leftmost_child); 
  if (is_terminal(t->info) == 1) {
    strcat_c(result, t->info);
  }
	if (t->leftmost_child != NULL) {
		if (t->leftmost_child->right_sibling != NULL)
			yield_traversal(t->leftmost_child->right_sibling);
	}
}

void get_exp(Tree t) {
  exp_tree_node* root = NULL;
  yield_traversal(t);
  add(&root, result);
  infix_exp(root);
  while(n_parens != 0) {
    printf(")");
    n_parens--;
  }
}