from tweepy import Stream
from tweepy import OAuthHandler
from tweepy.streaming import StreamListener
import json
from HTMLParser import HTMLParser
import re

ckey = ''
csecret = ''
atoken = ''
asecret = ''

class listener(StreamListener):

	def on_data(self,data):
		try:
			data = json.loads(HTMLParser().unescape(data))
			#time = data["created_at"].encode('utf-8')
			#print time
			tweet = data["text"].encode('utf-8')
			tweet=' '.join(re.sub("(@[A-Za-z0-9]+)|([^0-9A-Za-z \t])|(\w+:\/\/\S+)"," ",tweet).split())
			#print tweet
			places="null"
			if data.get('place'):
				places = data['place']['full_name'].encode('utf-8')
				print places	
			saveFile = open('twittext5.csv','a')
			saveFile.write(tweet)
			saveFile.write('\n')
			saveFile.close()
			saveFile = open('twitplace5.csv','a')
			saveFile.write(places)
			saveFile.write('\n')
			saveFile.close()
			
			return True
		except BaseException,e:
			print 'failed ondata',str(e)
			time.sleep(5)
			
	
	def on_error(self,status):
		print status
	

	
auth =OAuthHandler(ckey,csecret)
auth.set_access_token(atoken,asecret)
twitterStream = Stream(auth,listener())
twitterStream.filter(track=["trump"]) 
