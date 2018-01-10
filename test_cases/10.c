//Function call and pointer

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void main()
{
	int a=3, b=5;
	
	swap(&a, &b);
}


