cmake_minimum_required(VERSION 3.20)
project(ShootThemUp CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(ShootThemUp
    main.cpp
    Bonus.cpp
    BonusBomb.cpp
    BonusHeal.cpp
    BonusProjectile.cpp
    BonusShield.cpp
    Boss.cpp
    EnemyShip.cpp
    GameModel.cpp
    GameView.cpp
    Level.cpp
    MovableObject.cpp
    PlayerShip.cpp
    PositionObject.cpp
    Projectile.cpp
    Ship.cpp
)

target_link_libraries(ShootThemUp PRIVATE sfml-graphics sfml-window sfml-system)
