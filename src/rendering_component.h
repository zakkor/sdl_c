#ifndef RENDERING_COMPONENT_H
#define RENDERING_COMPONENT_H
#include "SDL2/SDL.h"

typedef struct rendering_component
{
    SDL_Texture *tex;
    // keep a pointer to the renderer
    SDL_Renderer *ren;
    
} rendering_component;

rendering_component * rc_init(const char *image_path, SDL_Renderer *ren);
void rc_render(rendering_component *rc);
void rc_destroy(rendering_component *rc);

#endif /* RENDERING_COMPONENT_H */
