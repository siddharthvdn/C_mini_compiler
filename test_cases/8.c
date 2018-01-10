//Nested if-else

void main()
{
	int a = 5;
	
	if(a>5)
	{
		if(a>10)
			printf("a is greater than 10");
		else
		{
			printf("a is lesser than 10");
			printf("a is greater than 5");
		}
	}
	else if(a>0)
	{		
		printf("a is zero");
	}					
}

