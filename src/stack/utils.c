/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camarcos <camarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:48:12 by carolinamc        #+#    #+#             */
/*   Updated: 2024/12/04 18:31:21 by camarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <limits.h>

int	print_stack(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	return (1);
}
//imprimir numeros del stack

int	find_max(t_stack *a)
{
	t_node	*current;
	int		max;

	if (!a || !a->top)
		error_exit("Error: pila vacía.");
	current = a->top;
	max = INT_MIN;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}
//encontrar el valor máximo de la pila

int	lst_getmin(t_stack *stack)
{
	t_node	*current;
	int		min;

	if (!stack || !stack->top)
		error_exit("Error. Pila vacía.");
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
//encontrar el valor mínimo de la pila

int	lst_getmax(t_stack *stack)
{
	t_node	*current;
	int		max;

	if (!stack || !stack->top)
		error_exit("Error. Pila vacía.");
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
//encontrar el valor máximo de la pila

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
//encontrar el índice máximo de la pila


int min_element(t_stack *stack)
{
	t_node *head = stack->top;
	int min = INT_MAX;

	while (head)
	{
		if (head->value < min)
			min = head->value;
		head = head->next;
	}
	return min;
}