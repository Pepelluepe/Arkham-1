#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Initializer.hpp"
#include "GameState.hpp"
#include "Window.hpp"

#include <memory>
#include <vector>

/// \brief Main engine class.

//Private inheritance of Initializer ensures initialization of systems before game starts
class gameEngine : private Initializer
{
public:
    gameEngine();
    ~gameEngine() = default;

    inline void Run()
    {
        while(m_running)
        {
            HandleEvents();
            Update();
            Draw();
        }
    }

    void ChangeState(GameState* state);
    void PushState(GameState* state);
    void PopState();


private:
    std::vector< std::unique_ptr<GameState> > m_states;
    //Level m_gameLevel;
    Window m_window;

    bool m_running;
    SDL_Event m_gameEvent;

    void HandleEngineEvents();

    void Update();
    void HandleEvents();
    void Draw();

    inline void Quit() { m_running = false;}
    inline bool IsRunning() { return m_running; }

    void LoadWindow(const char* name, int w, int h);
};

#endif // GAMEENGINE_H

