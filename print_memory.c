#include <unistd.h>
#include <stdlib.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_hexa(unsigned char c)
{
	if (c >= 16)
	{
		ft_hexa(c / 16);
		ft_hexa(c % 16);
	}
	else
	{
		ft_putchar(c + ((c < 10) ? '0' : 'a' - 10));
	}
}

void	ft_char(unsigned char c)
{
	ft_putchar((c > 33 && c <127)? c : '.');
}

void	print_memory(const void *addr, size_t size)
{
	unsigned char *str;
	str = (unsigned char *) addr;
	size_t i = 0;
	int nbr = 0;
	int tmp = 0;

	while (i < size)
	{
		if (nbr < 16)
		{
			if (str[i] < 16)
				ft_putchar('0');
			ft_hexa(str[i]);
			tmp++;
			if (tmp == 2)
			{
				ft_putchar(' ');
				tmp = 0;
			}

		}
		i++;
		nbr++;
		if(nbr == 16 || i == size)
		{
			if (nbr < 16)
			{
				tmp = nbr;
				while (tmp < 16)
				{
					ft_putchar(' ');
					ft_putchar(' ');
					if (tmp % 2 == 0)					
						ft_putchar(' ');
					tmp++;
				}
			}
			while (nbr > 0)
			{
				ft_char(str[i - nbr]);
				nbr--;
			}
			ft_putchar('\n');
		}
	}
}
int main(int ac, char **av)
{char	tab[26] = {0, 83, 97, 108,
		117, 116,  21, 32, 108, 101, 115, 26,42,42,42,42, 100, 111, 112, 97, 105, 110, 1, 42, 42 };
//int tab[2] = { 0,2147483647};
	print_memory(tab, sizeof(tab));
	return (0);

	//	ft_hexa((unsigned char)atoi(av[1]));
	//	return (0);
}

