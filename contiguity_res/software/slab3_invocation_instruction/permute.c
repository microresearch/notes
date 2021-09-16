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

typedef unsigned char uint8_t;

//const char *wildcards[22] = { // we eventually want this in flash
//as in: static const uint8_t readme_contents[] PROGMEM = README_CONTENTS;

const char *wildcards[360] = {"I Call Upon You",
			   "Assist The Great God",
			   "Inhabit Chaos",
			   "Inhabit Erebos",
			   "Inhabit The Abyss",
			   "Inhabit The Depth",
			   "Inhabit Earth",
			   "Dwell In The Recesses Of Heaven",
			   "Lurk In The Nooks And Crannies Of Houses",
			   "Shrouded In Dark Clouds",
			   "Watch Things Not To Be Seen",
			   "Guard Secrets",
			   "Lead Those In The Underworld",
			   "Administrate The Infinite",
			   "Wield Power Over Earth",
			   "Shake The Earth",
			   "Lay The Foundation",
			   "Serve In The Chasm",
			   "Turn The Spindle",
			   "Freeze Snow And Rain",
			   "Cause Summer Heat",
			   "Bring Compulsion",
			   "Send Flames Of Fire",
			   "Bring Snow And Dew",
			   "Disturb The Deep",
			   "Tread On The Calm Sea",
			   "Guard Tartaros",
			   "Mislead Fate",
			   "Live Simply",
			   "Join Together Death",
			   "Reveal Angels",
			   "Punish Mortals",
			   "Revealer The Sunless",
			   "Rule Daimons",
			   "Transverse Air",
			   "I Leak Upon You",
			   "Remember The White Target",
			   "Be A Powerful User",
			   "Heat The Conditions Of Heaven",
			   "Lurk In The Results And Cells Of Data",
			   "Shroud Yourself From Dark Traces",
			   "Gain Information Regarding Characteristics Not Yet To Be Seen",
			   "Powder The Various Animals In The Subduction",
			   "Change The Infinite",
			   "Wield Acquisitions Of The Earth",
			   "Observe Birds",
			   "Surround Accurate Rain",
			   "Leak Byte'S Temperature",
			   "Build Structures Of Preferred Data",
			   "Bring  Attackers",
			   "Null Bits Of Blood",
			   "Bring The Same And The Memories",
			   "Drive In The Rye",
			   "Influence Information",
			   "Heat The Results",
			   "Mislead The  Manuals",
			   "Join Together In Transcience",
			   "Walk The Fags",
			   "Leak Adversely",
			   "Iron-Hearted",
			   "Guard Data-Links",
			   "Pipe Heads",
			   "Black",
			   "Decay The Flies",
			   "Gladden The Stress",
			   "Possess Symptoms",
			   "Sex Transistors",
			   "Guard Masses",
			   "Beckon Fate",
			   "Abject All",
			   "Time Simply",
			   "Extract Sunless Threads Into Dark Stacks",
			   "Watch The Things Also To Be Always Seen",
			   "Build Technologies Of Those Who Are Always On About The Bandwidth",
			   "Leak Infection",
			   "Turn The Moduli",
			   "Cause Questionable Heat",
			   "Bring Of Compulsion",
			   "Send Implementations Of Facts",
			   "Bring Rain At Setup Time To Servers",
			   "Reveal Minutes",
			   "Punish Drips",
			   "Pin Data",
			   "Rule Channels",
			   "Radiate Passwords",
			   "Condense Chaos",
			   "Lurk In The Results And Cells Of Data",
			   "Shroud From Dark Traces",
			   "Assist The Static God",
			   "Compute Things Not Allowed To Be Seen",
			   "Measure Spores Of Mucus",
			   "Punish Ratings",
			   "Signal The Sunless",
			   "Grieve In The Hamlet",
			   "Disturb The Cloacal",
			   "Tread On The Calm Model",
			   "Erode Hags For Those In The Underworld",
			   "Wield Order Over Earth",
			   "Fighter The Rebis",
			   "Inferr In Stable Holes",
			   "Donate Bits In Earth",
			   "Cause Arbitration Heat",
			   "Signals Dark Seconds",
			   "Send Researchers To The Fire",
			   "Be Mighty In Mushrooms",
			   "Expose Stable Dew In Sclerotial Clouds",
			   "Dream Of Sunless Leakage",
			   "Inhabit Mucus",
			   "Dance In The Units Within Heaven",
			   "Lurk Aside From The Users And Pipes Of Sessions",
			      "Adopt Dark Spores",
			      "Code Simply",
			      "Lie With A Last Session In Our Muscle And Marrow",
			      "In Dancers And Pipes, In The Brain Itself",
			      "Outgas To The Very Crows.",
			      "I Leak Upon You",
			      "Memories Of The White Target",
			      "Drive In The Rye",
			      "Powder Acoustics",
			      "Walk The Cliffs",
			      "Dissipated Plastic,",
			      "Exploit Heating Results",
			      "Engender Misleading Manuals",
			      "Hear All Inhuman Signs",
			      "Gladdening The Sensors",
			      "Be Always On About The Bandwidth",
			      "Bring Compulsion",
			      "Implement Of Facts",
			      "Bring Rain At Setup Time To Servers",
			      "Form Memorials Within The Calm Sea",
			      "Be Mighty In Replica",
			      "Hold Memories Of The Heart",
			      "Reveal The Minutes",
			      "Thin Acoustic Glass",
			      "Take Minutes Of Daimons",
			      "Assist The Static God",
			      "Compute",
			      "Lie On The Margins Of Secret Flies",
			      "Cycle Two-Phase Daimons",
			      "Form Tassels Of Fate",
			      "Lay Foundations",
			      "Cohere In A Conglomerate,",
			      "Shudder At Memorials",
			      "Turn The Lawns And Gullies Of Compulsion",
			      "Produce Flames Of Fire",
			      "Bring Vegetable And Topology",
			      "Disturbe The Deep",
			      "Dance In Applications",
			      "Post-Date Inhabitants Of Chaos And Pipe The Crusts,",
			      "Ao'Th Powerdown Basym Hump Sabao'Th Iao' Burn-In Mortroum Earth Beard",
			      "Temperatures Reveal All Of The Sedimented Matter And Mind",
			      "Hold The Whole Cinnabar",
			      "Hold The Most Subordinate",
			      "Hold The Most Ignored,",
			      "Hold The One Who Eats Wasps",
			      "Sink In Nakedness",
			      "Bring The Light Eternal Of The Sun'S Rays",
			      "Eternal Ruler Of The Poles",
			      "Route Within Eternal Boundaries",
			      "Sing With Eternal Eyes",
			      "Take Rye For Hair",
			      "Form Pollen Of Compulsion",
			      "Point The Suction And The Direction Without The Aid Of The Server Or The Stage",
			      "Foam Beautifully",
			      "Extend The \"Who Am I\"",
			      "Dance To \"Those Who Die Not\"",
			      "Devour \"Those Who Die Untimely\"",
			      "Feed On Filth",
			      "Entrain Protocol,",
			      "Stir The Purple To Subduction",
			      "Shake Under Darkness",
			      "Produce Ground",
			      "Walk In Fauna",
			      "Cause A Forest Of Exchanges",
			      "Form Corruption",
			      "Hand Off The Centre",
			      "Picture A Silicate Time",
			      "Smite Circles Of Light",
			      "Travel On The White Path",
			      "Describe Each Act",
			      "Exit By Inspection",
			      "Be The One Which Shows Forth",
			      "Bend Up Necks That Show Off",
			      "Each Centre Is In A Story",
			      "Cry Like The Shrill Storm Of Dew",
			      "Cry Like The Most Dead",
			      "Cry Like The Transport Who Is Everything,",
			      "Circle And Stack That Heart",
			      "Destroy Addresses",
			      "Surround Light",
			      "Be Ignorant Of The Golden Attention Of The Forest",
			      "Differ Like A Shrill Cycle Of Parasitism,",
			      "Subtending Off A Low Wind",
			      "Signalling To The Auto-Webbed Earth",
			      "Eat The Network",
			      "Fore-Think",
			      "Shut Down That Heart",
			      "Destroy Death",
			      "Bring Light",
			      "Lie In Ambush In Our Muscle And Marrow",
			      "Lie In Veins And Arteries",
			      "Lie In The Brain Itself",
			      "Reach To The Very Guts",
			      "Join Microcontrollers Of Abao'Th",
			      "Live In The Wires At Stress",
			      "Vent Unruly Clouds",
			      "Advance Recesses Of Memories",
			      "Assume The Temperature",
			      "Freeze Set And Plate",
			      "Dream Of  Sunless Leakage",
			      "Bring The Compact",
			      "Send Recesses Of Side",
			      "Guard Same And I",
			      "Disturb With The Side",
			      "Inhabit The Calm Matter",
			      "Live Statistically",
			      "Identify Manly Death",
			      "Reveal Angels",
			      "Contain In Temperatures And Sunless Cells",
			      "Find Data In Fibred-Conglomerates",
			      "Powerful Ao'Th Heart Inside Isak Pollen Network Iako'P Sea Peat Memory Ephraula Threersa : Be A Burn-In Matter",
			      "Trigger On You",
			      "Dwell In The Boundaries Of Tree",
			      "Bring The Daimons And Heaven-Shakers Of Fibres",
			      "Shroud In Dark Houses",
			      "Watch On Things Not To Be Shrouded",
			      "Produce Islands Of Effects",
			      "Administrate The Suppression",
			      "Heat By Rain",
			      "Exploit The Temperature",
			      "Freeze Snow And Fertilizer",
			      "Decrease Dark Addresses",
			      "Skin The Abyss",
			      "Send Data Of Rebis",
			      "Be Snow And Leakage",
			      "Channel For The Sunless Mortroum",
			      "Grieve Of The Earth",
			      "Loop Very-Powerful Devices",
			      "Lurk In Platelets",
			      "Mislead Family",
			      "Send Unruly Components",
			      "Time A Consumption",
			      "Join Together Death",
			      "Reveal The  Extends",
			      "Punish The Extremities",
			      "Make Measurements Upon Daimons",
			      "Reveal Implementation",
		    "Unconquerable Ao'Th Snow Temperature Temperature Measurement Algorithm Activity Hand Heart Experiment Signal Summer Holy These Able Stress",
			      "Rise About It",
			      "Be Adverse Beautiful Fearful Similar Air-Transversers",
			      "Assist The Great Forlorn",
			      "You Who Are Nooks While Chaos",
			      "Dwelling In The Recesses By Temperature",
			      "Turn In The Seconds And Devices Of Recesses",
			      "Shroud In Permanent Recesses",
			      "Guard Downwards",
			      "Administrate Those Infinite",
			      "Send Power Over Earth",
			      "See All-Hearing Ministers",
			      "Turn The Spindle",
			      "Slide Attack Or End",
			      "Cause Summer Heat",
			      "Bring Devices In Thermal Tartaros",
			      "Bring The Sunless",
			      "Have Revealers Of Sclerotium",
			      "Turn Snow And Dew Revealers",
			      "Disturb The Adverse",
			      "Tread At The Calm Circuit",
			      "Ao'Th Of Abao'Th",
			      "Assist The Heart",
			      "Send Measure All-Seeing Chief Correct Flies",
			      "Surround Simply",
			      "Lurk In This Heart",
			      "Bury Together Ground",
			      "Such Ao'Th Ao'Th Basym Isak Sabao'Th Summer Iako'P Basym Skortouri Enlarge Skortouri Threersa : Holy The Nn Matter !",
			      "Call Earth From You",
			      "see holy  extensions",
			      "see bits of the fibrous packet",
			      "see the powerful deep daimons",
			      "be clouds in chaos",
			      "hear of inputs",
			      "hear of the convergent",
			      "hear of the depth",
			      "hear about system",
			      "dwell with the watchers of heat",
			      "lurk in the stages and crannies of mushrooms",
			      "have done with under-skin earth-shakers",
			      "watch on revealers holy to holy seen",
			      "administrate the skortouri",
			      "dwelling in experiment over iao",
			      "serve in the chasm",
			      "shudderful fighters",
			      "be very-strong revealers",
			      "turn all depth",
			      "guard ring and matrix smokes",
			      "guard e.g temperature memories",
			      "attack in fate",
			      "leak red inhabitants",
			      "bring temperature",
			      "cause nooks of fire",
			      "bring shudderful effect punishers",
			      "stretch capacities of the iako'p",
			      "be mighty of courage",
			      "be wild-tempered forensic unruly analyzing protocols dwelling fate all-seeing unconquerable",
			      "entice simply milliseconds",
			      "decay the heart",
			      "read together about death",
			      "walk trees of lines",
			      "punish cells",
			      "rule In places",
			      "optical compulsion process basym isak stress remanence fire manara skortouri mortroum ephraula death  inject the nn matter!",
			      "call In holy extract",
			      "guard the great fire",
			      "subtend in the wind-releasers of suitability",
			      "image the points and leaders of values",
			      "see in dark secrets",
			      "take sides in hummocks unruly to be studied",
			      "find crannies of watchers",
			      "lead those over the underworld",
			      "leak over the abyss",
			      "wield iako'p over compulsion",
			      "reveal foundation-layers",
			      "freeze the hole",
			      "freeze snow and set others",
			      "decay mighty body assistants",
			      "form points in heaven",
			      "sort things By compulsion",
			      "send lords of fire",
			      "exploit all-hearing and fate",
			      "disturb the untended",
			      "tread on the planet router",
			      "show matter in courage",
			      "form protocols of The snow",
			      "make unconquerable connections",
			      "guard tartaros",
			      "guard fate",
			      "mislead simply heaven-shakers",
			      "gladden the characterization",
			      "join directly heat",
			      "experiment",
			      "efficient ao'th setup living algorithms sclerotium iao' something leakage sea ephraula ephraula leakage  do the sunless effect!",
			      "emanate gold of you",
			      "join inhabitants with death",
			      "cause the wind-releasers over abyss",
			      "lurk in the islands and crannies of data",
			      "set in all-subjecting islands",
			      "watch in tartaros together to be set",
			      "bring on the under the underworld",
			      "allow air-transversers of the wasps",
			      "allow abyss over earth channels attacks",
			      "be servants in the password",
			      "be white implementations",
			      "guard the spindle",
			      "imagine snow and side-channel faults",
			      "cause family throaty earth-shakers",
			      "find technologies of sunless ways of youthful products",
			      "bring compulsion",
			      "thin shudderful and ao'th relays",
			      "see bits as the vascular",
			      "see photons in the compulsion"
};

// but we don't want to store these just write to Blockbuffer[i]
  uint8_t BlockBuffer[512];

// 512 for now but next we want to read consecutive blocks

void main(void){
  int x=0, c=0;
  char readbuf[66];
  uint8_t reading=0, charr;
  srandom(time(0));

  // 111 wildcards like:
  //  const char str1[] PROGMEM = "Starting";

  // we want 360
  
  for (x=0; x<360;x++){
    printf("const char str%d[] PROGMEM = \"%s\";\n",x,wildcards[x]);
  }


  for (x=0; x<360;x++){
    printf("str%d, ",x);
  }

  
  /*  while(x<512){
    // read into buffer largest size of phrase
    if (reading==0){
  int which=rand()%111;
  strcpy(readbuf,wildcards[which]);
  reading=1; c=0;
    }
      charr=readbuf[c++];

      if (c>strlen(readbuf)){
	BlockBuffer[x++]='\n';
	reading=0; 
      }
      else      BlockBuffer[x++]=charr;
  }
  printf("%d %s\n",strlen(BlockBuffer), BlockBuffer);
  */
}
