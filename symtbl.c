#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symtbl.h"

#define SYM_TBL 0
#define CONST_TBL 1


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


void insert(char* x, char* type, int* scope_in, int depth_in, int table)
{
	if(lookup(x, table))
		return;

	int idx = hash(x, 100);

	node* cell = (node*)malloc(sizeof(node));
	cell->name = (char*)malloc(strlen(x));
	strcpy(cell->name, x);

	cell->type = (char*)malloc(strlen(type));		
	strcpy(cell->type, type);
	
	if(depth_in==0)
	{
		cell->scope = NULL;
		cell->depth = 0;
	}
	else
	{
		cell->scope = (int*)malloc(sizeof(int)*depth_in);
		cell->depth = depth_in;
	}

	for(int i=0; i<depth_in; i++)
	{
		cell->scope[i] = scope_in[i];
	}		


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


void check_scope(char* x, int* scope_in, int depth_in)
{
	int idx = hash(x, 100);

	char error_msg[100];
	

	if(sym_tbl[idx]==NULL)
 	{
 		strcpy(error_msg,"Variable undeclared: ");
 		strcat(error_msg, x); 
 		yyerror(error_msg); 
 		return;
 	}
 		
 	node* t = NULL;	
 	t = sym_tbl[idx];
 	
 	while(t!=NULL)
	{
		if(strcmp(t->name, x)==0)
			break;
		t = t->next;
	}
	
	int i;
	if(depth_in<t->depth)
	{
 		strcpy(error_msg,"Variable out of scope: ");
 		strcat(error_msg, x); 
 		yyerror(error_msg); 
 		return;
 	}

	for(i = 0; i<t->depth;i++)
	{
		if(scope_in[i] != t->scope[i])	
		{
	 		strcpy(error_msg,"Variable out of scope: ");
	 		strcat(error_msg, x); 
	 		yyerror(error_msg); 
	 		return;
 		}
	}
	
}

void change_scope(char* x, int level_in)
{
	int idx = hash(x, 100);

	char error_msg[100];
	

	if(sym_tbl[idx]==NULL)
 	{
 		strcpy(error_msg,"Variable undeclared: ");
 		strcat(error_msg, x); 
 		yyerror(error_msg); 
 		return;
 	}
 		
 	node* t = NULL;	
 	t = sym_tbl[idx];
 	
 	while(t!=NULL)
	{
		if(strcmp(t->name, x)==0)
			break;
		t = t->next;
	}
	
	t->depth = t->depth + 1;
	
	int *temp = (int*)malloc(sizeof(int)*(t->depth));
	for(int i=0; i<t->depth-1; i++)
	{
		temp[i] = t->scope[i];
	}
	t->scope = temp;
	
	t->scope[t->depth-1] = level_in + 1;	
}

void display()
{
	printf("\n----------------------------\n\tSymbol table\n----------------------------\n");
	printf("Value\t\t-\tType\t-\tScope\n----------------------------\n");

	int i,j;	

	for(i=0; i<100; i++)
	{
		if(sym_tbl[i]==NULL)
			continue;
	
		node* t = sym_tbl[i];

		
			
	
		while(t!=NULL)	
		{
			printf("%s\t\t-\t%s\t-\t", t->name, t->type);

			if(t->depth==0)
				printf("Global");
			
			for(j=0; j<t->depth; j++)
				printf("%d ", t->scope[j]);

			printf("\n");
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