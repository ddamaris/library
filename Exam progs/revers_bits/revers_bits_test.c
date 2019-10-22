#include <unistd.h>

void	pr_bit(unsigned char c)
{
	int		i;
	char	ch;
	
	i = 0;
	while (i < 8)
	{
		ch = c & 128;
		(ch == 0) ? write(1, "0", 1) : write(1, "1", 1);
		c = c << 1;
		i++;
	}
	write(1,"\n", 1);
}

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	ch;
	unsigned char	t;
	int				l;

	l = 0;
	ch = 0;
	while (l < 7)
	{
		t = octet & 1;
		ch = ch | t;
		ch = ch << 1;
		pr_bit(ch);
		octet = octet >> 1;
		l++;
	}
	return (ch);
}
int	main(void)
{
	unsigned char c;

	c = 'f';
	write(1, &c, 1);
	write(1, "\n", 1);
	pr_bit(c);
	write(1, "\n", 1);
	c = reverse_bits(c);
	write(1, &c, 1);
	write(1, "\n", 1);
	return (0);
}
