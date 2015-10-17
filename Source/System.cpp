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
    /*auto itr = std::find(mFilter.begin(), mFilter.end(), entityId);
    if (mFilter.passFilter(entityId, mEntityManager) && itr == mFilter.end())
    {
        mEntities.push_back(entityId);
    }
    else if (!mFilter.passFilter(entityId, mEntityManager) && itr != mFilter.end())
    {
        mEntities.erase(mEntities.begin() + foundPos);
    }*/
}

} // namespace ses
