#include "push_swap.h"

/// @brief Checks if an array of strings contains a non int. frees and exits.
/// @param arguments_s array of strings
/// @param created_at_runtime 1 if malloced at runtime.
void valid_int(char **arguments_s)
{
	int i;
	int j;
	char *temp;

	i = 0;
	while (arguments_s[i] != 0)
	{
		temp = arguments_s[i];
		j = 0;
		while (temp[j] != '\0')
		{
			if (!ft_isdigit(temp[j]))
					validation_error(arguments_s);
			j++;
		}
		i++;
	}
	return ;
}