/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jda-cost <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 08:52:27 by jda-cost          #+#    #+#             */
/*   Updated: 2025/12/18 08:52:29 by jda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal_time;
	pthread_t		thread_id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	int				number_of_philosophers;
	long			time_to_die;
	long			start_time;
	long			time_to_eat;
	long			time_to_sleep;
	int				must_eat_count;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	int				someone_died;
	struct s_philo	*philo;
}	t_table;

//rotina

void		philo_sleep(t_philo *philo);
void		think(t_philo *philo);
void		eat(t_philo *philo);
void		*monitor(void *arg);

//pegando e largando garfos

void		take_forks(t_philo *philo);
void		drop_forks(t_philo *philo);
void		print_status(t_philo *philo, char *msg);
long		get_time_in_ms(void);
int			everyone_ate(t_table *table);

//utils

int			ft_isdigit(int c);
int			ft_atoi(const char *str);
long		ft_atol(const char *str);
#endif
