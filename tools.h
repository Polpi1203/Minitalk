#ifndef TOOLS_H
# define TOOLS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"

void	set_signal_action(void);
int     ft_pow(int power);
char	*strjoin_char(char const *s1, char ascii);
void	print_handler(int signal);
int     binary_to_ascii(int	*result);

typedef struct Minitalk Minitalk; 
struct Minitalk
{
    int     len;
    int     final;
    char    *string;
};

#endif