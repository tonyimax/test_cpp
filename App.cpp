//
// Created by Hacker X on 2024/4/27.
//

#include "App.h"
using namespace std;

bool App::Init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) { // 初始化SDL
        cout << "SDL_Init error: " << SDL_GetError() << endl;
        return false;
    }

    Window = SDL_CreateWindow("Hello SDL world!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH,
                              HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI); // 创建SDL窗口
    if (NULL == Window) {
        cout << "SDL_CreateWindow error: " << SDL_GetError() << endl;
        return false;
    }

    Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
    if (NULL == Renderer) {
        cout << "SDL_CreateRenderer error: " << SDL_GetError() << endl;
        return false;
    }

    return true;
}

int App::Execute(int argc, char **argv) {
    if (!Init()) {
        return 1;
    }

    SDL_Event event;
    while (Running) {
        while (SDL_PollEvent(&event) != 0) {
            OnEvent(&event);
        }

        Loop();
        Render();

        SDL_Delay(2000);
    }

    Cleanup();
    return 0;
}

