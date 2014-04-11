#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "Printable.hpp"
#include <memory>

class Window;


class Button : public Printable
{
    Window* m_win;


public:

    Button();
    ~Button() = default;

    Button(const Button& other) = delete;

    void Update();
    void Draw();
    void HandleEvents(SDL_Event& event);

    int GetW() { return position.w; }
    int GetH() { return position.h; }
};

#endif // BUTTON_HPP

