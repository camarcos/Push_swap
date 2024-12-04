/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinamc <carolinamc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:03:41 by camarcos          #+#    #+#             */
/*   Updated: 2024/12/04 16:47:36 by carolinamc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_stack(t_stack *stack, int value)
{
	t_node	*new_node;
	t_node	*last;

	new_node = create_node(value);
	if (!new_node)
	{
		error_exit("Error: no se pudo asignar memoria para el nodo");
		exit(EXIT_FAILURE);
	}
	new_node->next = NULL;
	last = stack->top;
	if (last == NULL)
		stack->top = new_node;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new_node;
	}
	stack->size++;
}
// añade un nuevo nodo en la parte superior de la pila

int	pop(t_stack *stack)
{
	t_node	*temp;
	int		value;

	if (stack->top == NULL)
	{
		error_exit("Error. Stack vacio");
		exit(EXIT_FAILURE);
	}
	temp = stack->top;
	value = temp->value;
	stack->top = stack->top->next;
	free(temp);
	stack->size--;
	return (value);
}
// elimina y devuelve el valor del nodo en la parte superior de la pila

void	free_list(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
}
// libera toda la memoria ocupada por los nodos y la estructura de la pila

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
// libera la memoria ocupada por un array de strings

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
// devuelve el número de nodos en la pila
