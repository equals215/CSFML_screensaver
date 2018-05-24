/*
** EPITECH PROJECT, 2017
** framebuffer.h by tfoubert <thomas.foubert@epitech.eu>
** File description:
** framebuffer.h file of the {{project_name}} project
*/

#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <SFML/Graphics.h>

typedef struct framebuffer {
	unsigned int width;
	unsigned int height;
	sfColor *pixels;
}framebuffer_t;

#endif
