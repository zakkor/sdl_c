#ifndef ACTOR_H
#define ACTOR_H

#include "rendering_component.h"

typedef struct
{
    rendering_component *rc;
} actor;

actor * actor_init(const char *image_path, SDL_Renderer *ren);
void actor_render(actor *act);
void actor_destroy(actor *act);

#endif /* ACTOR_H */
