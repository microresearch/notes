from pattern.web import URL, plaintext, Crawler

outfile = open("test_txt", "w")

class Polly(Crawler): 
    def visit(self, link, source=None):
        #        print 'visited:', repr(link.url), 'from:', link.referrer
        print repr(link.url)
        #        s = URL(link.url).download()
        #s = plaintext(s, keep={})
        #print s.encode('utf-8') # append to file?
        #outfile.write(s.encode('utf-8'))
        
        def fail(self, link):
            print 'failed:', repr(link.url)

p = Polly(links=['http://lustybooks.com/vintage-erotica-all.html'], delay=1)
while not p.done:
    p.crawl(method=0, cached=False, throttle=3)

            
# s = URL('http://lustybooks.com/erotica/6/party-wife-rex-weldon/p-6.html').download()
# s = plaintext(s, keep={})

# print s.encode('utf-8')

# # save as file

# outfile = open("test_txt", "w")
# outfile.write(s.encode('utf-8'))
outfile.close()

