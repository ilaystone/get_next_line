#include "get_next_line.h"
// 16-five
// 16-one
// 16-one-n
// 16-three
// 16-two
// 4-five
// 4-one
// 4-one-n
// 4-three
// 4-two
// 8-five
// 8-one
// 8-one-n
// 8-three
// 8-two
// does
// easy
// empty
// empty_line_then_char
// factbook
// hello
// lon
// long_line
// long_line_easy
// long_line_three
// long_lines_same_length
// moulinetter
// moulinetter2
// one_blank_line
// pigs
// stuff
// tards
// testing
// this_is_a_file
// two_blank_lines

int main()
{
	int		i;
	int		c;
	char *p;
	
	p = malloc(MAX_LENGTH);
	i = open(FN, 0);
	c = 1;
	while (get_next_line(i, &p))
		printf("%s\n", p);
	return (0);
}