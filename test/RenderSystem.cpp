#include "RenderSystem.hpp"
#include "../EntityManager.hpp"
#include <iostream>

RenderSystem::RenderSystem(EntityManager::Ptr entityManager)
: System(entityManager)
{
    mFilter.requiresOne({SpriteComponent::getId(),RectangleComponent::getId()});
}

std::string RenderSystem::getId()
{
    return "RenderSystem";
}

void RenderSystem::render(sf::RenderTarget& target)
{
    for (std::size_t i = 0; i < mEntities.size(); i++)
    {
        if (mEntityManager->hasComponent<SpriteComponent>(mEntities[i]))
        {
            target.draw(mEntityManager->getComponent<SpriteComponent>(mEntities[i]).mSprite);
        }
        else if (mEntityManager->hasComponent<RectangleComponent>(mEntities[i]))
        {
            target.draw(mEntityManager->getComponent<RectangleComponent>(mEntities[i]).mShape);
        }
    }
}

void RenderSystem::handlePacket(sf::Packet& packet)
{
    int eventId;
    packet >> eventId;
    switch (eventId)
    {
        case 10:
        {
            sf::Int32 entityId;
            sf::Vector2f mvt;
            packet >> entityId >> mvt;
            for (std::size_t i = 0; i < mEntities.size(); i++)
            {
                if (mEntities[i] == entityId)
                {
                    if (mEntityManager->hasComponent<SpriteComponent>(mEntities[i]))
                    {
                        mEntityManager->getComponent<SpriteComponent>(mEntities[i]).mSprite.move(mvt);
                        sf::Packet packet;
                        packet << 11 << 11 << entityId << mEntityManager->getComponent<SpriteComponent>(mEntities[i]).mSprite.getPosition();
                        mEntityManager->sendPacket(packet);
                    }
                }
            }
        } break;
        case 11:
        {
            sf::Int32 entityId;
            sf::Vector2f pos;
            packet >> entityId >> pos;
            for (std::size_t i = 0; i < mEntities.size(); i++)
            {
                if (mEntities[i] == entityId)
                {
                    if (mEntityManager->hasComponent<SpriteComponent>(mEntities[i]))
                    {
                        mEntityManager->getComponent<SpriteComponent>(mEntities[i]).mSprite.setPosition(pos);
                    }
                }
            }
        }
        default: break;
    }
}



