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
#include "MeasurementFactory.h"

using namespace std;

namespace TimeData
{

//----------------------------------------------------------------------
    static TimeSeries makeRandom(int size, MeasurementFactory &factory)
    {
        TimeSeries ts;
        for (int i = 0; i < size; i += 1)
            ts.addValue(factory.makeRandom());
        return std::move(ts);
    };

//----------------------------------------------------------------------
// One way to output a vector using a copy algorithm and a stream iterator
//

} // namespace TimeData
