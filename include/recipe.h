#pragma once

#include "ingredient.h"

#include <nlohmann/json.hpp>
#include <vector>
#include <fstream>


using json = nlohmann::json;

namespace cookingmeemaw {

class Recipe {
 public:
    /**
     * Default constructor for a Recipe object.
     */
    Recipe() = default;

    /**
     * Constructor for creating a Recipe object from JSON.
     * @param json the json object used to retrieve JSON data
     */
    explicit Recipe(const json &json);

    // The following functions are used while I figure out how to use nlohmann JSON to deserialize nested objects.
    /**
     * Manually constructs each Ingredient object in a recipe and adds it to ingredients_.
     */
    void FillRecipeList();

    /**
     * Setter for recipe name.
     * @param name 
     */
    void SetRecipeName(const std::string &name);

    /**
     * Setter for recipe image url.
     * @param image_url 
     */
    void SetImageUrl(const std::string &image_url);

 private:
    std::string recipe_name_;
    std::string image_url_;
    std::vector<Ingredient> ingredients_;
};

}  // namespace cookingmeemaw
