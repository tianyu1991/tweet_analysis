text<-read.csv("twittext.csv",stringsAsFactors=FALSE)
place<-read.csv("twitplace.csv",sep='\n')
n<-place=="null"
places<-place[!n]
places<-as.factor(places)


states_names<-read.csv("names.csv",stringsAsFactors=FALSE)
n<-nrow(states_names)
for (i in 1:n){
	places[grep(states_names[i,1],places)]=states_names[i,1]
	places[grep(states_names[i,2],places)]=states_names[i,1]
}
places[grep("Nueva York",places)]="NY"
places2<-cbind(places,rep(1,length(places)))
places2<-as.data.frame(places2)
places2$count<-as.numeric(places2$count)
places2$states<-as.factor(places2$states )
colnames(places2)=c("states","count")
library(dplyr)

sum_count<-summarize(group_by(places2,states),count=sum(count))
sum_count<-as.data.frame(sum_count)

library(plyr)
sum_count<-arrange(sum_count,desc(count))
qplot(sum_count)
