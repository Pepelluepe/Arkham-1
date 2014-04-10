#include "GameState.hpp"
#include "gameEngine.hpp"

void GameState::ChangeState(gameEngine* game, GameState* state)
{
    game->ChangeState(state);
}
