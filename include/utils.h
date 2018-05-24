/*
** EPITECH PROJECT, 2017
** utils.h
** File description:
** utils.h file of the {{project_name}} project
*/

#ifndef UTILS_H
#define UTILS_H

#include <SFML/Graphics.h>
#include "my.h"

int *get_random_rect_values(void);
sfColor *convert_hex_rgb(unsigned int hex_value);
int is_num(char *s);
int is_id(int id_to_check);
void destroyer(window_t *window);

void put_values_rect(sfVector2i *coords, int *randoms);
void increment_values(int *randoms, int index, int nb);
int is_in_screen(sfVector2i *A);

#endif
