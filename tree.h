#ifndef _tree_h
#define _tree_h

typedef struct Node *Tree;

extern Tree zero_child_tree(char x);
extern Tree one_child_tree(char x, Tree t);
extern Tree two_child_tree(char x, Tree t1, Tree t2);
extern Tree three_child_tree(char  x, Tree t1, Tree t2, Tree t3);
extern char* production_str(char c);
extern void print_tree(Tree root, int ind);

#endif