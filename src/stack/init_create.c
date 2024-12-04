/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinamc <carolinamc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:36:46 by carolinamc        #+#    #+#             */
/*   Updated: 2024/12/04 17:13:52 by carolinamc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		error_exit("Entrada no válida: no es un número entero.");
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}
// crea un nuevo nodo, asigna el valor y lo inicializa

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}
// inicializa una estructura t_stack con top en NULL y tamaño 0

void	initialize_stacks(int argc, char **argv, t_stack **a, t_stack **b)
{
	*a = init_stack();
	*b = init_stack();
	parse_arguments(argc, argv, a);
	if (!(*a) || !(*b))
		error_exit("Error al inicializar stack.");
}
// inicializa las pilas a y b, y procesa los argumentos de entrada

void	parse_arguments(int argc, char **argv, t_stack **a)
{
	char	**split;
	int		i;

	if (!(*a))
		error_exit("Error al inicializar stack.");
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			error_exit("Error al dividir argumentos.");
		process_split_arguments(split, a);
		free_split(split);
		i++;
	}
}
// divide los argumentos de entrada y los procesa

void	process_split_arguments(char **split, t_stack **a)
{
	int		j;
	long	num;

	j = 0;
	while (split[j])
	{
		num = ft_atol(split[j]);
		if (num < INT_MIN || num > INT_MAX)
		{
			free_split(split);
			error_exit("Error. Número fuera de rango.");
		}
		if (lst_getindex(num, (*a)->top) != -1)
		{
			free_split(split);
			error_exit("Error. Número duplicado detectado.");
		}
		push_stack(*a, num);
		j++;
	}
}
// procesa los argumentos divididos