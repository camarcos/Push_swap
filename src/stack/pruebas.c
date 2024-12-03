/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camarcos <camarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:28:44 by camarcos          #+#    #+#             */
/*   Updated: 2024/12/03 17:38:58 by camarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void ft_parse_args(char **argv, t_stack **a)
{
	int i;
	char **split;
	long num;

	i = 0;
	while (argv[++i])
	{
		split = ft_split(argv[i], ' ');
		if (!split[1])
		{
			if (!split[0])
			{
				free_split(split);
				error_exit("Error: no es un número entero.");
			}
			num = ft_atol_strict(split, 0);
		}
		free_split(split);
	}
	duplicates(*a);
}

void	radix(t_stack *a, t_stack *b)
{
    int		max_index;
    int		bin_digits;
    int		i, j;
    int		stack_size;

    assign_indices(a);
    max_index = find_max_index(a);
    bin_digits = calculate_max_bits(max_index);
    stack_size = a->size;
    i = 0;
    while (i < bin_digits)
    {
        j = 0;
        while (j < stack_size)
        {
            if (((a->top->index >> i) & 1) == 0)
			{
                pb(a, b);
				// printf("hola\n");
			}	
            else
                ra(a);
            j++;
        }
        // if (i < bin_digits - 1)
        // {
            while (b->size > 0)
			{
                pa(a, b);
				// printf("adios\n");	
			}
        //}
        i++;
    }
    while (b->size > 0)
        pa(a, b);
    if (!is_sorted(a))
        error_exit("Error: No se ordenó correctamente.");
}

int	ft_listsize(t_node *stack)
{
	t_node	*aux;
	int		i;

	i = 0;
	aux = stack;
	while (aux)
	{
		aux = aux->next;
		i++;
	}
	return (i);
}

int	lst_getmin(t_stack *stack)
{
	t_node	*current;
	int		min;

	if (!stack || !stack->top)
		error_exit("Error: Pila vacía.");
	current = stack->top;
	min = current->value;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

int	lst_getmax(t_stack *stack)
{
	t_node	*current;
	int		max;

	if (!stack || !stack->top)
		error_exit("Error: Pila vacía.");
	current = stack->top;
	max = current->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	lst_maxindex(t_node *stack)
{
	t_node	*aux;
	t_node	*max;

	aux = stack->next;
	max = stack;
	while (aux)
	{
		if (aux->index > max->index)
			max = aux;
		aux = aux->next;
	}
	return (max->index);
}

int	lst_getindex(long num, t_node *stack)
{
	t_node	*aux;
	int		i;

	i = 0;
	aux = stack;
	while (aux)
	{
		if (aux->value == num)
			return (i);
		aux = aux->next;
		i++;
	}
	return (-1);
}

int	find_max_index(t_stack *stack)
{
	t_node	*current;
	int		max_index;

	if (!stack || !stack->top)
		error_exit("Error: Pila vacía.");
	current = stack->top;
	max_index = current->index;
	while (current)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	return (max_index);
}

void	assign_indices(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;

	if (!stack || !stack->top)
		return;
	current = stack->top;
	while (current)
	{
		int rank = 0;
		compare = stack->top;
		while (compare)
		{
			if (compare->value < current->value)
				rank++;
			compare = compare->next;
		}
		current->index = rank;
		current = current->next;
	}
}
void	free_split()
{
	
}