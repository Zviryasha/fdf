#include "minilibx/mlx.h"
#include "libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "get_next_line/get_next_line.h"

int		is_corect_name(char *s)
{
	int i;
	int j;

	i = ft_strlen(s) - 1;
	if (s[i] == 'f' && s[i - 1] == 'd' && s[i - 2] == 'f' && s[i - 3] == '.')
	{
		i = 0;
		j = 0;
		while (s[i] != '\0')
		{
			if (s[i] == '.')
				j++;
			i++;
		}
	if (j == 1)
		return (0);
	}
	return (-1);
}

int is_corect_table(int fd)
{
	char *line;

	while ((get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
	}
	return (0);
}

int		is_corect_file(char *s)
{
	int fd;

	if (is_corect_name(s) != 0)
		return (-1);
	if ((fd = open(s, O_RDONLY)) < 0)
		return (-1);
	if (is_corect_table(fd) != 0)
		return (-1);
	return (0);
}

int	main(int ac, char **ar)
{
	if (ac == 2)
	{
		if (is_corect_file(ar[1]) == 0)
			printf("OK!\n");
		else
			printf("Error\n");
	}
	if (ac == 1)
	{
		printf("usage:\n./fdf [map]\n");
	}
	if (ac > 2)
	{
		printf("Error\n");
	}
	return (0);
}