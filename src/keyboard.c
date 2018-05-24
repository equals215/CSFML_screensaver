/*
** EPITECH PROJECT, 2017
** keyboard.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** keyboard.c file of the {{project_name}} project
*/

#include "screensaver.h"

void keyboard_event(window_t *window)
{
	if (window->event.type == sfEvtKeyPressed)
		sfRenderWindow_close(window->main_window);
}
