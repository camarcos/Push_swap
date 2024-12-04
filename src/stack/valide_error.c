/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinamc <carolinamc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:41:22 by carolinamc        #+#    #+#             */
/*   Updated: 2024/12/04 17:44:02 by carolinamc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str)
		error_exit("Error: no es un número entero.");
	return (result * sign);
}
//mirar si son solo numeros

long	validate_max_min(const char **str, long result, int sign)
{
	while (**str >= '0' && **str <= '9')
	{
		if (sign == 1 && result > (LONG_MAX - (**str - '0')) / 10)
			return (LONG_MAX);
		if (sign == -1 && result > (LONG_MAX - (**str - '0')) / 10)
			return (LONG_MIN);
		result = result * 10 + (**str - '0');
		(*str)++;
	}
	return (result);
}
//validar si el numero esta en el rango de long

int	duplicates(t_stack *a)
{
	t_node	*current;
	t_node	*check;

	current = a->top;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}
//comprobar si hay repetidos

int	is_sorted(t_stack *a)
{
	t_node	*current;

	if (!a || a->size <= 1)
		return (1);
	current = a->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
//comprobar si la pila esta ordenada

void	error_exit(const char *message)
{
	(void)message;		
	write(2, "Error.\n", 6);
	exit(EXIT_FAILURE);
}
//mensaje de error y salida del programa