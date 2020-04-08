#include "entity.h"
#include "detection.h"
#include "perso.h"




void detection_collision(perso *p, entity* e){
	if (e->col==0){
if ((p->posperso.x + p->posperso. w< e->pos_entity. x) || (p->posperso.x> e->pos_entity. x + e->pos_entity. w) ||
(p->posperso.y + p->posperso.h< e->pos_entity. y) || (p->posperso.y> e->pos_entity. y + e->pos_entity. h ))
e->col= 0;
else 
e->col=1;
	}

}

