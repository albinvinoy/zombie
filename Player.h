#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player{
    public:

        Player();

        void spawn(IntRect arena, Vector2f resolution, int tileSize);

        void resetPlayerStats();
        bool hit(Time timeHit);
        Time getLastHitTime();
        FloatRect getPosition();
        Vector2f getCenter();
        float getRotation();

        Sprite getSprite();
        
        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();

        void stopLeft();
        void stopRight();
        void stopUp();
        void stopDown();

        void update(float elapsedTime, Vector2i mousePosition);

        void upgradeSpeed();
        void upgradeHealth();

        void increaseHealthLevel(int amount);

        int getHealth();

    private:
        const float START_SPEED = 200;
        const float START_HEALTH = 100;
        Sprite _sprite;
        Texture _texture;
        Vector2f _resolution;
        IntRect _arena;
        int _tileSize;

        bool _upPressed;
        bool _downPressed;
        bool _leftPressed;
        bool _rightPressed;

        int _health;
        int _maxHealth;

        Time _lastHit;

        float _speed;
};
