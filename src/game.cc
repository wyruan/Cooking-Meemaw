#include "game.h"

namespace cookingmeemaw {

Game::Game() {
    recipe_.FillRecipeList();
    recipe_.SetRecipeName(kRecipeName);
    recipe_.SetImageUrl(kImageUrl);

    score_ = 100;
    chop_goal_ = 0;
    chop_progress_ = 0;
    mayo_count_ = 0;
    salt_count_ = 0;
    pepper_count_ = 0;

    state_ = GameState::StartGame;
}

GameState Game::GetGameState() const {
    return state_;
}

void Game::SetGameStatus(const GameState &state) {
    state_ = state;
}

void Game::SetChopGoal(size_t goal) {
    chop_goal_ = goal;
}

void Game::IncrementChopProgress() {
    chop_progress_++;
}

size_t Game::GetChopProgress() const {
    return chop_progress_;
}

size_t Game::GetChopGoal() const {
    return chop_goal_;
}

void Game::IncrementMayoCount() {
    mayo_count_++;
}

void Game::IncrementSaltCount() {
    salt_count_++;
}

void Game::IncrementPepperCount() {
    pepper_count_++;
}

size_t Game::GetMayoCount() const {
    return mayo_count_;
}

size_t Game::GetSaltCount() const {
    return salt_count_;
}

size_t Game::GetPepperCount() const {
    return pepper_count_;
}

void Game::CalculateChopGameScore() {
    size_t penalty = (chop_goal_ - chop_progress_) * 5;
    score_ -= penalty;
}

size_t Game::GetScore() const {
    return score_;
}

void Game::CalculateClickGameScore() {
    size_t penalty =
            ((ingredient_goal_ - mayo_count_) + (ingredient_goal_ - salt_count_) + (ingredient_goal_ - pepper_count_)) *
            5;
    score_ -= penalty;
}

bool Game::HasCollectedAllIngredients() const {
    if (mayo_count_ >= ingredient_goal_ && salt_count_ >= ingredient_goal_ && pepper_count_ >= ingredient_goal_) {
        return true;
    }
    return false;
}

}  // namespace cookingmeemaw
