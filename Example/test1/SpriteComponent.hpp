#ifndef SPRITECOMPONENT_HPP
#define SPRITECOMPONENT_HPP

#include "../../Source/Component.hpp"

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class SpriteComponent : public ses::Component
{
    public:
        SpriteComponent();

        static std::string getId();

        sf::Sprite mSprite;
        sf::Texture mTexture;
};

#endif // SPRITECOMPONENT_HPP
