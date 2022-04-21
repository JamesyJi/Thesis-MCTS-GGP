#ifndef COMMON_RESOURCE_H_
#define COMMON_RESOURCE_H_

#include <chrono>

namespace Common
{
class Resource 
{
public:
    Resource(){}
    virtual ~Resource(){}

    virtual void ResetAndStart() = 0;
    virtual bool UseResource() = 0;
};


class TimeResource : public Resource
{
private:
    // In milliseconds
    double mLimit;
    double mEnd;
public:
    TimeResource(double seconds)
    : mLimit(1000 * seconds)
    {}
    
    ~TimeResource(){}

    void ResetAndStart() 
    {
        auto now = std::chrono::high_resolution_clock::now();
        mEnd = std::chrono::duration_cast<std::chrono::seconds>(now) + mLimit;
    }

    bool UseResource()
    {
        return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now()) < mEnd;
    }
};


class IterationResource : public Resource
{
private:
    int mLimit;
    int mCurrent;
public:
    IterationResource(int iter)
    : mLimit(iter) 
    {}

    void ResetAndStart()
    {
        mCurrent = 0;
    }

    bool UseResource()
    {
        return mCurrent++ <= mLimit;
    }
};
}

#endif