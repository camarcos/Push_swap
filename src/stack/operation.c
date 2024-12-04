/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinamc <carolinamc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:06:30 by carolinamc        #+#    #+#             */
/*   Updated: 2024/12/04 17:11:11 by carolinamc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	radix(t_stack *a, t_stack *b)
{
	int	max_index;
	int	bin_digits;
	int	i;

	assign_indices(a);
	max_index = find_max_index(a);
	bin_digits = calculate_max_bits(max_index);
	i = 0;
	while (i < bin_digits)
	{
		bits(a, b, i);
		i++;
	}
}
//algoritmo de ordenación radix

void	process_bits(t_stack *a, t_stack *b, int i)
{
	int	size;
	int	j;

	size = a->size;
	j = 0;
	while (j < size)
	{
		if (((a->top->value >> i) & 1) == 0)
			pb(a, b);
		else
			ra(a);
		j++;
	}
	while (b->size > 0)
		pa(a, b);
}
//verifica si el bit es 0 o 1 para cada número de A
//si el bit es 0 lo mueve a B y si es 1 lo deja en A

void	bits(t_stack *a, t_stack *b, int bit)
{
	int	stack_size;
	int	j;

	stack_size = a->size;
	j = 0;
	while (j < stack_size)
	{
		if (((a->top->index >> bit) & 1) == 0)
			pb(a, b);
		else
			ra(a);
		j++;
	}
	while (b->size > 0)
		pa(a, b);
}
//verifica si el bit es 0 o 1 para cada número de A

int	calculate_max_bits(int max_num)
{
	int	max_bits;

	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
//calcular el numerode bits para saber el numero de iteraciones necesario

void	sort_large_stack(t_stack *a, t_stack *b)
{
	radix(a, b);
	if (!is_sorted(a))
		error_exit("Error: no se ordenó correctamente.\n");
}
//funcion principal
