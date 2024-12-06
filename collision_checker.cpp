#include <limits>
#include "collision_checker.h"

CollisionChecker::CollisionChecker(double threshold) : threshold(threshold) {
    // Constructor implementation
}

double CollisionChecker::calculateTTC(double distance, double speed) {
    if (speed <= 0) {
        return std::numeric_limits<double>::infinity(); // No collision if speed is zero or negative
    }
    return distance / speed;
}

bool CollisionChecker::isCollisionImminent(double ttc) {
    return ttc <= threshold;
}