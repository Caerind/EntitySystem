#include "RectangleComponent.hpp"

RectangleComponent::RectangleComponent()
{
    mShape.setSize({100,100});
    mShape.setPosition(0,0);
    mShape.setFillColor(sf::Color::Red);
}
