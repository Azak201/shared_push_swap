/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:53:01 by amismail          #+#    #+#             */
/*   Updated: 2024/12/04 16:53:11 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*the main function work as follow , splitter functoin take the argc & argv
and return 2D array that have all inputs as a strings .
the handler function take the array of inputs and if there any problem with it
the function will call exit and break the program otherwise it will back to main.
after that the inserter function will take the array of inputs and convert it to 
linked list then will send it to function that will sort it if ther any error 
the inserter will return 1 that will make the condition of if(val != 0) true then
it will free and exit the programm in case of sucsess the inserter will return 0. */
int	main(int arc, char **arv)
{
	char	**inputs;
	int		val;

	inputs = spliter(arc, arv);
	if (!inputs)
		ft_exit(1, NULL);
	handler(inputs);
	val = inserter(inputs);
	if (val != 0)
		ft_exit(2, inputs);
	ft_exit(3, inputs);
}
