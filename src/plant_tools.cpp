<<<<<<< HEAD
#include <plant.h>
#include <plant/uniroot.h>

namespace plant {
namespace tools {

Environment fixed_environment(double canopy_openness,
                              double height_max) {
  std::vector<double> x = {0, height_max/2.0, height_max};
  std::vector<double> y = {canopy_openness, canopy_openness, canopy_openness};
  interpolator::Interpolator env;
  env.init(x, y);
  // WHAT SHOULD WE DO HERE TO HAVE TWO DIFFERENT PARAMETERS ?? Probably not a pb?
  Parameters<FF16_Strategy> p;
  Environment ret(make_environment(p));
  ret.light_environment = env;
  return ret;
}
=======
>>>>>>> upstream/master

#include <plant.h>

// [[Rcpp::export]]
plant::Internals FF16_oderunner_plant_internals(
  const plant::ode::Runner<plant::tools::IndividualRunner<plant::FF16_Strategy,plant::FF16_Environment>>& obj) {
  return obj.obj.plant.r_internals();
}

// [[Rcpp::export]]
plant::Internals FF16r_oderunner_plant_internals(
  const plant::ode::Runner<plant::tools::IndividualRunner<plant::FF16r_Strategy, plant::FF16_Environment>>& obj) {
  return obj.obj.plant.r_internals();
}



//' @export
// [[Rcpp::export]]
<<<<<<< HEAD
double FF16_lcp_whole_plant(plant::PlantPlus<plant::FF16_Strategy> p) {
  return plant::tools::lcp_whole_plant(p);
}
//' @export
// [[Rcpp::export]]
double FF16r_lcp_whole_plant(plant::PlantPlus<plant::FF16r_Strategy> p) {
  return plant::tools::lcp_whole_plant(p);
}
//' @export
// [[Rcpp::export]]
double FF16FvCB_lcp_whole_plant(plant::PlantPlus<plant::FF16FvCB_Strategy> p) {
  return plant::tools::lcp_whole_plant(p);
}
=======
plant::Internals K93_oderunner_plant_internals(
  const plant::ode::Runner<plant::tools::IndividualRunner<plant::K93_Strategy, plant::K93_Environment>>& obj) {
  return obj.obj.plant.r_internals();
}


>>>>>>> upstream/master
