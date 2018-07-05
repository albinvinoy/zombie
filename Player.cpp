#include "Player.h"
#include <cmath>

Player::Player(){
    _speed = START_SPEED;
    _health = START_HEALTH;
    _maxHealth = START_HEALTH;

    _texture.loadFromFile("graphics/player.png");
    _sprite.setTexture(_texture);

    //sprite set to center
    _sprite.setOrigin(25,25);
}

void Player::spawn(IntRect arena, Vector2f resolution, int titleSize){
    //Player in middle
    _position.x = arena.width/2;
    _position.y = arena.height/2;

    _arena.left = arena.left;
    _arena.width = arena.width;
    _arena.top = arena.top;
    _arena.height = arena.height;

    //size of tiles
    _tileSize = titleSize;

    _resolution.x = resolution.x;
    _resolution.y = resolution.y;
}

void Player::resetPlayerStats(){
    _speed = START_SPEED;
    _health = START_HEALTH;
    _maxHealth = START_HEALTH;
}

Time Player::getLastHitTime(){
    return _lastHit;
}

bool Player::hit(Time timeHit){
    if(timeHit.asMilliseconds() - _lastHit.asMilliseconds() > 200){
        _lastHit = timeHit;
        _health -= 10;
        return true;
    }
    else{
        return false;
    }
}

FloatRect Player::getPosition(){
    /*
    The returned rectangle is in global coordinates, which means that it takes into account the transformations (translation, rotation, scale, ...) that are applied to the entity.
    */
    return _sprite.getGlobalBounds();
}

Vector2f Player::getCenter(){
    return _position;
}

float Player::getRotation(){
    return _sprite.getRotation();
}

Sprite Player::getSprite(){
    return _sprite;
}

int Player::getHealth(){
    return _health;
}

void Player::moveLeft(){
    _leftPressed = true;
}

void Player::moveRight(){
    _rightPressed = true;
}

void Player::moveUp(){
    _upPressed = true;
}

void Player::moveDown(){
    _downPressed = true;
}

void Player::stopLeft(){
    _leftPressed = false;
}

void Player::stopRight(){
    _rightPressed = false;
}

void Player::stopUp(){
    _upPressed = false;
}

void Player::stopDown(){
    _downPressed = false;
}

void Player::update(float elapsedTime, Vector2i mousePosition){
    if(_upPressed){
        _position.y -= _speed * elapsedTime;
    }
    if(_downPressed){
        _position.y += _speed * elapsedTime;
    }
    if(_leftPressed){
        _position.x -= _speed * elapsedTime;
    }
    if(_rightPressed){
        _position.x += _speed * elapsedTime;
    }

    _sprite.setPosition(_position);

    if(_position.x > _arena.width - _tileSize){
        _position.x = _arena.width - _tileSize;
    }
    if(_position.x < _arena.left + _tileSize){
        _position.x = _arena.left + _tileSize;
    }
    if(_position.y > _arena.height - _tileSize){
        _position.y = _arena.height - _tileSize;
    }
    if(_position.y < _arena.top + _tileSize){
        _position.y = _arena.top + _tileSize;
    }

    float angle = (atan2(mousePosition.y - _resolution.y / 2,mousePosition.x - _resolution.x /2) * 180) / 3.141;
    _sprite.setRotation(angle);

}

void Player::upgradeSpeed()
{
	_speed += (START_SPEED * .2);
}

void Player::upgradeHealth()
{
	_health += (START_HEALTH * .2);

}

void Player::increaseHealthLevel(int amount)
{
	_health += amount;
	if (_health > _maxHealth)
	{
		_health = _maxHealth;
	}
}