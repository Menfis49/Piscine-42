#include "list.h"

int	ft_list(t_list *begin_list)
{
	int result;

	result = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		result += 1;
	}
	return result;
}
