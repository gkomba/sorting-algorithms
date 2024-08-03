/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnome_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkomba <<marvin@42.fr> >                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:18:53 by gildo             #+#    #+#             */
/*   Updated: 2024/08/03 12:22:22 by gkomba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/* Gnome Sort also called Stupid sort is based on the concept of a Garden Gnome   	 */
/* sorting his flower pots.A garden gnome sorts the flower pots by the following 	 */
/* method:																		 	 */
/* - He looks at the flower pot next to him and the previous one; if they are in 	 */
/* the right order he steps one pot forward, otherwise he swaps them and steps   	 */ 
/* one pot backwards.															 	 */
/* - If there is no previous pot (he is at the starting of the pot line), he 	     */
/* steps forwards; if there is no pot next to him (he is at the end of the pot line) */
/* he is done.																		 */
/* source: https://www.geeksforgeeks.org/gnome-sort-a-stupid-one/					 */

void	ft_gnome_sort(int *tab, int size)
{
	int i;
	int tmp;

	i = 0;
	while (i < size)
	{
		if (i == 0 || tab[i] >= tab[i - 1])
			i++;
		else
		{
			tmp = tab[i];
			tab[i] = tab[i - 1];
			tab[i - 1] = tmp;
			i--;
		}
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
	ft_gnome_sort(arr, size);
	print(arr, size);
	return 0;
}