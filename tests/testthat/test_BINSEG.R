test_that("returned vector is long enough",{
  K <- 3
  data.vec <- as.matrix(iris[3])[,1]
  expect_equal(K, length(BINSEG(K, data.vec)))
})
