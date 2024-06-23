#include <SDL2/SDL.h>
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
int main(int argc, char **argv) {
    SDL_Window* window = NULL; //渲染窗口
    SDL_Surface* screenSurface = NULL;//窗口表面层
    //初始化SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
        printf( "SDL初始化失败,错误: %s\n", SDL_GetError() );
    }
    else{
        //创建窗口
        window = SDL_CreateWindow( "SDL示例窗口",//窗口标题
                                   SDL_WINDOWPOS_UNDEFINED, //窗口x坐标
                                   SDL_WINDOWPOS_UNDEFINED, //窗口y坐标
                                   SCREEN_WIDTH, //窗口宽
                                   SCREEN_HEIGHT, //窗口高
                                   SDL_WINDOW_SHOWN );
        if( window == NULL ){
            printf( "SDL窗口创建失败,错误: %s\n", SDL_GetError() );
        }
        else{
            //获取窗口表面层
            screenSurface = SDL_GetWindowSurface( window );
            //填充表面层
            SDL_FillRect( screenSurface,
                          NULL,
                          SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

            //更新窗口表面层
            SDL_UpdateWindowSurface( window );

            bool quit = false;//退出标志
            SDL_Event e;
            while (!quit) {
                while (SDL_PollEvent(&e)) { //处理SDL事件
                    if (e.type == SDL_QUIT) {
                        quit = true;//退出SDL事件循环
                    }
                }
            }
        }
    }
    SDL_DestroyWindow( window );//消毁窗口
    SDL_Quit();//退出SDL子系统
    return 0;
}
