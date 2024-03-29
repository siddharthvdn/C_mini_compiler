void yyerror(char*);

typedef struct node
{
	char* name;		
	char* type;
	char* params;

	int array_bound;

	int func_def;

	int* scope;
	int depth;
		
	struct node* next;
}node;

node* sym_tbl[100];
node* const_tbl[100];
node* fun_tbl[100];

#define SYM_TBL 0
#define CONST_TBL 1
#define FUN_TBL 2


int hash(char* x, int M);

node* lookup(char* x, int table);

void insert(char* x, char* type, int* scope_in, int depth_in, int table);

void insert_fun(char* x, char* type, int* scope_in, int depth_in, char* param_list_in);

void check_scope(char* x, int* scope_in, int depth_in, int table);

void change_scope(char* x, int level_in);

void display();

