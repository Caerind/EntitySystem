#ifndef INPUTSYSTEM_HPP
#define INPUTSYSTEM_HPP

#include "../../Source/System.hpp"
#include "SpriteComponent.hpp"

#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>

class InputSystem : public ses::System
{
    public:
        InputSystem(std::shared_ptr<ses::EntityManager> entityManager);

        void update(sf::Time dt);

        void handlePacket(sf::Packet& packet);

        void entityUpdate(sf::Int32 const& entityId);

        std::size_t entitiesCount() const { return mEntities.size(); }

    protected:
        ses::ComponentFilter mFilter;
        ses::EntityVector mEntities;
};

#endif // INPUTSYSTEM_HPP
