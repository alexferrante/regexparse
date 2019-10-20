#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "rd_parse.h"
#include "tree.h"
#define FAIL NULL

typedef struct Node *Tree;

struct Node {
  char info;
  Tree leftmost_child, right_sibling;
};

Tree zero_child_tree(char x);
Tree one_child_tree(char x, Tree t);
Tree two_child_tree(char x, Tree t1, Tree t2);
Tree three_child_tree(char x, Tree t1, Tree t2, Tree t3);
void print_tree(Tree root, int ind);
char* production_str(char c);

Tree parse_tree;
char *next;

Tree recursive_parse() {
  return prod_E();
}

Tree prod_E() {
  Tree y1 = prod_C();
  if (y1 == NULL) return FAIL;
  Tree y2 = prod_ET();
  if (y2 == NULL) return FAIL;
  return two_child_tree('E', y1, y2);
}

Tree prod_C() {
  Tree y1 = prod_S();
  if (y1 == NULL) return FAIL;
  Tree y2 = prod_CT();
  if (y2 == NULL) return FAIL;
  return two_child_tree('C', y1, y2);
}

Tree prod_ET() {
  if (lookahead('|')) {
    if (!match_terminal('|')) return FAIL;
    Tree y1 = prod_E();
    if (y1 == NULL) return FAIL;
    return two_child_tree('T', zero_child_tree('|'), y1);
  } else {
    Tree y2 = zero_child_tree('3');
    return one_child_tree('T', y2);
  }
}

Tree prod_S() {
  Tree y1 = prod_A();
  if (y1 == NULL) return FAIL;
  Tree y2 = prod_ST();
  if (y2 == NULL) return FAIL;
  return two_child_tree('S', y1, y2);
}

Tree prod_CT() {
  if (lookahead('.')) {
    if (!match_terminal('.')) return FAIL;
    Tree y1 = prod_C();
    if (y1 == NULL) return FAIL;
    return two_child_tree('P', zero_child_tree('.'), y1);
  } else {
    Tree y2 = zero_child_tree('3');
    return one_child_tree('P', y2);
  }

}

Tree prod_ST() {
  if (lookahead('*')) {
    if (!match_terminal('*')) return FAIL;
    Tree y1 = prod_ST();
    if (y1 == NULL) return FAIL;
    return two_child_tree('B', zero_child_tree('*'), y1);
  } else {
    Tree y2 = zero_child_tree('3');
    return one_child_tree('B', y2);
  }
}

Tree prod_A() {
  if (lookahead('(')){
		if(!match_terminal('(')) return FAIL;
		Tree y1 = prod_E();
		if (y1 == NULL) return FAIL;
		if (!match_terminal(')')) return FAIL;
		return three_child_tree('A', zero_child_tree('('), y1, zero_child_tree(')'));
	} else {
		 Tree y2 = prod_X();
		 if (y2 != NULL) return one_child_tree('A', y2);
  }
  return FAIL;
}

Tree prod_X() {
  char c = *next;
	switch(c) {
		case 'a':
			if (match_terminal('a')){
				Tree t = zero_child_tree('a');
				return one_child_tree('X', t);
			}
			break;
		case 'b':
			if (match_terminal('b')){
				Tree t = zero_child_tree('b');
				return one_child_tree('X', t);
			}
			break;
		case 'c':
			if (match_terminal('c')){
				Tree t = zero_child_tree('c');
				return one_child_tree('X', t);
			}
			break;
		case 'd':
			if (match_terminal('d')){
				Tree t = zero_child_tree('d');
				return one_child_tree('X', t);
			}
			break;
		case 'e':
			if (match_terminal('e')){
				Tree t = zero_child_tree('e');
				return one_child_tree('X', t);
			}
			break;
		case 'f':
			if (match_terminal('f')){
				Tree t = zero_child_tree('f');
				return one_child_tree('X', t);
			}
			break;
		case 'g':
			if (match_terminal('g')){
				Tree t = zero_child_tree('g');
				return one_child_tree('X', t);
			}
			break;
		case 'h':
			if (match_terminal('h')){
				Tree t = zero_child_tree('h');
				return one_child_tree('X', t);
			}
			break;
		case 'i':
			if (match_terminal('i')){
				Tree t = zero_child_tree('i');
				return one_child_tree('X', t);
			}
			break;
		case 'j':
			if (match_terminal('j')){
				Tree t = zero_child_tree('j');
				return one_child_tree('X', t);
			}
			break;
    case 'k':
			if (match_terminal('k')){
				Tree t = zero_child_tree('k');
				return one_child_tree('X', t);
			}
			break;
    case 'l':
			if (match_terminal('l')){
				Tree t = zero_child_tree('l');
				return one_child_tree('X', t);
			}
			break;
    case 'm':
			if (match_terminal('m')){
				Tree t = zero_child_tree('m');
				return one_child_tree('X', t);
			}
			break;
    case 'n':
			if (match_terminal('n')){
				Tree t = zero_child_tree('n');
				return one_child_tree('X', t);
			}
			break;
    case 'o':
			if (match_terminal('o')){
				Tree t = zero_child_tree('o');
				return one_child_tree('X', t);
			}
			break;
    case 'p':
			if (match_terminal('p')){
				Tree t = zero_child_tree('p');
				return one_child_tree('X', t);
			}
			break;
    case 'q':
			if (match_terminal('q')){
				Tree t = zero_child_tree('q');
				return one_child_tree('X', t);
			}
			break;
    case 'r':
			if (match_terminal('r')){
				Tree t = zero_child_tree('r');
				return one_child_tree('X', t);
			}
			break;
    case 's':
			if (match_terminal('s')){
				Tree t = zero_child_tree('s');
				return one_child_tree('X', t);
			}
			break;
    case 't':
			if (match_terminal('t')){
				Tree t = zero_child_tree('t');
				return one_child_tree('X', t);
			}
			break;
    case 'u':
			if (match_terminal('u')){
				Tree t = zero_child_tree('u');
				return one_child_tree('X', t);
			}
			break;
    case 'v':
			if (match_terminal('v')){
				Tree t = zero_child_tree('v');
				return one_child_tree('X', t);
			}
			break;
    case 'w':
			if (match_terminal('w')){
				Tree t = zero_child_tree('w');
				return one_child_tree('X', t);
			}
			break;
    case 'x':
			if (match_terminal('x')){
				Tree t = zero_child_tree('x');
				return one_child_tree('X', t);
			}
			break;
    case 'y':
			if (match_terminal('y')){
				Tree t = zero_child_tree('y');
				return one_child_tree('X', t);
			}
			break;
    case 'z':
			if (match_terminal('z')){
				Tree t = zero_child_tree('z');
				return one_child_tree('X', t);
			}
			break;
		default:
			return FAIL;
			break;
  }
  return FAIL;
}

int is_char(char x) {
  return (x=='a'|| x=='b'|| x=='c'|| x=='d'||x=='e'|| x=='f'|| x=='g'|| x=='h'|| x=='i'|| x=='j' ||
          x=='k'|| x=='l'|| x=='m'|| x=='n'||x=='o'|| x=='p'|| x=='q'|| x=='r'|| x=='s'|| x=='t' ||
          x=='u'|| x=='v'|| x=='w'|| x=='x'||x=='y'|| x=='z');
}

int is_terminal(char x) {
  return (x=='*' || x=='.' || x=='|' || x=='(' || x==')' || is_char(x));
}

Tree get_leaf(Tree root) {
  if (root->leftmost_child != NULL) {
    Tree t1 = get_leaf(root->leftmost_child);
    if (t1 != NULL) {
      return t1;
    }
  } else if (root->info != '3' && !is_terminal(root->info)) return root;
  if (root->right_sibling != NULL) {
    Tree t2 = get_leaf(root->right_sibling);
    if (t2 != NULL) return t2;
  }
  return FAIL;
}

int match_terminal(char c) {
  if (*next == c) {
    next++;
    return 1;
  } else {
    return 0;
  }
}

int lookahead(char c) {
  return *next == c;
}
  
Tree rd_parse() {
  char* input = (char*)malloc(3);
  fgets(input,255,stdin);
	next = input;
	printf("Creating Parse Tree for: %s\n", input);
	parse_tree = recursive_parse();
  if (parse_tree != NULL && lookahead('\n')) {
    printf("Completed parse: \n");
    print_tree(parse_tree, 0);
    printf("\n");
  } else {
    printf("Invalid\n");
  }
  return parse_tree;
}