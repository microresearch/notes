from pattern.web import URL, plaintext, Crawler

listy=['http://lustybooks.com/erotica/1/18-hole-swap-richard-alexis/'
,'http://lustybooks.com/erotica/7/the-24-hour-orgy-robin-peters/'
,'http://lustybooks.com/erotica/5/3-for-all-d-w-masters/'
,'http://lustybooks.com/erotica/5/3-men-3-ways-helena-dixon/'
,'http://lustybooks.com/erotica/4/7-deadly-sinners-christopher-sly/'
,'http://lustybooks.com/erotica/16/a-in-bed-staci-peters/'
,'http://lustybooks.com/erotica/16/abducted-michael-macpherson/'
,'http://lustybooks.com/erotica/12/abducted-daughter-wilhelm-mauser/'
,'http://lustybooks.com/erotica/12/the-abducted-honeymooner-karl-van-husen/'
,'http://lustybooks.com/erotica/17/abducted-on-vacation-julie-howard/'
,'http://lustybooks.com/erotica/12/the-abduction-of-cindy-vol-i-edward-mitchell/'
,'http://lustybooks.com/erotica/12/the-abduction-of-cindy-vol-ii-edward-mitchell/'
,'http://lustybooks.com/erotica/6/abused-again-and-again-john-mckeon/'
,'http://lustybooks.com/erotica/6/abused-aunt-val-marrick/'
,'http://lustybooks.com/erotica/10/abused-daughter-paul-gable/'
,'http://lustybooks.com/erotica/4/abused-daughter/'
,'http://lustybooks.com/erotica/5/abused-family-m-j-jacobs/'
,'http://lustybooks.com/erotica/1/abused-farm-wife-r-w-finch/'
,'http://lustybooks.com/erotica/19/abused-secretary-max-sharkey/'
,'http://lustybooks.com/erotica/2/abused-stepdaughter-j-t-watson/'
,'http://lustybooks.com/erotica/12/the-abused-teenager-george-morgan/'
,'http://lustybooks.com/erotica/1/abused-wife-val-marrick/'
,'http://lustybooks.com/erotica/1/abused-young-housekeeper-j-t-watson/'
,'http://lustybooks.com/erotica/5/abused-young-virgin-c-k-ralston/'
,'http://lustybooks.com/erotica/17/acapulco-family-reunion-claire-adrian/'
,'http://lustybooks.com/erotica/15/action-after-hours-u-r-green/'
,'http://lustybooks.com/erotica/8/adding-up-to-action-mark-cranston/'
,'http://lustybooks.com/erotica/12/adolescent-sexual-practices-barbara-hoffman/'
,'http://lustybooks.com/erotica/9/adopted-daughter-billie-monday/'
,'http://lustybooks.com/erotica/18/the-adopted-sister-ross-thompson/'
,'http://lustybooks.com/erotica/18/adoption-agency-girl-rosco-j-murtson/'
,'http://lustybooks.com/erotica/12/the-adult-version-of-the-3-musketeers-john-farrel/'
,'http://lustybooks.com/erotica/8/the-adulterers-john-carter/'
,'http://lustybooks.com/erotica/9/adults-who-prey-on-teenage-girls/'
,'http://lustybooks.com/erotica/6/the-adventures-of-claudia-joan-cabot/'
,'http://lustybooks.com/erotica/8/affairs-over-40-barbara-boinck/'
,'http://lustybooks.com/erotica/8/the-affectionate-mother-renee-stevens/'
,'http://lustybooks.com/erotica/16/after-dinner-nymph-sandy-ego/'
,'http://lustybooks.com/erotica/13/after-hours-secretary-brad-harris/'
,'http://lustybooks.com/erotica/20/after-school-elizabeth-watson/'
,'http://lustybooks.com/erotica/8/airborne-orgasms-cheri-canyon/'
,'http://lustybooks.com/erotica/11/all-around-nurse-daniel-m-miller/'
,'http://lustybooks.com/erotica/14/all-day-with-mom-kathy-andrews/'
,'http://lustybooks.com/erotica/1/all-in-the-family-duncan-fox/'
,'http://lustybooks.com/erotica/5/all-in-the-family/'
,'http://lustybooks.com/erotica/16/all-in-the-family-miles-peters/'
,'http://lustybooks.com/erotica/12/all-legs/'
,'http://lustybooks.com/erotica/15/all-men-please-her-elizabeth-strays/'
,'http://lustybooks.com/erotica/19/all-night-long/'
,'http://lustybooks.com/erotica/19/all-the-loving-couples-leo-v-gordon/'
,'http://lustybooks.com/erotica/15/all-the-men-please-her-connie-lingiss/'
,'http://lustybooks.com/erotica/8/all-the-way-mina-tyson/'
,'http://lustybooks.com/erotica/8/all-the-way-every-way-john-marx/'
,'http://lustybooks.com/erotica/2/all-the-way-family-ray-todd/'
,'http://lustybooks.com/erotica/10/all-the-way-wife-harry-stevens/'
,'http://lustybooks.com/erotica/5/all-the-young-flesh-roger-james/'
,'http://lustybooks.com/erotica/15/all-you-can-cheat-willie-maiket/'
,'http://lustybooks.com/erotica/12/the-alluring-bed-will-durant/'
,'http://lustybooks.com/erotica/1/along-came-a-swapper-richard-b-long/'
,'http://lustybooks.com/erotica/20/always-horny-family-kathy-harris/'
,'http://lustybooks.com/erotica/13/always-horny-wife-david-brown/'
,'http://lustybooks.com/erotica/10/always-willing-wife-jeff-collins/'
,'http://lustybooks.com/erotica/9/amy-loves-it-everyway-bob-dansk/'
,'http://lustybooks.com/erotica/15/an-adulterers-guide-hugh-mongus/'
,'http://lustybooks.com/erotica/14/an-affair-with-sis-mark-carver/'
,'http://lustybooks.com/erotica/4/an-end-for-love-kathy-breen/'
,'http://lustybooks.com/erotica/16/an-innocent-co-ed-laura-keene/'
,'http://lustybooks.com/erotica/6/an-inside-report-on-oralism-among-the-poor-christian-peters/'
,'http://lustybooks.com/erotica/4/an-orgy-for-mom-erika-norman/'
,'http://lustybooks.com/erotica/18/an-orgy-with-mom-kathy-andrews/'
,'http://lustybooks.com/erotica/17/an-overdue-bill-carl-willoughby/'
,'http://lustybooks.com/erotica/4/anal-action-wife-milly-st-john/'
,'http://lustybooks.com/erotica/7/anal-assault-paul-stone/'
,'http://lustybooks.com/erotica/6/anal-baby-sitters-h-hadley-williams/'
,'http://lustybooks.com/erotica/6/anal-daughters-jack-benjamin/'
,'http://lustybooks.com/erotica/4/anal-nieces-hal-edward/'
,'http://lustybooks.com/erotica/7/anal-orgy-paul-stone/'
,'http://lustybooks.com/erotica/4/anal-planet-alex-forbes/'
,'http://lustybooks.com/erotica/7/anal-rampage-paul-stone/'
,'http://lustybooks.com/erotica/9/anal-rape-abused-beaten-victims/'
,'http://lustybooks.com/erotica/4/anal-rider-randy-brooks/'
,'http://lustybooks.com/erotica/4/anal-starlets-edwin-coft/'
,'http://lustybooks.com/erotica/1/and-going-down-with-the-smiths-milt-jaxon/'
,'http://lustybooks.com/erotica/14/and-mom-makes-three-sally-simpson/'
,'http://lustybooks.com/erotica/20/and-mom-makes-three-kathy-andrews/'
,'http://lustybooks.com/erotica/8/andreas-sex-secrets-tiffany-diamond/'
,'http://lustybooks.com/erotica/11/angel-baby-edward-r-rangely/'
,'http://lustybooks.com/erotica/12/angelas-naughty-secret-mark-conroy/'
,'http://lustybooks.com/erotica/18/the-angry-swappers-aston-marlowe/'
,'http://lustybooks.com/erotica/19/animal-affairs-rodney-browne/'
,'http://lustybooks.com/erotica/19/animal-affairs-of-a-soul-sister-angie-baxter/'
,'http://lustybooks.com/erotica/4/animal-lovers-joseph-edenn/'
,'http://lustybooks.com/erotica/13/animal-partners-beth-james/'
,'http://lustybooks.com/erotica/4/the-animal-sex-syndrome-robert-reynolds/'
,'http://lustybooks.com/erotica/9/anne-takes-them-all-paul-conroy/'
,'http://lustybooks.com/erotica/1/anns-boy-hunger-brian-layer/'
,'http://lustybooks.com/erotica/5/anns-gang-rape-janet-mccoy/'
,'http://lustybooks.com/erotica/12/anns-young-studs-jane-moore/'
,'http://lustybooks.com/erotica/4/another-bed-another-time-geoffrey-edwards/'
,'http://lustybooks.com/erotica/16/another-kind-of-love-greg-hamilton/'
,'http://lustybooks.com/erotica/3/another-mother-sucks-gary-shaw/'
,'http://lustybooks.com/erotica/3/the-anus-cult-donald-jason/'
,'http://lustybooks.com/erotica/8/any-mans-mistress-marsha-gibbons/'
,'http://lustybooks.com/erotica/13/anybodys-plaything-mildred-thompson/'
,'http://lustybooks.com/erotica/11/anything-goes-alistair-morley/'
,'http://lustybooks.com/erotica/13/april-in-chains-paul-roan/'
,'http://lustybooks.com/erotica/8/army-camp-vamp-sinclair-jackson/'
,'http://lustybooks.com/erotica/4/ass-poor-danielle-davis/'
,'http://lustybooks.com/erotica/3/ass-reaming-blake-michaels/'
,'http://lustybooks.com/erotica/12/astrids-wanton-awakening-mark-conroy/'
,'http://lustybooks.com/erotica/15/at-his-command-sheri-frick/'
,'http://lustybooks.com/erotica/14/at-sisters-back-door-ray-mills/'
,'http://lustybooks.com/erotica/12/the-athletic-coach-bill-gillie/'
,'http://lustybooks.com/erotica/4/attack-from-behind-joseph-cirelli/'
,'http://lustybooks.com/erotica/7/aunt-bound-for-fun-curt-aldrich/'
,'http://lustybooks.com/erotica/14/aunt-donna-do-me-jeff-atkins/'
,'http://lustybooks.com/erotica/17/aunt-ellens-visit-clifton-vann/'
,'http://lustybooks.com/erotica/7/aunt-in-chains-j-t-watson/'
,'http://lustybooks.com/erotica/10/aunt-in-heat-nick-eastwood/'
,'http://lustybooks.com/erotica/5/aunt-into-bondage-mark-carver/'
,'http://lustybooks.com/erotica/4/aunt-sharon-enslaved-paul-gable/'
,'http://lustybooks.com/erotica/3/aunt-susan-saw-em-suck-david-crane/'
,'http://lustybooks.com/erotica/18/the-aunt-turns-on-donna-allen/'
,'http://lustybooks.com/erotica/18/auntie-in-the-middle-mark-carver/'
,'http://lustybooks.com/erotica/3/auntie-sneaks-and-peeks-tim-peterson/'
,'http://lustybooks.com/erotica/14/auntie-wants-more-m-j-jacobs/'
,'http://lustybooks.com/erotica/13/auntie-with-the-hots-john-kellerman/'
,'http://lustybooks.com/erotica/2/aunties-boy-pamela-james/'
,'http://lustybooks.com/erotica/15/aunties-eager-for-sex-tom-katt/'
,'http://lustybooks.com/erotica/3/aunties-horny-family-bill-randolph/'
,'http://lustybooks.com/erotica/18/aunties-horny-urges-don-scott/'
,'http://lustybooks.com/erotica/10/aunties-hot-itch-kevin-sellers/'
,'http://lustybooks.com/erotica/13/aunties-hot-lessons-pamela-james/'
,'http://lustybooks.com/erotica/1/aunties-hot-panties-jason-cannon/'
,'http://lustybooks.com/erotica/2/aunties-hot-surprise-brian-laver/'
,'http://lustybooks.com/erotica/14/aunties-incest-urge-donna-allen/'
,'http://lustybooks.com/erotica/2/aunties-naughty-visit-donna-allen/'
,'http://lustybooks.com/erotica/18/aunties-oral-urge-kathy-harris/'
,'http://lustybooks.com/erotica/4/aunties-our-slave-blake-garfield/'
,'http://lustybooks.com/erotica/2/aunties-young-lovers/'
,'http://lustybooks.com/erotica/6/aunts-and-nephews-james-warren/'
,'http://lustybooks.com/erotica/8/autumn-scandals-martin-pyx/'
,'http://lustybooks.com/erotica/4/awake-to-love-john-nemec/'
,'http://lustybooks.com/erotica/5/b-d-lesbians/'
,'http://lustybooks.com/erotica/7/b-d-wife-donna-allen/'
,'http://lustybooks.com/erotica/5/baby-bang-my-box-trixie-dickinson/'
,'http://lustybooks.com/erotica/11/the-baby-pros-barbara-hoffman/'
,'http://lustybooks.com/erotica/6/the-baby-sitters-ward-fulton/'
,'http://lustybooks.com/erotica/14/the-babysitter-balls-best-steve-golden/'
,'http://lustybooks.com/erotica/3/the-babysitter-bares-all-steve-golden/'
,'http://lustybooks.com/erotica/6/babysitter-in-bondage-marvin-cox/'
,'http://lustybooks.com/erotica/18/babysitter-in-heat-nick-eastwood/'
,'http://lustybooks.com/erotica/13/the-babysitter-gloria-russell/'
,'http://lustybooks.com/erotica/2/babysitter-with-the-hots-r-t-masters/'
,'http://lustybooks.com/erotica/19/the-babysitters-hot-itch-ken-preston/'
,'http://lustybooks.com/erotica/14/the-babysitters-hot-panties-j-t-watson/'
,'http://lustybooks.com/erotica/12/a-babysitters-hunger-andrea-michaels/'
,'http://lustybooks.com/erotica/19/the-babysitters-itch-tom-allison/'
,'http://lustybooks.com/erotica/12/the-babysitters-punishment-will-henry/'
,'http://lustybooks.com/erotica/7/babysitters-wild-nights-n-mate/'
,'http://lustybooks.com/erotica/4/back-door-love-trina-slade/'
,'http://lustybooks.com/erotica/3/back-door-mother-kathy-andrews/'
,'http://lustybooks.com/erotica/3/back-door-neighbors-donna-allen/'
,'http://lustybooks.com/erotica/4/back-door-orgies-h-hadley-williams/'
,'http://lustybooks.com/erotica/7/back-door-rape-eagleton-crowe/'
,'http://lustybooks.com/erotica/14/back-door-schoolgirl-thomas-trent/'
,'http://lustybooks.com/erotica/3/back-door-sisters-frank-brown/'
,'http://lustybooks.com/erotica/3/back-door-wives-ron-taylor/'
,'http://lustybooks.com/erotica/19/back-of-the-barn-blake-streete/'
,'http://lustybooks.com/erotica/4/the-backdoor-lovers-sue-varian/'
,'http://lustybooks.com/erotica/2/backwoods-family-ray-todd/'
,'http://lustybooks.com/erotica/1/bad-bad-girl-joan-carren/'
,'http://lustybooks.com/erotica/7/bad-girls-in-bondage-paul-gable/'
,'http://lustybooks.com/erotica/5/bad-news-billy-black-scott-arlen/'
,'http://lustybooks.com/erotica/9/badge-of-lust/'
,'http://lustybooks.com/erotica/9/balcony-of-shame-curt-colman/'
,'http://lustybooks.com/erotica/2/ball-in-the-family-nick-eastwood/'
,'http://lustybooks.com/erotica/3/a-ball-with-mother-kathy-andrews/'
,'http://lustybooks.com/erotica/2/a-ball-with-the-kids-brad-logan/'
,'http://lustybooks.com/erotica/16/a-balling-clan-valerie-peterson/'
,'http://lustybooks.com/erotica/3/balling-cousins-matthew-king/'
,'http://lustybooks.com/erotica/1/balling-families-jeff-collins/'
,'http://lustybooks.com/erotica/16/balling-horny-wife-john-damon/'
,'http://lustybooks.com/erotica/14/balling-mother-marvin-cox/'
,'http://lustybooks.com/erotica/16/balling-the-boys-ann-winter/'
,'http://lustybooks.com/erotica/16/barbara-balls-em-all-janet-london/'
,'http://lustybooks.com/erotica/8/bareback-lovin-wilson-smith/'
,'http://lustybooks.com/erotica/9/the-barroom-captive-stacey-moorelock/'
,'http://lustybooks.com/erotica/11/bastinado-walter-briggs/'
,'http://lustybooks.com/erotica/6/beach-girl-in-bondage-paul-gable/'
,'http://lustybooks.com/erotica/1/beasts-are-better-richard-long/'
,'http://lustybooks.com/erotica/7/beaten-prisoner-wife/'
,'http://lustybooks.com/erotica/13/the-beautiful-bitch-bruce-j-brooks/'
,'http://lustybooks.com/erotica/13/a-beauty-for-brutes-frank-leonard/'
,'http://lustybooks.com/erotica/7/the-beaver-boffers-tanya-springs/'
,'http://lustybooks.com/erotica/8/bed-my-wife-vance-gordon/'
,'http://lustybooks.com/erotica/15/bed-to-bed-family-fanny-heine/'
,'http://lustybooks.com/erotica/19/bedding-nurse-mercy-toni-elles/'
,'http://lustybooks.com/erotica/15/bedding-the-boss-jim-slim/'
,'http://lustybooks.com/erotica/8/bedding-them-all-jaye-walker/'
,'http://lustybooks.com/erotica/8/bedding-thy-neighbors-wife-jessie-king/'
,'http://lustybooks.com/erotica/15/bedfellows-everywhere-ben-effet/'
,'http://lustybooks.com/erotica/14/a-bedful-of-women-gil-frenz/'
,'http://lustybooks.com/erotica/2/bedtime-family-harry-stevens/'
,'http://lustybooks.com/erotica/5/behind-bedroom-doors-dennis-fredericks/'
,'http://lustybooks.com/erotica/8/behind-her-husbands-back-barbara-boinck/'
,'http://lustybooks.com/erotica/17/the-belgian-captive-mark-jason/'
,'http://lustybooks.com/erotica/19/bend-over-mom-sam-stone/'
,'http://lustybooks.com/erotica/6/the-best-of-guenter-klow-his-most-famous-cases-vol-2-guenter-klow/'
,'http://lustybooks.com/erotica/16/bestiality-and-a-young-girl-kathleen-hennessy/'
,'http://lustybooks.com/erotica/4/bestiality-for-cindy/'
,'http://lustybooks.com/erotica/3/between-mother-and-aunt-kathy-andrews/'
,'http://lustybooks.com/erotica/3/between-mother-and-son-david-crane/'
,'http://lustybooks.com/erotica/16/beverlys-vacation/'
,'http://lustybooks.com/erotica/7/bi-babes-do-it-better-david-lasher/'
,'http://lustybooks.com/erotica/11/the-big-snatch-r-l-vanbssa/'
,'http://lustybooks.com/erotica/19/big-titted-duo/'
,'http://lustybooks.com/erotica/5/the-big-whip-off/'
,'http://lustybooks.com/erotica/7/biggest-one-in-town-langston-huge/'
,'http://lustybooks.com/erotica/6/biker-captive-paul-gable/'
,'http://lustybooks.com/erotica/2/billys-horny-mom-william-taylor/'
,'http://lustybooks.com/erotica/19/billys-horny-mother-robert-kelly/'
,'http://lustybooks.com/erotica/3/billys-hot-mom-kathy-andrews/'
,'http://lustybooks.com/erotica/14/billys-hot-mother-donna-allen/'
,'http://lustybooks.com/erotica/13/a-bitch/'
,'http://lustybooks.com/erotica/5/bitch-in-bed-norma-thomas/'
,'http://lustybooks.com/erotica/8/bitch-in-bondage-rod-strong/'
,'http://lustybooks.com/erotica/16/bitchs-lesson/'
,'http://lustybooks.com/erotica/6/black-buck/'
,'http://lustybooks.com/erotica/12/black-captive-mark-jeggers/'
,'http://lustybooks.com/erotica/5/black-hot-ready-jewel-malby/'
,'http://lustybooks.com/erotica/3/black-leather-mama/'
,'http://lustybooks.com/erotica/1/black-mailed-teacher-robert-vickers/'
,'http://lustybooks.com/erotica/5/the-black-mailed-wife-peter-jensen/'
,'http://lustybooks.com/erotica/6/black-meat-lust/'
,'http://lustybooks.com/erotica/13/the-black-nursemaid/'
,'http://lustybooks.com/erotica/20/black-office-bondage-s-t-karmen/'
,'http://lustybooks.com/erotica/9/black-passion/'
,'http://lustybooks.com/erotica/6/black-prof-white-coed/'
,'http://lustybooks.com/erotica/9/the-blackmail-club-r-van-dorne/'
,'http://lustybooks.com/erotica/9/blackmailed-william-davis/'
,'http://lustybooks.com/erotica/9/the-blackmailed-couple-karen-ziegler/'
,'http://lustybooks.com/erotica/20/blackmailed-housewives-john-longwood/'
,'http://lustybooks.com/erotica/9/blackmailed-into-sin-peter-jensen/'
,'http://lustybooks.com/erotica/12/blackmailed-into-swapping-dana-swanson/'
,'http://lustybooks.com/erotica/19/blackmailed-swingers-jeff-collins/'
,'http://lustybooks.com/erotica/19/blackmailed-teenager-robert-vickers/'
,'http://lustybooks.com/erotica/12/blackmailed-wife-curt-aldrich/'
,'http://lustybooks.com/erotica/17/the-blackmailed-wife-peter-jensen/'
,'http://lustybooks.com/erotica/19/blackmailed-wives-j-t-watson/'
,'http://lustybooks.com/erotica/9/blackstones-cruelty-house/'
,'http://lustybooks.com/erotica/16/the-blonde-he-never-met-dan-skin/'
,'http://lustybooks.com/erotica/13/blow-girl-heather-brown/'
,'http://lustybooks.com/erotica/3/blow-harder-daughter-mark-roman/'
,'http://lustybooks.com/erotica/3/blow-the-man-down-jason-bonds/'
,'http://lustybooks.com/erotica/18/blue-movie-baby-dean-wyatt/'
,'http://lustybooks.com/erotica/9/the-boarding-house-erskine-wilder/'
,'http://lustybooks.com/erotica/11/boarding-school-bitches-brian-lake/'
,'http://lustybooks.com/erotica/6/the-body-dealer-charles-richards/'
,'http://lustybooks.com/erotica/18/bold-hot-schoolgirl-john-kellerman/'
,'http://lustybooks.com/erotica/8/bondage-bride/'
,'http://lustybooks.com/erotica/8/bondage-city-willa-hofner/'
,'http://lustybooks.com/erotica/9/bondage-discipline-perverse-passions/'
,'http://lustybooks.com/erotica/7/bondage-for-daughter-j-t-watson/'
,'http://lustybooks.com/erotica/7/bondage-for-three-wives-henry-perkins/'
,'http://lustybooks.com/erotica/6/bondage-girl-robert-vickers/'
,'http://lustybooks.com/erotica/4/bondage-heiress-raymond-rogers/'
,'http://lustybooks.com/erotica/7/bondage-mother-john-friday/'
,'http://lustybooks.com/erotica/17/bondage-payment-edward-mitchell/'
,'http://lustybooks.com/erotica/6/bondage-slave-ron-taylor/'
,'http://lustybooks.com/erotica/4/bondage-slave-niece-william-burke/'
,'http://lustybooks.com/erotica/6/bondage-slave-sister-val-marrick/'
,'http://lustybooks.com/erotica/6/bondage-slave-virgin-john-kellerman/'
,'http://lustybooks.com/erotica/5/bondage-slave-wife-john-mckeon/'
,'http://lustybooks.com/erotica/6/bondage-slaves-bob-hawkins/'
,'http://lustybooks.com/erotica/13/bondage-whore-roberta-vickers/'
,'http://lustybooks.com/erotica/4/bondage-wives-brad-boyer/'
,'http://lustybooks.com/erotica/9/bonnie-bound/'
,'http://lustybooks.com/erotica/1/bonnies-eager-in-laws-terri-duncan/'
,'http://lustybooks.com/erotica/9/the-bordello-initiation-chris-robinson/'
,'http://lustybooks.com/erotica/13/bordello-prisoner-armando-morales/'
,'http://lustybooks.com/erotica/4/bordertown-lust-david-andrews/'
,'http://lustybooks.com/erotica/18/born-to-bondage-penelope-pendergast/'
,'http://lustybooks.com/erotica/19/bosom-girl-karen-brent/'
,'http://lustybooks.com/erotica/19/bosom-girl-pamela-fuller/'
,'http://lustybooks.com/erotica/10/the-boss-daughter-jason-cannon/'
,'http://lustybooks.com/erotica/4/boss-mans-wife-george-esterville/'
,'http://lustybooks.com/erotica/17/the-boss-slave-rod-strong/'
,'http://lustybooks.com/erotica/9/the-bosss-lodge-dick-morehouse/'
,'http://lustybooks.com/erotica/9/the-bosss-mistress/'
,'http://lustybooks.com/erotica/12/the-bosss-wife-ian-roberts/'
,'http://lustybooks.com/erotica/4/both-daddy-and-my-dog-gloria-foster/'
,'http://lustybooks.com/erotica/6/bottoms-up-nieces-hal-edwards/'
,'http://lustybooks.com/erotica/17/bound-and-degraded-jeffrey-booker/'
,'http://lustybooks.com/erotica/7/bound-and-raped-cousin-paul-gable/'
,'http://lustybooks.com/erotica/5/bound-for-kicks-john-c-douglas/'
,'http://lustybooks.com/erotica/6/bound-for-torment-paul-gable/'
,'http://lustybooks.com/erotica/8/bound-hooker-willa-huffner/'
,'http://lustybooks.com/erotica/7/bound-raped-bride/'
,'http://lustybooks.com/erotica/20/bound-virgin-i-b-mann/'
,'http://lustybooks.com/erotica/7/bound-whipped-raped-schoolgirls-curt-aldrich/'
,'http://lustybooks.com/erotica/4/bound-white-slaves-will-hofner/'
,'http://lustybooks.com/erotica/10/boy-craving-wife-norma-egan/'
,'http://lustybooks.com/erotica/14/boy-hungry-aunt-pamela-james/'
,'http://lustybooks.com/erotica/10/boy-hungry-teacher-nick-eastwood/'
,'http://lustybooks.com/erotica/14/boy-loving-mother-carl-ross/'
,'http://lustybooks.com/erotica/10/boy-loving-widow-norma-egan/'
,'http://lustybooks.com/erotica/7/the-boy-next-door-kent-st-james/'
,'http://lustybooks.com/erotica/20/boy-o-alan-marshall/'
,'http://lustybooks.com/erotica/5/boy-scouts-housewife-playtoy-marty-hodman/'
,'http://lustybooks.com/erotica/18/the-boy-teaser-mark-jacobs/'
,'http://lustybooks.com/erotica/8/the-boyfriends-surprise-gail-ray/'
,'http://lustybooks.com/erotica/12/boys-camp-mother-lydia-holmes/'
,'http://lustybooks.com/erotica/15/boys-like-to-bed-her-paul-mall/'
,'http://lustybooks.com/erotica/12/boys-school-teacher-j-p-murdoch/'
,'http://lustybooks.com/erotica/13/the-breaking-of-cassie-lorimer-white/'
,'http://lustybooks.com/erotica/17/brench-whorehouse-lana-randolph/'
,'http://lustybooks.com/erotica/4/brendas-anal-lust-roger-caine/'
,'http://lustybooks.com/erotica/18/a-bride-and-her-brother-curt-aldrich/'
,'http://lustybooks.com/erotica/5/a-bride-for-the-whole-family-james-elliott/'
,'http://lustybooks.com/erotica/13/a-bride-for-torment-marshall-roberts/'
,'http://lustybooks.com/erotica/12/the-bride-next-door-kevin-sellers/'
,'http://lustybooks.com/erotica/14/brides-urge-bonnie-cockcroft/'
,'http://lustybooks.com/erotica/1/bring-your-wife-for-me-victor-karmann/'
,'http://lustybooks.com/erotica/6/bronze-bombshell/'
,'http://lustybooks.com/erotica/5/brooke-opens-up/'
,'http://lustybooks.com/erotica/10/the-brother-lover-brad-harris/'
,'http://lustybooks.com/erotica/17/brother-sister-lovers-amos-warden/'
,'http://lustybooks.com/erotica/19/the-brother-teasers-marvin-cox/'
,'http://lustybooks.com/erotica/1/brother-was-first-ray-todd/'
,'http://lustybooks.com/erotica/16/brothers-and-sisters-chuck-forel/'
,'http://lustybooks.com/erotica/20/brothers-and-sisters-ron-evans/'
,'http://lustybooks.com/erotica/17/brothers-and-sisters-charles-wykes/'
,'http://lustybooks.com/erotica/17/brothers-and-wives-bill-avery/'
,'http://lustybooks.com/erotica/3/brothers-ball-best-ray-mills/'
,'http://lustybooks.com/erotica/2/brothers-balling-family-j-t-watson/'
,'http://lustybooks.com/erotica/15/brothers-favorite-flirt-justin-thyme/'
,'http://lustybooks.com/erotica/15/brothers-having-a-ball-marge-arin/'
,'http://lustybooks.com/erotica/7/brothers-in-bondage-gregory-ouchamp/'
,'http://lustybooks.com/erotica/2/brothers-naughty-family-donna-allen/'
,'http://lustybooks.com/erotica/15/brothers-pleasure-amanda-clitton/'
,'http://lustybooks.com/erotica/9/brutal-degradation/'
,'http://lustybooks.com/erotica/7/the-brutal-world-of-gang-rapists-and-their-victims-r-t-powers/'
,'http://lustybooks.com/erotica/7/the-bugger-man-carl-lawrence/'
,'http://lustybooks.com/erotica/5/burning-desires-fred-sparkrock/'
,'http://lustybooks.com/erotica/3/butting-in-on-mom-thomas-trent/'
,'http://lustybooks.com/erotica/12/by-sin-possessed-jules-davis/'
,'http://lustybooks.com/erotica/6/caged-virgin-brad-harris/'
,'http://lustybooks.com/erotica/16/call-girl-school-andrew-shaw/'
,'http://lustybooks.com/erotica/5/call-it-gangbang-parnell-farmer/'
,'http://lustybooks.com/erotica/13/the-camp-girl-frank-anvic/'
,'http://lustybooks.com/erotica/9/camp-orgy-holly-tanner/'
,'http://lustybooks.com/erotica/19/camp-thunderbird-alan-williams/'
,'http://lustybooks.com/erotica/1/camping-with-daddy-paul-tate/'
,'http://lustybooks.com/erotica/20/campus-call-girl-scott-oneill/'
,'http://lustybooks.com/erotica/5/campus-go-go-girl-don-king/'
,'http://lustybooks.com/erotica/16/campus-sex-club-loren-beauchamp/'
,'http://lustybooks.com/erotica/12/campus-tramps-sandy-beldoe/'
,'http://lustybooks.com/erotica/6/candy-maxwell-kenton/'
,'http://lustybooks.com/erotica/7/candys-summer-of-pain-paul-loren/'
,'http://lustybooks.com/erotica/8/canine-training-school-jason-philips/'
,'http://lustybooks.com/erotica/18/cannery-girl-eleanor-gray/'
,'http://lustybooks.com/erotica/7/cant-get-satisfied-honey-steele/'
,'http://lustybooks.com/erotica/5/cant-stop-the-sex-paul-longfellow/'
,'http://lustybooks.com/erotica/12/the-captive-amazon-ian-scott/'
,'http://lustybooks.com/erotica/14/captive-aunt-donna-allen/'
,'http://lustybooks.com/erotica/12/the-captive-bank-teller-andrew-ochristopher/'
,'http://lustybooks.com/erotica/12/the-captive-bride-charles-wykes/'
,'http://lustybooks.com/erotica/13/captive-but-innocent-ralph-wiseman/'
,'http://lustybooks.com/erotica/12/captive-college-girl-lydia-holmes/'
,'http://lustybooks.com/erotica/17/captive-commuter-dick-stone/'
,'http://lustybooks.com/erotica/7/a-captive-cousin-joe-alexander/'
,'http://lustybooks.com/erotica/19/captive-daughter-richard-reed/'
,'http://lustybooks.com/erotica/19/captive-family-michael-jaegger/'
,'http://lustybooks.com/erotica/7/captive-family-in-chains-john-friday/'
,'http://lustybooks.com/erotica/12/the-captive-female-doctor-connie-lindquist/'
,'http://lustybooks.com/erotica/6/captive-housewife-heather-brown/'
,'http://lustybooks.com/erotica/12/captive-in-hong-kong-edward-mitchell/'
,'http://lustybooks.com/erotica/12/captive-in-mexico-george-morgan/'
,'http://lustybooks.com/erotica/17/captive-lady-cop-andrew-ochristopher/'
,'http://lustybooks.com/erotica/12/the-captive-lady-detective-lydia-holmes/'
,'http://lustybooks.com/erotica/12/the-captive-lady-detective-john-thomas-hardy/'
,'http://lustybooks.com/erotica/17/captive-mom-dick-stone/'
,'http://lustybooks.com/erotica/12/the-captive-mother-george-morgan/'
,'http://lustybooks.com/erotica/17/the-captive-motorist-judd-michaels/'
,'http://lustybooks.com/erotica/7/captive-niece-ted-leonard/'
,'http://lustybooks.com/erotica/12/the-captive-nurse-edward-mitchell/'
,'http://lustybooks.com/erotica/4/captive-nurses-nathan-silvers/'
,'http://lustybooks.com/erotica/13/captive-of-the-lust-master-peggy-swenson/'
,'http://lustybooks.com/erotica/13/captive-of-the-studs-ward-fulton/'
,'http://lustybooks.com/erotica/12/captive-on-lust-island-judd-michaels/'
,'http://lustybooks.com/erotica/12/the-captive-reporter-edward-mitchell/'
,'http://lustybooks.com/erotica/17/the-captive-runaway-edward-mitchell/'
,'http://lustybooks.com/erotica/17/the-captive-saleslady-rod-strong/'
,'http://lustybooks.com/erotica/5/captive-sister-val-marrick/'
,'http://lustybooks.com/erotica/17/the-captive-smuggler-rod-strong/'
,'http://lustybooks.com/erotica/6/captive-teenager-paul-gable/'
,'http://lustybooks.com/erotica/12/the-captive-amber-jameson/'
,'http://lustybooks.com/erotica/6/captive-virgin-paul-gable/'
,'http://lustybooks.com/erotica/12/the-captive-virgin-susanne-arnold/'
,'http://lustybooks.com/erotica/12/captive-weekend-judd-michaels/'
,'http://lustybooks.com/erotica/19/captive-wife-heather-brown/'
,'http://lustybooks.com/erotica/6/captive-wives-john-friday/'
,'http://lustybooks.com/erotica/6/the-captives-ann-taylor/'
,'http://lustybooks.com/erotica/12/captured-by-convicts-john-wilson/'
,'http://lustybooks.com/erotica/12/captured-by-outlaws-george-morgan/'
,'http://lustybooks.com/erotica/16/captured-by-passion-lil-lian/'
,'http://lustybooks.com/erotica/12/the-captured-family-george-morgan/'
,'http://lustybooks.com/erotica/12/the-captured-girlfriend-edward-mitchell/'
,'http://lustybooks.com/erotica/12/captured-heiress-frank-chase/'
,'http://lustybooks.com/erotica/12/captured-in-iran-graham-rogers/'
,'http://lustybooks.com/erotica/5/the-caretakers-playground-blackmail-bob-walters/'
,'http://lustybooks.com/erotica/9/carnal-clinic-james-n-berwyn/'
,'http://lustybooks.com/erotica/9/carnal-close-out-tony-calvano/'
,'http://lustybooks.com/erotica/16/carnal-encounters-lynn-sands/'
,'http://lustybooks.com/erotica/18/the-carnal-greek-rod-gaff/'
,'http://lustybooks.com/erotica/15/carols-a-comin-sam-eagerly/'
,'http://lustybooks.com/erotica/13/carpool-captive-stan-miller/'
,'http://lustybooks.com/erotica/5/a-case-of-the-hots-florence-king/'
,'http://lustybooks.com/erotica/1/casebook-incest-and-other-abnormal-sex-practices-patty-benson/'
,'http://lustybooks.com/erotica/9/casebook-sexual-show-offs-voyeurs-thrill-of-masturbation/'
,'http://lustybooks.com/erotica/1/casebook-the-incest-experience-jason-smith/'
,'http://lustybooks.com/erotica/1/casebook-the-young-sexualists-tom-brisbane/'
,'http://lustybooks.com/erotica/8/cash-for-flesh-jean-fashta/'
,'http://lustybooks.com/erotica/9/castle-of-sin-ira-ross/'
,'http://lustybooks.com/erotica/19/cathy-f-e-campbell/'
,'http://lustybooks.com/erotica/8/cats-tail-robyn-peters/'
,'http://lustybooks.com/erotica/4/caught-between-two-teens-barbara-james/'
,'http://lustybooks.com/erotica/16/caught-in-lusts-web-ben-e-boye/'
,'http://lustybooks.com/erotica/6/chain-gang-girls-john-friday/'
,'http://lustybooks.com/erotica/7/chain-whipped-bride-ted-leonard/'
,'http://lustybooks.com/erotica/7/chain-whipped-mom-paul-gable/'
,'http://lustybooks.com/erotica/7/chained-and-raped-niece-paul-gable/'
,'http://lustybooks.com/erotica/7/chained-and-raped-wife-j-t-watson/'
,'http://lustybooks.com/erotica/16/chained-by-a-cruel-mistress/'
,'http://lustybooks.com/erotica/7/chained-caged-sister-j-t-watson/'
,'http://lustybooks.com/erotica/5/chained-cheerleader-robert-vickers/'
,'http://lustybooks.com/erotica/5/chained-coed-robert-vickers/'
,'http://lustybooks.com/erotica/5/chained-daughter/'
,'http://lustybooks.com/erotica/6/chained-daughter-randy-howard/'
,'http://lustybooks.com/erotica/7/chained-daughter-roped-mother-paul-gable/'
,'http://lustybooks.com/erotica/13/chained-degredation-rod-strong/'
,'http://lustybooks.com/erotica/13/chained-loving-it-bert-rogers/'
,'http://lustybooks.com/erotica/7/chained-mother-and-daughter-j-t-watson/'
,'http://lustybooks.com/erotica/7/chained-punished-daughter-henry-perkins/'
,'http://lustybooks.com/erotica/7/chained-raped-nun-hanry-perkins/'
,'http://lustybooks.com/erotica/7/chained-slave-secretary-donna-allen/'
,'http://lustybooks.com/erotica/7/chained-slave-wife-nathan-silvers/'
,'http://lustybooks.com/erotica/15/chained-to-desire-andrea-herty/'
,'http://lustybooks.com/erotica/7/chained-tortured-nun-reverend-bob/'
,'http://lustybooks.com/erotica/7/chained-tortured-schoolgirl-paul-gable/'
,'http://lustybooks.com/erotica/4/chained-trained-nurse-nathan-silvers/'
,'http://lustybooks.com/erotica/7/chained-trained-wife-jason-bonds/'
,'http://lustybooks.com/erotica/7/chained-up-daughter-paul-gable/'
,'http://lustybooks.com/erotica/7/chained-virgin-j-t-watson/'
,'http://lustybooks.com/erotica/7/chained-virgin-sisters-nathan-silvers/'
,'http://lustybooks.com/erotica/7/chained-whipped-librarians-john-friday/'
,'http://lustybooks.com/erotica/7/chained-wife-j-t-watson/'
,'http://lustybooks.com/erotica/6/chained-women-j-t-watson/'
,'http://lustybooks.com/erotica/4/chains-for-daughter-blake-garfield/'
,'http://lustybooks.com/erotica/6/chains-for-linda-brad-boyer/'
,'http://lustybooks.com/erotica/7/chains-for-the-wife-j-t-watson/'
,'http://lustybooks.com/erotica/6/the-champs-white-chick/'
,'http://lustybooks.com/erotica/17/change-partners-marcus-van-heller/'
,'http://lustybooks.com/erotica/16/charity-ball-craig-esposito/'
,'http://lustybooks.com/erotica/19/charlenes-dirty-movie-brad-harris/'
,'http://lustybooks.com/erotica/16/chattel-castle/'
,'http://lustybooks.com/erotica/5/cheating-husband-cheating-wife-marty-balid/'
,'http://lustybooks.com/erotica/2/cheating-spouses-norma-egan/'
,'http://lustybooks.com/erotica/13/cheating-wife-jane-fox/'
,'http://lustybooks.com/erotica/17/a-cheating-wife-r-van-dorne/'
,'http://lustybooks.com/erotica/7/cheerleader-in-bondage-nathan-silvers/'
,'http://lustybooks.com/erotica/4/cheerleader-in-chains-blake-garfield/'
,'http://lustybooks.com/erotica/3/the-cheerleaders-hot-splits-victoria-parker/'
,'http://lustybooks.com/erotica/5/cherry-breakers-kent-roland/'
,'http://lustybooks.com/erotica/5/cherry-busting-brother-l-k-madding/'
,'http://lustybooks.com/erotica/5/cherry-chasers-carl-schubbe/'
,'http://lustybooks.com/erotica/8/cherrys-naughty-nights-jaye-walker/'
,'http://lustybooks.com/erotica/3/chicken-slave-rex-harper/'
,'http://lustybooks.com/erotica/4/chicks-and-older-studs-sue-varian/'
,'http://lustybooks.com/erotica/16/child-bride-tony-adams/'
,'http://lustybooks.com/erotica/9/children-as-sex-toys-for-mature-adults-roy-owen/'
,'http://lustybooks.com/erotica/11/the-childrens-governess-barry-irving/'
,'http://lustybooks.com/erotica/3/the-childrens-nursemaid/'
,'http://lustybooks.com/erotica/4/childs-play-the-family-way-harriet-ryder/'
,'http://lustybooks.com/erotica/17/chinatown-abduction-julie-howard/'
,'http://lustybooks.com/erotica/16/chopper-girl-jason-cannon/'
,'http://lustybooks.com/erotica/13/christines-lusty-summer-erica-kingston/'
,'http://lustybooks.com/erotica/1/cindy-for-swap-terri-duncan/'
,'http://lustybooks.com/erotica/15/cindy-learns-to-please-hal-usinate/'
,'http://lustybooks.com/erotica/19/cindy-needs-it-bad/'
,'http://lustybooks.com/erotica/19/cindys-new-family-james-porter/'
,'http://lustybooks.com/erotica/5/cinnamon-stick/'
,'http://lustybooks.com/erotica/9/the-city-cousin/'
,'http://lustybooks.com/erotica/5/city-slut-william-karp/'
,'http://lustybooks.com/erotica/5/class-ass-michael-corbin/'
,'http://lustybooks.com/erotica/12/the-classroom-party-ted-bradford/'
,'http://lustybooks.com/erotica/7/club-kink-darian-thomas/'
,'http://lustybooks.com/erotica/16/co-ed-hooker/'
,'http://lustybooks.com/erotica/17/the-co-eds-punished-mother-mel-crowson/'
,'http://lustybooks.com/erotica/19/the-coachs-wife-norma-egan/'
,'http://lustybooks.com/erotica/8/coed-camp-john-romero/'
,'http://lustybooks.com/erotica/6/coed-in-chains-robert-vickers/'
,'http://lustybooks.com/erotica/5/coed-sluts-tabitha-briton/'
,'http://lustybooks.com/erotica/12/the-coeds-torment-byron-jackson/'
,'http://lustybooks.com/erotica/20/the-coeds-wild-field-trip-robert-vickers/'
,'http://lustybooks.com/erotica/5/coffee-tea-and-ecstasy-wilma-tarrant/'
,'http://lustybooks.com/erotica/18/a-college-girls-education-bill-gillie/'
,'http://lustybooks.com/erotica/17/college-girls-slavery-sharon-farmer/'
,'http://lustybooks.com/erotica/4/color-her-hot-lester-lake/'
,'http://lustybooks.com/erotica/7/come-again-robin-peters/'
,'http://lustybooks.com/erotica/2/come-and-get-it-dad-ray-todd/'
,'http://lustybooks.com/erotica/8/come-find-cindy-jerri-mahoney/'
,'http://lustybooks.com/erotica/11/come-meet-my-mom-kathy-andrews/'
,'http://lustybooks.com/erotica/8/come-to-mother-sylvia-garth/'
,'http://lustybooks.com/erotica/3/come-wifey-come-donna-allen/'
,'http://lustybooks.com/erotica/14/come-with-me-dad-j-t-watson/'
,'http://lustybooks.com/erotica/4/come-with-me-daddy-charlene-colnett/'
,'http://lustybooks.com/erotica/14/come-with-mom-don-scott/'
,'http://lustybooks.com/erotica/14/coming-mother-kathy-andrews/'
,'http://lustybooks.com/erotica/12/coming-on-teacher-frank-brown/'
,'http://lustybooks.com/erotica/3/coming-onto-mom-kathy-andrews/'
,'http://lustybooks.com/erotica/11/coming-through-the-rye-gene-r-bowman/'
,'http://lustybooks.com/erotica/9/coming-with-daddy-warren-bisig/'
,'http://lustybooks.com/erotica/14/coming-with-mom-kathy-andrews/'
,'http://lustybooks.com/erotica/10/coming-with-mom-mark-jacobs/'
,'http://lustybooks.com/erotica/2/coming-with-the-family-ray-todd/'
,'http://lustybooks.com/erotica/8/commie-sex-trap-roger-blake/'
,'http://lustybooks.com/erotica/16/communal-orgies-greg-pearson/'
,'http://lustybooks.com/erotica/9/the-company-doctor-monte-larden/'
,'http://lustybooks.com/erotica/18/company-slaves-russ-miller/'
,'http://lustybooks.com/erotica/18/the-companys-special-girls-jane-dawson/'
,'http://lustybooks.com/erotica/19/competing-with-mom-jason-cannon/'
,'http://lustybooks.com/erotica/4/the-compulsive-analist-kathy-breen/'
,'http://lustybooks.com/erotica/2/the-condo-swappers-hank-borden/'
,'http://lustybooks.com/erotica/11/confessions-of-a-french-countess/'
,'http://lustybooks.com/erotica/5/confessions-of-a-modern-satyr-odell-brown/'
,'http://lustybooks.com/erotica/17/confessions-of-a-private-dick-timothy-lea/'
,'http://lustybooks.com/erotica/6/connies-stud/'
,'http://lustybooks.com/erotica/18/convent-school-virgin-jack-grant/'
,'http://lustybooks.com/erotica/9/convention-hookers-ellen-evans/'
,'http://lustybooks.com/erotica/9/the-convicts-teen-hostage-h-b-kinney/'
,'http://lustybooks.com/erotica/5/cop-rape-jill-cantner/'
,'http://lustybooks.com/erotica/3/cornholded-nurses-sheldon-asamir/'
,'http://lustybooks.com/erotica/12/the-corporate-doctor-c-r-calvary/'
,'http://lustybooks.com/erotica/17/the-corrupted-wife-jon-larson/'
,'http://lustybooks.com/erotica/11/corruption-peter-finchley/'
,'http://lustybooks.com/erotica/18/corruption-crossroads-mark-carver/'
,'http://lustybooks.com/erotica/9/the-counselors-sex-games-jack-marlow/'
,'http://lustybooks.com/erotica/11/country-club-widows-james-elliott/'
,'http://lustybooks.com/erotica/9/country-doctor-terry-baer/'
,'http://lustybooks.com/erotica/13/country-girl-in-town-wesley-brighton-jr/'
,'http://lustybooks.com/erotica/8/country-kicks-bob-novada/'
,'http://lustybooks.com/erotica/1/country-wife-j-s-bradley/'
,'http://lustybooks.com/erotica/2/cousin-blew-them-all-kathy-harris/'
,'http://lustybooks.com/erotica/10/cousin-comes-first-nick-eastwood/'
,'http://lustybooks.com/erotica/4/cousin-in-bondage-blake-garfield/'
,'http://lustybooks.com/erotica/3/cousins-coming-together-harry-stevens/'
,'http://lustybooks.com/erotica/3/the-cousins-eat-out-victoria-parker/'
,'http://lustybooks.com/erotica/19/cousins-in-heat-pamela-james/'
,'http://lustybooks.com/erotica/11/cozy-country-club-rand-mctiernan/'
,'http://lustybooks.com/erotica/4/crazy-for-rope/'
,'http://lustybooks.com/erotica/11/cross-dressing-daddy/'
,'http://lustybooks.com/erotica/7/crucified-chained-nun-john-friday/'
,'http://lustybooks.com/erotica/6/cruel-lips-marcus-van-heller/'
,'http://lustybooks.com/erotica/8/cry-uncle-jay-wood/'
,'http://lustybooks.com/erotica/17/cuban-capture-carlos-juarez/'
]

outfile = open("test_txt3", "w")

class Polly(Crawler): 
    def visit(self, link, source=None):
        #        print 'visited:', repr(link.url), 'from:', link.referrer
        if "/p" in repr(link.url):
            #print repr(link.url)
            s = URL(link.url).download()
            s = plaintext(s, keep={})
            print s.encode('utf-8') # append to file?
            outfile.write(s.encode('utf-8'))
        
        def fail(self, link):
            print 'failed:', repr(link.url)

for list in listy:
    # p = Polly(links=list, delay=1)
    #while not p.done:
    #    p.crawl(method=1, cached=True, throttle=1)
    for xx in range(1,30):
        try:
            lister=str(list)+"p-"+str(xx)+".html"
            #        print(list)
            s = URL(lister).download()
            s = plaintext(s, keep={})
            print s.encode('utf-8') # append to file?
            outfile.write(s.encode('utf-8'))
        except:
            print ""
            
# s = URL('http://lustybooks.com/erotica/6/party-wife-rex-weldon/p-6.html').download()
# s = plaintext(s, keep={})

# print s.encode('utf-8')

# # save as file

# outfile = open("test_txt", "w")
# outfile.write(s.encode('utf-8'))
outfile.close()
