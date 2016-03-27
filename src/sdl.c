#include <stdbool.h>

#include "SDL2/SDL.h"
#include "actor.h"

int main(void)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
	printf("SDL_Init error: %s\n", SDL_GetError());
	SDL_Quit();
	return EXIT_FAILURE;
    }
    SDL_Window *win = SDL_CreateWindow("Hello world", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    if (win == NULL)
    {
	printf("SDL_CreateWindow error: %s\n", SDL_GetError());
	SDL_Quit();
	return EXIT_FAILURE;
    }
    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (ren == NULL)
    {
	printf("SDL_CreateRenderer error: %s\n", SDL_GetError());
	SDL_DestroyWindow(win);
	SDL_Quit();
	return EXIT_FAILURE;
    }

    actor *player = actor_init("res/image.bmp", ren);
    if (player == NULL)
    {
	printf("SDL_LoadBMP error: %s\n", SDL_GetError());
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(ren);
	SDL_Quit();
	return EXIT_FAILURE;
    }

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
