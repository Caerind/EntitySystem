#ifndef RENDERSYSTEM_HPP
#define RENDERSYSTEM_HPP

#include "../System.hpp"
#include "SpriteComponent.hpp"
#include "RectangleComponent.hpp"

#include <SFML/Graphics/RenderTarget.hpp>

class RenderSystem : public System
{
    public:
        RenderSystem(std::shared_ptr<EntityManager> entityManager);

        static std::string getId();

        void render(sf::RenderTarget& target);

        void handlePacket(sf::Packet& packet);
};

#endif // RENDERSYSTEM_HPP
