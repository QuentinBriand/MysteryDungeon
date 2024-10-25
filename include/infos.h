/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** INFOS
*/

#ifndef INFOS_H_
    #define INFOS_H_

    #include <SFML/Audio.h>
    #include <SFML/Network.h>
    #include <SFML/Graphics.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <math.h>
    #include <stdio.h>
    #include <time.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <stddef.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #if defined(_WIN32) || defined(_WIN64)
        #include <direct.h>
        #define getcwd _getcwd
    #else
        #include <unistd.h>
    #endif

    #define WINDOW_NAME "Pokemon Mystery Dungeon Red Rescue Team"
    #define SIZE 7.0f
    #define RATE 0.15f
    #define FONT_SIZE 15.0f
    #define COMBAT_FONT_SIZE 15.0f
    #define PORT 7272

    #include "rpg.h"

#endif
