# permutations
# Slab x: description

import random

#diana= ['Diana','Dodi','Queen', 'King','Prince','Princess', 'Goddess', 'Victim', 'Huntress', 'Star','Mary', 'Trinity','Double', 'Bitch', 'Vaughan','Ballard','Catherine','Dr Remington','Henri Paul']

firstwords=['Calculations', 'Measurements', 'Predictions', 'Instructions','Processes','Computations','Divinations','Material Conditions','Small Movements','Elements','Devices','Measurement devices','Measures conducted','Actions','Incantations','Infrastructures','Exchanges','Recordings','Designated objects','Constellations','Inputs','Material changes', 'Small changes','Clumsy devices','Mute interfaces','Clumsy technical devices','Incoming receptions','Slabs']

#which

doing=['interfere with','destroy','subtly alter','imperceptibly change','describe','change', 'depend upon', 'are conducted with','have nothing to do with','reveal something about','predict what will happen at','are seperate from','contain','compile','feedback upon','interface with','translate into','impact upon','are contained from','are contained against','render permutations within', 'gain entry into','take energy from','define','connect to','align with','are afforded by','are linked to','enforce a seperation within','isolate','are placed at','lurk in','inhabit','watch over','shroud','gain information regarding characteristic of','observe','surround','enclose','leak out in','form structure within','influence','condense','reveal','compute aspects of','disturb','expose','dream of','encode','summarise']

#loc
locations=['a location', 'an environment','a place','a location as location','what is at a location','what is at a place','that which is external to a location','what is external to a place','the atmosphere','the feeling of a place','that point in space','a defined place']

addons=['.',' ','.',' ','.',' ','.',' ',' for no apparent reason.',' for no reason.',' for a specific reason.','.',' ',' with no set of references.',' with no sense.',' without any end result.',' finally.',' eventually.',' forever.',' for a well defined duration.',' for an ill-defined duration.',' for a defined period.',' at intervals.',' at clear intervals.',' at clear intervals and for well defined periods of time.',' at clear intervals for ill defined periods of time.', ' at ill defined intervals for clearly defined periods of time.',' at ill defined intervals for clearly defined periods of time.',' at periodic intervals.',' for an unspecified period.', ' for a hidden yet defined period of time.',' with no further results.', ' with any clear results being necessarily hidden',' eternally.',' without consequences.',' for unknown reasons.','continuously','indefinitely','for indefinite periods of time', 'for definite periods of time', 'for continuous periods of time']

# could add through, by way of, x processes eg. by way of the addition of, by way of the ...of, process/object + for whatever reason, for no reason
byways=['by way of the addition of further','for no other reason than for','by way of','involving further','through adding','through the prediction of future','through the revealing of','without having anything to do with','in order to gain entry into further','through the re-distribution of','within the realm of','with thye exclusion of certain', 'with the exclusion of','by way of excluding all future','by way of excluding all previous','outside all possible','through rendering as data','through aligning with','as well as involving further','not in any way influenced by','in order to generate','without making sense of','to fuel the production of','to engage in further','lay the foundation for future','lay the foundation for further', 'are acquired by way of','prompting a finite series of','prompting an infinite series of','which cannot be run for']

lastwords=['calculations', 'measurements', 'predictions', 'instructions','processes','computations','divinations','material conditions','small movements','elements','devices','measurement devices','measures','actions','incantations','lack of any reason','reason or reasons unknown','infrastructures','exchanges','recordings','designated objects','stones or rocks','clumsy devices','mute interfaces','clumsy technical devices','incoming receptions','slabs']

wiches=['which', 'that']

sent=[]

#a location

for x in range(100000):
    
    addon=random.choice(addons)
    if addon==' ':
        sentence =random.choice(firstwords)+" "+random.choice(wiches)+" "+random.choice(doing)+" "+random.choice(locations)+" "+random.choice(byways)+" "+random.choice(lastwords)+"."
    else:
        opener=random.choice(firstwords)
        closer=random.choice(lastwords)
        if opener.lower()!=closer:
            sentence =random.choice(firstwords)+" "+random.choice(wiches)+" "+random.choice(doing)+" "+random.choice(locations)+addon
    if sentence not in sent: sent.append(sentence)

for senten in sent:
    print senten
        

