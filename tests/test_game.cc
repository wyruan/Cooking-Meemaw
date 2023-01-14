#include <game.h>

#include <catch2/catch.hpp>

using namespace cookingmeemaw;

TEST_CASE("Game can properly calculate in-game scores") {
    SECTION("Game correctly calculates chop game score") {
        Game game;
        game.SetChopGoal(5);
        
        SECTION("Game correctly calculates score for no chops made") {
            game.CalculateChopGameScore();
            
            REQUIRE(game.GetScore() == 75);
        }
        
        SECTION("Game correctly calculates score for partial # of chops made") {
            game.IncrementChopProgress();
            game.IncrementChopProgress();
            
            game.CalculateChopGameScore();
            
            REQUIRE(game.GetScore() == 85);
        }
        
        SECTION("Game correctly calculates score for meeting chop goal (no penalty)") {
            for (size_t i = 0; i < 5; i++) {
                game.IncrementChopProgress();
            }
            
            game.CalculateChopGameScore();
            
            REQUIRE(game.GetScore() == 100);
        }
    }
    
    SECTION("Game correctly calculates click game score") {
        Game game;
        
        SECTION("Game correctly calculates score for no clicks made") {
            game.CalculateClickGameScore();
            REQUIRE(game.GetScore() == 25);
        }
        
        SECTION("Game correctly calculates score for partial # of clicks made") {
            game.IncrementMayoCount();
            game.IncrementSaltCount();
            game.IncrementPepperCount();
            
            game.CalculateClickGameScore();
            
            REQUIRE(game.GetScore() == 40);
        }
        
        SECTION("Game correctly calculates score for meeting ingredient goals (no penalty)") {
            for (size_t i = 0; i < 5; i++) {
                game.IncrementMayoCount();
                game.IncrementSaltCount();
                game.IncrementPepperCount();
            }

            game.CalculateClickGameScore();

            REQUIRE(game.GetScore() == 100);
        }
    }
}
