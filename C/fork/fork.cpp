#include<stdio.h>
int main()
{
	fork();
	fork() && fork() || fork();
	fork();
	printf("Hello\n");
	return 0;
}
