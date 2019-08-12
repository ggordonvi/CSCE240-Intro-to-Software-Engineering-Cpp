/*
 * Copyright 2018
 * Created by George E Gordon
 */
#include "average_temp_display.h"  // NOLINT

namespace csce240 {

double AverageTempDisplay::temps_[AverageTempDisplay::temps_size_];

/*
 *  GetHumidity Method:
 *    
 */
double AverageTempDisplay::GetHumidity() const {
  return humidity_;
}
void AverageTempDisplay::SetHumidity(double val) {
  humidity_ = val;
}

double AverageTempDisplay::GetPressure() const {
  return pressure_;
}
void AverageTempDisplay::SetPressure(double val) {
  pressure_ = val;
}

double AverageTempDisplay::GetTemperature() const {
  return temperature_;
}
void AverageTempDisplay::SetTemperature(double val) {
  for (int i = 0; i < temps_size_; ++i) {
    if (temps_[i] == 0) {
      temps_[i] = val;
      break;
    }
  }
  counter_ += 1;
  Update();
  temperature_ = val;
}

void AverageTempDisplay::Update() {
  double total_temp = 0;
  for (int i = 0; i < temps_size_; ++i) {
    if (temps_[i] != 0) {
      total_temp += temps_[i];
    }
  }
  avg_temp_ = total_temp / counter_;
  /*
  for (int i = 0; i < temps_size_; ++i) {
    if(temps_[i] != NULL) {
      std::cout << i << ": " << temps_[i] << "\n" << std::endl;
    }
  }
  */
}

void AverageTempDisplay::ExtractTo(std::ostream& cout) const {
  cout << "Average Temperature for last " << counter_ <<
      " readings was " <<avg_temp_;
}


}  // namespace csce240
