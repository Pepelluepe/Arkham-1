#include "Window.hpp"
#include <cstdio>

Window::Window()
{
}

Window::Window(const char* name, int w, int h)
{
    Init(name, w, h);
}

Window::~Window()
{
    SDL_DestroyRenderer( m_renderer );
    SDL_DestroyWindow(m_window );
}

void Window::Init(const char* name, int w, int h )
{
    screenHeight = h;
    screenWidth = w;

    m_window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_SHOWN );

    if( nullptr == m_window )
    {
        //Window could not be created
        throw WinException;
    }
    else
    {
        m_renderer = SDL_CreateRenderer( m_window, -1, SDL_RENDERER_ACCELERATED );
        if( nullptr == m_renderer )
        {
            throw WinException;
        }
        else
        {
            SDL_SetRenderDrawColor( m_renderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE );
        }
    }
}

void Window::DrawEverything()
{
    SDL_RenderPresent( m_renderer );
}
void Window::ClearScreen()
{
    SDL_RenderClear( m_renderer );
}

void Window::RenderBackgroundColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    SDL_Rect backgroundRect;
    backgroundRect.x = 0;
    backgroundRect.y = 0;
    backgroundRect.w = screenWidth;
    backgroundRect.h = screenHeight;
    //Change color to black to render black background
    SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
    SDL_RenderFillRect(m_renderer, &backgroundRect);//Render black background
    //Go back to previous color(white)
    SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
}
