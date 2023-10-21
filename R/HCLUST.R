
HCLUST <- function(data.mat, n.clusters){                                          
  
  n.rows <- nrow(data.mat)                                                         
  n.features <- ncol(data.mat)                                                     
  my.dist.mat <- matrix(NA, n.rows, n.rows)                                        
                                                                                   
  for(row.i in 1:n.rows){                                                          
    one.data.mat <- matrix(data.mat[row.i,], n.rows, n.features, byrow=TRUE)       
                                                                                   
    my.dist.mat[, row.i] <- rowSums(abs(data.mat - one.data.mat))                  
  }                                                                                
  cluster.id.list <- as.list(1:n.rows)                                             
                                                                                   
  while(length(unique(cluster.id.list)) - 1 > n.clusters){                         
    # unique from ?which, ?match and ?unique
    
    to.join.dt <- data.table::data.table(                                                      
      row=as.integer(row(my.dist.mat)),                                            
      col=as.integer(col(my.dist.mat)),                                            
      dist=as.numeric(my.dist.mat))
    
    list.of.possible <- list()
    for(data.i in 1:nrow(to.join.dt)){
      if(to.join.dt[data.i,]$row < to.join.dt[data.i,]$col) { 
        list.of.possible[[data.i]] <- data.table::data.table(to.join.dt[data.i,])
      }

    }
    
    to.join.dt <- data.table::rbindlist(list.of.possible)
    to.join.dt <- to.join.dt[which.min(to.join.dt$dist),]
    to.update <- to.join.dt$row                                                    
    to.delete <- to.join.dt$col                                                    
    join.ids <- c(to.update, to.delete)                                           
    join.dist.cols <- my.dist.mat[, join.ids]                                      
    my.dist.mat[to.update,] <- my.dist.mat[,to.update] <-                          
      apply(join.dist.cols, 1, min)                                                

    my.dist.mat[to.delete,] <- my.dist.mat[,to.delete] <- NA                       
                                                                                   
                                                                                   
    cluster.id.list[[to.update]] <- append(cluster.id.list[[to.update]],           
      cluster.id.list[[to.delete]])                                                
    cluster.id.list[[to.delete]] <- NA                                             
  }                                                                                
                                                                                   
  cluster.number <- 1                                                              
  id.vec <- vector(mode="numeric", length=n.rows)                                  
  for(cluster.i in 1:length(unique(cluster.id.list))){                             
    indicies <- unlist(unique(cluster.id.list)[cluster.i])                         
    if(typeof(indicies) != "logical"){                                             
      id.vec[indicies] <- cluster.number                                           
      cluster.number <- cluster.number + 1                                         
    }                                                                              
  }                                                                                
                                                                                   
  return(id.vec)                                                                
}               
