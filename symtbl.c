#include "symtbl.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	

#define SYM_TBL 0
#define CONST_TBL 1

extern int lineno;

typedef struct node
{
	char* name;		
	char* type;
			
	struct node* next;
}node;

node* sym_tbl[100];
node* const_tbl[100];

int hash(char* x, int M) 
{
   int i, sum;
   for (sum=0, i=0; i < strlen(x); i++)
     sum += x[i];
   return sum % M;
}

int lookup(char* x, int table)
{
	int idx = hash(x, 100);

	node* t = NULL;

	if(table==0)
	{
 		if(sym_tbl[idx]==NULL)
 			return 0;
 		
 		t = sym_tbl[idx];
 	}
 	else
 	{
 		if(const_tbl[idx]==NULL)
	 		return 0;
 		
 		t = const_tbl[idx];
 	}
	
	while(t!=NULL)
	{
		if(strcmp(t->name, x)==0)
			return 1;
		t = t->next;
	}
	
	return 0;
			
}


void insert(char* x, char* type, int table)
{
	if(lookup(x, table))
		return;

	int idx = hash(x, 100);
	
	node* cell = (node*)malloc(sizeof(node));
	cell->name = (char*)malloc(strlen(x));
	strcpy(cell->name, x);
	strcpy(cell->type, type);
	cell->next = NULL;		
	
	node* t = NULL;
	
	if(table==0)
	{
 		if(sym_tbl[idx]==NULL)
 		{
 			sym_tbl[idx] = cell;
 			return;
 		}
 		
 		t = sym_tbl[idx];
 	}
 	else
 	{
 		if(const_tbl[idx]==NULL)
 		{
 			const_tbl[idx] = cell;
 			return;
 		}
 		
 		t = const_tbl[idx];
 	}
	
	while(t->next!=NULL)
	t = t->next;
	
	t->next = cell; 		
}

void display()
{
	printf("\n----------------------------\n\tSymbol table\n----------------------------\n");
	printf("Value\t\t-\tType\n----------------------------\n");

	int i;	

	for(i=0; i<100; i++)
	{
		if(sym_tbl[i]==NULL)
			continue;
		
		node* t = sym_tbl[i];
		
		while(t!=NULL)	
		{
			printf("%s\t\t-\t%s\n", t->name, t->type);
			t = t->next;
		}
			
	}
	
	
	printf("\n\n----------------------------\n\tConstant table\n----------------------------\n");
	printf("Value\t\t-\tType\n----------------------------\n");
	
	for(i=0; i<100; i++)
	{
		if(const_tbl[i]==NULL)
			continue;
		
		node* t = const_tbl[i];
		
		while(t!=NULL)	
		{
			printf("%s\t\t-\t%s\n", t->name, t->type);
			t = t->next;
		}
			
	}
}
