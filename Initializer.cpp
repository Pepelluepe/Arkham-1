#include "Initializer.hpp"
#include "Logger.hpp"

#define SDL_INIT_FLAGS SDL_INIT_VIDEO

#define IMG_INIT_FLAGS IMG_INIT_PNG

Initializer::Initializer()
{
    Logger::Get()->Log("Initializer constructor called");
    //Initialize SDL, throw exception if demanded systems were not initialized
    if( SDL_Init( SDL_INIT_FLAGS ) < 0 )
    {
        throw InitException;
    }
    else
    {
        //Initialize SDL_IMG, throw exception if demanded systems were not initialzied
        if( ! (IMG_Init( IMG_INIT_FLAGS ) & IMG_INIT_FLAGS) )
        {
            throw InitException;
        }
        else
        {
            //Set linear texture filtering
            if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
            {
                Logger::Get()->Log("Warning! Linear texture filtering disabled!\n");
            }
            //Set up vertical sync
            if( !SDL_SetHint( SDL_HINT_RENDER_VSYNC, "1" ) )
            {
                Logger::Get()->Log("Warning: VSync not enabled!" );
            }
        }

        //Initialize SDL_TTF, throw exception if demanded systems weren't initialized
        if(TTF_Init() != 0)
        {
            throw InitException;
        }
    }
}

Initializer::~Initializer()
{
    Logger::Get()->Log("Initializer destructor called");
    //Clean up
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
