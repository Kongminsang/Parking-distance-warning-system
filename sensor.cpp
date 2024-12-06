#include "sensor.h"
#include <random>

Sensor::Sensor() : currentDistance(50.0), currentSpeed(5.0), currentAcceleration(-0.1) {
    // Constructor implementation with initial values
}

double Sensor::generateDistance() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> accDis(0.0, 0.02); // Smaller random change in acceleration
    currentAcceleration += accDis(gen); // Update acceleration with small random change

    currentSpeed += currentAcceleration; // Update speed based on acceleration
    if (currentSpeed < 0) currentSpeed = 0; // Ensure speed does not go negative
    currentDistance -= currentSpeed; // Update distance based on speed

    return addNoise(currentDistance);
}

double Sensor::generateSpeed() {
    return addNoise(currentSpeed);
}

double Sensor::addNoise(double value) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> dis(0.0, 0.2); // Smaller noise with mean 0 and standard deviation 0.2
    return value + dis(gen);
}