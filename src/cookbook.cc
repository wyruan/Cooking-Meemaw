#include "cookbook.h"

namespace cookingmeemaw {

Cookbook::Cookbook(const std::string &file) {
    // Referenced this source:
    // https://stackoverflow.com/questions/33628250/c-reading-a-json-object-from-file-with-nlohmann-json
    std::ifstream stream(file);
    json cookbook = json::parse(stream);

    // Referenced this source:
    // https://github.com/nlohmann/json/issues/1561
    for (const auto &recipe : cookbook["recipes"].items()) {
        recipes_.emplace_back(recipe);
    }
}

}  // namespace cookingmeemaw
