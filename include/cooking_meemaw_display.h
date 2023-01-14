#pragma once

#include "cinder/gl/gl.h"
#include "cinder/app/App.h"
#include "cinder/Rand.h"

#include "game.h"
#include "game_object.h"

namespace cookingmeemaw {

class Display {
 public:
    Display() = default;

    /**
     * Sets up and draws images for start screen
     */
    void DrawStartScreen(int window_height, int window_width);

    /**
     * Draws the background image for each mini-game 
     * @param window_height height of the app window
     * @param window_width width of the app window
     */
    void DrawGameBackground(int window_height, int window_width);

    /**
     * Draws the images needed for the chop mini-game screen.
     * @param game the Game object used to retrieve data to display
     * @param window_height height of the app window
     * @param window_width width of the app window
     * @param time_remaining a double representing how much time is left for player to complete mini-game goals
     */
    void DrawChopGameScreen(const Game &game, int window_height, int window_width, double time_remaining);

    /**
     * Helper function to draw the veggies and knife for the chop mini-game. 
     * @param knife_left_x_pos left x-coordinate for the knife image
     * @param knife_right_x_pos right x-coordinate for the knife image
     * @param knife_top_y_pos upper y-coordinate for the knife image
     * @param knife_bottom_y_pos bottom y-coordinate for the knife image
     * @param potato_left_x_pos left x-coordinate for the potato image
     * @param potato_right_x_pos right x-coordinate for the potato image
     * @param potato_top_y_pos top y-coordinate for the potato image
     * @param potato_bottom_y_pos bottom y-coordinate for the potato image
     * @param carrot_left_x_pos left x-coordinate for the carrot image
     * @param carrot_right_x_pos right x-coordinate for the carrot image
     * @param carrot_top_y_pos top y-coordinate for the carrot image 
     * @param carrot_bottom_y_pos bottom y-coordinate for the carrot image
     * @param onion_left_x_pos left x-coordinate for the onion image
     * @param onion_right_x_pos right x-coordinate for the onion image
     * @param onion_top_y_pos top y-coordinate for the onion image
     * @param onion_bottom_y_pos bottom y-coordinate for the onion image
     */
    void DrawChopGameObjects(float knife_left_x_pos,
                             float knife_right_x_pos, float knife_top_y_pos, float knife_bottom_y_pos,
                             float potato_left_x_pos, float potato_right_x_pos, float potato_top_y_pos,
                             float potato_bottom_y_pos, float carrot_left_x_pos, float carrot_right_x_pos,
                             float carrot_top_y_pos, float carrot_bottom_y_pos, float onion_left_x_pos,
                             float onion_right_x_pos, float onion_top_y_pos, float onion_bottom_y_pos);

    /**
     * Draws the text box that displays the current score.
     * @param game the Game object used to retrieve the data to display
     */
    void DrawScoreTextBox(const Game &game);

    /**
     * Draws the timer that displays the time remaining to complete the mini-game.
     * @param time_remaining a double representing the time left 
     */
    void DrawTimer(double time_remaining);

    /**
     * Draws the images needed for the click mini-game.
     * @param window_height height of the app window
     * @param window_width width of the app window
     * @param num_of_each_object number of each GameObject object to add
     * @param image_height height of image
     */
    void DrawClickGameScreen(const Game &game, int window_height, int window_width, size_t num_of_each_object,
                             int image_height, double time_remaining);

    /**
     * Adds a mayo GameObject object to the GameObject vector.
     * @param window_height height of the app window
     * @param window_width width of the app window
     * @param image_height height of image
     */
    void AddMayoObject(int window_height, int window_width, int image_height);

    /**
     * Adds a salt GameObject object to the GameObject vector.
     * @param window_height height of the app window
     * @param window_width width of the app window
     * @param image_height height of image
     */
    void AddSaltShakerObject(int window_height, int window_width, int image_height);

    /**
     * Adds a pepper GameObject object to the GameObject vector.
     * @param window_height height of the app window
     * @param window_width width of the app window
     * @param image_height height of image
     */
    void AddPepperShakerObject(int window_height, int window_width, int image_height);

    /**
     * Draws the ingredient progress text boxes that display the ingredient progresses.
     * @param game the Game object used to retrieve the data to display
     */
    void DrawIngredientProgress(const Game &game) const;

    /**
     * Draws the game over screen.
     * @param game the Game object used to retrieve the data to display
     * @param window_height height of the app window
     * @param window_width width of the app window
     */
    void DrawGameOverScreen(const Game &game, int window_height, int window_width);

    /**
     * Draws the amount of stars depending on the game's ending score.
     * @param game the Game object used to retrieve the data to display
     */
    void DrawStars(const Game &game);

    /**
     * Returns the vector of GameObjects.
     * @return a vector of GameObjects
     */
    std::vector<GameObject> GetGameObjects() const;


 private:
    std::vector<GameObject> objects_;

    // Images
    const std::string kStartImage = "pixelcookingmeemaw.png";
    const std::string kWelcomeBackground = "kitchen.jpg";
    const std::string kGameBackground = "pinkplaidwallpaper.jpg";
    const std::string kMeemawImage = "meemaw.png";
    const std::string kSpeechBoxImage = "speechbox.png";
    const std::string kCuttingBoardImage = "cuttingboard.png";
    const std::string kKnifeImage = "pixelknife.png";
    const std::string kPotatoImage = "potato.png";
    const std::string kCarrotImage = "carrot.png";
    const std::string kOnionImage = "onion.png";
    const std::string kMayoImage = "duckmayo.png";
    const std::string kSaltShakerImage = "saltshaker.png";
    const std::string kPepperShakerImage = "peppershaker.png";
    const std::string kGameOverBackground = "gameover.png";
    const std::string kStar = "pixelstar.png";
    const std::string kGrayedOutStar = "pixelgraystar.png";

    // Text
    const std::string kWelcomeText = "Cooking Meemaw";
    const std::string kStartText = "Press [ spacebar ] to start cooking!";
    const std::string kChopGameText = "Press [ spacebar ] to chop the veggies! Hurry or else Meemaw will be mad!";
    const std::string kClickGameText = "Help Meemaw collect the remaining ingredients! Click to collect them!";
    const std::string kThreeStarText = "Even better than Meemaw!";
    const std::string kTwoStarText = "Good job! Meemaw is content.";
    const std::string kOneStarText = "Nice try, but Meemaw is discontent.";
    const std::string kZeroStarText = "...";

    // Timer
    const double kTimeLow = 17.0;
    const double kTimeCritical = 9.0;

    // Progress
    const double kProgressLow = 50.0;
    const double kProgressMedium = 75.00;

    // Ingredient progress
    const size_t kLowStock = 3;
    const size_t kMediumStock = 4;

    // Star score calculations
    const size_t kThreeStar = 100;
    const size_t kTwoStar = 67;
    const size_t kOneStar = 34;
};

}  // namespace cookingmeemaw
