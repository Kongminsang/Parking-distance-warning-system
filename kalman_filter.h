#ifndef KALMAN_FILTER_H
#define KALMAN_FILTER_H

#include <Eigen/Dense>

class KalmanFilter {
public:
    KalmanFilter();
    void init(double dt, const Eigen::VectorXd& x0);
    void predict();
    void update(const Eigen::VectorXd& z);

    Eigen::VectorXd getState();

private:
    double dt; // Time step
    Eigen::VectorXd x; // State vector
    Eigen::MatrixXd F; // State transition matrix
    Eigen::MatrixXd P; // Covariance matrix
    Eigen::MatrixXd Q; // Process noise covariance matrix
    Eigen::MatrixXd H; // Measurement matrix
    Eigen::MatrixXd R; // Measurement noise covariance matrix
    Eigen::MatrixXd I; // Identity matrix
};

#endif // KALMAN_FILTER_H