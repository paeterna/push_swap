/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:44:37 by osadeddi          #+#    #+#             */
/*   Updated: 2024/11/02 15:33:39 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <libft.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	top_a;
	int	top_b;
}		t_stack;

typedef struct s_halving_b
{
	int	mid;
	int	rotations;
	int	chunk_size;
	int	chunk_b;
	int	flag;
	int	j;
}		t_halving_b;

typedef struct s_sort_chunk
{
	int	mid;
	int	chunk_size;
	int	*chunk_b2a;
	int	chunk_a;
	int	i;
	int	rotations;
}		t_sort_chunk;

void	swap_a(int *stack_a, int *top_a);
void	swap_b(int *stack_b, int *top_b);
void	swap_s(int *stack_a, int *stack_b, int *top_a, int *top_b);
int		push_b(int *stack_a, int *stack_b, int *top_a, int *top_b);
int		push_a(int *stack_a, int *stack_b, int *top_a, int *top_b);
int		rotate_a(int *stack_a, int *top_a);
int		rotate_b(int *stack_b, int *top_b);
int		rotate_r(int *stack_a, int *stack_b, int *top_a, int *top_b);
int		reverse_rotate_a(int *stack_a, int *top_a);
int		reverse_rotate_b(int *stack_b, int *top_b);
int		reverse_rotate_r(int *stack_a, int *stack_b, int *top_a, int *top_b);
int		is_sorted(int *stack_a, int top_a);
int		mid_a(int *stack, int top);
int		mid_b(int *temp, int j);
int		*sort_stack(int *stack, int top);
void	halving_a(t_stack *s, int *chunk, int *i);
int		is_smallest(int *stack, int top, int j);
int		check_rotation_a(int *stack, int top, int mid);
int		check_rotation_b(int *stack, int top, int mid);
int		chunk_count(int a);
void	*sort_chunk(t_stack *s, int chunk);
void	*sort_chunk_init(t_sort_chunk *c, t_stack *s);
void	*stack_init(t_stack **s, int argc, char **argv, int is_split);
void	*halving_b(t_stack *s, int *chunk, int *i);
void	halving_b_init(t_halving_b *b);
int		error_fun(t_stack *s);
void	*free_c(t_sort_chunk *c);
void	free_args(char **args, int is_split);
void	free_stack(t_stack *s);
void	loop_a(t_stack *s, t_sort_chunk *c);
int		check_input(int *argc, char ***argv, int *split);

#endif
