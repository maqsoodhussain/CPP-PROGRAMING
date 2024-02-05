rm(list = ls())
library(xlsx)
library(caret)
library(MASS)
library(FSinR)
#library(Bolstad2) #for numerical  integratiion  , use sintegral(x,y)$int
library(pracma)

#READ datset AND STORE IN global variable DATASET
dataReadGLOBAL.function = function(inputFilePath,varCount,metrics){ 
  print("started dataReadGLOBAL.function")
  print(metrics)
  
  DATASET <<- read.xlsx(inputFilePath,sheetIndex=1)
  
  print(colnames(DATASET))
  
  
  if(varCount < 1 )  ######
  DATASET <<- DATASET[,metrics]   ######
  else
    DATASET <<- DATASET[,2:varCount]
  
  print(colnames(DATASET))
  print("completed dataReadGLOBAL.function")
  
  
}
#READ datset AND RETURN  DATASET
dataRead.function = function(inputFilePath,varCount,metrics){ 
  print("started dataRead.function")
  print(metrics)
  
  Dataset = read.xlsx(inputFilePath,sheetIndex=1)
  
  print(colnames(Dataset))
  
  
  if(varCount < 1 )  ######
  Dataset = Dataset[,metrics]   ######
  else
    Dataset = Dataset[,2:varCount]
  
  print(colnames(Dataset))
  print("completed dataRead.function")
  Dataset
  
}

#log transform data in global variable DATASET
transformLog.function <- function(vars){
  
  print("started tansformLog.function")
  
  for(i in 1:vars){
    for(j in 1:vars){
      if(DATASET[i,j] < 0.000001) {DATASET[i,j]   <<-  log(0.000001)}
      
      else { DATASET[i,j]   <<-  log(DATASET[i,j]) }
    }
  }
  
  print("completed transformLog.function")
}

#return minMax normalized data
minMaxNormalization.function = function(data)
{
  #min max scaling
  maxs <- apply(data, 2, max)
  mins <- apply(data, 2, min)
  
  data = as.data.frame(scale(data, center = mins, scale = maxs - mins))
  
  
  data 
  
}


# AREA UNDER LOC-BASED LIFTS BEGINS
aul.function = function(data){
  # argument data is a dataframe with three columns
  # actual  is the column for  actual dependent variable
  # actual is ploted on y-axis in cumulative lift charts
  # predicted is the column for predicted dependent variable
  # predicted is used to order the modules
  # x_axis is the variable ploted on x-axis in cumulative lift charts
  # x_axis can be lines_of_code in case of LOC based lift charts or
  # x_axis can be number_of_modules in case of general lift charts
  
  print("started aul.function")
  
  data = data[order(-data$predicted,data$x_axis),]
  data$LOC.CUM.PERCENT = cumperdata.function(data$x_axis)
  data$BUGS.CUM.PERCENT = cumperdata.function(data$actual)
  
  
  #aul = sintegral(data$LOC.CUM.PERCENT, data$BUGS.CUM.PERCENT)$int
  aul = trapz(data$LOC.CUM.PERCENT, data$BUGS.CUM.PERCENT)
  
  print(aul)
  print("completed aul.function")
  aul
}

cumperdata.function = function(data){
  print("started cumperdata.function")
  cumdata = cumsum(data)
  cumpercent = cumdata  / cumdata[length(cumdata)]
  
  print("completed cumperdata.function")
  
  cumpercent
}

# AREA UNDER LOC-BASED LIFTS ENDS

#function used to define custom performance Peffort in train function of caret package
#accesses the global variable DATASET$LOC
P_effort.function <- function (data, lev = NULL, model = NULL) {
  #comments are written by NAYEEM AHMAD BHAT 
  #control.object a global variable is defined inside createDataPartition file inside caret package
  #control.object$index is list of row number vectors of training data instances from data argument of train function 
  #control.object$indexOut is list of row number vectors of test data instances from data argument of train function 
  #these are used to keep track of train and test sets used in each iteration of Cross-Validation
  #they were defined to evaluate models based on cumulative lift charts
  #DATASET is a global variable  to hold the data for training and testing, passed as argument to train function 
  #  
  
  
  
  data.perf = data.frame(actual = rep(0,nrow(data)),
                         predicted = rep(0,nrow(data)),
                         x_axis = rep(0,nrow(data))
  )
  
  data.perf$actual = data$obs
  data.perf$predicted = data$pred
  
  
  data.perf$x_axis  = DATASET[data$rowIndex,]$LOC
  
  classifier = aul.function(data.perf)
  
  data.perf$predicted = data.perf$actual
  
  opt = aul.function(data.perf)
  
  out <- c(1 - (opt - classifier))
  
  
  names(out) <- c("Peffort")
  
  
  
  out
}

#function used to define custom performance Popt in train function of caret package
P_opt.function <- function (data, lev = NULL, model = NULL) {
  #comments are written by NAYEEM AHMAD BHAT 
  #control.object a global variable is defined inside createDataPartition file inside caret package
  #control.object$index is list of row number vectors of training data instances from data argument of train function 
  #control.object$indexOut is list of row number vectors of test data instances from data argument of train function 
  #these are used to keep track of train and test sets used in each iteration of Cross-Validation
  #they were defined to evaluate models based on cumulative lift charts
  #DATASET is a global variable  to hold the data for training and testing, passed as argument to train function 
  #  
  
  
  data.perf = data.frame(actual = rep(0,nrow(data)),
                         predicted = rep(0,nrow(data)),
                         x_axis = rep(0,nrow(data))
  )
  
  data.perf$actual = data$obs
  data.perf$predicted = data$pred
  
  data.perf$x_axis  = rep(1,nrow(data))
  
  
  classifier = aul.function(data.perf)
  
  data.perf$predicted = data.perf$actual
  
  opt = aul.function(data.perf)
  
  out <- c(1 - (opt - classifier))
  
  
  names(out) <- c("Popt")
  
  
  out
}


#return a vector of maxseeds length + 1
getseeds.function = function(maxseeds)
{
  set.seed(123)
  seeds <- vector(mode = "list", length = (maxseeds+1))
  for(i in 1:(maxseeds+1)) seeds[[i]] <- sample.int(2000, 44)
  
  seeds
}


# 'number' number of folds in k fold cv
# 'repeats' number of repeats in multiple k fold cv
# 'x_axis'  metric not included in predictors from training dataset
startExperiment = function(data = NULL, outcome = NULL,x_axis = "LOC", modelmethod = "rpart", 
                           evalPerformance = NULL, summaryFunction = NULL,
                           method = "cv", 
                           number  = 10, repeats = 1, 
                           classProbs = NULL,
                           returnData = NULL,
                           returnResample = NULL,
                           savePredictions = NULL,
                           sampling = NULL,
                           index = NULL, indexOut = NULL,
                           splitRatio = 0.8)
{
  
  #  iteration <<- 0    # index to iterate over control.object index and indexout lists
  maxiteration <<- number * repeats  # max number of resamples created is equal to repeats * number
  
  
  ## Do  'repeats' of 'number'-Fold CV for  data. We set the seed at each iteration.
  seeds = getseeds.function(maxiteration)
  #  print(seeds)
  
  fitControl <- trainControl(method = method, number = number, repeats = repeats,
                             classProbs = classProbs,
                             summaryFunction = summaryFunction,
                             p = splitRatio, 
                             returnResamp = returnResample,
                             returnData = returnData,
                             savePredictions = savePredictions,
                             sampling = sampling,
                             index = index, indexOut=indexOut,
                             seeds  = seeds
  )
  
  set.seed(1)
  
  n = colnames(data)
  f <- as.formula(paste(
    paste(outcome,"~ " , collapse = " "),
    paste(n[!n %in% c(outcome, x_axis)], collapse = " + ")	)	)
  
  fit <- train(f , data = data,
               method = modelmethod,
               trControl = fitControl,
               metric = evalPerformance,
               maximize = TRUE
  )
  
}





# 'number' number of folds in k fold cv
# 'repeats' number of repeats in multiple k fold cv
# 'x_axis'  metric not included in predictors from training dataset
featureSelect = function(data = NULL, outcome = NULL,x_axis = "LOC", modelmethod = "rpart", 
                         evalPerformance = NULL, summaryFunction = NULL,
                         method = "cv", 
                         number  = 10, repeats = 1, 
                         classProbs = NULL,
                         returnData = NULL,
                         returnResample = NULL,
                         savePredictions = NULL,
                         sampling = NULL,
                         index = NULL, indexOut = NULL,
                         splitRatio = 0.8)
{
  
  #  iteration <<- 0    # index to iterate over control.object index and indexout lists
  maxiteration <<- number * repeats  # max number of resamples created is equal to repeats * number
  
  
  ## Do  'repeats' of 'number'-Fold CV for  data. We set the seed at each iteration.
  seeds = getseeds.function(maxiteration)
  #  print(seeds)
  
  resamplingParams <- list(method = method, number = number, repeats = repeats,
                           classProbs = classProbs,
                           summaryFunction = summaryFunction,
                           p = splitRatio, 
                           returnResamp = returnResample,
                           returnData = returnData,
                           savePredictions = savePredictions,
                           sampling = sampling,
                           index = index, indexOut=indexOut,
                           seeds  = seeds
  )
  
  set.seed(1)
  
  n = colnames(data)
  f <- as.formula(paste(
    paste(outcome,"~ " , collapse = " "),
    paste(n[!n %in% c(outcome, x_axis)], collapse = " + ")	)	)
  
  fittingParams <- list(
    metric = evalPerformance,
    maximize = TRUE
  )
  
  
  evaluator <- wrapperEvaluator("glm",resamplingParams, fittingParams)
  
  #searcher <- searchAlgorithm("sequentialForwardSelection")
  searcher <- searchAlgorithm("sequentialFloatingForwardSelection")
  
  if(nIVar < 2)
  {
    bestf.list[[length(bestf.list) + 1]] <<-  c(1)
    
    bestf = c(1,1,1)
  }
  else
  {
    
    
    results <<- featureSelection(data[,1:nVar], "X.bugs.",searcher,evaluator)
    
    print(results$bestFeatures)
    
    bestf.list[[length(bestf.list) + 1]] <<-  results$bestFeatures
    
    bestf = c(results$bestFeatures,1,1)
  }
  
  as.logical(bestf)
}



writeperformance.function = function(wpOrCp, avgOrAll,performance, model,dataset, performanceFrame){
  print("started writeperformance.function ")
  
  
  DIRECTORY.NAME = paste(pathname,"EXTENSIVE_COMPARISON_FSELECT_CV_CP", performance, sep = "/")
  
  
  FILE.NAME   = paste(DIRECTORY.NAME, paste( wpOrCp, avgOrAll, performance, model, dataset,".xlsx", sep = "_" ), sep = "/" )
  
  if(!dir.exists(DIRECTORY.NAME)) { dir.create(DIRECTORY.NAME, recursive = TRUE)} 
  
  
  write.xlsx(performanceFrame, FILE.NAME, sheetName =  performance ,col.names=TRUE,append=TRUE,row.names= FALSE, showNA = FALSE)
  
  
  
  print("completed writePerformance.function")
  
}




DATASETNAMES = c("eclipse","mylyn","equinox","pde","lucene")
#DATASETNAMES = c("lucene","equinox","eclipse")
pathname = "F:\\Nayeem\\extensiveComparison\\"

METRICSSETS = list(
  list("change-metrics.xlsx", 16, c()),
  list("change-metrics.xlsx", -3, c("X.numberOfFixesUntil","X.bugs.")),
  list("change-metrics.xlsx", -3, c("X.numberOfVersionsUntil","X.bugs.")),
  list("change-metrics.xlsx", -3, c("X.numberOfFixesUntil","X.numberOfVersionsUntil","X.bugs.")),
  
  list("bug-metrics.xlsx", -3, c("X.numberOfBugsFoundUntil","X.numberOfNonTrivialBugsFoundUntil.", "X.numberOfMajorBugsFoundUntil",
                                 "X.numberOfCriticalBugsFoundUntil","X.numberOfHighPriorityBugsFoundUntil",
                                 "X.bugs.")),
  list("bug-metrics.xlsx", -3, c("X.numberOfBugsFoundUntil", "X.bugs.")),
  
  list("single-version-ck-oo.xlsx", 18, c()),
  list("single-version-ck-oo.xlsx", -3, c("X.cbo.","dit","X.lcom.","X.noc.","X.rfc.","X.wmc.","X.bugs.")),
  list("single-version-ck-oo.xlsx", -3, c("X.fanIn.", "X.fanOut.", "X.numberOfAttributes.", 
                                          "X.numberOfAttributesInherited." , "X.numberOfLinesOfCode.",
                                          "X.numberOfMethods.", "X.numberOfMethodsInherited.",
                                          "X.numberOfPrivateAttributes.", "X.numberOfPrivateMethods.",
                                          "X.numberOfPublicAttributes." , "X.numberOfPublicMethods.","X.bugs.")), 
  list("single-version-ck-oo.xlsx", -3, c("X.numberOfLinesOfCode.","X.bugs.")),
  
  list("complexity-code-change.xlsx", -3, c("X.CvsEntropy.","X.bugs.")),
  list("complexity-code-change.xlsx", -3, c("X.CvsWEntropy.","X.bugs.")),
  list("complexity-code-change.xlsx", -3, c("X.CvsExpEntropy.","X.bugs.")),
  list("complexity-code-change.xlsx", -3, c("X.CvsLinEntropy.","X.bugs.")),
  list("complexity-code-change.xlsx", -3, c("X.CvsLogEntropy.","X.bugs.")),
  
  list("churn\\churn.xlsx",18 , c()),
  list("churn\\weighted-churn.xlsx",18 , c()),
  list("churn\\lin-churn.xlsx",18, c()),
  list("churn\\exp-churn.xlsx",18, c()),
  list("churn\\log-churn.xlsx",18, c()),
  
  list("entropy\\ent.xlsx",18, c()),
  list("entropy\\weighted-ent.xlsx",18, c()),
  list("entropy\\lin-ent.xlsx",18, c()),
  list("entropy\\exp-ent.xlsx",18, c()),
  list("entropy\\log-ent.xlsx",18, c())
)



dataset.loc.read = function(i,j)
{
  
  #read both WP and CP  data and make CP data as DATASET as global
  
  filename = paste(pathname,i,"\\",j[1], sep = "")
  print(filename)
  
  
  dataset = dataRead.function(filename, (j[[2]] + 1), j[[3]]) #read dataset and store in global variable DATASET
  
  
  #read LOC metric to aid in effort evaluation
  filename = paste(pathname,i,"\\","single-version-ck-oo.xlsx", sep = "")
  print(filename)
  
  
  if(task == "classification")
  {
    bugs = as.factor(dataset$X.bugs. > 0)
    levels(bugs) <- c("nondefective", "defective")
  }
  
  
  #add dataset with LOC metric to aid in effort evaluation
  LOC =  dataRead.function(filename, -3, c("X.numberOfLinesOfCode."))
  dataset$LOC = LOC	
  
  
  dataset  = minMaxNormalization.function(dataset)
  
  
  if(task == "classification")
  {
    dataset$X.bugs.  = bugs
  }
  
  
  dataset = unique(dataset)
  
  dataset
}

CP.dataset.loc.read = function(i,j)
{
  n = DATASETNAMES
  CP.data = data.frame()
  
  cp.dataset.names = n[!n %in% c(i)]
  
  for(k in cp.dataset.names)
  {
    dataset = dataset.loc.read(k,j)
    
    CP.data = rbind(CP.data, dataset)
  }
  
  CP.data
}
#DATASETNAMES = c("equinox")


DATASET = data.frame()
task = "regression"		#could be classification or regression
PERFORMANCE = "Popt"		# could be any value  c("Popt","Peffort","ROC","RMSE","Accuracy") depending on the the task and summary function
SUMMARYFUNCTION = P_opt.function	# could be twoClassSummary, defaultSummary, P_opt.function, P_effort.function
CLASSPROBS = FALSE
MODELMETHOD = "glm"		#could be glm, rpart, naiveBayes,
CVMETHOD  = "repeatedcv"	#could be cv, repeatedcv, LGOCV, 
NUMBER   = 5		#set as 5 , means five fold validation, 80/20 ratio
REPEATS = 10		#set as 10
context = "cp"



nVar = 2
nIVar = 1
METRIC = c("moser","NFIX","NR","NFIX+NR","BUG-CAT","BF","ck-oo","ck","oo","loc",
           "HCM","WHCM","EDHCM","LDHCM","LGDHCM",
           "churn","weighted-churn","lin-churn","exp-churn","log-churn",
           "ent","weigthed-ent","lin-ent","exp-ent","log-ent")
DatasetPerframeAvg = data.frame(METRIC)   #OK
metricsetPerframeWhole = data.frame()   #OK
for(i in DATASETNAMES)
{
  metricsetPerframeAvg = data.frame()  #OK
  DatasetPerframeWhole = data.frame()  #OK
  
  bestf.list = list()    #list to track best features from each metricset for the dataset
  
  metricsetiter = 1
  for(j in METRICSSETS)
  {
    WP.data  = dataset.loc.read(i,j)
    print("*********** wp data read")
    CP.data = CP.dataset.loc.read(i,j)
    print("*********** cp data read")
    
    WP.data[is.na(WP.data)] = 0
    CP.data[is.na(CP.data)] = 0
    
    # Here we should have availability of WP and CP datasets
    
    
    #get indexOut and index by running experiment on WP.data
    DATASET <<- WP.data
    
    
    nVar <<- ncol(DATASET) - 1
    
    nIVar <<- nVar - 1
    
    
    
    #start the experiment  
    #TAKE CARE TO SPECIFY x_axis as "LOC" argument when evaluating in terms of Peffort metric
    RESULTS = startExperiment(data = DATASET, modelmethod = MODELMETHOD,
                              outcome = "X.bugs.",
                              evalPerformance = PERFORMANCE,
                              summaryFunction = SUMMARYFUNCTION,
                              classProbs = CLASSPROBS,
                              returnResample = "all",
                              savePredictions = TRUE,
                              sampling = NULL,
                              returnData = TRUE,method = CVMETHOD,splitRatio = 0.80,number = NUMBER,repeats = REPEATS)
    
    indexOut = control.object$indexOut
    index = control.object$index
    
    print("*********** split of wp data done")
    #get best features from CP.data by running feature selection on CP.data
    DATASET <<- CP.data
    
    #TODO: write the code for feature selection
    
    features =  featureSelect(data = DATASET, modelmethod = MODELMETHOD,
                              outcome = "X.bugs.",
                              evalPerformance = PERFORMANCE,
                              summaryFunction = SUMMARYFUNCTION,
                              classProbs = CLASSPROBS,
                              returnResample = "all",
                              savePredictions = TRUE,
                              sampling = NULL,
                              returnData = TRUE,method = CVMETHOD,splitRatio = 0.80,number = NUMBER,repeats = REPEATS)
    
    print("*********** feature selection of cp data done") 
    
    #combine WP.data and CP.data and adjust index and indexOut
    for(p in 1:length(index))
    {
      indexOut[[p]] = indexOut[[p]] + nrow(DATASET)
      index[[p]] = 1:nrow(CP.data)
    }
    DATASET <<- rbind(DATASET,WP.data)
    
    #run experiment on CP.data
    
    
    #start the experiment  
    #TAKE CARE TO SPECIFY x_axis as "LOC" argument when evaluating in terms of Peffort metric
    RESULTS = startExperiment(data = DATASET[,features], modelmethod = MODELMETHOD,
                              outcome = "X.bugs.",
                              evalPerformance = PERFORMANCE,
                              summaryFunction = SUMMARYFUNCTION,
                              classProbs = CLASSPROBS,
                              returnResample = "all",
                              savePredictions = TRUE,
                              sampling = NULL,
                              returnData = TRUE,method = CVMETHOD,splitRatio = 0.80,number = NUMBER,repeats = REPEATS,
                              indexOut = indexOut,
                              index = index)
    
    
    print("***********  cpdp   exp done") 
    
    
    
    #TODO: WRITE CODE to save prediction results and to save average of only first repeat in multiple k-fold CV
    metricsetPerframe = data.frame(RESULTS$resample[,PERFORMANCE])   # OK	save the prediction performance of CV 
    metricsetPerframeAvg = rbind(metricsetPerframeAvg, 
                                 data.frame(mean(metricsetPerframe[,1])))     # OK average  the CV prediction performance and 
    #combine avg over different metrics sets
    
    if(metricsetiter == 1)
    {
      DatasetPerframeWhole = data.frame(metricsetPerframe[,1])			 #OK combine the prediction performance of CV over different metricsets
      metricsetiter = metricsetiter + 1
    }
    else
    {
      DatasetPerframeWhole = cbind(DatasetPerframeWhole, 
                                   data.frame(metricsetPerframe[,1]))			#OK combine the prediction performance of CV over different metricsets
    }
    
  }
  
  DatasetPerframeAvg  = cbind(DatasetPerframeAvg,metricsetPerframeAvg)               #OK combine  the combined avg of pred performance over different metrics sets over different datasets                                          
  
  
  metricsetPerframeWhole = rbind(metricsetPerframeWhole, 
                                 DatasetPerframeWhole)			 # OK combine  the combined pred performance over different metrics sets over different datasets                                          
  
  # write DatasetPerframeWhole to file 'PERFORMANCE_all_approaches_INDIVIDUAL_dataset' file for whitney u test experiment 2
  
  colnames(DatasetPerframeWhole) = METRIC
  
  writeperformance.function(context,"all", PERFORMANCE, "glm", i, DatasetPerframeWhole)
}

colnames(DatasetPerframeAvg) = c("METRIC",DATASETNAMES) 
# write DatasetPerframeAvg to file 'Avg_PERFORMANCE_all_approaches_each_dataset' file for friedman and nemenyi test experiment 1   and average rank of approaches                                                       
writeperformance.function(context,"avg", PERFORMANCE,"glm","BPD",DatasetPerframeAvg)
colnames(metricsetPerframeWhole) = METRIC

# write metricsetPerframeWhole to file 'PERFORMANCE_all_approaches_entire_dataset' file for whitney u test experiment 2

writeperformance.function(context,"all", PERFORMANCE,"glm","BPD",metricsetPerframeWhole)



