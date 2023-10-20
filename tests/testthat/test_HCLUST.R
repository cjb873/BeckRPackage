test_that("returned vector is long enough", {                                      
  clustering <- HCLUST(as.matrix(iris[3:4][1:5,]), 3)                          
  expect_equal(length(clustering), nrow(as.matrix(iris[3:4][1:5,])))                     
  })                                                                               
