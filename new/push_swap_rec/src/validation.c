#include "push_swap.h"
#include <limits.h>

/// @brief Checks if an array of strings contains a non int. frees and exits.
/// @param arguments_s array of strings
/// @param created_at_runtime 1 if malloced at runtime.
void valid_int(char **arguments_s, int created_at_runtime)
{
	int i;
	int j;
	char *temp;

	i = 0;
	j = 0;
	while (arguments_s[i] != NULL)
	{
		temp = arguments_s[i];
		if (temp[j] == '-')
				j++;
		while (temp[j] != '\0')
		{
			if (!ft_isdigit(temp[j]))
			{
				if (created_at_runtime)
					validation_error(arguments_s);
				validation_error(0);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return ;
}

void unique_ints(int *arg_i)
{
	int i;
	int j;

	i = 0;
	while (arg_i[i] != '\0')
	{
		j = (i + 1);
		while (arg_i[j] != '\0')
		{
			if (arg_i[i] == arg_i[j])
				ft_error(0);
			j++;
		}
		i++;
	}
}