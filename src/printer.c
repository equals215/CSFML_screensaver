/*
** EPITECH PROJECT, 2017
** printer.c by tfoubert <thomas.foubert@epitech.eu>
** File description:
** printer.c file of the {{project_name}} project
*/

#include "screensaver.h"

void animations_printer(void)
{
	my_printf("1:\tDisplaying lines with random colors from the center\n");
	my_printf("2:\tDisplaying circles with random colors\n");
	my_printf("3:\t[WIP]Displaying squares with random colors\n");

}

void help_printer(void)
{
	my_printf("%s%s%s%s%s%s%s",
	"animation rendering in a CSFML window.\n\n",
	"USAGE\n  ./my_screensaver [OPTIONS] animation_id\n   animation_id\t\t",
	"ID of the animation to process (between 1 and 20).",
	"\n\nOPTIONS\n  -d\t\t\tprint the description of all the animations ",
	"and quit.\n  -h\t\t\tprint the usage and quit.\n\nUSER INTERACTIONS\n",
	"  [WIP]LEFT_ARROW\t\tswitch to the previous animation.\n",
	"  [WIP]RIGHT_ARROW\t\tswitch to the next animation.\n\n");
}
