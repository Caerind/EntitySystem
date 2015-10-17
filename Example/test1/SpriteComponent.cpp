#include "SpriteComponent.hpp"

SpriteComponent::SpriteComponent()
{
    mTexture.loadFromFile("Example/test1/background.png");
    mSprite.setTexture(mTexture);
    mSprite.setPosition(100,100);
}
