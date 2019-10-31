#include "get_next_line_bonus.h"

int main()
{
	int		i;
	int		c;
	char *p;
	
	p = malloc(2147483647);
	i = open("does", 0);
	c = 1;
	while (get_next_line(i, &p))
		printf("%s\n", p);
	return (0);
}