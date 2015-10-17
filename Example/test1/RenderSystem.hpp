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

        void render(sf::RenderTarget& target);

        void handlePacket(sf::Packet& packet);

        void entityUpdate(sf::Int32 const& entityId);

        std::size_t entitiesCount() const { return mEntities.size(); }

    protected:
        ses::ComponentFilter mFilter;
        ses::EntityVector mEntities;
};

#endif // RENDERSYSTEM_HPP
