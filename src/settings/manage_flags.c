/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** flags_handling
*/

#include "rpg.h"

void manage_fps(char *arg, wininf *inf)
{
    int i = 0;
    for (; i < 6 && my_strcmp(my_strlowcase(arg),
    my_strlowcase(inf->settings->fps[i])) != 0; i++);
    inf->settings->fps[5][0] = 'M';
    if (i == 6) {
        my_printf(stdout, "Framerate not found, defaulting to 60\n");
        inf->settings->c_fps = 1;
    } else {
        inf->settings->c_fps = i;
    }
}

void manage_lang(char *arg, wininf *inf)
{
    if (my_strcmp(arg, "en") == 0){
        inf->lang = ENGLISH;
    } else if (my_strcmp(arg, "fr") == 0){
        inf->lang = FRANCAIS;
    } else {
        inf->lang = ENGLISH;
        my_printf(stdout, "Language not found, defaulting to English\n");
    }
}

void manage_host(char *arg, wininf *inf)
{
    sfIpAddress ip = sfIpAddress_getLocalAddress();
    my_printf(stdout,
        "Starting server side on your local address at %d...\n", PORT);
    inf->net->is_host = 1;
    inf->net->is_multi = 1;
    inf->net->packet = sfPacket_create();
    inf->net->socket = sfUdpSocket_create();
    inf->net->ip = malloc(sizeof(sfIpAddress));
    *inf->net->ip = ip;
    inf->net->port = PORT;
    char ipstr[40];
    sfIpAddress_toString(ip, ipstr);
    my_printf(stdout, "Binding to %s\n", ipstr);
    sfUdpSocket_setBlocking(inf->net->socket, sfFalse);
    sfUdpSocket_bind(inf->net->socket, inf->net->port, ip);
    sfSocketSelector_addUdpSocket(inf->net->selector, inf->net->socket);
}

void manage_client(char *arg, wininf *inf)
{
    int len = 0;
    for (; arg[len] != ':'; len++);
    arg += len;
    int port = my_atoi(arg + 1);
    inf->net->packet = sfPacket_create();
    arg -= len; arg[len] = '\0';
    inf->net->is_host = 0;
    inf->net->is_multi = 1;
    inf->net->socket = sfUdpSocket_create();
    sfIpAddress ip = sfIpAddress_fromString(arg);
    sfUdpSocket_setBlocking(inf->net->socket, sfFalse);
    try_to_connect(ip, port, inf);
}
