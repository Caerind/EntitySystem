#ifndef RECTANGLECOMPONENT_HPP
#define RECTANGLECOMPONENT_HPP

#include "../../Source/Component.hpp"

#include <SFML/Graphics/RectangleShape.hpp>

class RectangleComponent : public ses::Component
{
    public:
        RectangleComponent();

        sf::RectangleShape mShape;
};
#endif // RECTANGLECOMPONENT_HPP
