# BeckRPackage

<!-- badges: start -->
[![R-CMD-check](https://github.com/cjb873/BeckRPackage/actions/workflows/R-CMD-check.yaml/badge.svg)](https://github.com/cjb873/BeckRPackage/actions/workflows/R-CMD-check.yaml)
<!-- badges: end -->


This package implements two R functions, `kmeans_interface` and `HCLUST`. The function `kmeans_interface` is written in C++ and then called using the `Rcpp` package. 
The function `HCLUST` is written natively in R.

### Dependencies
To ensure that this package will correctly build, you will need to install the [Rcpp](https://www.rcpp.org/) package in R. Additionally, you will need the 
[Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page) C++ library. 

### Building
To build the library, run the command `R CMD INSTALL <path_to_package>`.

### Testing
To run the tests, run the command `R CMD check <path_to_package>`.


