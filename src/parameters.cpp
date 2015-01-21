#include <tree2/parameters.h>

#include <Rcpp.h>

namespace tree2 {

Parameters::Parameters()
  : c_ext(0.5),
    patch_area(1.0),
    Pi_0(0.25),
    n_patches(1),
    disturbance_mean_interval(30) {
}

size_t Parameters::size() const {
  return strategies.size();
}

size_t Parameters::n_residents() const {
  return static_cast<size_t>
    (std::count(is_resident.begin(), is_resident.end(), true));
}

size_t Parameters::n_mutants() const {
  return size() - n_residents();
}

// TODO: make this return *this? so that we can do something like
//   parameters(p.validate())
// within initialisation lists?
void Parameters::validate() const {
  const size_t len = size();
  if (!(seed_rain.size() == len && is_resident.size() == len)) {
    util::stop("Inconsistent lengths (strategies, seed_rain, is_resident)");
  }
}

}
