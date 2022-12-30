/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <afaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:22:46 by polpi             #+#    #+#             */
/*   Updated: 2022/12/30 14:43:59 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools.h"

char	*strjoin_char(char const *s1, char ascii)
{
	char	*result;
	int		i;
	int		len_real;

	i = 0;
	len_real = (ft_strlen(s1) + 1);
	result = (char *)malloc(sizeof (char) * (len_real + 1));
	if (result == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = ascii;
	i++;
	result[i] = '\0';
	free ((void *)(s1));
	return (result);
}


int    ft_pow(int power)
{
	int	res;

	res = 2;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	while (power > 1)
	{
		res *= 2;
		power--;
	}
	return (res);
}

void	print_handler(int signal)
{ 
	static Minitalk t = {0, 0, NULL};

	if (!t.string)
	{
		t.string = malloc(sizeof(char) * 1);
		t.string[0] = 0;
	}
	if (signal == SIGUSR1)
		t.final += ft_pow(t.len);
	t.len++;
	if (t.len == 8)
	{
		if (t.final == 0)
		{
			ft_printf("Message reçu : %s\n", t.string);	
			free (t.string);
			t.string = NULL;
		}
		else
			t.string = strjoin_char(t.string, t.final);
		t.len = 0;
		t.final = 0;
	}
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	struct sigaction	act = {0};

	ft_printf("PID : %d\n", getpid());

	act.sa_handler = &print_handler;
	act.sa_flags = SA_NODEFER;

	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	
	while(1)
	{
		pause();
	}
}