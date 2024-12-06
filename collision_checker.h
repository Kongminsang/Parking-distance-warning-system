#ifndef COLLISION_CHECKER_H
#define COLLISION_CHECKER_H

class CollisionChecker {
public:
    CollisionChecker(double threshold);
    double calculateTTC(double distance, double speed);
    bool isCollisionImminent(double ttc);

private:
    double threshold; // Time-to-collision threshold
};

#endif // COLLISION_CHECKER_H