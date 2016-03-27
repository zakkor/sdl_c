#include <stdbool.h>

#include "SDL2/SDL.h"
#include "actor.h"

int main(void)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *win = SDL_CreateWindow("Hello world", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    actor *player = actor_init("res/image.bmp", ren);

    bool game_over = false;
    SDL_Event event;
    while (!game_over)
    {
	while (SDL_PollEvent(&event))
	{
	    switch (event.type)
	    {
	    case SDL_QUIT:
		{
		    game_over = true;
		} break;
	    default:
		break;
	    }
	}
	SDL_RenderClear(ren);
	actor_render(player);
	SDL_RenderPresent(ren);
    }

    actor_destroy(player);
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
    
    return EXIT_SUCCESS; 
}
