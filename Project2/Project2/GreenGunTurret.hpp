#ifndef GREENGUNTURRET_HPP
#define GREENGUNTURRET_HPP
#include "Turret.hpp"

class GreenGunTurret : public Turret {
public:
    static const int Price;
    GreenGunTurret(float x, float y);
    void CreateBullet() override;
};
#endif // GREENGUNTURRET_HPP
