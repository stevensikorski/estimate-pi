#include <cmath>
#include <iostream>
#include <random>

class MonteCarlo
{
    private:
        double count;
        double total;
    public:
        MonteCarlo(double count, double total);
};

struct Point
{
    double x;
    double y;
};

MonteCarlo::MonteCarlo(double count, double total)
{
    this->count = count;
    this->total = total;

    double estimate = (double) 4 * (count/total); // Monte Carlo Method for Pi
    double error = abs(estimate - M_PI) / M_PI * 100; // Percent Error Formula

    std::cout << "  Estimate of Pi:             "   << estimate << std::endl;
    std::cout << "  Value of Pi:                " << M_PI << std::endl;
    std::cout << "  Percent Error:              " << error << "%" << std::endl;
}

double randomize()
{
    return 2.0 * rand() / RAND_MAX - 1;
}

bool determine(Point point)
{
    double distance = abs(sqrt(pow(point.x, 2) + pow(point.y, 2))); // Distance Formula
    return (distance <= 1) ? true : false;
}

int main()
{
    srand(time(0));
    double count = 0, total = 0;
    std::cout << "====== ESTIMATE PI WITH MONTE CARLO METHOD ======" << std:: endl;
    std::cout << std::endl;
    std::cout << "  Enter number of points:     ";
    std::cin >> total;

    for (int i = 0; i < total; i++)
    {
        Point point;
        point.x = randomize();
        point.y = randomize();
        count = (determine(point)) ? count + 1 : count;
    }
    
    MonteCarlo Pi(count, total);
    return 0;
}