#include "TestState.hpp"

#include "gameEngine.hpp"
#include "TextTexture.hpp"
#include "SDL_ttf.h"

TestState::TestState(Window& win) : m_win(&win)
{
    SDL_Color color = { 0, 132, 255};
    text.reset(new TextTexture("media/go3v2.ttf", "Hello, world! I do work!", color, 35, *m_win) );
}

TestState::~TestState()
{
}

void TestState::HandleEvents(SDL_Event& event)
{
}

void TestState::Update(gameEngine* engine)
{
}

void TestState::Draw()
{
    text->Draw();
}
