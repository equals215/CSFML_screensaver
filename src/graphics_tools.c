/*
** EPITECH PROJECT, 2017
** graphics_tools.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** graphics_tools.c file of the {{project_name}} project
*/

#include "screensaver.h"

void draw_line(framebuffer_t *framebuffer, sfVector2i *A, sfVector2i *B,
unsigned int color)
{
	int dx = abs(B->x - A->x);
	int sx = A->x < B->x ? 1 : -1;
	int dy = -abs(B->y - A->y);
	int sy = A->y < B->y ? 1 : -1;
	int err = dx + dy, e2;

	for (;;) {
		my_put_pixel(framebuffer, A->x, A->y, color);
		if (A->x == B->x && A->y == B->y)
			break;
		e2 = 2 * err;
		if (e2 >= dy) {
			err += dy;
			A->x += sx;
		}
		if (e2 <= dx) {
			err += dx;
			A->y += sy;
		}
	}
}

void draw_rect(framebuffer_t *framebuffer, sfVector2i *coords,
sfVector2i *coords_tmp, unsigned int color)
{
	if (is_in_screen(&coords[0]) && is_in_screen(&coords[1]))
		draw_line(framebuffer, &coords[0], &coords[1], color);
	if (is_in_screen(&coords_tmp[1]) && is_in_screen(&coords[3]))
		draw_line(framebuffer, &coords_tmp[1], &coords[3], color);
	if (is_in_screen(&coords_tmp[3]) && is_in_screen(&coords[2]))
		draw_line(framebuffer, &coords_tmp[3], &coords[2], color);
	if (is_in_screen(&coords_tmp[2]) && is_in_screen(&coords_tmp[0]))
		draw_line(framebuffer, &coords_tmp[2], &coords_tmp[0], color);
}

void plot_circle(framebuffer_t *framebuffer, sfVector2i *A, int r,
unsigned int color)
{
	int x = -r;
	int y = 0;
	int err = 2 - 2 * r;

	do {
		if (((A->x - x) < WINDOW_WIDTH) && ((A->y + y) < WINDOW_HEIGHT))
			my_put_pixel(framebuffer, A->x - x, A->y + y, color);
		if (((A->x - y) < WINDOW_WIDTH) && ((A->y - x) < WINDOW_HEIGHT))
			my_put_pixel(framebuffer, A->x - y, A->y - x, color);
		if (((A->x + x) < WINDOW_WIDTH) && ((A->y - y) < WINDOW_HEIGHT))
			my_put_pixel(framebuffer, A->x + x, A->y - y, color);
		if (((A->x + y) < WINDOW_WIDTH) && ((A->y + x) < WINDOW_HEIGHT))
			my_put_pixel(framebuffer, A->x + y, A->y + x, color);
		r = err;
		if (r > x) err += ++x * 2 + 1;
		if (r <= y) err += ++y * 2 + 1;
	} while (x < 0);
}
