#include "MyEntityManager.hpp"

MyEntityManager::MyEntityManager()
: EntityManager()
{
    setPrefab("Sprite",[&]() -> sf::Int32
    {
        sf::Int32 id = addEntity();
        addComponent<SpriteComponent>(id);
        return id;
    });

    setPrefab("Rectangle",[&]() -> sf::Int32
    {
        sf::Int32 id = addEntity();
        addComponent<RectangleComponent>(id);
        return id;
    });
}

void MyEntityManager::handlePacket(sf::Packet& packet)
{
    sf::Int32 eventId;
    packet >> eventId;
    switch (eventId)
    {
        case 10: mSystems->handlePacket(RenderSystem::getId(),packet); break;
        case 11: { std::string prefabId; packet >> prefabId; usePrefab(prefabId); } break;
        default: break;
    }
}
