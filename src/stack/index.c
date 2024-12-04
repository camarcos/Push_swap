/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinamc <carolinamc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:55:35 by carolinamc        #+#    #+#             */
/*   Updated: 2024/12/04 22:21:21 by carolinamc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
//devuelve el índice más alto de la pila

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
//devuelve el índice de un número en la pila

void	assign_indices(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;
	int		rank;

	if (!stack || !stack->top)
		return ;
	current = stack->top;
	while (current)
	{
		rank = 0;
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
//asigna un índice a cada nodo de la pila, según su valor

int	min_element(t_stack *stack)
{
	t_node	*head;
	int		min;

	head = stack->top;
	min = head->value;
	while (head)
	{
		if (head->value < min)
			min = head->value;
		head = head->next;
	}
	return (min);
}
//devuelve el valor más bajo de la pila
