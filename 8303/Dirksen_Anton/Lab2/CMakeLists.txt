cmake_minimum_required(VERSION 3.15)
project(oop_labs)

set(CMAKE_CXX_STANDARD 14)

set(SFML_INCLUDE_DIR "/home/mensch/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "/home/mensch/SFML-2.5.1/lib")
set(SFML_DIR "/home/mensch/SFML-2.5.1/lib/cmake/SFML")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

add_executable(oop_labs main.cpp Field/Field.cpp Field/Field.h Objects/Object.cpp Objects/Object.h Point.cpp Point.h Objects/Units/Unit.cpp Objects/Units/Unit.h Objects/Units/Archers/Archer.h Objects/Units/Archers/Bowman.cpp Objects/Units/Archers/Bowman.h Objects/Units/Archers/Crossbowman.cpp Objects/Units/Archers/Crossbowman.h Objects/Units/Factories/UnitFactory.h Objects/Units/Swordsmen/Swordsman.h Objects/Units/Swordsmen/Knight.cpp Objects/Units/Swordsmen/Knight.h Objects/Units/Swordsmen/Squire.cpp Objects/Units/Swordsmen/Squire.h Objects/Units/Wizards/Wizard.h Objects/Units/Wizards/Druid.cpp Objects/Units/Wizards/Druid.h Objects/Units/Wizards/Archmage.cpp Objects/Units/Wizards/Archmage.h Objects/Units/Factories/ArcherFactory.h Objects/Units/Factories/SwordsmenFactory.h Objects/Units/Factories/WizardFactory.h Field/FieldIterator.h Field/Cell.h Objects/Units/Armor/Armor.h Objects/Units/Armor/ChainMail.h Objects/Units/Armor/Cuirass.h Objects/Units/Armor/LeatherArmor.h Objects/Units/Armor/Cloak.h Objects/Units/Armor/Hoodie.h Objects/Units/Weapon/Weapon.h Objects/Units/Weapon/LongSword.h Objects/Units/Weapon/Dagger.h Objects/Units/Weapon/Bow.h Objects/Units/Weapon/Crossbow.h Objects/Units/Weapon/MagicStaff.h Objects/Units/Weapon/SpellBook.h Objects/Base.cpp Objects/Base.h)

target_link_libraries(oop_labs sfml-graphics sfml-window sfml-system)
