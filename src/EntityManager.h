#pragma once
#include <vector>

class Entity;

class EntityManager {
public:
    const std::vector<Entity*>& getEntityList() const;
    void addEntity(Entity* entity);
private:
    std::vector<Entity*> entities;
};