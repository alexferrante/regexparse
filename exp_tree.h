#include "tree.h"

typedef struct exp_tree_node exp_tree_node;
extern void yield_traversal(Tree t);
extern char *add(exp_tree_node **node, char *s);
extern void infix_exp(exp_tree_node* node);
extern char *concat(char *s1,  char *s2);
extern void get_exp(Tree t);
extern void strcat_c(char *str, char c);
extern char* ch_to_str(char c);