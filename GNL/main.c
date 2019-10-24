#include "get_next_line.h"

int main()
{
	int		i;
	int		c;
	char *p;
	
	p = malloc(BUFFER_SIZE);
	i = open("factbook", 0);
	c = 1;
	printf("%d", i);
	while (get_next_line(i, &p))
		printf("%s\n", p);
	return (0);
}