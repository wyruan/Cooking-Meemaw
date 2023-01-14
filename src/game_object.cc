#include "game_object.h"

namespace cookingmeemaw {

GameObject::GameObject(const glm::vec2 &position, const std::string &image) : position_(position), image_(image) {
}

const glm::vec2 &GameObject::GetPosition() const {
    return position_;
}

const std::string &GameObject::GetImage() const {
    return image_;
}

}  // namespace cookingmeemaw
