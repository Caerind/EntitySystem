#include "ClientEntityManager.hpp"

ClientEntityManager::ClientEntityManager()
: EntityManager()
{
    mConnected = false;
    mSocket.setBlocking(false);
}

void ClientEntityManager::sendPacket(sf::Packet& packet)
{
    mSocket.send(packet);
}

void ClientEntityManager::handlePackets()
{
    while (mRunning)
    {
        if (mConnected)
        {
            sf::Packet m;
            while (mSocket.receive(m) == sf::Socket::Done && mSystems != nullptr)
            {
                handlePacket(m);
            }
        }
        else
        {
            if (mSocket.connect(sf::IpAddress::LocalHost, 53000) == sf::Socket::Done)
            {
                std::cout << "Client :: Connexion reussie" << std::endl;
                mConnected = true;
            }
            else
            {
                std::cout << "Client :: Impossible de se connecter" << std::endl;
            }
        }
    }
}

void ClientEntityManager::handlePacket(sf::Packet& packet)
{
    int eventId;
    packet >> eventId;
    std::cout << "Client :: event : " << eventId << std::endl;
    switch (eventId)
    {
        case 11: mSystems->handlePacket(ses::type_to_string<RenderSystem>(),packet);
        case 50: { sf::Int32 entityId; packet >> entityId; addEntity(entityId); } break;
        case 51: { sf::Int32 entityId; packet >> entityId; addComponent<SpriteComponent>(entityId); } break;
        default: break;
    }
}

