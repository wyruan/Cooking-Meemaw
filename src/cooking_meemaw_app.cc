#include "cooking_meemaw_app.h"

namespace cookingmeemaw {

cookingmeemaw::CookingMeemawApp::CookingMeemawApp() {
    ci::app::setWindowSize(kWindowWidth, kWindowHeight);
}

void CookingMeemawApp::setup() {
    size_t goal = static_cast<size_t>(cinder::Rand::randFloat(0, 15));
    game_.SetChopGoal(goal);

    for (size_t i = 0; i < kNumberOfGameObjects; i++) {
        display_.AddMayoObject(kWindowHeight, kWindowWidth, kImageHeight);
        display_.AddSaltShakerObject(kWindowHeight, kWindowWidth, kImageHeight);
        display_.AddPepperShakerObject(kWindowHeight, kWindowWidth, kImageHeight);
    }
}

void CookingMeemawApp::draw() {
    // Checks current game status and draws appropriate screen
    if (game_.GetGameState() == GameState::StartGame) {
        display_.DrawStartScreen(kWindowHeight, kWindowWidth);
    } else if (game_.GetGameState() == GameState::PlayChopGame) {
        display_.DrawChopGameScreen(game_, kWindowHeight, kWindowWidth, time_remaining_);
        display_.DrawChopGameObjects(knife_left_x_pos_, knife_right_x_pos_, knife_top_y_pos_, knife_bottom_y_pos_,
                                     potato_left_x_pos_, potato_right_x_pos_, potato_top_y_pos_, potato_bottom_y_pos_,
                                     carrot_left_x_pos_, carrot_right_x_pos_, carrot_top_y_pos_, carrot_bottom_y_pos_,
                                     onion_left_x_pos_, onion_right_x_pos_, onion_top_y_pos_, onion_bottom_y_pos_);
    } else if (game_.GetGameState() == GameState::PlayClickGame) {
        display_.DrawClickGameScreen(game_, kWindowHeight, kWindowWidth, kNumberOfGameObjects, kImageHeight,
                                     time_remaining_);
    } else if (game_.GetGameState() == GameState::GameOver) {
        display_.DrawGameOverScreen(game_, kWindowHeight, kWindowWidth);
    }
}

void CookingMeemawApp::update() {
    // Updates timer on the screen
    if (is_timer_on_) {
        auto now = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_time = now - start_time_;
        time_remaining_ = kGameSeconds - elapsed_time.count();

        if (time_remaining_ <= 0) {
            is_timer_on_ = false;
        }
    }

    if (game_.GetGameState() == GameState::PlayChopGame) {
        // If time runs out during chop game, score and game status is updated (also restarts timer).
        if (!is_timer_on_) {
            game_.CalculateChopGameScore();
            is_timer_on_ = true;
            start_time_ = std::chrono::system_clock::now();
            game_.SetGameStatus(GameState::PlayClickGame);

        }

        // If chop goal is met before time is up, update game status and reset timer.
        if (game_.GetChopProgress() == game_.GetChopGoal()) {
            game_.SetGameStatus(GameState::PlayClickGame);
            start_time_ = std::chrono::system_clock::now();
            is_timer_on_ = true;
        }
    }

    if (game_.GetGameState() == GameState::PlayClickGame) {
        // If time runs out during click game, score and game status is updated.
        if (!is_timer_on_) {
            game_.CalculateClickGameScore();
            game_.SetGameStatus(GameState::GameOver);
        }

        // If ingredient goals are met before time is up, turn off timer and update game status.
        if (time_remaining_ > 0 && game_.HasCollectedAllIngredients()) {
            is_timer_on_ = false;
            game_.SetGameStatus(GameState::GameOver);
        }
    }
}

void CookingMeemawApp::keyDown(ci::app::KeyEvent event) {
    switch (event.getCode()) {
        case ci::app::KeyEvent::KEY_SPACE: {
            if (game_.GetGameState() == GameState::StartGame) {
                start_time_ = std::chrono::system_clock::now();
                is_timer_on_ = true;
                game_.SetGameStatus(GameState::PlayChopGame);
                break;
            }

            if (game_.GetGameState() == GameState::PlayChopGame) {
                if (time_remaining_ > 0 && IsWithinRangeOfVeggies()) {
                    game_.IncrementChopProgress();
                }
                break;
            }
        }
        case ci::app::KeyEvent::KEY_UP: {
            if (game_.GetGameState() == GameState::PlayChopGame) {
                knife_top_y_pos_ = knife_top_y_pos_ - pixel_movement_;
                knife_bottom_y_pos_ = knife_bottom_y_pos_ - pixel_movement_;
            }
            break;
        }

        case ci::app::KeyEvent::KEY_DOWN: {
            if (game_.GetGameState() == GameState::PlayChopGame) {
                knife_top_y_pos_ += pixel_movement_;
                knife_bottom_y_pos_ += pixel_movement_;
            }
            break;
        }


        case ci::app::KeyEvent::KEY_LEFT: {
            if (game_.GetGameState() == GameState::PlayChopGame) {
                knife_left_x_pos_ = knife_left_x_pos_ - pixel_movement_;
                knife_right_x_pos_ = knife_right_x_pos_ - pixel_movement_;
            }
            break;
        }

        case ci::app::KeyEvent::KEY_RIGHT: {
            if (game_.GetGameState() == GameState::PlayChopGame) {
                knife_left_x_pos_ += pixel_movement_;
                knife_right_x_pos_ += pixel_movement_;
            }
            break;
        }
    }
}

void CookingMeemawApp::mouseDown(ci::app::MouseEvent event) {
    if (game_.GetGameState() == GameState::PlayClickGame) {
        for (const GameObject &object : display_.GetGameObjects()) {
            if (event.isLeft() && (object.GetPosition().x <= event.getPos().x) &&
                (event.getPos().x <= object.GetPosition().x + (float) kImageHeight) &&
                (object.GetPosition().y <= event.getPos().y) &&
                (event.getPos().y <= object.GetPosition().y + (float) kImageHeight)) {

                // Finds if mouseClick was in proximity of an Ingredient object
                // Finds first object, increments appropriate goal, and stops checking once found
                if (object.GetImage() == kMayoImage) {
                    game_.IncrementMayoCount();
                    break;
                } else if (object.GetImage() == kSaltShakerImage) {
                    game_.IncrementSaltCount();
                    break;
                } else {
                    game_.IncrementPepperCount();
                    break;
                }
            }
        }
    }
}

bool CookingMeemawApp::IsWithinRangeOfVeggies() const {
    if ((knife_left_x_pos_ <= potato_right_x_pos_ && knife_left_x_pos_ >= potato_left_x_pos_) &&
        (knife_top_y_pos_ <= potato_bottom_y_pos_ && knife_bottom_y_pos_ >= potato_top_y_pos_)) {
        return true;
    }

    if ((knife_left_x_pos_ <= carrot_right_x_pos_ && knife_left_x_pos_ >= carrot_left_x_pos_) &&
        (knife_top_y_pos_ <= carrot_bottom_y_pos_ && knife_bottom_y_pos_ >= carrot_top_y_pos_)) {
        return true;
    }

    if ((knife_left_x_pos_ <= onion_right_x_pos_ && knife_left_x_pos_ >= onion_left_x_pos_) &&
        (knife_top_y_pos_ <= onion_bottom_y_pos_ && knife_bottom_y_pos_ >= onion_top_y_pos_)) {
        return true;
    }
    return false;
}

}  // namespace cookingmeemaw
