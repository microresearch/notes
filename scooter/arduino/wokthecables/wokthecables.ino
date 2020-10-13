// wok the cables

// Follow conditions and interpret instructions relayed in hotspot/ESSID tags at 10 minute intervals. 
// Document all findings of divinatory art on any social media using hashtag #wokthecables.


#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h> // Over-the-Air updates
#include <ESP8266WebServer.h>
#include "./DNSServer.h" // Dns server
#include <FS.h> // SPIFFS

const char *final_mess[3] = {"0","0","READ&EXE#wokthecables"}; 

const char *wildcards[44] = {"WOKthescooter","andrideto",
			     "takeESSIDX","stepsforward=",
			     "ShopforLAST-", "CLose*to",
			     "Crawlyourskin", "BACKto",
			     "Buyandfollow", "a CABLEto",
			     "TOAST-eatair", "wire1-0sign",
			     "FollowtheONE", "seenJUST NOW",
			     "go-EXE-","UNdergroundTO",
			     "RemainSTAYand","struggle|with",
			     "SendTHISmessage","@lastMESSAGEE",
			     "GOTOfoundreceiver","thenTOSScoins",
			     "DOtlastINSTRUCT","AGAIN&comment",
			     "turn0/left>0right","@next Xroads",
			     "REVdirection","forXsteps=",
			     "firstleft","fromNXT_",
			     "doitagainAND","darklyfollow_",
			     "goINside","@nearest*_",
			     "watchsigns~for","&#shinesto",
			     "revealitand","showit_2_",
			     "climb_nearest","^^^^",
			     "NOWMAKE_YOUR","YOURFULL_INVENTORY",
			     "GAMEOVER","-return_to"
};

// add a modifier: 0=none, 1-number, 2=operands, 3=instruction

char wildifmod[22]={2,1,2,2,2,0,0,2,2,0,0,0,1,1,2,2,2,2,2,2,0,2};

const char *cards[22] = {"aFOOL-","aMAGIC-","aWITCH-","aQUEEN-","aKING-","aAMETHYST-","aLOVERS-","aCAR-","aADJUST-","aHERMIT-","aFORTUNE-","aLUST-","aHANGED-","aDEATH-","aART-","aDEVIL-","aTOWER-","aSTAR-","aMOON-","aSUN-","aAEON-","aUNIVERS-"};

const char *conditions[22] = {"BEGIN","always","letME_","ifOpen","0x","if","EQU","0x","else","Nver","when","4ever","CMP","ifending","ifNOT","ifAlways","WAIT","when","ifnight","ifday","LOOP","<-"};

char condif[22]={1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0};

const char *cond_operands[22] = {"start","Want","guided","opposed","ordered","hidden","two","inmotion","==","Alone","SURplus","l0nging","changing","ending","ZERO","shad0w","BRK","sh1n1ng","reflecting","day","forever","r3turned"};

const char *instruction[22]={"RIDE","WANT","dream","buRy","WOK","reveal","LICK","GO","dis-ASM","stay","shop","SHOUT!","stand","leave","raise","MINE","Dstroy","SHine","refl3ct","BURN","LOOP4_","reboot"};

const char *inst_mods[22] = {"_2_","FROM","back","INto","IN","thru","of","of","@","-","N","N","N","0","1","both","ALL","EXE","from","over","IN","_2to"};

char numericmod[22]={0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,0}; 

const char *inst_operands[22] = {"scooter","Tur/n/ing","TREE","earth","SACRIFICE","U-Bahn","JOINING","crow","cafe","LAIR","shop","stain","COIL","mask","future","tunnel","building","water","mirror","SUN","fire","EXCEPTION"};

const char *cars[22] = {"$","%","\(",")","*","*","_","#",".","$","+","V","¬","\\","/","^","@","*","\(",".","~","0"};

DNSServer dnsServer;
const byte DNS_PORT = 53;
int taroty=6001, mess=0;
      
ESP8266WebServer server(80);

#ifndef STASSID
#define STASSID "\xF0\x9F\x9B\xB4 beta"
//#define STASPSK "mypassword"
#endif

IPAddress apIP(192, 168, 4, 1);
const char* ssid = STASSID;
//const char* password = STAPSK;

void setup() {
  Serial.begin(115200);
  Serial.println("Booting");

  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP(ssid);
  dnsServer.start(DNS_PORT, "*", apIP); // redirect dns request to AP ip
        
  MDNS.begin("esp8266", WiFi.softAPIP());
  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());

  //Over-the-Air updates
  ArduinoOTA.setHostname("ESP8266");
  ArduinoOTA.setPassword("change-me");
  ArduinoOTA.begin();
  SPIFFS.begin();

  //redirect all traffic to index.html
  server.onNotFound([]() {
        Serial.println("NOTFOUND");
	if(!handleFileRead(server.uri())){
	  const char *metaRefreshStr = "<head><meta http-equiv=\"refresh\" content=\"0; url=http://192.168.4.1/index.html\" /></head><body><p>redirecting...</p></body>";
	server.send(200, "text/html", metaRefreshStr);
	      }
    });
      
  server.begin();

  
  randomSeed(RANDOM_REG32);

  
}

void loop() {
  char picked_card, inter[3];
  char fullessid[2][64]; // loop to display
  
  // code to generate ESSID string from cards
  // run this every 10 minutes for new ESSID 
  
  if ((taroty++) > 6000){ // test with 100 = 10 seconds so 600onemin - 6000=tenmins
    taroty=0;
    if ((rand()%12)==11) {
    // pick wildcard with suitable modifier
      picked_card=rand()%22; 
      strcpy(fullessid[0], cards[picked_card]);
      strcat(fullessid[0], wildcards[picked_card*2]);
      strcpy(fullessid[1], wildcards[(picked_card*2)+1]);
      
      if (wildifmod[picked_card]==1) {
	sprintf(inter,"%d",(rand()%12));
	strcat(fullessid[1], inter);
      }

      if (wildifmod[picked_card]==2) {
	picked_card=rand()%22;
	strcat(fullessid[1], inst_operands[picked_card]);
      }  
    }//////
 else {
  picked_card=rand()%22;
  strcpy(fullessid[0], cards[picked_card]);

  picked_card=rand()%22;  
  if (condif[picked_card]==1) strcat(fullessid[0], conditions[picked_card]);

  picked_card=rand()%22;
  strcat(fullessid[0], cond_operands[picked_card]);

  if ((rand()%6)==2) {
  picked_card=rand()%22;
  strcat(fullessid[0], cars[picked_card]);
  }

  picked_card=rand()%22;
  strcpy(fullessid[1], instruction[picked_card]);

  picked_card=rand()%22;
  if (numericmod[picked_card]==0) strcat(fullessid[1], inst_mods[picked_card]);
  else {
    sprintf(inter,"%d",rand()%12);
    strcat(fullessid[1], inter);
  }

  if ((rand()%6)==2) {
  picked_card=rand()%22;
  strcat(fullessid[1], cars[picked_card]);
  }
  
  picked_card=rand()%22;
  strcat(fullessid[1], inst_operands[picked_card]);
 }

  // if is longer than 32 truncate
  //  if (strlen(fullessid)>31) fullessid[31]='\0';
  
  //  printf("%s \n", fullessid);
  //  printf("%d \n",strlen(fullessid)); // is it longer than 32 if so cut.

    //  Serial.println(fullessid[0]);
    //  Serial.println(fullessid[1]);
}

  // loop through ESSID as my HANDY only shows 16 say characters
  // so first 2 fullessids and then final mess
  //  WiFi.softAP(fullessid);
  if ((taroty%200)==0) {// was 200 but now less for testing
    if (mess>2) mess=0;
    if (mess<2) {
      Serial.println(fullessid[mess]);
      WiFi.softAP(fullessid[mess]);
    }
    else {
      Serial.println(final_mess[mess]);
      WiFi.softAP(final_mess[mess]);
    }
    mess++;
  }
    

  
  //  MDNS.begin("esp8266", WiFi.softAPIP());
  //  Serial.println("Ready");
  //  Serial.print("IP address: ");
  //  Serial.println(WiFi.softAPIP());


    dnsServer.processNextRequest();
    ArduinoOTA.handle();
    server.handleClient();
  delay(50); 
}


String getContentType(String filename){
  if(server.hasArg("download")) return "application/octet-stream";
  else if(filename.endsWith(".htm")) return "text/html";
  else if(filename.endsWith(".html")) return "text/html";
  else if(filename.endsWith(".css")) return "text/css";
  else if(filename.endsWith(".js")) return "application/javascript";
  else if(filename.endsWith(".png")) return "image/png";
  else if(filename.endsWith(".gif")) return "image/gif";
  else if(filename.endsWith(".jpg")) return "image/jpeg";
  else if(filename.endsWith(".ico")) return "image/x-icon";
  else if(filename.endsWith(".xml")) return "text/xml";
  else if(filename.endsWith(".mp4")) return "video/mp4";
  else if(filename.endsWith(".pdf")) return "application/x-pdf";
  else if(filename.endsWith(".zip")) return "application/x-zip";
  else if(filename.endsWith(".gz")) return "application/x-gzip";
  return "text/plain";
}

//Given a file path, look for it in the SPIFFS file storage. Returns true if found, returns false if not found.
bool handleFileRead(String path){
  if(path.endsWith("/")) path += "index.html";
  String contentType = getContentType(path);
  String pathWithGz = path + ".gz";
  if(SPIFFS.exists(pathWithGz) || SPIFFS.exists(path)){
    if(SPIFFS.exists(pathWithGz))
      path += ".gz";
    File file = SPIFFS.open(path, "r");
    size_t sent = server.streamFile(file, contentType);
    file.close();
    return true;
  }
  return false;
}