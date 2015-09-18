#ifndef RECTANGLECOMPONENT_HPP
#define RECTANGLECOMPONENT_HPP

#include "../Component.hpp"

#include <SFML/Graphics/RectangleShape.hpp>

class RectangleComponent : public Component
{
    public:
        RectangleComponent();

        static std::string getId();

        sf::RectangleShape mShape;
};
#endif // RECTANGLECOMPONENT_HPP
