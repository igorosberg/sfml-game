#include <cmath>
#include <chrono>
#include <random>

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
}
