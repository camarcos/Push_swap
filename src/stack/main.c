/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camarcos <camarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:26:18 by camarcos          #+#    #+#             */
/*   Updated: 2024/11/26 13:34:32 by camarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	validate_argu(int argc, char **argv)
{
	int		i;
	long	num;

	i = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			error_exit("Número no válido.");
		i++;
	}
}
//utiliza el algoritmo de radix para manejar grandes pilas de manera eficiente

void	initialize_stacks(int argc, char **argv, t_stack **a, t_stack **b)
{
	int	i;

	i = 1;
	validate_argu(argc, argv);
	*a = init_stack();
	*b = init_stack();
	if (!(*a) || !(*b))
		error_exit("Error al inicializar stack.");
	while (i < argc)
	{
		push_stack(*a, ft_atol(argv[i]));
		i++;
	}
	if (duplicates(*a))
		error_exit("Hay números duplicados.");
}

void	sort_stack(t_stack *a, t_stack *b)
{
	// /* ========================================= */

	// t_node *aux = a->top;

	// while (aux)
	// {
	// 	printf("=> %d [%p]\n", aux->value, aux->next);
	// 	aux = aux->next;
	// }

	// /* ========================================= */

	if (is_sorted(a))
	{
		free_list(a);
		free_list(b);
		exit(0);
	}

	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_small_stack(a, b);
	else
		sort_large_stack(a, b);
	
	free_list(a);
	free_list(b);
}
//Administra la lógica para determinar el algoritmo de ordenación según el tamaño de la pila.
//Libera memoria antes de salir, asegurando que no haya fugas.

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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
	{
		printf ("Error, numero de argumetos incorrecto\n");
		return (0);
	}	
	initialize_stacks(argc, argv, &a, &b);
	sort_stack(a, b);
	return (0);
}
