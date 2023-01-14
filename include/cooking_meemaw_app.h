#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

#include "game.h"
#include "cooking_meemaw_display.h"

namespace cookingmeemaw {

class CookingMeemawApp : public ci::app::App {
 public:
    /**
     * Default constructor for app.
     */
    CookingMeemawApp();

    /**
   * Overriding Cinder-provided methods.
   */
    void setup() override;

    void draw() override;

    void update() override;

    void keyDown(ci::app::KeyEvent event) override;

    void mouseDown(ci::app::MouseEvent event) override;

 private:
    Game game_;
    Display display_;

    // Set up of app window
    const int kWindowHeight = 600;
    const int kWindowWidth = 1250;

    // Images
    const std::string kCarrotImage = "carrot.png";
    const std::string kOnionImage = "onion.png";
    const std::string kMayoImage = "duckmayo.png";
    const std::string kSaltShakerImage = "saltshaker.png";
    const std::string kPepperShakerImage = "peppershaker.png";

    // Text
    const std::string kStartText = "Press [ spacebar ] to start cooking!";
    const std::string kClickGameText = "Help Meemaw collect the remaining ingredients! Click to collect them!";

    // Timer 
    std::chrono::time_point<std::chrono::system_clock> start_time_;
    const size_t kGameSeconds = 25;
    double time_remaining_ = 0;
    bool is_timer_on_ = false;


    // Game objects
    const size_t kNumberOfGameObjects = 10;

    // Changed from size_t to int.
    const int kImageHeight = 75;

    // Moving knife + image positions
    const float pixel_movement_ = 25;
    float knife_left_x_pos_ = 35;
    float knife_right_x_pos_ = 200;
    float knife_top_y_pos_ = 225;
    float knife_bottom_y_pos_ = 575;

    // Vegetable positions
    const float potato_left_x_pos_ = 295;
    const float potato_right_x_pos_ = 535;
    const float potato_top_y_pos_ = 300;
    const float potato_bottom_y_pos_ = 475;
    const float carrot_left_x_pos_ = 550;
    const float carrot_right_x_pos_ = 775;
    const float carrot_top_y_pos_ = 275;
    const float carrot_bottom_y_pos_ = 450;
    const float onion_left_x_pos_ = 800;
    const float onion_right_x_pos_ = 975;
    const float onion_top_y_pos_ = 250;
    const float onion_bottom_y_pos_ = 415;
    
    /**
     * Checks if the knife image is near the veggie images.
     * @return true if knife is within proximity of the veggies, false otherwise
     */
    bool IsWithinRangeOfVeggies() const;
};

}  // namespace cookingmeemaw
