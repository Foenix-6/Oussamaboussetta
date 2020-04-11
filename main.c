#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h> 
#include "entity.h"

int main()
{
    int hauteur_fenetre = 1000,
        largeur_fenetre = 1500;

   

	SDL_Init(SDL_INIT_VIDEO);

//creation de la fenetre 
	SDL_Surface *screen;
	 if(SDL_Init(SDL_INIT_VIDEO)!=0)
    {
        printf("unable to initialize SDL: %s\n",SDL_GetError());
        return 1;
    }
 screen=SDL_SetVideoMode(largeur_fenetre,hauteur_fenetre,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(screen==NULL)
    {
        printf("unable to set video mode:%s\n",SDL_GetError());
        return 1;
    }
	SDL_WM_SetCaption("CORONA", NULL); 
// creation background
 	SDL_Surface *background ;
	SDL_Rect background_pos;
	background = IMG_Load("background.jpeg");
	background_pos.x = 0;
	background_pos.y = 0;
// afficher background 
	SDL_BlitSurface(background,NULL,screen,&background_pos);
	SDL_Flip(screen);
 
//init entity
entity e;
initialiser_entity (&e) ;

int done = 1;
        while (done)
	{
  	anim(&e);

	mvt_entity(&e);

	afficher_entity(&e ,screen);
	}

	

	SDL_FreeSurface(background);
	SDL_Quit();

    return 0;
}
