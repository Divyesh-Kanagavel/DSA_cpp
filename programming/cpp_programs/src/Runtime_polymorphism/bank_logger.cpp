#include <cstdio>

// nullptr and other safety checks to be added -> ignored for this example
struct Logger
{
    virtual ~Logger() = default;
    virtual void log_transfer(long from, long to, double amount) = 0;

};

struct ConsoleLogger :  Logger
{
    void log_transfer(long from, long to, double amount) override
    {
        printf("[console] %ld -> %ld : %f\n", from, to, amount);
    }
};

struct FileLogger : Logger
{
    void log_transfer(long from, long to, double amount) override
    {
        printf("[file] %ld -> %ld : %f\n", from, to, amount);
    }
};

struct Bank
{
    // Constructor injection
    Bank(Logger *logger) : logger{logger}
    {}

    void make_transfer(long from, long to, double amount)
    {
        logger->log_transfer(from, to, amount);
    }

    void set_logger(Logger *new_logger)
    {
        logger = new_logger;
    }


    private:
        Logger* logger;
};

int main()
{
    ConsoleLogger console_logger;
    Bank bank {&console_logger};
    bank.make_transfer(1000, 2000, 49.95);
    FileLogger file_logger;
    bank.set_logger(&file_logger);
    bank.make_transfer(1000, 2000, 49.95);
    return 0;
}