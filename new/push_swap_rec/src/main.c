#include "push_swap.h"

int main(int argc, char **argv)
{
	if (argc == 1)
		ft_error(0);
	else if (argc == 2)
		read_two_arguments(argv[1]);
	read_n_arguments((argv + 1));
	ft_printf("Done");
	return(0);
}