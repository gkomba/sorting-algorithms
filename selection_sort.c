/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 09:41:52 by gkomba            #+#    #+#             */
/*   Updated: 2024/08/03 12:11:41 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* Selection sort is a simple and efficient sorting algorithm that works by           */
/* repeatedly selecting the smallest (or largest) element from the unsorted portion   */
/* of the list and moving it to the sorted portion of the list. The algorithm         */
/* repeatedly selects the smallest (or largest) element from the unsorted portion of  */
/* the list and swaps it with the first element of the unsorted part. This process is */
/* repeated for the remaining unsorted portion until the entire list is sorted.       */
/* source: https://www.geeksforgeeks.org/selection-sort-algorithm-2/				  */

int	find_smaller(int *tab, int len)
{
	int	smaller;
	int	smaller_index;
	int	i;

	i = 1;
	smaller = tab[0];
	smaller_index = 0;
	while (i < len)
	{
		if (tab[i] < smaller)
		{
			smaller = tab[i];
			smaller_index = i;
		}
		i++;
	}
	return (smaller_index);
}

void	seletion_sort(int *tab, int len, int *new_tab)
{
	int	tmp_tab[len];
	int	i;
	int	smaller;
	int	j;

	i = -1;
	while (++i < len)
		tmp_tab[i] = tab[i];
	i = 0;
	while (i < len)
	{
		smaller = find_smaller(tmp_tab, (len - i));
		new_tab[i] = tmp_tab[smaller];
		j = smaller;
		while (j < len - i -1)
		{
			tmp_tab[j] = tmp_tab[j + 1];
			j++;
		}
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

int	main()
{
	int	tab[] = {5, 3, 6, 2, 10};
	int	len = sizeof(tab) / 4;
	int	new_tab[len];
	int size = 5;

	print(tab, size);
	printf("\n");
	seletion_sort(tab, len, new_tab);
	print(tab, size);
	return (0);
}
