#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
public:
    Sensor();
    double generateDistance();
    double generateSpeed();

private:
    double addNoise(double value);
    double currentDistance;
    double currentSpeed;
    double currentAcceleration;
};

#endif // SENSOR_H