/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hobby.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jda-cost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 10:24:32 by jda-cost          #+#    #+#             */
/*   Updated: 2025/12/18 10:24:33 by jda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping");
	usleep(philo->table->time_to_sleep * 1000);
}

void	think(t_philo *philo)
{
	print_status(philo, "is thinking");
}

void	eat(t_philo *philo)
{
	take_forks(philo);
	philo->last_meal_time = get_time_in_ms();
	print_status(philo, "is eating");
	usleep(philo->table->time_to_eat * 1000);
	philo->meals_eaten++;
	drop_forks(philo);
}

int	everyone_ate(t_table *table)
{
	int	i;

	if (table->must_eat_count == -1)
		return (0);
	i = 0;
	while (i < table->number_of_philosophers)
	{
		if (table->philo[i].meals_eaten < table->must_eat_count)
			return (0);
		i++;
	}
	return (1);
}
