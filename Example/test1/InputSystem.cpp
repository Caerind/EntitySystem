#include "InputSystem.hpp"
#include "../../Source/EntityManager.hpp"

InputSystem::InputSystem(ses::EntityManager::Ptr entityManager)
: System(entityManager)
{
    mFilter.requires(ses::type<SpriteComponent>());
}

void InputSystem::update(sf::Time dt)
{
    float speed = 100.f;
    for (std::size_t i = 0; i < mEntities.size(); i++)
    {
        sf::Vector2f movement;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            movement.x++;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        {
            movement.x--;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            movement.y--;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            movement.y++;
        }
        movement *= dt.asSeconds() * speed;
        if (movement != sf::Vector2f() && mEntityManager != nullptr)
        {
            sf::Packet packet;
            packet << 10 << 10 << mEntities[i] << movement;
            mEntityManager->sendPacket(packet);
        }
    }
}

void InputSystem::handlePacket(sf::Packet& packet)
{
}




