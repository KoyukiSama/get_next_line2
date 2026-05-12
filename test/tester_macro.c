
#include "tester_macro.h"

void memprint(const void *mem, size_t n)
{
	const unsigned char *p;
	
	p = mem;
	for (size_t i = 0; i < n; i++) {
		printf("%02x ", p[i]);
	}
	printf("\n");
}

int	strscmp(char **strs1, char **strs2)
{
	size_t	i = 0;
	int		cmp = 0;

	while (strs1[i] && strs2[i])
	{
		cmp = strcmp(strs1[i], strs2[i]);
		if (cmp != 0)
			return (cmp);
		i++;
	}
	if (strs1[i] == NULL && strs2[i] == NULL)
		return (0);
	if (strs1[i])
		return (1);
	else
		return (-1);
}

void print_strs(char **strs)
{
	if (!strs)
		printf("NULL");
	printf("[");
	while (*strs)
		printf(" \"%s\",", *strs++);
	if (!*strs)
		printf(" NULL");
	printf(" ]\n");
}

void free_strs(char **strs)
{
	while (*strs)
		free(*strs++);
	free(strs);
}
