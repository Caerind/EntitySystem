#include "System.hpp"
#include "EntityManager.hpp"

namespace ses
{

System::System(EntityManager::Ptr entityManager)
: mEntityManager(entityManager)
{
}

System::~System()
{
}

void System::handlePacket(sf::Packet& packet)
{
}

void System::entityUpdate(sf::Int32 const& entityId)
{
    /*auto itr = std::find(mEntities.begin(), mEntities.end(), entityId);
    if (mFilter.passFilter(entityId, mEntityManager) && itr == mEntities.end())
    {
        mEntities.push_back(entityId);
    }
    else if (!mFilter.passFilter(entityId, mEntityManager) && itr != mEntities.end())
    {
        mEntities.erase(itr);
    }*/
}

} // namespace ses
