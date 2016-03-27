#include "rendering_component.h"
#include <stdio.h>
#include <stdlib.h>

rendering_component * rc_init(const char *image_path, SDL_Renderer *ren)
{
    rendering_component * rc = malloc(sizeof(rendering_component));
    
    SDL_Surface *bmp = SDL_LoadBMP(image_path);
    
    rc->tex = SDL_CreateTextureFromSurface(ren, bmp);
    
    SDL_FreeSurface(bmp);

    rc->ren = ren;
    return rc;
}

void rc_render(rendering_component *rc)
{
    SDL_RenderCopy(rc->ren, rc->tex, NULL, NULL);
}

void rc_destroy(rendering_component *rc)
{
    free(rc);
}
