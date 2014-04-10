#ifndef INITIALIZER_H
#define INITIALIZER_H

#include <exception>
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "Logger.hpp"

/**
  * \brief Class that initializes all SDL systems
  */
class Initializer
{
    //Exception class for Initializer
    class InitializerException: public std::exception
    {
        virtual const char* what() const throw()
        {
            Logger::Get()->Log("Initializer has thrown an exception: ");

            std::string returned = "Initialization of SDL Modules failed! SDL_Error: ";
            returned = returned + SDL_GetError();

            Logger::Get()->Log(returned);

            return returned.c_str();
        }
    }InitException;

public:
    Initializer();
    ~Initializer();
};

#endif // INITIALIZER_H

