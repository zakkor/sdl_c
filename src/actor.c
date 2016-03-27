#include "actor.h"
#include <stdlib.h>

actor * actor_init(const char *image_path, SDL_Renderer *ren)
{
    actor * act = malloc(sizeof(actor));
    act->rc = rc_init(image_path, ren);
    if (act->rc == NULL)
    {
	return NULL;
    }
    return act;
}

void actor_render(actor *act)
{
    rc_render(act->rc);
}

void actor_destroy(actor *act)
{
    rc_destroy(act->rc);
    free(act);
}
