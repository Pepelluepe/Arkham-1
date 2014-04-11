#ifndef TESTSTATE_HPP
#define TESTSTATE_HPP

#include "GameState.hpp"
#include <memory>
#include "TextTexture.hpp"
#include "Texture.hpp"

#include "TextureManager.hpp"
#include <vector>


class Window;
class Player;

class TestState : public GameState
{
    Window* m_win;
    std::unique_ptr<Texture> text;

public:
    TestState() = delete;
    TestState(const TestState& other) = delete;
    TestState& operator=(const TestState& other) = delete;

    TestState(Window& win);
    ~TestState();

    void HandleEvents(SDL_Event& event);
    void Update(gameEngine* engine);
    void Draw();

    void Pause(){}
    void Resume(){}
};


#endif //TESTSTATE_HPP
