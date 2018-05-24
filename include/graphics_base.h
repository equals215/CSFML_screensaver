/*
** EPITECH PROJECT, 2017
** graphics_base.h by tfoubert <thomas.foubert@epitech.eu>
** File description:
** graphics_base.h file of the {{project_name}} project
*/

#ifndef GRAPHICS_BASE_H
#define GRAPHICS_BASE_H

#include <SFML/Graphics.h>
#include "my.h"

void framebuffer_reset(window_t *window);
void my_put_pixel(framebuffer_t *framebuffer, unsigned int width,
	unsigned int height, int hex_value);
void framebuffer_create(window_t *window, unsigned int width, unsigned int height);
int generate_sprite(window_t *window);
window_t *init_window(void);

#endif
