/*
** EPITECH PROJECT, 2017
** main.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** main.c file of the {{project_name}} project
*/

#include "screensaver.h"

int flag_handler(char *flag)
{
	if (flag[0] == '-') {
		if (flag[1] == 'd')
			animations_printer();
		else if (flag[1] == 'h')
			help_printer();
		else {
			my_printf("./my_screensaver: invalid flag\n%s\n",
				"retry with -h");
			return (84);
		}
	} else if (is_num(flag) && is_id(my_atoi(flag)))
		return (my_atoi(flag));
	else {
		my_printf("./my_screensaver: invalid option\n%s\n",
			"retry with -h");
		return (84);
	}
	return (-1);
}

int options_handler(int ac, char **av)
{
	int flag_return = 0;

	switch (ac) {
		default :
			my_printf("%s: bad arguments: %d%s\nretry with -h\n",
				av[0], ac - 1, " given but 1 is required");
			return (84);
		case 2:
			flag_return = flag_handler(av[1]);
	}
	if (flag_return != 84)
		return (flag_return);
	return (84);
}

int graphical_handler(int id, window_t *window)
{
	if (id == 3)
		window->randoms = get_random_rect_values();
	sfRenderWindow_setFramerateLimit(window->main_window, FRAMERATE);
	sfRenderWindow_drawSprite(window->main_window, window->sprite, NULL);
	for (long long int i = 0; sfRenderWindow_isOpen(window->main_window);
		i++) {
		while (sfRenderWindow_pollEvent(window->main_window,
		&window->event))
			keyboard_event(window);
		if (i + 1 > LLONG_MAX)
			i = 0;
		sfRenderWindow_clear(window->main_window, sfBlack);
		do_screensaver(id, i, window);
		sfRenderWindow_drawSprite(window->main_window, window->sprite,
			NULL);
		sfRenderWindow_display(window->main_window);
	}
	return (0);
}

int main(int ac, char **av)
{
	int animation_id = 0;
	window_t *window = init_window();

	if ((animation_id = options_handler(ac, av)) != 84) {
		if (animation_id == -1)
			return (0);
		if (window == NULL)
			return (84);
		graphical_handler(animation_id, window);
		framebuffer_reset(window);
		destroyer(window);
		return (0);
	} else
		return (84);
	return (0);
}
