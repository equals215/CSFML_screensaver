/*
** EPITECH PROJECT, 2017
** graphics_tools.h by tfoubert <thomas.foubert@epitech.eu>
** File description:
** graphics_tools.h file of the {{project_name}} project
*/

#ifndef GRAPHICS_TOOLS_H
#define GRAPHICS_TOOLS_H

#include "framebuffer.h"
#include <SFML/Graphics.h>

void draw_line(framebuffer_t *framebuffer, sfVector2i *A, sfVector2i *B, unsigned int color);
void plot_circle(framebuffer_t *framebuffer, sfVector2i *A, int r, unsigned int color);
void draw_rect(framebuffer_t *framebuffer, sfVector2i *coords, sfVector2i *coords_temp, unsigned int color);

#endif
