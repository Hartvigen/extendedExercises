//============================================================================
// Name        : extended1/main.cpp
// Author      : Simonas Saltenis
// Version     :
// Description : Extended exercise 1 of the sP course
//============================================================================

#include <chrono>
#include <algorithm>
#include "timeseries.h"

using namespace std;
using namespace std::chrono;
using namespace TimeData;

constexpr auto ts_number = 100000;
constexpr auto ts_length = 100;

int main()
{
    // Part 2
    //----------------------------------
    vector<TimeSeries> vv;

    for (auto i = 0; i < ts_number; i++)
        vv.push_back(TimeSeries::makeRandom(ts_length)); // Here, rvalue reference version of push_back is called

    for (auto& ts : vv)  // Note the reference! Otherwise we would add to a temporary (and expensive) copy
        ts += TimeSeries::makeRandom(ts_length);

    auto t0 = high_resolution_clock::now();
    sort(vv.begin(), vv.end());
    auto t1 = high_resolution_clock::now();
    cout << "Sorting values: " << duration_cast<milliseconds>(t1 - t0).count() << "msec\n";

    // Part 3
    // -----------------------------------
    // Note that I use exactly the same code as for Part 1!
    vector<TimeSeriesH> vh;

    for (auto i = 0; i < ts_number; i++)
        vh.push_back(TimeSeriesH::makeRandom(ts_length));

    for (auto& ts : vh)
        ts += TimeSeriesH::makeRandom(ts_length);

    t0 = high_resolution_clock::now();
    sort(vh.begin(), vh.end());
    t1 = high_resolution_clock::now();
    cout << "Sorting wrapped pointers: " << duration_cast<milliseconds>(t1-t0).count() << "msec\n";
    //
    // On my machine, this is twice SLOWER than part 2 (without debug info)
    // This is the penalty for an additional level of indirection, when accessing timeseries objects
    // Note that, in part 2, we are not shufflinfg 100-integer-array-objects,
    // std::vector encapsulates a pointer to an array, not an array itself.
    // On my machine sizeof(TimeSeries) == 32.
    // If the last line of TimeSeries definition is uncommented, time series objects become large
    // and it is expensive to move them when sorting.
    // Then, on my machine, Part 3 becomes about 30% FASTER than Part 2.
    //

    return 0;
}
