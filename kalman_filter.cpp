#include "kalman_filter.h"

KalmanFilter::KalmanFilter() {
    // Constructor implementation (if needed)
}

void KalmanFilter::init(double dt, const Eigen::VectorXd& x0) {
    this->dt = dt;
    this->x = x0;

    // Initialize matrices
    F = Eigen::MatrixXd::Identity(x.size(), x.size());
    P = Eigen::MatrixXd::Identity(x.size(), x.size());
    Q = Eigen::MatrixXd::Identity(x.size(), x.size());
    H = Eigen::MatrixXd::Identity(x.size(), x.size());
    R = Eigen::MatrixXd::Identity(x.size(), x.size());
    I = Eigen::MatrixXd::Identity(x.size(), x.size());
}

void KalmanFilter::predict() {
    // Predict the state
    x = F * x;
    P = F * P * F.transpose() + Q;
}

void KalmanFilter::update(const Eigen::VectorXd& z) {
    // Update the state
    Eigen::VectorXd y = z - H * x;
    Eigen::MatrixXd S = H * P * H.transpose() + R;
    Eigen::MatrixXd K = P * H.transpose() * S.inverse();
    x = x + K * y;
    P = (I - K * H) * P;
}

Eigen::VectorXd KalmanFilter::getState() {
    return x;
}