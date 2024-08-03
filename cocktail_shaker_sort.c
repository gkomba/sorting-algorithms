/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cocktail_shaker_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:08:48 by gildo             #+#    #+#             */
/*   Updated: 2024/08/03 11:49:30 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* Cocktail Sort is a variation of Bubble sort. The Bubble sort algorithm      */
/* always traverses elements from left and moves the largest element to its    */
/* correct position in the first iteration and second-largest in the second    */
/* iteration and so on. Cocktail Sort traverses through a given array in both  */
/* directions alternatively. Cocktail sort does not go through the unnecessary */
/* iteration making it efficient for large arrays.							   */
/* source: https://www.geeksforgeeks.org/cocktail-sort/						   */

void	ft_cocktail_shaker_sort(int *arr, int start, int end)
{
	int has_swap;
	int tmp;
	int i;

	has_swap = 1;
	while (has_swap)
	{
		has_swap = 0;
		i = start;
		while (i < (end - 1))
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				has_swap  = 1;
			}
			i++;
		}
		if (!has_swap)
			break ;
		has_swap = 0;
		--end;
		i = end - 1;
		while (i > start)
		{
			if (arr[i] > arr[i + 1])
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				has_swap  = 1;
			}
			i--; 
		}
		++start;
	}
}

void	print(int *tab, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		printf("%d\n", tab[i]);
}

int main(void)
{
	int arr[] = {34, 2, 78, 12, 45, 23, 9, 56};
	int size = 8;

    print(arr, size);
	printf("\n");
    ft_cocktail_shaker_sort(arr, 0, size);
	print(arr, size);
	return (0);
}