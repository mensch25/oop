#include "base.h"

using namespace unit;


Base::Base(const Point2D& point, std::shared_ptr<Mediator> mediator) :
    Unit(point, mediator)
{
    NoArmorFactory armorFactory;
    NoWeaponFactory weaponFactory;

    healthPoints = 200;
    armor = armorFactory.createArmor();
    weapon = weaponFactory.createWeapon();
    nUnits = 0;
}


bool Base::moveLeft()
{
    return false;
}


bool Base::moveTop()
{
    return false;
}


bool Base::moveBottom()
{
    return false;
}


bool Base::moveRight()
{
    return false;
}


bool Base::isFly() const
{
    return false;
}


std::shared_ptr<Unit> Base::createGroundUnit()
{
    int num = generateRandomNum(2);
    std::shared_ptr<Unit> unit;
    Point2D pos = this->position;
    pos.x++;

    switch (num) {
    case 0:
        unit = director.createThief(pos, mediator);
        break;
    case 1:
        unit = director.createWarrior(pos, mediator);
        break;
    }

    return createUnit(unit);
}


std::shared_ptr<Unit> Base::createFlyingUnit()
{
    int num = generateRandomNum(2);
    std::shared_ptr<Unit> unit;
    Point2D pos = this->position;
    pos.x++;

    switch (num) {
    case 0:
        unit = director.createDragon(pos, mediator);
        break;
    case 1:
        unit = director.createKamikadze(pos, mediator);
        break;
    }

    return createUnit(unit);
}


std::shared_ptr<Unit> Base::createStandingUnit()
{
    int num = generateRandomNum(2);
    std::shared_ptr<Unit> unit;
    Point2D pos = this->position;
    pos.x--;

    switch (num) {
    case 0:
        unit = director.createGoldMiner(pos, mediator);
        break;
    case 1:
        unit = director.createTower(pos, mediator);
        break;
    }

    return createUnit(unit);
}


size_t Base::farm() const
{
    return FIVE_GOLD;
}


std::shared_ptr<Unit> Base::clone()
{
    std::shared_ptr<Unit> base(new Base(*this));
    return base;
}


char Base::draw() const
{
    return '+';
}


void Base::update()
{
    --nUnits;
}


int Base::generateRandomNum(int end) const
{
    srand(time(0));
    return rand() % end;
}


std::shared_ptr<Unit> Base::createUnit(std::shared_ptr<Unit> unit)
{
    if (nUnits < MAX_N_UNITS && mediator->notify(unit, CRT_UNIT)) {
        unit->subscribe(shared_from_this());
        nUnits++;
        return unit;
    }

    return nullptr;
}
