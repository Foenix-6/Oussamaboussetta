#include "entity.h"

int 
    down=0,up=0,
maxi_up=100 ,maxi_down=500,
nb_frame=15 ;//3ded les images 



void init_tab_anim_entity(SDL_Rect *clip)
{
    // imashy 3al imin
    clip[0].x = 0;
    clip[0].y = 0;
    clip[0].w = 100;
    clip[0].h = 100;
    int i = 1;
    for (i = 1; i < nb_frame; i++)
    {
        clip[i].w = 100;
        clip[i].h = 100;
        clip[i].x = clip[i].w + clip[i - 1].x;
        clip[i].y = 0;
    }

    //3al isar
    clip[nb_frame].x = 0;
    clip[nb_frame].y = 100;
    clip[nb_frame].w = 100;
    clip[nb_frame].h = 100;
    i = (nb_frame + 1);
    for (i =(nb_frame + 1); i <( 2*nb_frame ); i++)
    {
        clip[i].w = 100;
        clip[i].x = clip[i - 1].x + clip[i].w;
        clip[i].y = 100;
        clip[i].h = 100;
    }
    
    clip[2*nb_frame ].x = 0;
    clip[2*nb_frame ].y = 200;
    clip[2*nb_frame ].w = 100;
    clip[2*nb_frame ].h = 100;
    i =(2*nb_frame +1);
    for (i = (2*nb_frame +1); i < (3* nb_frame); i++)
    {
        clip[i].w = 100;
        clip[i].x = clip[i - 1].x + clip[i].w;
        clip[i].y = 200;
        clip[i].h = 100;
    }

    
    clip[3* nb_frame].x = 0;
    clip[3* nb_frame].y = 300;
    clip[3* nb_frame].w = 100;
    clip[3* nb_frame].h = 100;
    i =( 3* nb_frame+1);
    for (i = (3* nb_frame+1); i < (4*nb_frame); i++)
    {
        clip[i].w = 100;
        clip[i].x = clip[i - 1].x + clip[i].w;
        clip[i].y = 300;
        clip[i].h = 100;
    }
}

void initialiser_entity(entity *e)
{
    e->entity = IMG_Load("run.png");
    e->pos_entity.x = 700;
    e->pos_entity.y = 100;
    init_tab_anim_entity(e->anim_entity);
    e->frame_entity=0;
    e->col=0;
}


void afficher_entity(entity * e , SDL_Surface *screen)
{
   
   SDL_BlitSurface(e->entity,&e->anim_entity[e->frame_entity], screen, &e->pos_entity);

  

}


void mvt_entity(entity *e)
{
if(e->pos_entity.y>=maxi_down){
  down=0;
  up=1;
printf("%d , down,%d/t",e->pos_entity.y,down); }
if(e->pos_entity.y<=maxi_up){
  down=1;
  up=0;
printf("%d , up,%d/t",e->pos_entity.y,up);}

  if (up==1) e->pos_entity.y--;
  if (down==1) e->pos_entity.y++;

}

void anim(entity *e)
{    e->frame_entity++;
    if (e->frame_entity <0 || e->frame_entity > 14) 
       e->frame_entity=0;

}
