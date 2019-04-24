if(!fork())
{
	printf("I'm the child!\n");
	exit(0);
} 
else
{
	printf("I'm the parent!\n");
	wait(NULL);
}
