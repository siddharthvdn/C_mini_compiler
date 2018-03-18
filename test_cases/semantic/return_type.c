int fun(int a, int b);

int fun2();

int c, d;
char e;

int main()
{
	fun(c, fun(c,d));

	return c;
}
