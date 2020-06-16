#ifndef entite_H_INCLUDED
#define entite_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "utilitaire.h"
#include<time.h>
/**
* @struct the entity 
* @brief struct for the entity
*/
typedef struct {
SDL_Surface *entity ; /*!< Surface. */
SDL_Rect pos_entity;/*!< Rectangle*/
SDL_Rect anim_entity[70];/*!< Rectangle*/
int frame_entity;
int direction;
int col ;
int type;
int maxi_up,maxi_down;
int show;

}entity ;
typedef struct {
SDL_Surface *ennemie ; /*!< Surface. */
SDL_Rect pos_ennemie;/*!< Rectangle*/
SDL_Rect anim_ennemie[70];/*!< Rectangle*/
int frame_ennemie;
int direction;
int col ;
int type;
int maxi_up,maxi_down;
int show;

}ennemie ;
/**
* @struct personnage
* @brief struct for the personnage 
*/
typedef struct
{
SDL_Surface *perso; /*!< Surface. */
SDL_Rect perso_pos ;/*!< Rectangle*/
}personnage ;

void init_tab_anim_entity(SDL_Rect* clip,entity *e); 
void initialiser_entity (entity *e) ;
void afficher_entity(entity * e , SDL_Surface *screen);
void anim(entity *e);
void mvt_entity(entity *e);
void update_entity(entity *e);
void initialiser_perso(personnage *p);
void afficher_perso(personnage * p , SDL_Surface *screen);
//void rand_min_max(entity *e);
int detect_collision(personnage *p, entity* e);
int gestion(entity* e);

void init_tab_anim_ennemie (SDL_Rect* clip,ennemie  *en); 
void initialiser_ennemie  (ennemie  *en) ;
void afficher_ennemie (ennemie  * en , SDL_Surface *screen);
void anim_ennemie (ennemie  *en);
void mvt_ennemie (ennemie  *en,personnage *p);
void update_ennemie (ennemie  *en,personnage *p);
//void rand_min_max(ennemie  *en);
int detect_collision_ennemie(personnage *p, ennemie * en);




#endif 
