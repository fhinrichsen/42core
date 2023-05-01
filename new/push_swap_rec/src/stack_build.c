#include "push_swap.h"

void read_two_arguments(char *argv)
{
	ft_printf("I should read in: %s\n", argv);

	char **arguments_s;

	arguments_s = ft_split(argv, ' ');
	valid_int(arguments_s, 1);
}

void read_n_arguments(char **arguments_s)
{
	int i = 0;
	while (arguments_s[i])
	{
		ft_printf("Inside: %s\n", arguments_s[i]);
		i++;
	}
	return;
}
