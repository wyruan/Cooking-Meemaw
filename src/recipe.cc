#include "recipe.h"

namespace cookingmeemaw {

Recipe::Recipe(const json &json) {
    recipe_name_ = json["recipe"];
    image_url_ = json["completedImageUrl"];

    // Not sure how to deserialize nested JSON into objects )-: 
    // So for now I will manually create the objects so that I can progress with my game.
    // Might came back later but right now is not a priority. 
    /*for (const auto& ingredient : json["recipes"]["recipe"]["ingredients"].items()) {
        ingredients_.emplace_back(ingredient);
    }*/
}

void Recipe::FillRecipeList() {
    std::string potato_name = "potato";
    std::string potato_game_type = "mouseClick";
    std::string potato_imageUrl = "https://static.wikia.nocookie.net/stardewvalley/images/c/c2/Potato.png/revision/latest/top-crop/width/360/height/360?cb=20160322110253";

    std::string carrot_name = "carrot";
    std::string carrot_game_type = "mouseClick";
    std::string carrot_imageUrl = "https://static.wikia.nocookie.net/food-plus/images/0/07/Infobox_Cooked_Carrot.png/revision/latest/top-crop/width/360/height/450?cb=20171127232207";

    std::string onion_name = "onion";
    std::string onion_game_type = "mouseClick";
    std::string onion_imageUrl = "https://static.wikia.nocookie.net/stardewvalley/images/c/cc/Garlic.png/revision/latest/top-crop/width/360/height/360?cb=20160323190508";

    std::string mayonnaise_name = "mayonnaise";
    std::string mayonnaise_type = "matching";
    std::string mayonnaise_imageUrl = "https://stardewvalleywiki.com/mediawiki/images/2/23/Duck_Mayonnaise.png";

    std::string salt_name = "salt";
    std::string salt_game_type = "matching";
    std::string salt_imageUrl = "https://cdn.discordapp.com/attachments/758546299669708810/833895337436774420/saltshaker.png";

    std::string pepper_name = "pepper";
    std::string pepper_game_type = "matching";
    std::string pepper_imageUrl = "https://cdn.discordapp.com/attachments/758546299669708810/833912588709920808/peppershaker.png";

    ingredients_.emplace_back(potato_name, potato_imageUrl, potato_game_type);
    ingredients_.emplace_back(carrot_game_type, carrot_imageUrl, carrot_game_type);
    ingredients_.emplace_back(onion_name, onion_imageUrl, onion_game_type);
    ingredients_.emplace_back(mayonnaise_name, mayonnaise_imageUrl, mayonnaise_type);
    ingredients_.emplace_back(salt_name, salt_imageUrl, salt_game_type);
    ingredients_.emplace_back(pepper_name, pepper_imageUrl, pepper_game_type);
}

void Recipe::SetRecipeName(const std::string &name) {
    recipe_name_ = name;
}

void Recipe::SetImageUrl(const std::string &image_url) {
    image_url_ = image_url;
}

}  // namespace cookingmeemaw
