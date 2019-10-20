#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table_parse.h"
#include "tree.h"
#define FAIL NULL

typedef struct Node *Tree;

struct Node {
  char info;
  Tree leftmost_child, right_sibling;
};

Tree parse_tree; 
Tree tree_stack[50];
char stack[50];
int stack_idx;
int t_stack_idx;
char* input;
int in_left;

int table[8][7] = { {1,0,0,0,0,1,0}, // E
            {0,3,2,0,0,0,3}, // ET 
            {4,0,0,0,0,4,0}, // C 
            {0,6,6,5,0,0,6}, // CT
            {7,0,0,0,0,7,0}, // S 
            {0,9,9,9,8,0,9}, // ST 
            {11,10,0,0,0,11,0}, // A 
            {0,0,0,0,0,12,0} // X
          };

int char_to_int(char c){
  switch(c) {
    case 'E': return 0; break;
    case 'T': return 1; break;  // ET
    case 'C': return 2; break;
    case 'P': return 3; break; // CT
    case 'S': return 4; break;
    case 'B': return 5; break; // ST
    case 'A': return 6; break;
    case 'X': return 7; break;
    case '(': return 0; break;
    case ')': return 1; break;
    case '|': return 2; break;
    case '.': return 3; break;
    case '*': return 4; break;
    case 'a': return 5; break;
    case 'b': return 5; break;
    case 'c': return 5; break;
    case 'd': return 5; break;
    case 'e': return 5; break;
    case 'f': return 5; break;
    case 'g': return 5; break;
    case 'h': return 5; break;
    case 'i': return 5; break;
    case 'j': return 5; break;
    case 'k': return 5; break;
    case 'l': return 5; break;
    case 'm': return 5; break;
    case 'n': return 5; break;
    case 'o': return 5; break;
    case 'p': return 5; break;
    case 'q': return 5; break;
    case 'r': return 5; break;
    case 's': return 5; break;
    case 't': return 5; break;
    case 'u': return 5; break;
    case 'v': return 5; break;
    case 'w': return 5; break;
    case 'x': return 5; break;
    case 'y': return 5; break;
    case 'z': return 5; break;
    case '\0': return 6; break;
    default: return -1; break;
  }
}

void E() {
  push('T'); // ET
  push('C');
  Tree curr = pop_tree();
  Tree y1 = zero_child_tree('C');
  Tree y2 = zero_child_tree('T');
  y1 -> right_sibling = y2;
  curr -> leftmost_child = y1;
  push_tree(y2);
  push_tree(y1);
  process_input(pop());
}

void C() {
  push('P'); // CT
  push('S');
  Tree curr = pop_tree();
  Tree y1 = zero_child_tree('S');
  Tree y2 = zero_child_tree('P');
  y1->right_sibling = y2;
  curr->leftmost_child = y1;
  push_tree(y2);
  push_tree(y1);
  process_input(pop());
}

void ET1() {
  push('E');
  push('|');
  Tree curr = pop_tree();
  Tree y1 = zero_child_tree('|');
  Tree y2 = zero_child_tree('E');
  y1 -> right_sibling = y2;
  curr -> leftmost_child = y1;
  push_tree(y2);
  process_input(pop());
}


void ET2() {
  Tree curr = pop_tree();
  Tree eps = zero_child_tree('3');
  curr->leftmost_child = eps;
  process_input(pop());
}

void CT2() {
  Tree curr = pop_tree();
  Tree eps = zero_child_tree('3');
  curr -> leftmost_child = eps;
  process_input(pop());
}

void ST2() {
  Tree curr = pop_tree();
  Tree eps = zero_child_tree('3');
  curr -> leftmost_child = eps;
  process_input(pop());
}

void CT1() {
  push('C');
  push('.');
  Tree curr = pop_tree();
  Tree y1 = zero_child_tree('.');
  Tree y2 = zero_child_tree('C');
  y1 -> right_sibling = y2;
  curr -> leftmost_child = y1;
  push_tree(y2);
  push_tree(y1);
  process_input(pop());
}

void S() {
  push('B'); // ST
  push('A');
  Tree curr = pop_tree();
  Tree y1 = zero_child_tree('A');
  Tree y2 = zero_child_tree('B');
  y1 -> right_sibling = y2;
  curr -> leftmost_child = y1;
  push_tree(y2);
  push_tree(y1);
  process_input(pop());
}

void ST1() {
  push('B'); // ST
  push('*');
  Tree curr = pop_tree();
  Tree y1 = zero_child_tree('*');
  Tree y2 = zero_child_tree('B');
  y1 -> right_sibling = y2;
  curr -> leftmost_child = y1;
  push_tree(y2);
  push_tree(y1);
  process_input(pop());
}

void A1() {
  push(')');
  push('E');
  push('(');
  Tree curr = pop_tree();
  Tree parenA = zero_child_tree('(');
  Tree nextE = zero_child_tree('E');
  Tree parenB = zero_child_tree(')');
  parenA -> right_sibling = nextE;
  nextE -> right_sibling = parenB;
  curr -> leftmost_child = parenA;
  push_tree(nextE);
  process_input(pop());
}

void A2() {
  push('X');
  Tree curr = pop_tree();
  Tree nextX = zero_child_tree('X');
  curr -> leftmost_child = nextX;
  push_tree(nextX);
  process_input(pop());
}

void X() {
  push(*input);
  Tree curr = pop_tree();
  Tree sym = zero_child_tree(*input);
  curr -> leftmost_child = sym;
  process_input(pop());
}

void call_production_fn(int i) {
  switch(i) {
    case 1: E(); break;
    case 2: ET1(); break;
    case 3: ET2(); break;
    case 4: C(); break;
    case 5: CT1(); break;
    case 6: CT2(); break;
    case 7: S(); break;
    case 8: ST1(); break;
    case 9: ST2(); break;
    case 10: A1(); break;
    case 11: A2(); break;
    case 12: X(); break;
  }
}

int rem_input(){
  if (in_left > 0){
    return 1;
  }
  return 0;
}

void td_parse() {
  stack_idx = 0;
  t_stack_idx = 0;
  push('$');
  push('E');
  parse_tree = zero_child_tree('E');
  push_tree(parse_tree);
  input = (char*)malloc(100*sizeof(char));
	scanf("%[^\n]", input);
  in_left = strlen(input);
  while (!(input[0] == '+')) {
    printf("Creating Parse Tree for: %s\n", input);
    process_input(pop());
    if (rem_input()){
      input = (char*)malloc(100*sizeof(char));
    } else {
      print_tree(parse_tree, 0);
      printf("\nEnter + to quit\n");
    }
    stack_idx = 0;
    t_stack_idx = 0;
    push('$');
    push('E');
    parse_tree = zero_child_tree('E');
    push_tree(parse_tree);
    scanf(" %[^\n]", input);
    in_left = strlen(input);
  }
}

void push(char c){
  stack[stack_idx] = c;
  stack_idx++;
}

char pop(){
  stack_idx--;
  char c = stack[stack_idx];
  return c;
}

void push_tree(Tree t){
  tree_stack[t_stack_idx] = t;
  t_stack_idx++;
}

Tree pop_tree(){
  t_stack_idx--;
  Tree t = tree_stack[t_stack_idx];
  return t;
}

void print_stack(){
  int i = 0;
  while ((int)stack[i]!= 0){
    printf("%c, ", stack[i]);
    i++;
  }
}

void process_input(char c){
  int pInt, iInt;
  pInt = char_to_int(c);
  iInt = char_to_int(*input);
  if (c == *input){
    input++;
    in_left = in_left - 1;
    process_input(pop());
  } else if (table[pInt][iInt] == 0 && c != '$'){
    printf("Failed to parse:\n");
  } else if (c != '$'){
    if (table[pInt][iInt] == 0){
      printf("Failed to parse:\n");
    } else {
      call_production_fn(table[pInt][iInt]);
    }
  } else if (c == '$' && *input != '\0'){
    printf("Failed to parse:\n");
  } else {
    printf("Completed parse:\n");
  }
}
