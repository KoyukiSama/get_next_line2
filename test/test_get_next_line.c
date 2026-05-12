
#include "tester_macro.h"
#include "../get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>

int main(void)
{
	int fd1 = open("test1.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	int fd3 = open("test3.txt", O_RDONLY);
	int fd4 = open("test4.txt", O_RDONLY);
	int fd5 = open("test5.txt", O_RDONLY);
	int fd6 = open("test6.txt", O_RDONLY);
	int fd7f0 = open("test7-0.txt", O_RDONLY);
	int fd7f1 = open("test7-1.txt", O_RDONLY);
	int fd7f2 = open("test7-2.txt", O_RDONLY);
	int fd7f3 = open("test7-3.txt", O_RDONLY);
	int fd8 = open("test8.txt", O_RDONLY);
	char *line;

	// printf("0----------stdinput.txt | simple test----------0\n");
	// for (int i = 0; i < 5; i++)
	// {
	// 	line = get_next_line(0);
	// 	printf("%s", line);
	// 	free(line);
	// }

	printf("0----------test1.txt | simple test----------0\n");
	for (int i = 0; i < 8; i++)
	{
		line = get_next_line(fd1);
		printf("%s", line);
		free(line);
	}

	printf("\n0----------test2.txt | no '\\n' at end----------0\n");
	for (int i = 0; i < 4; i++)
	{
		line = get_next_line(fd2);
		printf("%s", line);
		free(line);
	}

	printf("\n0----------test3.txt | multiple '\\n'----------0\n");
	for (int i = 0; i < 6; i++)
	{
		line = get_next_line(fd3);
		printf("%s", line);
		free(line);
	}

	printf("\n0----------test4.txt | one BIG line----------0\n");
	for (int i = 0; i < 1; i++)
	{
		line = get_next_line(fd4);
		printf("%s", line);
		free(line);
	}
	
	printf("\n0----------test5.txt | 4 enters----------0\n");
	for (int i = 0; i < 3; i++)
	{
		line = get_next_line(fd5);
		printf("%s", line);
		free(line);
	}
	
	printf("\n0----------test6.txt | empty file----------0\n");
	for (int i = 0; i < 1; i++)
	{
		line = get_next_line(fd6);
		printf("%s", line);
		free(line);
	}
	
	printf("\n0----------test7.txt | 4 fds in sync----------0\n");
	for (int i = 0; i < 10; i++)
	{
		line = get_next_line(fd7f0);
		printf("%s", line);
		free(line);

		line = get_next_line(fd7f1);
		printf("%s", line);
		free(line);
		
		line = get_next_line(fd7f2);
		printf("%s", line);
		free(line);
		
		line = get_next_line(fd7f3);
		printf("%s", line);
		free(line);
	}
	
	printf("\n0----------test8.txt | error txt----------0\n");
	line = get_next_line(fd8);
	printf("%s", line);
	free(line);
	close(fd8);
	for (int i = 0; i < 5; i++)
	{
		line = get_next_line(fd8);
		printf("%s", line);
		free(line);
	}

	// int fdLOBSTER = open("testLOBSTER.txt", O_RDONLY);
	// #define DARK_RED "\033[38;5;196m"
	// #define COCONUT "\033[38;5;94m"
	// printf("\n0----------test8.txt | LOBSTERRR----------0\n");
	// line = get_next_line(fdLOBSTER);
	// printf("%s", line);
	// free(line);
	// for (size_t i = 0; i < 200000; i++)
	// {
	// 	line = get_next_line(fdLOBSTER);
	// 	line[strlen(line) - 1] = '\0';
	// 	printf("%s", line);
	// 	free(line);

	// 	line = get_next_line(fdLOBSTER);
	// 	line[strlen(line) - 1] = '\0';
	// 	printf(DARK_RED"%s"RESET, line);
	// 	free(line);
		
	// 	line = get_next_line(fdLOBSTER);
	// 	line[strlen(line) - 1] = '\0';
	// 	printf("%s", line);
	// 	free(line);

	// 	line = get_next_line(fdLOBSTER);
	// 	line[strlen(line) - 1] = '\0';
	// 	printf(COCONUT"%s"RESET, line);
	// 	free(line);

	// 	line = get_next_line(fdLOBSTER);
	// 	line[strlen(line) - 1] = '\0';
	// 	printf("%s", line);
	// 	free(line);

	// 	printf("#%lu\n", i);
	// }
	//close(fdLOBSTER);

	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	close(fd5);
	close(fd6);
	close(fd7f0);
	close(fd7f1);
	close(fd7f2);
	close(fd7f3);
	close(fd8);
}
