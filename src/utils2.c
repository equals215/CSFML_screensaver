/*
** EPITECH PROJECT, 2017
** utils2.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** utils2.c file of the {{project_name}} project
*/

#include "screensaver.h"

int is_in_screen(sfVector2i *A)
{
	if ((WINDOW_WIDTH * A->y + A->x) < (WINDOW_WIDTH * 1080 + 1920))
		return (1);
	return (0);
}

void increment_values(int *randoms, int index, int nb)
{
	for (int i = 0; i < index; i++) {
		randoms[i] += nb;
	}
}

void put_values_rect(sfVector2i *coords, int *randoms)
{
	int j = 0;

	for (int i = 0; i < 4; i++, j++) {
		coords[i].x = randoms[j];
		j++;
		coords[i].y = randoms[j];
	}
}
