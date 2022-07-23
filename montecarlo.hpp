#ifndef MONTE_CARLO
#define MONTE_CARLO

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

#endif