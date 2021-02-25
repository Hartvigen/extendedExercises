//
// Created by H on 25/02/2021.
//

#ifndef EXTENDEDEXERCISES_MEASUREMENTFACTORY_H
#define EXTENDEDEXERCISES_MEASUREMENTFACTORY_H

#include <bits/unique_ptr.h>
#include "measurements.h"

class MeasurementFactory{
public:
    virtual std::unique_ptr<Measurement> makeRandom() = 0;
};

#endif //EXTENDEDEXERCISES_MEASUREMENTFACTORY_H
