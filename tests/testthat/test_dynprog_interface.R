test_that("returned matrix has enough rows", {
  k <- 5
  data.vec <- as.matrix(iris[3])[,1]   
  expect_equal(k, nrow(dynprog_interface(k, data.vec)))
})
