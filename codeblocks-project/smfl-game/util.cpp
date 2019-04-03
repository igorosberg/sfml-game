#include <cmath>
#include <chrono>
#include <random>

# define PI 3.14159265358979323846

namespace util {
    namespace {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine generator (seed);

    }
    double dist(double x1, double y1, double x2, double y2){
        return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    }


    int random(int a, int b) {
        std::uniform_int_distribution<int> distribution(a,b);
        return distribution(generator);
    }

    double angleBwPoints(int x1, int y1, int x2, int y2) {
        double dy = y2-y1;
        double dx = x2-x1;
        double theta = atan2(dy,dx);
        theta *= 180/PI;
        if(theta < 0) theta = 360 + theta;
        return theta;
    }
}
