void yyerror(char*);

typedef struct node
{
	char* name;		
	char* type;

	int* scope;
	int depth;
		
	struct node* next;
}node;

node* sym_tbl[100];
node* const_tbl[100];


int hash(char* x, int M);

int lookup(char* x, int table);

void insert(char* x, char* type, int* scope_in, int depth_in, int table);

void check_scope(char* x, int* scope_in, int depth_in);

void change_scope(char* x, int level_in);

void display();

