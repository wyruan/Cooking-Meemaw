#include "ingredient.h"

namespace cookingmeemaw {

Ingredient::Ingredient(const json &json) {
    name_ = json["recipes"]["ingredients"]["name"];
    image_url_ = json["recipes"]["ingredients"]["imageUrl"];
    game_type_ = json["recipes"]["ingredients"]["gameType"];
}

Ingredient::Ingredient(const std::string &name, const std::string &image_url, const std::string &game_type) :
        name_(name), image_url_(image_url), game_type_(game_type) {
}

}  // namespace cookingmeemaw
