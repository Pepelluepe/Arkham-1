#include "TextTexture.hpp"
#include "Window.hpp"
#include "Logger.hpp"

TextTexture::TextTexture()
{
    m_text = "";
    m_font = nullptr;
    m_win = nullptr;
    m_texture = nullptr;
}

TextTexture::TextTexture(const std::string& fontFile, const std::string& text, SDL_Color color, int fontSize, Window& win) :
            m_text(text), m_color(color), m_fontSize(fontSize), m_font(nullptr)
{
    m_win = &win;
    m_texture = nullptr;
    RenderText(fontFile);
}

TextTexture::~TextTexture()
{
    TTF_CloseFont(m_font);
    SDL_DestroyTexture(m_texture);
}

void TextTexture::Draw(int x, int y)
{
    SDL_Rect dest;
    dest.x = x;
    dest.y = y;
    dest.h = m_rect.h;
    dest.w = m_rect.w;
    SDL_RenderCopy(m_win->getRenderer(), m_texture, &m_rect, &dest);
}

void TextTexture::SetText(const std::string& text, int fontsize)
{
    m_text = text;
    m_fontSize = fontsize;
    RenderText();
}

/**
* Render the message we want to display to a texture for drawing
* @param fontFile The font we want to use to render the text
*/
void TextTexture::RenderText(const std::string& fontFile)
{
    //Open the font
    if(!m_font)
        m_font = TTF_OpenFont(fontFile.c_str(), m_fontSize);
    if (m_font == nullptr)
    {
        throw TextException;
    }
    //We need to first render to a surface as that's what TTF_RenderText returns, then
    //load that surface into a texture
    SDL_Surface* surf = TTF_RenderText_Blended(m_font, m_text.c_str(), m_color);
    if (surf == nullptr)
    {
        TTF_CloseFont(m_font);
        throw TextException;
    }
    m_texture = SDL_CreateTextureFromSurface(m_win->getRenderer(), surf);
    if (m_texture == nullptr)
    {
        SDL_FreeSurface(surf);
        TTF_CloseFont(m_font);
        throw TextException;
    }
    //Clean up the surface and font
    m_rect = surf->clip_rect;
    SDL_FreeSurface(surf);
}
