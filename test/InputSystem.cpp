#include "InputSystem.hpp"
#include "../EntityManager.hpp"

InputSystem::InputSystem(EntityManager::Ptr entityManager)
: System(entityManager)
{
    mFilter.requires(SpriteComponent::getId());
}

std::string InputSystem::getId()
{
    return "InputSystem";
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




