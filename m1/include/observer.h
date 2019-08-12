/*
 * Copyright 2018
 * Created by George E Gordon
 */
#ifndef _06HW_INCLUDE_OBSERVER_  // NOLINT
#define _06HW_INCLUDE_OBSERVER_  // NOLINT

namespace csce240 {

class Observer {
 public:
  virtual ~Observer() = 0;

  virtual void Update() = 0;
};

}  // namespace csce240

#endif  // NOLINT
