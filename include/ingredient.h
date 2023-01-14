#pragma once

#include <nlohmann/json.hpp>
#include <string>
#include <vector>

using json = nlohmann::json;

namespace cookingmeemaw {

class Ingredient {
 public:
    /**
     * Default constructor for an Ingredient object.
     */
    Ingredient() = default;

    /**
     * Constructor for creating an Ingredient object from JSON.
     * @param json the json object used to retrieve JSON data
     */
    explicit Ingredient(const json &json);

    // Currently using this constructor b/c of troubling with JSON deserialization in Recipe class (-':
    /**
     * Constructor for an Ingredient object.
     * @param name string of ingredient name
     * @param image_url string of image url
     * @param game_type string of what game this ingredient is used in
     */
    explicit Ingredient(const std::string &name, const std::string &image_url, const std::string &game_type);


 private:
    std::string name_;
    std::string image_url_;
    std::string game_type_;
};

}  // namespace cookingmeemaw
