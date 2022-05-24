#include "EntityManager.h"

const std::vector<Entity*>& EntityManager::getEntityList() const {
    return entities;
}

void EntityManager::addEntity(Entity* entity) {
    entities.push_back(entity);
}

void EntityManager::clearEntityList(){
    entities.clear();
}