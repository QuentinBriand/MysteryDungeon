/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** flags_handling
*/

#include "rpg.h"
#if defined(__linux__)
    #include <getopt.h>
    #include <unistd.h>

    int get_settings_flags(int ac, char **av, wininf *win)
    {
        static struct option lo[] = {{"collisions", no_argument, NULL, 'c'},
                                {"pokemon", required_argument, NULL, 'p'},
                                {"house", required_argument, NULL, 'H'},
                                {"client", required_argument, NULL, 1001},
                                {"host", no_argument, NULL, 1000},
                                {"language", required_argument, NULL, 'l'},
                                {"framerate", required_argument, NULL, 'f'}};
        int opt = 0;
        while ((opt = getopt_long(ac, av, "H:c:p:l:f:", lo, NULL)) != -1) {
            change_settings(opt, optarg, win);
        }
        return 0;
    }

    void change_settings(int opt, char *arg, wininf *inf)
    {
        if (opt == 'p') {
            int pokemon = my_atoi(arg);
            if (pokemon > 49) {
                my_printf(stdout, "Pokemon not found, defaulting to 1\n");
                inf->settings->pokemon = 1;
            } else {
                inf->settings->pokemon = pokemon;
            }
        }
        if (opt == 'H')
            inf->settings->house = my_atoi(arg);
        if (opt == 'c')
            inf->settings->show_collision = 1;
        if (opt == 1001) manage_client(arg, inf);
        if (opt == 1000) manage_host(arg, inf);
        if (opt == 'l') manage_lang(arg, inf);
        if (opt == 'f') manage_fps(arg, inf);
    }
#elif defined(_WIN32)
    int get_settings_flags(int ac, char **av, wininf *win)
    {
        for (int i = 1; i < ac; i++) {
            if (my_strcmp(av[i], "--collisions") == 0 || my_strcmp(av[i], "-c") == 0)
                win->settings->show_collision = 1;
            if (my_strcmp(av[i], "--pokemon") == 0 || my_strcmp(av[i], "-p") == 0)
                win->settings->pokemon = my_atoi(av[i + 1]);
            if (my_strcmp(av[i], "--house") == 0 || my_strcmp(av[i], "-H") == 0)
                win->settings->house = my_atoi(av[i + 1]);
            if (my_strcmp(av[i], "--client") == 0)
                manage_client(av[i + 1], win);
            if (my_strcmp(av[i], "--host") == 0)
                manage_host(av[i + 1], win);
            if (my_strcmp(av[i], "--language") == 0 || my_strcmp(av[i], "-l") == 0)
                manage_lang(av[i + 1], win);
            if (my_strcmp(av[i], "--framerate") == 0 || my_strcmp(av[i], "-f") == 0)
                manage_fps(av[i + 1], win);
        }
        return 0;
    }
#endif