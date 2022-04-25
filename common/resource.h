#pragma once

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
    std::chrono::milliseconds mLimit;
    std::chrono::time_point<std::chrono::high_resolution_clock> mEnd;
public:
    TimeResource(int seconds)
    : mLimit(1000 * seconds)
    {}
    
    ~TimeResource(){}

    void ResetAndStart() 
    {
        mEnd = std::chrono::high_resolution_clock::now() + mLimit;
    }

    bool UseResource()
    {
        return std::chrono::high_resolution_clock::now() < mEnd;
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
