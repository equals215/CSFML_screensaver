/*
** EPITECH PROJECT, 2017
** screensaver.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** screensaver.c file of the {{project_name}} project
*/

#include "screensaver.h"

void anim1(long long i, window_t *window)
{
	sfVector2i A;
	sfVector2i B;
	int rand_x = rand();
	int rand_y = rand();
	int color = rand();
	(void)i;

	if ((window->elapsed_reset +=
	(float) window->w_time.microseconds / 1000000.0) > 5) {
		framebuffer_reset(window);
		window->elapsed_reset = 0.0;
		sfClock_restart(window->w_clock);
	}
	A.x = (1920 / 2) % 1920;
	A.y = (1080 / 2) % 1080;
	B.x = (rand_x) % 1920;
	B.y = (rand_y) % 1080;
	draw_line(window->framebuffer, &A, &B, color);
}

void anim2(long long i, window_t *window)
{
	sfVector2i A;
	int rand_x = rand();
	int rand_y = rand();
	int r = rand() % 10;
	int color = rand();

	if ((window->elapsed_reset +=
	(float) window->w_time.microseconds / 1000000.0) > 5) {
		framebuffer_reset(window);
		window->elapsed_reset = 0.0;
		sfClock_restart(window->w_clock);
	}
	A.x = (rand_x) % 1920;
	A.y = (rand_y) % 1080;
	plot_circle(window->framebuffer, &A, r + (i % 10), color);
}

void anim3(long long i, window_t *window)
{
	sfVector2i *coords = malloc(sizeof(sfVector2i) * 4);
	sfVector2i *coords_tmp = malloc(sizeof(sfVector2i) * 4);
	int color = rand();
	(void)i;

	put_values_rect(coords, window->randoms);
	put_values_rect(coords_tmp, window->randoms);
	if ((window->elapsed_reset +=
	(float) window->w_time.microseconds / 1000000.0) > 5) {
		framebuffer_reset(window);
		window->elapsed_reset = 0.0;
		sfClock_restart(window->w_clock);
		window->randoms = get_random_rect_values();
	}
	framebuffer_reset(window);
	draw_rect(window->framebuffer, coords, coords_tmp, color);
	increment_values(window->randoms, 8, 5);
}

void do_screensaver(int id, long long i, window_t *window)
{
	void (*animation[ANIMATIONS_NB])(long long, window_t *) =
		{anim1, anim2, anim3};
	float time_ms = 0.0;

	window->w_time = sfClock_getElapsedTime(window->w_clock);
	if ((time_ms = (float) window->w_time.microseconds / 1000000.0)
	> 0.04) {
		(*animation[id - 1])(i, window);
		sfTexture_updateFromPixels(window->texture,
			(const sfUint8 *) window->framebuffer->pixels,
			WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0);
		sfClock_restart(window->w_clock);
	}

}
