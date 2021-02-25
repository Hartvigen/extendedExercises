//============================================================================
// Name        : extended1/timeseries.cpp
// Author      : Simonas Saltenis
// Version     :
// Description : Extended exercise 1 of the sP course: Definitions of some TimeSeries methods
//============================================================================

#include "timeseries.h"
#include <algorithm>
#include <iterator>
#include <random>
#include <functional>

using namespace std;

namespace TimeData
{

//----------------------------------------------------------------------
TimeSeries TimeSeries::makeRandom(size_type n)
{
    auto die = bind(uniform_int_distribution<>{numeric_limits<int>::min(), numeric_limits<int>::max()},
                    default_random_engine{});
    TimeSeries ts;
    ts.data.resize(n);
    generate(ts.data.begin(), ts.data.end(), die);

    return ts;    // relying on the efficient move of the data vector
}

//----------------------------------------------------------------------
TimeSeries& TimeSeries::operator+=(const TimeSeries& t)
{

    if (t.data.size() > data.size())
        data.resize(t.data.size());  // automatically adds zeros at the end
    // if (t.data.size() < data.size()) then the following loop will stop at t.data.size()
    // and we do not do anything with the remaining elements of data,
    // which is the same as adding 0 to them :)

    for (size_type i = 0; i < t.data.size(); i++)
        data[i] += t.data[i];

    updateMinMax();

    return *this;
}

//----------------------------------------------------------------------
void TimeSeries::updateMinMax()
{
    maxValue = numeric_limits<int>::min();
    minValue = numeric_limits<int>::max();
    auto updater = [this](auto i)   // have to capture this to access data members of the object
                   {
                        if (i > maxValue) maxValue = i;
                        if (i < minValue) minValue = i;
                   };
    for_each(data.begin(), data.end(), updater);
}

//----------------------------------------------------------------------
// One way to output a vector using a copy algorithm and a stream iterator
//
ostream& operator<< (ostream& out, const TimeSeries& ts)
{
    out << '[';
    if (!ts.data.empty())
    {
        copy (ts.data.begin(), ts.data.end(), ostream_iterator<int>(out, ", "));
        out << "\b\b";
    }
    out << ']';
    return out;
}

} // namespace TimeData
