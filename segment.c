#include <stdio.h>
#include <stdlib.h>

int magic = 42;
char crap[1024];

void func(int arg)
{
	printf("stack segment near %p\n" , &arg);
}

int main(int argc , char **argv)
{
	char *ptr;
	ptr = malloc(1);
	func (42);
	
	printf("heap segment near %p\n" , ptr);
	printf("bss segment near %p\n" , crap);
	printf("text segment near %p\n" , &magic);
	
	free(ptr);
	exit(EXIT_SUCCESS);
}
