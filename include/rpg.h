/*
** EPITECH PROJECT, 2022
** B-MUL-200-NCE-2-1-myrpg-antoine.frankel
** File description:
** rpg
*/

#ifndef RPG_H_
#define RPG_H_

    #include "infos.h"
    #include "atlas.h"
    #include "entity.h"
    #include "inputs.h"
    #include "my.h"
    #include "math.h"
    #include "printf.h"
    #include "scenes.h"
    #include "types.h"
    #include "dialog.h"

typedef enum scenes_e {
    HOME,
    VILLAGE,
    INTERIOR,
    DOJO,
    BEKIPAN,
    DITTOLAND,
    MAIN_MENU
} scenes;

typedef struct atlases_t {
    sfImage *atlas;
    char **statics;
    char **collisions;
    char **scenes;
    char **pokemons_anim;
    char **houses;
    char **pnjs;
    char **icons;
    char **menus;
} atlases;

typedef struct collision_t {
    int (*check)(struct collision_t *self, sfVector2f pos);
    void (*draw)(struct collision_t *self, sfRenderWindow *win);
    sfVector2i pos;
    sfVector2i size;
    int radius;
    sfRectangleShape *rect;
    sfCircleShape *circle;
    int auto_trigger;
    int ptr;
} collision;

typedef struct time_inft {
    sfClock *dt_cal;
    float dt;
    float transi;
    float time;
    float anim;
} time_info;

typedef struct pnj_t {
    sfVector2f pos;
    entity *ent;
    char *dialog;
} pnj;

typedef struct linked_list_t {
    void *data;
    struct linked_list_t *next;
    struct linked_list_t *prev;
} list;

typedef struct scene_t {
    struct linked_list_t *pnjs;
    struct linked_list_t *colls;
    struct linked_list_t *statics;
    struct linked_list_t *animated;
} scene;

typedef struct player_t {
    sfSprite *test;
    sfVector2f vel;
    float speed;
} player;

typedef struct camera_t {
    sfView *view;
    sfSprite *target;
    sfVector2f static_p;
    float speed;
} camera;

typedef struct textbox_t {
    sfSprite *background;
    int nbr;
    struct linked_list_t *choices;
} textbox;

typedef struct ui_t {
    sfSprite *background;
    sfFont *font;
    float text_delay;
    sfSprite *test;
    struct linked_list_t *dialog;
} ui;

typedef struct choices_t {
    sfText *choice;
    sfText *desc;
    int ptr;
    void (**choices)(void);
} choices;

typedef struct menu_t {
    sfSprite *background;
    sfSprite *background2;
    sfSprite *cursor;
    struct linked_list_t *head;
    struct linked_list_t *choices;
    struct linked_list_t *selected;
    void (*ptrs[3])();
    int max_choice;
    int curr_choice;
    sfVector2f base_pos;
    int pressed;
} menus;

typedef struct wininf_t {
    sfEvent event;
    int transition;
    sfVideoMode mode;
    sfRenderWindow *win;
    struct scene_t scenes[6];
    enum scenes_e c_scene;
    enum scenes_e next_scene;
    sfVector2f next_pos;
    struct time_inft  time;
    struct camera_t camera;
    struct inputs_t inputs;
    struct atlases_t atlases;
    struct ui_t ui;
    struct menu_t *main_menu;
    int change_scene;
    int interacting;
    sfRectangleShape *transition_rect;
    void (*triggers[8])(struct wininf_t *win, struct player_t p);
} wininf;

typedef struct components_t {
    struct wininf_t inf;
    struct player_t pla;
} components;

int length_of_int(int a);
void draw_choices(wininf *inf, list *choices_l);
void draw_menu(wininf *inf);
void draw_home(wininf *inf);
void init_inputs(wininf *inf);
void move_cursor(wininf *inf);
camera init_camera(wininf inf);
void init_times(wininf *infos);
void init_textbox(wininf *win);
void update_inputs(wininf *inf);
void update_time(wininf *infos);
void update_events(wininf *inf);
void create_atlases(wininf *inf);
void create_triggers(wininf *inf);
void update_keyboard(wininf *inf);
void update_joysticks(wininf *inf);
wininf create_window_infos(char **av);
player init_player(wininf inf, int id);
void draw_player(wininf *inf, player p);
void add_collisions(char *str, list **l);
scene create_home(wininf *infos, int id);
void push_back(list **l, void *new_data);
float my_lerpf(float a, float b, float t);
menus *init_menu(wininf *inf, int menu_id);
float distance(sfVector2f a, sfVector2f b);
void add_to_list(list **l, void *new_elem);
void handle_scene(wininf *infos, player *p);
entity *create_entity(wininf *info, int id);
void draw_static_scene(wininf *inf, scene s);
sfIntRect find_icons(wininf *inf, char *str);
components create_all_components(char **argv);
void update_transition(wininf *inf, player p);
char **my_strtwa(char const *str, char *limit);
void draw_list(list *obj, sfRenderWindow *win);
void add_pnjs(atlases atlas, int idx, scene *s);
void push_back_double(list **l, void *new_data);
int check_rect_col(collision *self, sfVector2f pos);
void create_pnj(char *line, scene *s, atlases atlas);
scene create_static_environment(wininf *inf, int id);
int check_circle_col(collision *self, sfVector2f pos);
sfVector2f my_lerp(sfVector2f a, sfVector2f b, float t);
void add_circle_col(list **l, int radius, int x, int y);
void draw_rect_col(collision *self, sfRenderWindow *win);
sfSprite *atlas_to_sprite(sfIntRect rect, sfImage *atlas);
void draw_circle_col(collision *self, sfRenderWindow *win);
sfText *init_text(char *str, sfFont *font, sfVector2f pos);
int treat_balise(char *balise, sfColor *color, wininf *inf);
sfSprite *generate_textbox(sfVector2i size, sfImage *atlas);
void add_rect_col(list **l, sfVector2f pos, sfVector2f size);
dline *load_line(char *line, sfFont *font, int size, wininf *inf);
void draw_entity(time_info *time_s, list *obj, sfRenderWindow *win);
list *create_dialog_list(wininf *inf, char *path, sfVector2f poubelle);
void place_decorations(char *line, sfImage *atlas, char **csv, list **l);
void create_static_anim(sfImage *atlas, char *name, list **l, char **csv);
void add_icon(sfVector2i origin, sfImage *img, sfIntRect r, sfImage *atlas);
list *init_circular(char **arr, wininf *inf, sfVector2f pos, sfVector2f pos2);
void update_camera(camera c, float dt, sfRenderWindow *w, sfRectangleShape *t);
int is_valid(list *cols, sfVector2f pos, sfVector2f *vel, wininf *inf, player p);

void ta_mere(wininf *win, player p);
void interact_pnj(wininf *win, player p);
void sleep_and_save(wininf *win, player p);
void village_to_dojo(wininf *win, player p);
void homeext_to_village(wininf *win, player p);
void homeext_to_homeint(wininf *win, player p);
void village_to_bekipan(wininf *win, player p);
void village_to_dittoland(wininf *win, player p);

//POINTERS
void play(wininf *inf);
void options(wininf *inf);
void my_exit(wininf *inf);
void init_main_menu_pointers(wininf *inf);

//MATHS
float my_repeat(float t, float mag);
float my_pingpong(float t, float mag);
float my_clamp(float d, float min, float max);
float manhattan_distance(sfVector2f a, sfVector2f b);
float my_lerpf(float a, float b, float t);

//TEXTBOXES
void topbot_border(sfVector2i size, sfImage *new);
void leftright_border(sfVector2i size, sfImage *new);
sfSprite *generate_textbox(sfVector2i size, sfImage *atlas);
void add_corner(sfImage *img, sfImage *atlas, sfVector2i pos, sfVector2i glo);

#endif
