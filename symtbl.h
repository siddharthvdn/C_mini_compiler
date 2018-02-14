typedef struct node
{
	char* name;		
	char* type;
			
	struct node* next;
}node;

node* sym_tbl[100];
node* const_tbl[100];

int hash(char* x, int M);

int lookup(char* x, int table);


void insert(char* x, char* type, int table);

void display();
