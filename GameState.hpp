#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <SDL.h>

class gameEngine;

class GameState
{
public:

    virtual void Pause() = 0;
    virtual void Resume() = 0;

    virtual void HandleEvents(SDL_Event& event) = 0;
    virtual void Update(gameEngine* engine) = 0;
    virtual void Draw() = 0;

    void ChangeState(gameEngine* game, GameState* state);
    GameState() = default;
    virtual ~GameState() = default;
    GameState(const GameState& other) = delete;
    GameState& operator=(const GameState& other) = delete;
protected:
private:
};

#endif // GAMESTATE_HPP
