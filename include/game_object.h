#pragma once

#include "cinder/gl/gl.h"

namespace cookingmeemaw {

class GameObject {
 public:
    explicit GameObject(const glm::vec2 &position, const std::string &image);

    /**
     * Getter for a GameObject's position variable.
     * @return glm::vec2 representing the position
     */
    const glm::vec2 &GetPosition() const;

    /**
     * Getter for a GameObject's image variable.
     * @return std::string representing the image
     */
    const std::string &GetImage() const;

 private:
    glm::vec2 position_;
    std::string image_;
};

}  // namespace cookingmeemaw
