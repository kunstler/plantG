// -*-c++-*-
#ifndef PLANT_PLANT_PLANT_RUNNER_H_
#define PLANT_PLANT_PLANT_RUNNER_H_

#include <plant/plant_plus.h>
#include <plant/environment.h>

namespace plant {
namespace tools {

// TODO: This should be templated, I think, but that plays badly with
// RcppR6's requirements for "concrete" types.
struct PlantRunner {
// WHAT SHOULD WE DO HERE TO HAVE TWO DIFFERENT PARAMETERS ??
  PlantRunner(PlantPlus<FF16_Strategy> plant_, Environment environment_)
    : plant(plant_), environment(environment_) {
    plant.compute_vars_phys(environment);
  }
  static size_t ode_size() {return PlantPlus<FF16_Strategy>::ode_size();}
  double ode_time() const {return environment.time;}
  ode::const_iterator set_ode_state(ode::const_iterator it, double time) {
    it = plant.set_ode_state(it);
    environment.time = time;
    plant.compute_vars_phys(environment);
    return it;
  }
  ode::iterator ode_state(ode::iterator it) const {
    return plant.ode_state(it);
  }
  ode::iterator ode_rates(ode::iterator it) const {
    return plant.ode_rates(it);
  }
// WHAT SHOULD WE DO HERE TO HAVE TWO DIFFERENT PARAMETERS ??
  PlantPlus<FF16_Strategy> plant;
  Environment environment;
};

}
}

#endif
