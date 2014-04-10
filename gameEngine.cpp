#include "gameEngine.hpp"
#include "Texture.hpp"
#include "Logger.hpp"
#include "Printable.hpp"
#include <cstdio>

#include "TestState.hpp"
gameEngine::gameEngine()
{
    m_running = true;
    LoadWindow("Arkham Horror", 1024, 768);
    m_states.emplace_back(new TestState(m_window));
//    m_states.emplace_back(new MenuState(m_window, OPTION_START | OPTION_EXIT | OPTION_CREDITS | OPTION_HELP));
}

/// \brief Function updating world. Consists of game logic, collision check, etc.
void gameEngine::Update()
{
    //m_gameLevel.Update();
    m_states.back()->Update(this);
//    if(m_gameLevel.WantsToExit() )
//        Quit();
}
/// \brief Getting and handling events for everything in game. Engine itself checks for exit events.
void gameEngine::HandleEvents()
{
    while(SDL_PollEvent(&m_gameEvent))
    {
        HandleEngineEvents();
        //m_gameLevel.HandleEvents(m_gameEvent);
        m_states.back()->HandleEvents(m_gameEvent);
    }
}
/// \brief Renders everything in game and keeps FPS low.
void gameEngine::Draw()
{
    //m_gameLevel.Draw();
    m_window.ClearScreen();
    m_states.back()->Draw();
    m_window.DrawEverything();
}

void gameEngine::HandleEngineEvents()
{
    //If x'd out
    if( m_gameEvent.type == SDL_QUIT)
    {
        Quit();
    }
    else if( m_gameEvent.type == SDL_KEYDOWN && m_gameEvent.key.repeat == 0 )
    {
        //If player pressed escape
        if( m_gameEvent.key.keysym.sym == SDLK_ESCAPE )
        {
            Quit();
        }
    }

}

void gameEngine::ChangeState(GameState* state)
{
    if( !m_states.empty() )
    {
        m_states.pop_back();
    }

    m_states.push_back(std::unique_ptr<GameState>(state) );
}

void gameEngine::PushState(GameState* state)
{
    if( !m_states.empty() )
    {
        m_states.back()->Pause();
    }
    m_states.push_back(std::unique_ptr<GameState>(state));
}

void gameEngine::PopState()
{
    if( !m_states.empty() )
    {
        m_states.pop_back();
    }

    if( !m_states.empty() )
    {
        m_states.back()->Resume();
    }
}

void gameEngine::LoadWindow(const char* name, int w, int h)
{
    m_window.Init(name, w, h);
    Printable::SetWindowDimensions(w, h);
}
