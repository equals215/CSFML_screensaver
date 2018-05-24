/*
** EPITECH PROJECT, 2017
** handlers.h by tfoubert <thomas.foubert@epitech.eu>
** File description:
** handlers.h file of the {{project_name}} project
*/

#ifndef HANDLERS_H
#define HANDLERS_H

#include <SFML/Graphics.h>
#include "my.h"

int graphical_handler(int id, window_t *window);
int options_handler(int ac, char **av);
int flag_handler(char *flag);

#endif
