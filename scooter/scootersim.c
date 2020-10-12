#include <unistd.h>   
#include <sys/types.h>                                                          
#include <sys/stat.h>                                                           
#include <fcntl.h>                                                              
#include <string.h>                                                             
#include <time.h>                                                           
#include <dirent.h>                                                             
#include <limits.h>  
#include <errno.h> 
#include <stdlib.h>
#include <stdio.h>

// TODO: add wildcards that are quite clear instructions, add in some assembly language, arduino/essid, deliver web page with instructions

const char *wildcards[22] = {"jumponthescooterandrideto",
			     "takeESSIDXstepsforward=",
			     "Shopcloseto",
			     "Crawlskinbackto",
			     "Buyandfollowacableto",
			     "Toast-eatairwire1-0sign",
			     "Followtheoneseennow",
			     "go-undergroundto",
			     "Remainstayandstrugglewith",
			     "Repeat-thismessagetolastmessagee",
			     "gotofoundreceivertosscoins",
			     "dolastinstructionagaincomment",
			     "turnatnextcrossroads",
			     "reversedirectionXsteps=",
			     "leftfromthenext",
			     "doitagaindarklyfollow",
			     "goinsidenearest",
			     "watchsignsshinesto",
			     "revealitandshowitto",
			     "climbnearest",
			     "feedcrows-scatterclouds",
			     "gameover-returnto"
};

// add a modifier: 0=none, 1-number, 2=operands, 3=instruction

char wildifmod[22]={2,1,2,2,2,0,0,2,2,0,0,0,0,1,2,2,2,2,2,2,0,2};

const char *cards[22] = {"FOOL","MAGIC","WITCH","QUEEN","KING","AMETHYST","LOVERS","CAR","ADJUST","HERMIT","FORTUNE","LUST","HANGED","DEATH","ART","DEVIL","TOWER","STAR","MOON","SUN","AEON","UNIV"};

const char *conditions[22] = {"Begin","always","letme","ifopen","0x","if","EQU","0x","else","Never","when","Forever","stay","ifending","ifnot","always","ifending","when","ifnight","ifday","return","--"};

char condif[22]={1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0};

const char *cond_operands[22] = {"start","want","guided","oppose","ordered","hidden","two","motion","equal","alone","surplus","longing","changing","ending","equal","shadow","failing","shining","reflecting","day","forever","returned"};

const char *instruction[22]={"ride","want","dream","bury","wok","reveal","lick","go","dissasm","stay","shop","shout","stand","leave","build","mine","destroy","shine","reflect","burn","loop","reboot"};

const char *inst_mods[22] = {"to","from","back","into","in","thru","of","of","at","-","N","N","N","0","1","both","all","to","from","over","in","to"};

char numericmod[22]={0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0}; 

const char *inst_operands[22] = {"scooter","Turing","tree","earth","sacrifice","u-bahn","conjunct","crow","cafe","LAIR","shop","stain","cross","mask","future","tunnel","building","water","mirror","SUN","fire","stone"};


char fullessid[128]; // but max essid is only 32 so might have to truncate!

void main(void){
  char picked_card, inter[3];
  // seed random - randomSeed(analogRead(0));

  srandom(time(0));

  if ((rand()%12)==11) {
    // pick wildcard with suitable modifier
  picked_card=rand()%22; 
  strcpy(fullessid, cards[picked_card]);
  strcat(fullessid, wildcards[picked_card]);
  if (wildifmod[picked_card]==1) {
    sprintf(inter,"%d",(rand()%12));
    strcat(fullessid, inter);
  }

  if (wildifmod[picked_card]==2) {
  picked_card=rand()%22;
  strcat(fullessid, inst_operands[picked_card]);
  }  
}
    

 else {
  picked_card=rand()%22;
  strcpy(fullessid, cards[picked_card]);
  picked_card=rand()%22;  
  if (condif[picked_card]==1) strcat(fullessid, conditions[picked_card]);
  picked_card=rand()%22;
  strcat(fullessid, cond_operands[picked_card]);
  picked_card=rand()%22;
  strcat(fullessid, instruction[picked_card]);
  picked_card=rand()%22;
  if (numericmod[picked_card]==0) strcat(fullessid, inst_mods[picked_card]);
  else {
    sprintf(inter,"%d",rand()%12);
    strcat(fullessid, inter);
  }
    
  picked_card=rand()%22;
  strcat(fullessid, inst_operands[picked_card]);
 }
  
  printf("%s \n", fullessid);
  printf("%d \n",strlen(fullessid)); // is it longer than 32 if so cut.
}
