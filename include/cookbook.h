#pragma once

#include "recipe.h"

#include <nlohmann/json.hpp>
#include <string>
#include <vector>
#include <fstream>

using json = nlohmann::json;

namespace cookingmeemaw {

class Cookbook {
 public:
    /**
     * Default constructor for a Cookbook object.
     */
    Cookbook() = default;

    /**
     * Constructor for when a Cookbook object is to be made from a JSON file.
     * @param file string representing the file path to JSON file
     */
    explicit Cookbook(const std::string &file);

 private:
    std::vector<Recipe> recipes_;

    bool is_completed_ = false;
    const std::string kDifficulty = "Easy";
};

}  // namespace cookingmeemaw
