tweets<-readLines("trump/twittext.txt")
tweets<-strsplit(tweets,' ')
word_list<-unlist(tweets)
word2<-data.frame(word=word_list,count=rep(1,length(word_list)))
word_numbers<-group_by(word2,word)
s<-summarize(word_numbers,counts=sum(count))
s2<-arrange(s,desc(counts))
