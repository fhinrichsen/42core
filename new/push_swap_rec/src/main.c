#include "push_swap.h"

int main(int argc, char **argv)
{
	if (argc == 1)
		ft_error(0);
	if (argc == 2)
		read_two_arguments(argv[1]);
	else
		read_n_arguments((argv + 1), argc);
	ft_printf("Done");
	return(0);
}