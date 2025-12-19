/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jda-cost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:15:23 by jda-cost          #+#    #+#             */
/*   Updated: 2025/12/16 17:15:25 by jda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->table->number_of_philosophers == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has take a fork");
		usleep(philo->table->time_to_die * 1000);
		print_status(philo, "died");
		pthread_mutex_unlock(philo->left_fork);
		return (NULL);
	}
	while (!philo->table->someone_died)
	{
		eat(philo);
		philo_sleep(philo);
		think(philo);
	}
	return (NULL);
}

static void	init_table(t_table *table, int argc, char **argv)
{
	int	i;

	table->number_of_philosophers = ft_atoi(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		table->must_eat_count = ft_atoi(argv[5]);
	else
		table->must_eat_count = -1;
	table->someone_died = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * \
		table->number_of_philosophers);
	i = 0;
	while (i < table->number_of_philosophers)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&table->print_mutex, NULL);
}

static void	init_philos_and_threads(t_table *table, t_philo **philos)
{
	int	i;

	*philos = malloc(sizeof(t_philo) * table->number_of_philosophers);
	table->start_time = get_time_in_ms();
	i = 0;
	while (i < table->number_of_philosophers)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].meals_eaten = 0;
		(*philos)[i].last_meal_time = table->start_time;
		(*philos)[i].left_fork = &table->forks[i];
		(*philos)[i].right_fork = &table->forks[(i + 1) % \
			table->number_of_philosophers];
		(*philos)[i].table = table;
		i++;
	}
	table->philo = *philos;
	i = 0;
	while (i < table->number_of_philosophers)
	{
		pthread_create(&(*philos)[i].thread_id, NULL,
			philosopher_routine, &(*philos)[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_table		table;
	t_philo		*philos;
	pthread_t	monitor_thread;
	int			i;

	if (argc < 5 || argc > 6)
	{
		printf("./philo number_of_philosophers time_to_die time_to_eat \
time_to_sleep [must_eat_count]\n");
		return (0);
	}
	init_table(&table, argc, argv);
	init_philos_and_threads(&table, &philos);
	pthread_create(&monitor_thread, NULL, monitor, &table);
	i = 0;
	while (i < table.number_of_philosophers)
		pthread_join(philos[i++].thread_id, NULL);
	pthread_join(monitor_thread, NULL);
	i = 0;
	while (i < table.number_of_philosophers)
		pthread_mutex_destroy(&table.forks[i++]);
	pthread_mutex_destroy(&table.print_mutex);
	free(table.forks);
	free(philos);
	return (0);
}
