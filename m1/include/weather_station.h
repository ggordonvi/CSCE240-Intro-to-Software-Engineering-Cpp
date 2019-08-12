/*
 * Copyright 2018
 * Created by George E Gordon
 */
#ifndef _06HW_INCLUDE_WEATHER_STATION_H_  // NOLINT
#define _06HW_INCLUDE_WEATHER_STATION_H_  // NOLINT

#include <string.h>
#include <cassert>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
#include "observable.h"  // NOLINT
#include "sensor_net.h"  // NOLINT

typedef std::string string;

namespace csce240 {

class WeatherStation : public Observable {
 public:
  WeatherStation();
  virtual ~WeatherStation();

  double GetHumidity() const;
  double GetPressure() const;
  double GetTemperature() const;

 private:
  char *buffer_ = new char[15];
};

}  // namespace csce240

#endif  // NOLINT
