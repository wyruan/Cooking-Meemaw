#pragma once

#include "cinder/gl/gl.h"

#include "cookbook.h"
#include "game_object.h"

namespace cookingmeemaw {

enum class GameState {
    StartGame,
    PlayChopGame,
    PlayClickGame,
    GameOver
};

class Game {
 public:
    /**
     * Default constructor for a Game object.
     */
    Game();

    /**
     * Constructor for creating a game from a Cookbook object.
     * @param cookbook the Cookbook object containing all the recipes and ingredients
     */
    Game(const Cookbook &cookbook);

    /**
     * Getter for game state.
     * @return the current game state of the Game object
     */
    GameState GetGameState() const;

    /**
     * Setter for GameStatus object.
     * @param state the state to set the GameStatus to
     */
    void SetGameStatus(const GameState &state);

    /**
     * Setter for the chop goal.
     * @param goal the size_t representing the goal to set 
     */
    void SetChopGoal(size_t goal);

    /**
     * Increments the chop progress by +1 every time the corresponding event occurs.
     */
    void IncrementChopProgress();

    /**
     * Getter for the chop progress.
     * @return a size_t representing the chop progress
     */
    size_t GetChopProgress() const;

    /**
     * Getter for the chop goal.
     * @return a size_t representing the chop goal
     */
    size_t GetChopGoal() const;

    /**
     * Increments the mayo count by +1 every time the corresponding event occurs.
     */
    void IncrementMayoCount();

    /**
     * Increments the salt count by +1 every time the corresponding event occurs.
     */
    void IncrementSaltCount();

    /**
     * Increments the pepper count by +1 every time the corresponding event occurs.
     */
    void IncrementPepperCount();

    /**
     * Getter for the mayo count.
     * @return a size_t representing the mayo count
     */
    size_t GetMayoCount() const;

    /**
     * Getter for the salt count.
     * @return a size_t representing the salt count
     */
    size_t GetSaltCount() const;

    /**
     * Getter for the pepper count.
     * @return a size_t representin the pepper count
     */
    size_t GetPepperCount() const;

    /**
     * Calculates the chop mini-game score once time is up.
     */
    void CalculateChopGameScore();

    /**
     * Getter for the score.
     * @return a size_t representing the score
     */
    size_t GetScore() const;

    /**
     * Calculates the click mini-game score once time is up.
     */
    void CalculateClickGameScore();

    /**
     * Checks if all ingredients goals have been met (aka if all ingredients have been collected).
     * @return true if all ingredients have been met, false otherwise
     */
    bool HasCollectedAllIngredients() const;

 private:
    GameState state_;
    Recipe recipe_;
    size_t score_;
    size_t chop_goal_;
    size_t chop_progress_;
    size_t mayo_count_;
    size_t salt_count_;
    size_t pepper_count_;

    const size_t ingredient_goal_ = 5;

    // Constants to create a Recipe object
    const std::string kRecipeName = "potato salad";
    const std::string kImageUrl = "https://media.discordapp.net/attachments/746810859187208273/833884339280412732/unknown.png?width=720&height=540";
};

}  // namespace cookingmeemaw
