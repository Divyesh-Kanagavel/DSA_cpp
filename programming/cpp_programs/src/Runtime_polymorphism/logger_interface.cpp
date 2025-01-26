#include <cstdio>

struct Logger
{
    virtual ~Logger() = default;
    virtual void log_transfer(long from, long to, double amount) = 0;

};

struct ConsoleLogger : Logger
{
    void log_transfer(long from, long to, double amount) override 
    {
        printf("[console] %ld -> %ld : %f\n", from, to, amount);
    }

};

int main()
{
    Logger *logger = new ConsoleLogger();
    logger->log_transfer(1000, 2000, 100.0);
    delete logger;
    return 0;
}