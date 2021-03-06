% Generated by roxygen2: do not edit by hand
% Please edit documentation in r/scm_support.R
\name{equilibrium_verbose}
\alias{equilibrium_verbose}
\alias{equilibrium_quiet}
\title{Noisy Parameters for Equilibrium Finding}
\usage{
equilibrium_verbose(base = Control())

equilibrium_quiet(base = Control())
}
\arguments{
\item{base}{An optional \code{Control} object.  If omitted, the
defaults are used.}
}
\description{
Control parameters for \code{\link{equilibrium_seed_rain}} that
make progress noisier.  This is just a convenience function.
}
