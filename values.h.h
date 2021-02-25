//
// Created by H on 25/02/2021.
//

#ifndef EXTENDEDEXERCISES_VALUES_H_H
#define EXTENDEDEXERCISES_VALUES_H_H


// Daily stock price
struct StockPrice
{
    unsigned day;     // day number
    unsigned price;   // price in USD cents
};

// Temperature Measurement
class TempMeasure
{
public:
    TempMeasure () : m{0.0} {}
    TempMeasure (double _m) : m{_m} {}

    operator double() const { return m; }

private:
    double m;
};

#endif //EXTENDEDEXERCISES_VALUES_H_H
