/*
** EPITECH PROJECT, 2017
** window.h
** File description:
** window.h file of the {{project_name}} project
*/

#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.h>
#include "framebuffer.h"

typedef struct window
{
	sfVideoMode mode;
	sfRenderWindow *main_window;
	sfEvent event;
	framebuffer_t *framebuffer;
	sfSprite *sprite;
	sfTexture *texture;
	sfClock *w_clock;
	sfTime w_time;
	float elapsed_reset;
	int *randoms;
}window_t;

#endif
