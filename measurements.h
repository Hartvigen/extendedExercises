//
// Created by H on 25/02/2021.
//

#ifndef EXTENDEDEXERCISES_MEASUREMENTS_H
#define EXTENDEDEXERCISES_MEASUREMENTS_H


#include <bits/unique_ptr.h>

class Measurement {


public:
    virtual bool larger(const Measurement& other) = 0;
    virtual std::unique_ptr<Measurement> difference(const Measurement& other) = 0;

    virtual ~Measurement() = default;

    virtual void print() = 0;



};


#endif //EXTENDEDEXERCISES_MEASUREMENTS_H
