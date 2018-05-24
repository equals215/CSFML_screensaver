/*
** EPITECH PROJECT, 2017
** gaphics_base.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** gaphics_base.c file of the {{project_name}} project
*/

#include "screensaver.h"

void framebuffer_reset(window_t *window)
{
	free(window->framebuffer->pixels);
	free(window->framebuffer);
	framebuffer_create(window, WINDOW_WIDTH, WINDOW_HEIGHT);
}

void my_put_pixel(framebuffer_t *framebuffer, unsigned int x,
unsigned int y, int hex_value)
{
	sfColor *pixel_to_put = convert_hex_rgb(hex_value);

	if ((WINDOW_WIDTH * y + x) < (WINDOW_WIDTH * 1080 + 1920))
		framebuffer->pixels[WINDOW_WIDTH * y + x].r = pixel_to_put->r;
	if ((WINDOW_WIDTH * y + x) < (WINDOW_WIDTH * 1080 + 1920))
		framebuffer->pixels[WINDOW_WIDTH * y + x].g = pixel_to_put->g;
	if ((WINDOW_WIDTH * y + x) < (WINDOW_WIDTH * 1080 + 1920))
		framebuffer->pixels[WINDOW_WIDTH * y + x].b = pixel_to_put->b;
	if ((WINDOW_WIDTH * y + x) < (WINDOW_WIDTH * 1080 + 1920))
		framebuffer->pixels[WINDOW_WIDTH * y + x].a = pixel_to_put->a;
	free(pixel_to_put);
}

void framebuffer_create(window_t *window, unsigned int width,
unsigned int height)
{
	window->framebuffer = malloc(sizeof(framebuffer_t));
	window->framebuffer->width = width;
	window->framebuffer->height = height;
	window->framebuffer->pixels = malloc(sizeof(sfColor) * width * height);
	for (unsigned int x = 0; x < width; x++) {
		for (unsigned int y = 0; y < height; y++) {
			window->framebuffer->pixels[width * y + x].r = 0;
			window->framebuffer->pixels[width * y + x].g = 0;
			window->framebuffer->pixels[width * y + x].b = 0;
			window->framebuffer->pixels[width * y + x].a = 0;
		}
	}
}

int generate_sprite(window_t *window)
{
	window->texture = sfTexture_create(WINDOW_WIDTH, WINDOW_HEIGHT);

	if (!window->main_window)
		return (EXIT_FAILURE);
	sfTexture_updateFromPixels(window->texture,
		(const sfUint8 *) window->framebuffer->pixels,
		WINDOW_WIDTH, WINDOW_HEIGHT, 0, 0);
	if (!window->texture)
		return (EXIT_FAILURE);
	window->sprite = sfSprite_create();
	sfSprite_setTexture(window->sprite, window->texture, sfTrue);
	return (0);
}

window_t *init_window(void)
{
	window_t *window = malloc(sizeof(window_t));
	sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};

	window->mode = mode;
	framebuffer_create(window, WINDOW_WIDTH, WINDOW_HEIGHT);
	window->main_window = sfRenderWindow_create(window->mode,
		"my_screensaver", sfFullscreen, NULL);
	if (generate_sprite(window))
		return (NULL);
	window->w_clock = sfClock_create();
	window->w_time = sfClock_getElapsedTime(window->w_clock);
	return (window);
}
