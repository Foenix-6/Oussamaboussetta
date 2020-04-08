#include "entity.h"

int 
    down=0,up=0;



void init_tab_anim_entity(SDL_Rect *clip)
{
    // dir vers droite
    clip[0].x = 0;
    clip[0].y = 0;
    clip[0].w = 100;
    clip[0].h = 100;
    int i = 1;
    for (i = 1; i < 15; i++)
    {
        clip[i].w = 100;
        clip[i].h = 100;
        clip[i].x = clip[i].w + clip[i - 1].x;
        clip[i].y = 0;
    }

    //dir vers gauche
    clip[15].x = 0;
    clip[15].y = 100;
    clip[15].w = 100;
    clip[15].h = 100;
    i = 16;
    for (i = 16; i < (30); i++)
    {
        clip[i].w = 100;
        clip[i].x = clip[i - 1].x + clip[i].w;
        clip[i].y = 100;
        clip[i].h = 100;
    }
    //stable right
    clip[30].x = 0;
    clip[30].y = 200;
    clip[30].w = 100;
    clip[30].h = 100;
    i = 31;
    for (i = 31; i < (45); i++)
    {
        clip[i].w = 100;
        clip[i].x = clip[i - 1].x + clip[i].w;
        clip[i].y = 200;
        clip[i].h = 100;
    }

    //stable right
    clip[45].x = 0;
    clip[45].y = 300;
    clip[45].w = 100;
    clip[45].h = 100;
    i = 46;
    for (i = 46; i < (60); i++)
    {
        clip[i].w = 100;
        clip[i].x = clip[i - 1].x + clip[i].w;
        clip[i].y = 300;
        clip[i].h = 100;
    }
}

void initialiser_entity(entity *e)
{
    e->entity = IMG_Load("graphic/run.png");
    e->entity_pos.x = 700;
    e->entity_pos.y = 100;
    init_tab_anim_entity(e->anim_entity);
    e->cont_entity=0;
    e->type=1;
e->col=0;
}


void afficher_entity(entity * e , SDL_Surface *screen)
{
   
   SDL_BlitSurface(e->entity,&e->anim_entity[e->cont_entity], screen, &e->pos_entity);

  

}




