#ifndef TEXTTEXTURE_HPP
#define TEXTTEXTURE_HPP

#include <SDL_ttf.h>
#include "Texture.hpp"
#include <exception>
#include <string>
#include "Logger.hpp"

class Window;

class TextTexture : public Texture
{
    class TextTextureException: public std::exception
    {
        virtual const char* what() const throw()
        {
            Logger::Get()->Log("TextTexture has thrown an exception:");

            std::string returned = "Initialization of Texture failed! SDL_Error: ";
            returned = returned + SDL_GetError();

            Logger::Get()->Log(returned);

            return returned.c_str();
        }
    }TextException;

public:
    TextTexture();
    TextTexture(const TextTexture& other) = delete;
    TextTexture(const std::string& fontFile, const std::string& text, SDL_Color color, int fontSize, Window& win);
    ~TextTexture();

    void Draw(int x = 0, int y = 0);

    void SetText(const std::string& text, int fontsize = 0);
    inline std::string GetText() { return m_text; }

    operator SDL_Texture*() { return m_texture;}

    inline int GetW() { return m_rect.w;}
    inline int GetH() { return m_rect.h;}
    inline bool IsNull() { return (m_texture == nullptr);}


private:

    TTF_Font* m_font; //Could use FontManager...
    SDL_Color m_color;
    int m_fontSize;
    std::string m_text;

    void RenderText(const std::string& fontFile = "media/go3v2.ttf");
};

#endif //TEXTTEXTURE_HPP
