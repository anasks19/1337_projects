/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achahid- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 13:57:01 by achahid-          #+#    #+#             */
/*   Updated: 2024/04/10 13:57:03 by achahid-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

size_t		ft_strlen(const char *str);
long		ft_atol(const char *str);
t_bool		dead_loop(t_philo *philo);
t_bool		full_loop(t_philo *philo);

/**
 * ft_strlen - Get the length of str
 * @str: pointer to the string
 * 
 * Return: string's length
*/
size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (*(str + length))
		length++;
	return (length);
}

/**
 * ft_atol - converts a string to a long intger
 * @str: pointer to the string
 * 
 * Return: long integer.
*/
long	ft_atol(const char *str)
{
	int			sign;
	long		result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}

/**
 * dead_loop - checks continueously for
 * a philosopher death.
 * @philo: pointer to philosophers
 * 
 * Return: state of life; true if death, else false.
*/
t_bool	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (philo->program->simulation_end == true)
		return (pthread_mutex_unlock(philo->dead_lock), true);
	return (pthread_mutex_unlock(philo->dead_lock), false);
}

/**
 * full_loop -
*/
t_bool	full_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->full_lock);
	if (philo->full == true)
		return (pthread_mutex_unlock(philo->full_lock), true);
	return (pthread_mutex_unlock(philo->full_lock), false);
}