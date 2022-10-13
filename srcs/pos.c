#include "../push_swap.h"

void	get_pos(t_list *stack)
{
	int	i;

	i = 0;
	while(stack)
	{
		stack->pos = i;
		stack = stack->next;
		i++;
	}
}

static int funcpos(t_list *stack_a, int index, int taget_pos)
{
	while(stack_a)
	{
		if (index > stack_a->index 
		stack_a = stack_a->next;
	}
}


void	get_target_pos(t_list *stack_a, t_list *stack_b)
{
	if(!stack_a || !stack_b)
		return ;
	int	target_pos;
	
	get_pos(stack_b);
	print_list(stack_b);
	target_pos = 0;
	while (stack_b)
	{
		//target_post = funcpos(stack_a, stack_b->index, target_pos)
		//stack_b->target_pos = target_pos;
		stack_b = stack_b->next;
	}
}
