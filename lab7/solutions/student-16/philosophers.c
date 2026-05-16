#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_PHILOS	5
#define EAT_COUNT	3

typedef enum e_state
{
	THINKING,
	HUNGRY,
	EATING
}	t_state;

typedef enum e_philo_flags
{
	PHILO_NONE      = 0,
	PHILO_HAS_LEFT  = 1 << 0,
	PHILO_HAS_RIGHT = 1 << 1
}	t_philo_flags;

typedef struct s_philosopher
{
	int				id;
	t_state			state;
	t_philo_flags	flags;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*print_mutex;
}	t_philosopher;

static void	print_action(t_philosopher *philo, const char *action)
{
	pthread_mutex_lock(philo->print_mutex);
	printf("Philosopher %d %s\n", philo->id, action);
	pthread_mutex_unlock(philo->print_mutex);
}

static void	think(t_philosopher *philo)
{
	philo->state = THINKING;
	print_action(philo, "is THINKING");
	usleep(100000);
}

static void	take_forks(t_philosopher *philo)
{
	philo->state = HUNGRY;
	print_action(philo, "is HUNGRY");
	if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		philo->flags |= PHILO_HAS_LEFT;
		print_action(philo, "took left fork");
		pthread_mutex_lock(philo->right_fork);
		philo->flags |= PHILO_HAS_RIGHT;
		print_action(philo, "took right fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		philo->flags |= PHILO_HAS_RIGHT;
		print_action(philo, "took right fork");
		pthread_mutex_lock(philo->left_fork);
		philo->flags |= PHILO_HAS_LEFT;
		print_action(philo, "took left fork");
	}
}

static void	eat(t_philosopher *philo)
{
	philo->state = EATING;
	print_action(philo, "is EATING");
	usleep(200000);
}

static void	put_forks(t_philosopher *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo->flags = PHILO_NONE;
	print_action(philo, "put forks");
}

static void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;
	int				i;

	philo = (t_philosopher *)arg;
	i = 0;
	while (i < EAT_COUNT)
	{
		think(philo);
		take_forks(philo);
		eat(philo);
		put_forks(philo);
		i++;
	}
	return (NULL);
}

int	main(void)
{
	pthread_mutex_t	forks[NUM_PHILOS];
	pthread_mutex_t	print_mutex;
	t_philosopher	philos[NUM_PHILOS];
	int				i;

	pthread_mutex_init(&print_mutex, NULL);
	i = 0;
	while (i < NUM_PHILOS)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < NUM_PHILOS)
	{
		philos[i].id = i + 1;
		philos[i].state = THINKING;
		philos[i].flags = PHILO_NONE;
		philos[i].left_fork = &forks[i];
		philos[i].right_fork = &forks[(i + 1) % NUM_PHILOS];
		philos[i].print_mutex = &print_mutex;
		i++;
	}
	i = 0;
	while (i < NUM_PHILOS)
	{
		pthread_create(&philos[i].thread, NULL, philosopher_routine, &philos[i]);
		i++;
	}
	i = 0;
	while (i < NUM_PHILOS)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < NUM_PHILOS)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(&print_mutex);
	return (0);
}
