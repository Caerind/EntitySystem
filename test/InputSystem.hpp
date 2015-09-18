#ifndef INPUTSYSTEM_HPP
#define INPUTSYSTEM_HPP

#include "../System.hpp"
#include "SpriteComponent.hpp"

#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>

class InputSystem : public System
{
    public:
        InputSystem(std::shared_ptr<EntityManager> entityManager);

        static std::string getId();

        void update(sf::Time dt);

        void handlePacket(sf::Packet& packet);
};

#endif // INPUTSYSTEM_HPP
