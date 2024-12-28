/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osadeddi <osadeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:25:19 by osadeddi          #+#    #+#             */
/*   Updated: 2024/10/28 18:00:24 by osadeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

static int	check_isdigit(int argc, char **argv, int is_split)
{
	int	i;
	int	j;

	i = 1;
	if (is_split)
		i = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_duplicates(int argc, char **argv, int is_split)
{
	int	i;
	int	j;

	i = 1;
	if (is_split)
		i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	int_range(int argc, char **argv, int is_split)
{
	int	i;
	int	j;

	i = 1;
	if (is_split)
		i = 0;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j] == '0' && argv[i][j])
			j++;
		if (ft_strlen(argv[i]) - j > 10)
			return (0);
		if (ft_strlen(argv[i]) - j == 10)
		{
			if ((ft_strncmp(argv[i], "2147483647", 10) > 0 && j == 0)
				|| (ft_strncmp(argv[i] + j, "2147483648", 10) > 0 && j == 1))
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_input(int *argc, char ***argv, int *is_split)
{
	char	**args;

	if (*argc == 2)
	{
		args = ft_split((*argv)[1], ' ');
		if (!args)
			return (0);
		*argv = args;
		*argc = count_args(args);
		*is_split = 1;
	}
	if (!check_isdigit(*argc, *argv, *is_split))
		return (free_args(args, *is_split), 0);
	if (!int_range(*argc, *argv, *is_split))
		return (free_args(args, *is_split), 0);
	if (!check_duplicates(*argc, *argv, *is_split))
		return (free_args(args, *is_split), 0);
	return (1);
}
