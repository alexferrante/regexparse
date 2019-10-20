#include "tree.h"

extern Tree prod_E();
extern Tree prod_C();
extern Tree prod_ET();
extern Tree prod_S();
extern Tree prod_CT();
extern Tree prod_A();
extern Tree prod_ST();
extern Tree prod_X();
extern Tree recursive_parse();
extern int is_char(char x);
extern int match_terminal(char c);
extern int lookahead(char c);
extern int is_terminal(char c);
extern Tree rd_parse();
extern Tree get_leaf(Tree root);