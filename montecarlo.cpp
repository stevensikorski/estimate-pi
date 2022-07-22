#include <cmath>
#include <iostream>
#include <random>

struct Point
{
    double x;
    double y;
};

class MonteCarlo
{
    private:
        double count;
        double total;
        Point point;
    public:
        MonteCarlo(double count, double total);
        double randomize();
        bool determine(Point point);
};

MonteCarlo::MonteCarlo(double count, double total)
{
    this->count = count;
    this->total = total;

    for (int i = 0; i < total; i++) // Monte Carlo Method for Pi
    {
        Point point;
        point.x = randomize();
        point.y = randomize();
        count = (determine(point)) ? count + 1 : count;
    }

    double estimate = (double) 4 * (count/total); // Monte Carlo Method for Pi
    double error = abs(estimate - M_PI) / M_PI * 100; // Percent Error Formula

    std::cout << "  Estimate of Pi:             "   << estimate << std::endl;
    std::cout << "  Value of Pi:                " << M_PI << std::endl;
    std::cout << "  Percent Error:              " << error << "%" << std::endl;
}

double MonteCarlo::randomize()
{
    return 2.0 * rand() / RAND_MAX - 1;
}

bool MonteCarlo::determine(Point point)
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
    
    MonteCarlo Pi(count, total);
    return 0;
}