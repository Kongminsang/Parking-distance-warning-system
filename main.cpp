#include <iostream>
#include "sensor.h"
#include "kalman_filter.h"
#include "collision_checker.h"
#include <Eigen/Dense>

int main() {
    // Initialize sensor
    Sensor sensor;

    // Generate initial distance and speed
    double distance = sensor.generateDistance();
    double speed = sensor.generateSpeed();

    // Initialize Kalman Filter
    Eigen::VectorXd x0(2);
    x0 << distance, speed;
    KalmanFilter kf;
    kf.init(1.0, x0); // Assuming time step of 1 second

    // Initialize Collision Checker with a threshold of 2 seconds
    CollisionChecker collisionChecker(2.0);

    // Simulate sensor readings and check for collision
    for (int i = 0; i < 10; ++i) {
        // Generate new sensor readings
        distance = sensor.generateDistance();
        speed = sensor.generateSpeed();

        // Update Kalman Filter with new measurements
        Eigen::VectorXd z(2);
        z << distance, speed;
        kf.predict();
        kf.update(z);

        // Get filtered state
        Eigen::VectorXd state = kf.getState();
        double filteredDistance = state(0);
        double filteredSpeed = state(1);

        // Calculate Time-to-Collision (TTC)
        double ttc = collisionChecker.calculateTTC(filteredDistance, filteredSpeed);

        // Check if collision is imminent
        if (collisionChecker.isCollisionImminent(ttc)) {
            std::cout << "Warning: Collision imminent!" << std::endl;
        } else {
            std::cout << "Distance: " << filteredDistance << " m, Speed: " << filteredSpeed << " m/s, TTC: " << ttc << " s" << std::endl;
        }
    }

    return 0;
}