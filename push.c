/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:47:15 by osadeddi          #+#    #+#             */
/*   Updated: 2024/10/31 20:24:16 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_b(int *stack_a, int *stack_b, int *top_a, int *top_b)
{
	stack_b[++(*top_b)] = stack_a[(*top_a)--];
	write(1, "pb\n", 3);
	return (1);
}

int	push_a(int *stack_a, int *stack_b, int *top_a, int *top_b)
{
	stack_a[++(*top_a)] = stack_b[(*top_b)--];
	write(1, "pa\n", 3);
	return (1);
}
