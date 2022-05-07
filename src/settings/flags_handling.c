/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** flags_handling
*/

#include "rpg.h"
#include <getopt.h>
#include <unistd.h>

int get_settings_flags(int ac, char **av, wininf *win)
{
    static struct option lo[] = {{"collisions", no_argument, NULL, 'C'},
                            {"pokemon", required_argument, NULL, 'p'},
                            {"house", required_argument, NULL, 'H'},
                            {"client", required_argument, NULL, 1001},
                            {"host", no_argument, NULL, 1000},
                            {"language", required_argument, NULL, 'l'},
                            {"framerate", required_argument, NULL, 'f'}};
    int opt = 0;
    while ((opt = getopt_long(ac, av, "H:C:p:l:f:", lo, NULL)) != -1) {
        change_settings(opt, optarg, win);
    }
    return 0;
}

void change_settings(int opt, char *arg, wininf *inf)
{
    if (opt == 'p')
        inf->settings->pokemon = my_atoi(arg);
    if (opt == 'H')
        inf->settings->house = my_atoi(arg);
    if (opt == 'C')
        inf->settings->show_collision = 1;
    if (opt == 1001) manage_client(arg, inf);
    if (opt == 1000) manage_host(arg, inf);
    if (opt == 'l') manage_lang(arg, inf);
    if (opt == 'f') manage_fps(arg, inf);
}
