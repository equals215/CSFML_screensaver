/*
** EPITECH PROJECT, 2017
** utils.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** utils.c file of the {{project_name}} project
*/

#include "screensaver.h"

int *get_random_rect_values(void)
{
	int *values = malloc(sizeof(int) * 8);

	values[4] = rand() % 1920; //valeur C.x
	values[5] = rand() % 1080; //valeur C.y
	values[0] = values[4]; //valeur A.x
	values[1] = values[5] + (rand() % (1080 - values[5])); //valeur A.y
	values[2] = values[4] + (rand() % (1920 - values[4])); //valeur B.x
	values[3] = values[1]; //valeur B.y
	values[6] = values[2]; //valeur D.x
	values[7] = values[5]; //valeur D.y
	return (values);
}

sfColor *convert_hex_rgb(unsigned int hex_value)
{
	sfColor *rgb_values = malloc(sizeof(sfColor));

	rgb_values->r = ((hex_value >> 16) & 0xFF);
	rgb_values->g = ((hex_value >> 8) & 0xFF);
	rgb_values->b = ((hex_value) & 0xFF);
	rgb_values->a = 255;
	return (rgb_values);
}

int is_num(char *s)
{
	for (int i = 0; i < my_strlen(s); i++)
		if (s[i] <= 48 && s[i] >= 57)
			return (0);
	return (1);
}

int is_id(int id_to_check)
{
	int i = ANIMATIONS_NB;
	int anim_id[i];

	for (int j = 0; j < i; j++)
		anim_id[j] = j + 1;
	for (int j = 0; j < i; j++) {
		if (anim_id[j] == id_to_check)
			return (1);
	}
	return (0);
}

void destroyer(window_t *window)
{
	sfTexture_destroy(window->texture);
	sfSprite_destroy(window->sprite);
	sfRenderWindow_destroy(window->main_window);
}
