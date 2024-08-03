/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 13:41:14 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/03 11:56:49 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* Bubble Sort is the simplest sorting algorithm that works by      */
/* repeatedly swapping the adjacent elements if they are in the     */
/* wrong order. This algorithm is not suitable for large data       */
/* sets as its average and worst-case time complexity is quite high.*/
/* source: https://www.geeksforgeeks.org/bubble-sort-algorithm/     */

void	ft_bubble_sort(int *tab, int len)
{
	int	i;
	int	swap;

	i = 0;
	while (i < len - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			swap = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
}

void	print(int *tab, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		printf("%d\n", tab[i]);
}

int	main(void)
{
	int	tab[] = {3, 2, 1, 4};
	int size = 4;
	
	print(tab, size);
	printf("\n");
	ft_bubble_sort(tab, size);
	print(tab, size);
	return (0);
}

