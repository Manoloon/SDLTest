#include <stdio.h>
#include <SDL2/SDL.h>
#include <time.h>
#include <stdlib.h>

#define QUITKEY SDLK_ESCAPE
#define SCREEN_W 720
#define SCREEN_H 480

SDL_Window* Window = NULL;
SDL_Renderer* Renderer;
SDL_Event event;
SDL_Rect Source, Destination, dst;

int ErrorCount = 0;
int KeyPressed;
int RectCount = 0;
//stopWatch StopWatch;

int Random(int max)
{
  return (rand() % max) +1;
}

void LogError(char* msg)
{
  printf("%s\n",msg);
  ErrorCount++;
}

void SetCaption(char* msg)
{
  SDL_SetWindowTitle(Window,msg);
}

void Init()
{
  srand((int)time(NULL));
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_CreateWindowAndRenderer(SCREEN_W,SCREEN_H,SDL_WINDOW_SHOWN,&Window,&Renderer);
  if(!Window)
  {
    LogError("Init failed to create window");
  }
  SetCaption("Test");
}

void EndGame()
{
  SDL_DestroyRenderer(Renderer);
  SDL_DestroyWindow(Window);
  SDL_Quit();
  exit(0);
}

char GetChar()
{
  int result = -1;
  while (SDL_PollEvent(&event))
  {
    if(event.type == SDL_KEYDOWN)
    {
      result = event.key.keysym.sym;
      break;
    }
  }
  return result;
}

void DrawRandomRectangle()
{
  char buff[20];
  SDL_Rect Rect;
  SDL_SetRenderDrawColor(Renderer,Random(256),-1,Random(256),255);
  Rect.h = 120;
  Rect.w = 120;
  Rect.y = Random(SCREEN_H - Rect.h -1);
  Rect.x = Random(SCREEN_W - Rect.w -1);
  SDL_RenderFillRect(Renderer,&Rect);

  RectCount++;
  if(RectCount % 100000 == 0)
  {
    SDL_RenderPresent(Renderer);
    // TODO : stopTimer(%StopWatch);
    SetCaption(buff);
    // TODO : StartTimer(&StopWatch);
  }
}

void GameLoop()
{
  int GameRunning = 1;
  //TODO : StartTimer(%StopWatch);
  while (GameRunning)
  {
    DrawRandomRectangle();
    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
      case SDL_KEYDOWN:
        KeyPressed == event.key.keysym.sym;
        if(KeyPressed == QUITKEY)
        {
          GameRunning = 0;
          break;
        }
        break;
      case SDL_QUIT:
        GameRunning = 0;
        break;
      case SDL_KEYUP:
        break;
      default:
        break;
      }
    }
  }
}

int main(int argc,char* args[])
{
  Init();
  GameLoop();
  EndGame();
  return 0;
}