/*
 * Copyright 2018
 * Created by George E Gordon
 */
#include "display.h"  // NOLINT

namespace csce240 {

std::ostream& operator<<(std::ostream& cout, const Display& rhs) {
  rhs.ExtractTo(cout);

  return cout;
}

}  // namespace csce240


