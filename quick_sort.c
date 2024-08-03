/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:43:18 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/03 12:15:07 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* QuickSort is a sorting algorithm based on the Divide and Conquer algorithm 		 */
/* that picks an element as a pivot and partitions the given array around 			 */
/* the picked pivot by placing the pivot in its correct position in the sorted array.*/
/* source: https://www.geeksforgeeks.org/quick-sort-algorithm/ 						 */

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

int	partition(int *tab, int start, int end)
{
	int	pivot = 0;

	pivot = ((tab[start] + tab[end] + tab[(start + end) / 2]) / 3);
	while (start < end)
	{
		while (start < end && tab[start] <= pivot)
			start++;
		while (start < end && tab[end] > pivot)
			end--;
		ft_swap(&tab[start], &tab[end]);
	}
	return (start);
}

void	ft_qsort(int *tab, int start, int end)
{
	int	position = 0;

	if (start < end)
	{
		position = partition(tab, start, end);
		ft_qsort(tab, start, position - 1);
		ft_qsort(tab, position, end);
	}
}

void	print(int *tab, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		printf("%d\n", tab[i]);
}

int	main()
{
	int	tab[] = {4, 2, 6, 8, 1};
	int size = 5;
	print(tab, size);
	printf("\n");
	ft_qsort(tab, 0, size - 1);
	print(tab, size);
}
