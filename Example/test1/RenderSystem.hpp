#ifndef RENDERSYSTEM_HPP
#define RENDERSYSTEM_HPP

#include "../../Source/System.hpp"
#include "SpriteComponent.hpp"
#include "RectangleComponent.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

class RenderSystem : public ses::System
{
    public:
        RenderSystem(std::shared_ptr<ses::EntityManager> entityManager);

        static std::string getId();

        void render(sf::RenderTarget& target);

        void handlePacket(sf::Packet& packet);
};

#endif // RENDERSYSTEM_HPP
