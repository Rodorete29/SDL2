/* 
Forma de compilar programa de la siguiente manera:
g++ -Wall -I./include -L./lib -o Prueba main.cpp -lmingw32 -lSDL2main -lSDL2 -mwindows
*/

#include <SDL2/SDL.h>
#include <iostream>

int WinMain(int argc, char* argv[]) {
    // Inicializar SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL no pudo inicializarse. Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Crear una ventana
    SDL_Window* ventana = SDL_CreateWindow("SDL2 Ejemplo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (ventana == NULL) {
        std::cout << "No se pudo crear la ventana. Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Obtener el renderer asociado a la ventana
    SDL_Renderer* renderer = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        std::cout << "No se pudo crear el renderer. Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Lógica del juego iría aquí

    // Esperar por el usuario para cerrar la ventana
    SDL_Event evento;
    int salir = 0;
    while (!salir) {
        while (SDL_PollEvent(&evento) != 0) {
            if (evento.type == SDL_QUIT) {
                salir = 1;
            }
        }
    }

    // Liberar recursos
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(ventana);
    SDL_Quit();

    return 0;
}
