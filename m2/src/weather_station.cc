/*
 * Copyright 2018
 * Created by George E Gordon
 */
#include "weather_station.h"  // NOLINT

namespace csce240 {

/*
 *  Constructor:
 *    Turns on sensor network and initializes sensors
 */
WeatherStation::WeatherStation() {
  SensorNet::PowerOn();
}

/*
 *  Deconstructor:
 *    Turns off sensor network
 */
WeatherStation::~WeatherStation() {
  SensorNet::PowerOff();
}

/*
 *  GetHumidity Method:
 *    Use Sensor Net's ReadSensor method
 *    For loop to check all sensors (random seed)
 *      If buffer contains char 'H' for HUM
 *        Break, and keep that sensors buffer
 *    For loop to read through the buffer
 *      If char is digit, add to our return string
 *    Convert return string to double and divide by 100
 *    Return double
 */
double WeatherStation::GetHumidity() const {
  int size = 0;
  char * sensor;
  string humidity;
  for (int i = 0; i < SensorNet::k_sensor_count_; ++i) {
    SensorNet::ReadSensor(i, &size, buffer_);
    sensor = strchr(buffer_, 'H');
    if (sensor != NULL) {
      break;
    }
  }
  for (unsigned int i = 0; i < strlen(buffer_); ++i) {
    if (isdigit(buffer_[i])) {
      humidity += buffer_[i];
    }
  }
  double hum = stod(humidity)/100;
  return hum;
}

/*
 *  GetPressure Method:
 *    Use Sensor Net's ReadSensor method
 *    For loop to check all sensors (random seed)
 *      If buffer contains char 'R' for PRS
 *        Break, and keep that sensors buffer
 *    For loop to read through the buffer
 *      If char is digit, add to our return string
 *    Convert return string to double and divide by 100
 *    Return double
 */
double WeatherStation::GetPressure() const {
  int size = 0;
  char * sensor;
  string pressure;
  for (int i = 0; i < SensorNet::k_sensor_count_; ++i) {
    SensorNet::ReadSensor(i, &size, buffer_);
    sensor = strchr(buffer_, 'R');
    if (sensor != NULL) {
      break;
    }
  }
  for (unsigned int i = 0; i < strlen(buffer_); ++i) {
    if (isdigit(buffer_[i])) {
      pressure += buffer_[i];
    }
  }
  double pres = stod(pressure)/100;
  return pres;
}

/*
 *  GetTemperature Method:
 *    Use Sensor Net's ReadSensor method
 *    For loop to check all sensors (random seed)
 *      If buffer contains char 'T' for TMP
 *        Break, and keep that sensors buffer
 *    For loop to read through the buffer
 *      If char is digit, add to our return string
 *    Convert return string to double and divide by 100
 *    Return double
 */
double WeatherStation::GetTemperature() const {
  int size = 0;
  char * sensor;
  string temperature;
  for (int i = 0; i < SensorNet::k_sensor_count_; ++i) {
    SensorNet::ReadSensor(i, &size, buffer_);
    sensor = strchr(buffer_, 'T');
    if (sensor != NULL) {
      break;
    }
  }
  for (unsigned int i = 0; i < strlen(buffer_); ++i) {
    if (isdigit(buffer_[i])) {
      temperature += buffer_[i];
    }
  }
  double temp = stod(temperature)/100;
  return temp;
}

}  // namespace csce240

