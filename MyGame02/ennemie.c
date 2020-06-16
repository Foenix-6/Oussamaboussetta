/**
 * @file ennemie.c 
 */
#include "entity.h"




int 
nb_frame1=12 ,
ennemie_h=100,
ennemie_w=100,
ennemie_y=100,
ennemie_x=100;


void init_tab_anim_ennemie(SDL_Rect *clip,ennemie *en)
{	


for (int j=0;j<nb_frame1; j++)
	{
   	 clip[j].h=ennemie_h;
         clip[j].w=ennemie_w;
        clip[j].x = j*ennemie_w;
	clip[j].y = 0;
        }


}


/**
* @brief To initialize the ennemie en  .
* @param en the ennemie
* @return Nothing
*/

void initialiser_ennemie(ennemie *en)
{

    en->ennemie = IMG_Load("ENNEMIE.png");

    en->pos_ennemie.x = 900;
    en->pos_ennemie.y = 400;
    init_tab_anim_ennemie(en->anim_ennemie,en);
    en->frame_ennemie=0;
    en->direction=0;  
    en->col=0;
    en->show=1;
    
    
}
/**
* @brief To show the ennemie en .
* @param screen the screen
* @param en the ennemie
* @return Nothing
*/


void afficher_ennemie(ennemie * en , SDL_Surface *screen)
{
   
   SDL_BlitSurface(en->ennemie,&en->anim_ennemie[en->frame_ennemie], screen, &en->pos_ennemie);
  
  

}
/**
* @brief for the random movement of  the automation ennemi  .
* @param en the ennemie
* @param p the personnage  
* @return Nothing
*/

void mvt_ennemie(ennemie *en,personnage *p)
{	srand (time(0));
	int diff;
	int maxi_down=300+rand()%300;
	int maxi_up=150+rand()%300;

  	printf("maxup : %d\tmaxdown : %d\n",maxi_up,maxi_down );


if(en->pos_ennemie.y>= maxi_down)
{
en->direction =1;
}
if(en->pos_ennemie.y<=maxi_up)
{
en->direction =0;
}

if(en->direction==1)
{   
	en->pos_ennemie.y-=7;
 


}
if(en->direction==0)
{
        
	en->pos_ennemie.y+=7;


}

  diff=en->pos_ennemie.x-p->perso_pos.x;
  
  if (diff<350 && diff>50 ){

en->pos_ennemie.x-=3;
  }

if (diff >-350 && diff < 0){
  
  en->pos_ennemie.x+=3;
  }


}

/**
* @brief for the animation the ennemie .
* @param en the ennemie 
* @return Nothing
*/

void anim_ennemie(ennemie *en)
{   if (en->frame_ennemie >=0 && en->frame_ennemie <(nb_frame1-1)) 
 en->frame_ennemie++;
    if ( en->frame_ennemie ==(nb_frame1-1)) 
       en->frame_ennemie=0;
}
/**
* @brief for the integration of two functions (anim,mouv) .
* @param en the ennemie 
* @param p the personnage 
* @return Nothing
*/


void update_ennemie(ennemie *en,personnage *p)
{ 	mvt_ennemie(en,p);
	anim_ennemie(en);
	

}
/**
* @brief to change the maxi down and the maxi up randomly .
* @param en the ennemie 
* @return Nothing
*/


/*void rand_min_max(ennemie *en){
	srand (time(0));
  	e->maxi_up=50+rand()%100;
 	e->maxi_down=350+rand()%100;

  	printf("maxup : %d\tmaxdown : %d\n",e->maxi_up,e->maxi_down );

}*/


    
    


/**
* @brief for the detection of a collision bounding box  .
* @param en the ennemie 
* @param p the personnage 
* @return collision  
*/

int detect_collision_ennemie(personnage *p, ennemie* en)
{
	

if ((p->perso_pos.x + p->perso_pos. w< en->pos_ennemie. x) || (p->perso_pos.x> en->pos_ennemie. x + en->pos_ennemie. w) ||
(p->perso_pos.y + p->perso_pos.h< en->pos_ennemie. y) || (p->perso_pos.y> en->pos_ennemie. y + en->pos_ennemie. h ))
return 0;
else 
return 1;
 

}

