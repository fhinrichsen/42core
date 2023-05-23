#include "push_swap.h"

/// @brief removes the top node while keeping list intact
/// @param list pointer to linked list
/// @return popped element
t_node	*ft_pop(t_node **list)
{
	t_node	*tmp;

	if (!(*list))
		return (NULL);
	if ((*list) == (*list)->next)
	{
		tmp = *list;
		*list = NULL;
		return (tmp);
	}
	tmp = *list;
	(*list)->prev->next = (*list)->next;
	(*list)->next->prev = (*list)->prev;
	*list = (*list)->next;
	tmp->next = tmp;
	tmp->prev = tmp;
	return (tmp);
}

/// @brief pushes node to an existing list
/// @param list pointer to linked list to push to
/// @param push_this pointer of node to be pushed
/// @return not clear
void	ft_push(t_node **list, t_node *push_this)
{
	if (!(*list))
	{
		(*list) = push_this;
		return ;
	}
	(*list)->prev->next = push_this;
	push_this->prev = (*list)->prev;
	push_this->next = *list;
	(*list)->prev = push_this;
	*list = push_this;
}

/// @brief rotates entry point ot a list
/// @param direction 1 to ra 11 rb; 0 to rra or -1 rrb
/// @param list List to rotate
void	ft_rotate(int direction, t_node **list)
{
	if(direction == 1)
		ft_printf("ra\n");
	if(direction == 11)
		ft_printf("rb\n");
	if (direction > 0)
		*(list) = (*list)->next;
	else
		*(list) = (*list)->prev;
	if(direction == -1)
		ft_printf("rra\n");
	if(direction == 0)
		ft_printf("rrb\n");
}