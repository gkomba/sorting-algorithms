/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertin_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:05:50 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/03 17:16:58 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* Insertion sort is a simple sorting algorithm that works by iteratively           */
/* inserting each element of an unsorted list into its correct position in          */
/* a sorted portion of the list. It is a stable sorting algorithm, meaning that     */
/* elements with equal values maintain their relative order in the sorted output.   */
/* Insertion sort is a simple sorting algorithm that works by building a sorted     */
/* array one element at a time. It is considered an ”in-place” sorting algorithm,   */
/* meaning it doesn’t require any additional memory space beyond the original array.*/
/* soruce: https://www.geeksforgeeks.org/insertion-sort-algorithm/                  */

void    ft_insertion_sort(int *arr, int size)
{
    int tmp;
    int i;
    int j;

    i = 0;
    while (++i < size)
    {
        tmp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > tmp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tmp;
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
	ft_insertion_sort(tab, size);
	print(tab, size);
}