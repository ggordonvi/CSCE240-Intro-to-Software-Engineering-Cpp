/*
 * Copyright 2018
 * Created by George E Gordon
 */
#ifndef _06HW_INCLUDE_AVERAGE_TEMP_DISPLAY_H_  // NOLINT
#define _06HW_INCLUDE_AVERAGE_TEMP_DISPLAY_H_  // NOLINT

#include <ostream>
#include <iostream>
using std::cout;
using std::endl;

#include "display.h"  // NOLINT

namespace csce240 {

/* A class which maintains the average temperature in Celcius seen over the
 *   last n calls to SetTemperature.
 */
class AverageTempDisplay : public Display {
 public:
  double GetHumidity() const;
  void SetHumidity(double val);

  double GetPressure() const;
  void SetPressure(double val);

  double GetTemperature() const;
  void SetTemperature(double val);

  void Update();

  static const int temps_size_ = 25;

 protected:
  void ExtractTo(std::ostream& cout) const;

 private:
  double counter_;
  double humidity_;
  double pressure_;
  double temperature_;
  double avg_temp_;
  static double temps_[];
};

}  // namespace csce240

#endif  // NOLINT
