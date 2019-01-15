#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
void	test2(void *d)
{
	unsigned long int u = d;
	printf("%d\n", u);
	printf("%u\n", u);

}

void	test(int ac, ...)
{
	va_list ap;
	va_start(ap, ac);
	void *d;
	d =	va_arg(ap, void *);
	test2(d);	
	va_end(ap);
}

int		main(int ac, char **av)
{
	void *ret = atoi(av[1]);
	int u = 2147483647;
	unsigned int z = atoi(av[1]);
	if(ac){}
	printf("%mdaoifapme aekwkapseph.7lld %          y     %d\n", atoi(av[1]));
	printf("%d\n", z);
	printf("%u\n", atoi(av[1]));
	printf("%p\n", av[1]);
	printf("%#lx\n", av[1]);
	
	test(ac,ret);
	return (0);
}
