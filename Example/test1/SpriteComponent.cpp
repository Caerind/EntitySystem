#include "SpriteComponent.hpp"

SpriteComponent::SpriteComponent()
{
    mTexture.loadFromFile("test/background.png");
    mSprite.setTexture(mTexture);
    mSprite.setPosition(100,100);
}

std::string SpriteComponent::getId()
{
    return "SpriteComponent";
}
