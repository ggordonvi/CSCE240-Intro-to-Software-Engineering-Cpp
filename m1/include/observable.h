/*
 * Copyright 2018
 * Created by George E Gordon
 */
#ifndef _06HW_INCLUDE_OBSERVABLE_  // NOLINT
#define _06HW_INCLUDE_OBSERVABLE_  // NOLINT

#include "observer.h"  // NOLINT

namespace csce240 {

class Observable {
 public:
  virtual ~Observable();

  void Add(Observer* observer);
  void Delete(Observer* observer);
  void Notify();
};

}  // namespace csce240

#endif  // NOLINT
