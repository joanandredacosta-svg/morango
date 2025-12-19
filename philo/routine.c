/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jda-cost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:15:45 by jda-cost          #+#    #+#             */
/*   Updated: 2025/12/16 17:15:47 by jda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
	}
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	print_status(t_philo *philo, char *msg)
{
	long	timestamp;

	pthread_mutex_lock(&philo->table->print_mutex);
	if (!philo->table->someone_died)
	{
		timestamp = get_time_in_ms() - philo->table->start_time;
		printf("%ld %d %s\n", timestamp, philo->id, msg);
	}
	pthread_mutex_unlock(&philo->table->print_mutex);
}

long	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	*monitor(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	while (1)
	{
		i = 0;
		while (i < table->number_of_philosophers)
		{
			if (get_time_in_ms() - table->philo[i].last_meal_time > \
				table->time_to_die)
			{
				pthread_mutex_lock(&table->print_mutex);
				printf("%ld %d died\n", get_time_in_ms() - \
					table->start_time, table->philo[i].id);
				pthread_mutex_unlock(&table->print_mutex);
				table->someone_died = 1;
				return (NULL);
			}
			i++;
		}
		if (everyone_ate(table))
			return (table->someone_died = 1, NULL);
		usleep(1000);
	}
}
