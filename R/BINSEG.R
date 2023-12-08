BINSEG <- function(K, data.vec){
    loss.vec <- vector(mode="numeric", length=K)
    N.data <- length(data.vec)
    cum.data.vec <- c(0, cumsum(data.vec))
    cum.square.vec <- c(0, cumsum(data.vec^2))
    last.data.first.seg <- seq(1, N.data - 1)
    first.data.first.seg <- 1

  
  get_loss <- function(start, end){                                                  
    size <- end - start + 1                                                          
    square.term <- cum.square.vec[end+1] - cum.square.vec[start]                     
    data.term <- cum.data.vec[end+1] - cum.data.vec[start]                           
                                                                                   
    square.term-data.term^2/size                                                     
  }                                                                                  
                                                                                   
  get_diff <- function(start, end, change){                                          
    get_loss(start, change) + get_loss(change + 1, end) - get_loss(start, end)       
  }                                                                                  
                                                                                   
  get_split <- function(start, end){                                                 
    possible <- seq(start, end-1)                                                    
    diff.values <- get_diff(start, end, possible)                                    
    best.index <- which.min(diff.values)                                  
    data.table::data.table(start, end, change=best.index + start - 1, 
      diff=diff.values[best.index])          
  }         

  loss.vec[1] <- get_loss(1, N.data)
  potential.splits <- list()
  made.splits <- list()

  potential.splits[[1]] <- data.table::data.table(
    start=first.data.first.seg, end=N.data, change=get_split(1, N.data)$change,
    diff=get_split(1, N.data)$diff)


  for(seg.i in 2:K){
    min.split <- which.min(unlist(potential.splits)) / 4; #4 for len of dt
    made.splits[[seg.i-1]] <- potential.splits[[min.split]];
    potential.splits <- potential.splits[-min.split];

    loss.vec[seg.i] <- loss.vec[seg.i-1] + made.splits[[seg.i-1]]$diff;
    
    new.start <- made.splits[[seg.i-1]]$start;
    new.change <- made.splits[[seg.i-1]]$change;
    new.end <- made.splits[[seg.i-1]]$end;
    
    potential.split.end <- length(potential.splits);
    potential.splits[[potential.split.end + 1]] <- data.table::data.table(
      start=new.start, end=new.change, 
      change=get_split(new.start, new.change)$change,
      diff=get_split(new.start, new.change)$diff);

    
    potential.splits[[potential.split.end + 2]] <- data.table::data.table(
      start=new.change+1, end=new.end, 
      change=get_split(new.change+1, new.end)$change,
      diff=get_split(new.change+1, new.end)$diff);
  }


  return(loss.vec)

}

