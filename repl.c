#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "rd_parse.h"
#include "table_parse.h"
#include "exp_tree.h"
#include "tree.h"

Tree rd_parse();
void td_parse();

int main(int argc, char const *argv[]) {
  printf("Recursive descent parser: \n");
  printf("-----------------------------\n");
  printf("Enter input to test RD Parser: ");
  Tree rd = rd_parse();
  printf("\nExpression tree representation for input: ");
  get_exp(rd);
  printf("\n");
  printf("\nTable driven parser: \n");
  printf("-----------------------------\n");
  printf("Enter input to test TD Parser: \n");
  td_parse();
  return 0;
}
