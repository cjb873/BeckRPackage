test_that("returned vector is long enough", {
  clustering <- kmeans_interface(3, as.matrix(iris[3:4]))
  expect_equal(length(clustering), nrow(as.matrix(iris[3:4])))
  })
