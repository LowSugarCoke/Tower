#include <allegro5/base.h>
#include <random>
#include <string>

#include "DirtyEffect.hpp"
#include "Enemy.hpp"
#include "FireBullet.hpp"
#include "Group.hpp"
#include "PlayScene.hpp"
#include "Point.hpp"

class Turret;

FireBullet::FireBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret* parent) :
    Bullet("play/bullet-1.png", 300, 2, position, forwardDirection, rotation - ALLEGRO_PI / 2, parent) {

}
void FireBullet::OnExplode(Enemy* enemy) {

    float slowFactor = 0.1;  // example value, slows the enemy to half speed
    float slowTime = 0.5;    // example value, slows the enemy for 2 seconds
    enemy->Slow(slowFactor, slowTime);

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(2, 5);
    getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-2.png", dist(rng), enemy->Position.x, enemy->Position.y));
    

}
