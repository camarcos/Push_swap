/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinamc <carolinamc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 17:00:57 by carolinamc        #+#    #+#             */
/*   Updated: 2024/12/04 17:01:48 by carolinamc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
	{
		error_exit("Error, numero de argumetos incorrecto\n");
		return (0);
	}
	initialize_stacks(argc, argv, &a, &b);
	sort_stack(a, b);
	return (0);
}
//función principal
