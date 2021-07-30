#include "tpool.h"

int	func(void *v)
{
	int	*a = v;

	*a = 1;
	return (1);
}

int	main(void)
{
	t_tpool	pool;
	int	a = 0;

	init_tpool(&pool, 1);
	tpool_add(&pool, &func, &a);
	tpool_wait(&pool);
	return (0);
}
