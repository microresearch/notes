EESchema Schematic File Version 4
LIBS:finalsessioneurorack-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 2825 225  0    197  ~ 0
cgs 26 analog logic and mixer
Text Notes 1750 5075 0    197  ~ 0
buffers
$Comp
L Amplifier_Operational:TL072 U2
U 1 1 5C34897E
P 2800 2225
F 0 "U2" H 2800 2592 50  0000 C CNN
F 1 "TL072" H 2800 2501 50  0000 C CNN
F 2 "Housings_DIP:DIP-8_W7.62mm" H 2800 2225 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 2800 2225 50  0001 C CNN
	1    2800 2225
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R4
U 1 1 5C348DB0
P 1875 975
F 0 "R4" V 2071 975 50  0000 C CNN
F 1 "270K" V 1980 975 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 1875 975 50  0001 C CNN
F 3 "~" H 1875 975 50  0001 C CNN
	1    1875 975 
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C1
U 1 1 5C348E20
P 2825 2875
F 0 "C1" V 3054 2875 50  0000 C CNN
F 1 "47pF" V 2963 2875 50  0000 C CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 2825 2875 50  0001 C CNN
F 3 "~" H 2825 2875 50  0001 C CNN
	1    2825 2875
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_POT RV1
U 1 1 5C348F5D
P 850 1400
F 0 "RV1" H 780 1446 50  0000 R CNN
F 1 "100K" H 780 1355 50  0000 R CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 850 1400 50  0001 C CNN
F 3 "~" H 850 1400 50  0001 C CNN
	1    850  1400
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL072 U1
U 1 1 5C349109
P 1425 5675
F 0 "U1" H 1425 6042 50  0000 C CNN
F 1 "TL072" H 1425 5951 50  0000 C CNN
F 2 "Housings_DIP:DIP-8_W7.62mm" H 1425 5675 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 1425 5675 50  0001 C CNN
	1    1425 5675
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Small D1
U 1 1 5C3499B5
P 2050 1075
F 0 "D1" V 2004 1143 50  0000 L CNN
F 1 "BAT48" V 2095 1143 50  0000 L CNN
F 2 "Diodes_ThroughHole:D_DO-35_SOD27_P10.16mm_Horizontal" V 2050 1075 50  0001 C CNN
F 3 "~" V 2050 1075 50  0001 C CNN
	1    2050 1075
	0    1    1    0   
$EndComp
$Comp
L Device:D_Small D2
U 1 1 5C349A85
P 2225 1075
F 0 "D2" V 2271 1007 50  0000 R CNN
F 1 "BAT48" V 2180 1007 50  0000 R CNN
F 2 "Diodes_ThroughHole:D_DO-35_SOD27_P10.16mm_Horizontal" V 2225 1075 50  0001 C CNN
F 3 "~" V 2225 1075 50  0001 C CNN
	1    2225 1075
	0    -1   -1   0   
$EndComp
$Comp
L power:-12V #PWR04
U 1 1 5C34A1DA
P 850 1600
F 0 "#PWR04" H 850 1700 50  0001 C CNN
F 1 "-12V" H 865 1773 50  0000 C CNN
F 2 "" H 850 1600 50  0001 C CNN
F 3 "" H 850 1600 50  0001 C CNN
	1    850  1600
	-1   0    0    1   
$EndComp
$Comp
L Device:R_POT RV4
U 1 1 5C34A353
P 1550 975
F 0 "RV4" H 1480 1021 50  0000 R CNN
F 1 "100K" H 1480 930 50  0000 R CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 1550 975 50  0001 C CNN
F 3 "~" H 1550 975 50  0001 C CNN
	1    1550 975 
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR08
U 1 1 5C34A359
P 1550 1175
F 0 "#PWR08" H 1550 1275 50  0001 C CNN
F 1 "-12V" H 1565 1348 50  0000 C CNN
F 2 "" H 1550 1175 50  0001 C CNN
F 3 "" H 1550 1175 50  0001 C CNN
	1    1550 1175
	-1   0    0    1   
$EndComp
$Comp
L power:+12V #PWR07
U 1 1 5C34A38E
P 1550 750
F 0 "#PWR07" H 1550 600 50  0001 C CNN
F 1 "+12V" H 1565 923 50  0000 C CNN
F 2 "" H 1550 750 50  0001 C CNN
F 3 "" H 1550 750 50  0001 C CNN
	1    1550 750 
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 750  1550 825 
Wire Wire Line
	1700 975  1775 975 
Wire Wire Line
	1975 975  2050 975 
Wire Wire Line
	2050 975  2225 975 
Connection ~ 2050 975 
Wire Wire Line
	1550 1125 1550 1175
Wire Wire Line
	850  1550 850  1600
$Comp
L Device:R_Small R1
U 1 1 5C34B32D
P 1150 1400
F 0 "R1" V 1346 1400 50  0000 C CNN
F 1 "100K" V 1255 1400 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 1150 1400 50  0001 C CNN
F 3 "~" H 1150 1400 50  0001 C CNN
	1    1150 1400
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R7
U 1 1 5C34B3D4
P 2825 2625
F 0 "R7" V 3021 2625 50  0000 C CNN
F 1 "100K" V 2930 2625 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 2825 2625 50  0001 C CNN
F 3 "~" H 2825 2625 50  0001 C CNN
	1    2825 2625
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR011
U 1 1 5C34B4EA
P 2400 2125
F 0 "#PWR011" H 2400 1875 50  0001 C CNN
F 1 "GND" H 2405 1952 50  0000 C CNN
F 2 "" H 2400 2125 50  0001 C CNN
F 3 "" H 2400 2125 50  0001 C CNN
	1    2400 2125
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R8
U 1 1 5C34B6E4
P 3275 2225
F 0 "R8" V 3471 2225 50  0000 C CNN
F 1 "330R" V 3380 2225 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 3275 2225 50  0001 C CNN
F 3 "~" H 3275 2225 50  0001 C CNN
	1    3275 2225
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R9
U 1 1 5C34B7B6
P 3525 2225
F 0 "R9" V 3721 2225 50  0000 C CNN
F 1 "100K" V 3630 2225 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 3525 2225 50  0001 C CNN
F 3 "~" H 3525 2225 50  0001 C CNN
	1    3525 2225
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2400 2125 2500 2125
Wire Wire Line
	2500 2625 2725 2625
Wire Wire Line
	2500 2625 2500 2875
Wire Wire Line
	2500 2875 2725 2875
Connection ~ 2500 2625
Wire Wire Line
	3100 2225 3175 2225
Wire Wire Line
	2925 2625 3375 2625
Wire Wire Line
	2925 2875 3375 2875
Wire Wire Line
	3375 2225 3375 2625
Connection ~ 3375 2625
Wire Wire Line
	3375 2625 3375 2875
$Comp
L Amplifier_Operational:TL072 U2
U 2 1 5C34BC5D
P 4025 2125
F 0 "U2" H 4025 2492 50  0000 C CNN
F 1 "TL072" H 4025 2401 50  0000 C CNN
F 2 "Housings_DIP:DIP-8_W7.62mm" H 4025 2125 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 4025 2125 50  0001 C CNN
	2    4025 2125
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C4
U 1 1 5C34BC63
P 4050 2775
F 0 "C4" V 4279 2775 50  0000 C CNN
F 1 "47pF" V 4188 2775 50  0000 C CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 4050 2775 50  0001 C CNN
F 3 "~" H 4050 2775 50  0001 C CNN
	1    4050 2775
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R10
U 1 1 5C34BC69
P 4050 2525
F 0 "R10" V 4246 2525 50  0000 C CNN
F 1 "100K" V 4155 2525 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4050 2525 50  0001 C CNN
F 3 "~" H 4050 2525 50  0001 C CNN
	1    4050 2525
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR012
U 1 1 5C34BC6F
P 3625 2025
F 0 "#PWR012" H 3625 1775 50  0001 C CNN
F 1 "GND" H 3630 1852 50  0000 C CNN
F 2 "" H 3625 2025 50  0001 C CNN
F 3 "" H 3625 2025 50  0001 C CNN
	1    3625 2025
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R11
U 1 1 5C34BC75
P 4500 2125
F 0 "R11" V 4696 2125 50  0000 C CNN
F 1 "330R" V 4605 2125 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 4500 2125 50  0001 C CNN
F 3 "~" H 4500 2125 50  0001 C CNN
	1    4500 2125
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3625 2025 3725 2025
Wire Wire Line
	3725 2525 3950 2525
Wire Wire Line
	3725 2525 3725 2775
Wire Wire Line
	3725 2775 3950 2775
Connection ~ 3725 2525
Wire Wire Line
	4325 2125 4400 2125
Wire Wire Line
	4150 2525 4600 2525
Wire Wire Line
	4150 2775 4600 2775
Wire Wire Line
	4600 2125 4600 2525
Connection ~ 4600 2525
Wire Wire Line
	4600 2525 4600 2775
Wire Wire Line
	2500 2325 2500 2425
Wire Wire Line
	3725 2225 3725 2525
Wire Wire Line
	3375 2225 3425 2225
Connection ~ 3375 2225
Wire Wire Line
	3625 2225 3725 2225
Connection ~ 3725 2225
$Comp
L Device:R_POT RV5
U 1 1 5C34DE3E
P 2575 3450
F 0 "RV5" V 2368 3450 50  0000 C CNN
F 1 "100K" V 2459 3450 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 2575 3450 50  0001 C CNN
F 3 "~" H 2575 3450 50  0001 C CNN
	1    2575 3450
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R5
U 1 1 5C34E009
P 2325 3600
F 0 "R5" V 2521 3600 50  0000 C CNN
F 1 "100K" V 2430 3600 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 2325 3600 50  0001 C CNN
F 3 "~" H 2325 3600 50  0001 C CNN
	1    2325 3600
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2150 3600 2225 3600
$Comp
L Device:R_POT RV6
U 1 1 5C34F61A
P 2575 4275
F 0 "RV6" V 2368 4275 50  0000 C CNN
F 1 "100K" V 2459 4275 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 2575 4275 50  0001 C CNN
F 3 "~" H 2575 4275 50  0001 C CNN
	1    2575 4275
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R6
U 1 1 5C34F620
P 2325 4425
F 0 "R6" V 2521 4425 50  0000 C CNN
F 1 "100K" V 2430 4425 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 2325 4425 50  0001 C CNN
F 3 "~" H 2325 4425 50  0001 C CNN
	1    2325 4425
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2150 4425 2225 4425
Wire Wire Line
	2425 4425 2575 4425
Wire Wire Line
	3725 3450 3725 2775
Wire Wire Line
	2725 3450 3725 3450
Connection ~ 3725 2775
Wire Wire Line
	2725 4275 3725 4275
Wire Wire Line
	3725 4275 3725 3450
Connection ~ 3725 3450
Wire Wire Line
	2425 3450 2425 2950
Wire Wire Line
	2425 2425 2500 2425
Connection ~ 2500 2425
Wire Wire Line
	2500 2425 2500 2625
Connection ~ 2425 3450
Wire Wire Line
	2425 3600 2575 3600
Wire Wire Line
	2425 3450 2425 3600
Wire Wire Line
	2050 1175 2125 1175
Connection ~ 2425 3600
Wire Wire Line
	2425 3600 2425 4275
Wire Wire Line
	725  1250 850  1250
Wire Wire Line
	1000 1400 1050 1400
$Comp
L Device:R_POT RV2
U 1 1 5C35B0C5
P 850 2550
F 0 "RV2" H 780 2596 50  0000 R CNN
F 1 "100K" H 780 2505 50  0000 R CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 850 2550 50  0001 C CNN
F 3 "~" H 850 2550 50  0001 C CNN
	1    850  2550
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR05
U 1 1 5C35B0CB
P 850 2750
F 0 "#PWR05" H 850 2850 50  0001 C CNN
F 1 "-12V" H 865 2923 50  0000 C CNN
F 2 "" H 850 2750 50  0001 C CNN
F 3 "" H 850 2750 50  0001 C CNN
	1    850  2750
	-1   0    0    1   
$EndComp
Wire Wire Line
	850  2700 850  2750
$Comp
L Device:R_Small R2
U 1 1 5C35B0D8
P 1150 2550
F 0 "R2" V 1346 2550 50  0000 C CNN
F 1 "100K" V 1255 2550 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 1150 2550 50  0001 C CNN
F 3 "~" H 1150 2550 50  0001 C CNN
	1    1150 2550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	725  2400 850  2400
Wire Wire Line
	1000 2550 1050 2550
$Comp
L Device:R_POT RV3
U 1 1 5C35BF88
P 875 3800
F 0 "RV3" H 805 3846 50  0000 R CNN
F 1 "100K" H 805 3755 50  0000 R CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 875 3800 50  0001 C CNN
F 3 "~" H 875 3800 50  0001 C CNN
	1    875  3800
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR06
U 1 1 5C35BF8E
P 875 4000
F 0 "#PWR06" H 875 4100 50  0001 C CNN
F 1 "-12V" H 890 4173 50  0000 C CNN
F 2 "" H 875 4000 50  0001 C CNN
F 3 "" H 875 4000 50  0001 C CNN
	1    875  4000
	-1   0    0    1   
$EndComp
Wire Wire Line
	875  3950 875  4000
$Comp
L Device:R_Small R3
U 1 1 5C35BF9B
P 1175 3800
F 0 "R3" V 1371 3800 50  0000 C CNN
F 1 "100K" V 1280 3800 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" H 1175 3800 50  0001 C CNN
F 3 "~" H 1175 3800 50  0001 C CNN
	1    1175 3800
	0    -1   -1   0   
$EndComp
Wire Wire Line
	750  3650 875  3650
Wire Wire Line
	1025 3800 1075 3800
Wire Wire Line
	2125 1175 2125 1400
Wire Wire Line
	2125 2950 2425 2950
Connection ~ 2125 1175
Wire Wire Line
	2125 1175 2225 1175
Connection ~ 2425 2950
Wire Wire Line
	2425 2950 2425 2425
Connection ~ 2125 1400
Wire Wire Line
	2125 1400 2125 2550
Wire Wire Line
	1250 2550 1375 2550
Connection ~ 2125 2550
Wire Wire Line
	2125 2550 2125 2950
Wire Wire Line
	1275 3800 1375 3800
Wire Wire Line
	1375 3800 1375 2550
Connection ~ 1375 2550
Wire Wire Line
	1375 2550 2125 2550
Wire Wire Line
	4600 2125 4825 2125
Connection ~ 4600 2125
$Comp
L Amplifier_Operational:TL072 U2
U 3 1 5C374B88
P 5325 5450
F 0 "U2" H 5283 5496 50  0000 L CNN
F 1 "TL072" H 5283 5405 50  0000 L CNN
F 2 "Housings_DIP:DIP-8_W7.62mm" H 5325 5450 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 5325 5450 50  0001 C CNN
	3    5325 5450
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C5
U 1 1 5C374B8E
P 5550 5250
F 0 "C5" H 5642 5296 50  0000 L CNN
F 1 "100n" H 5642 5205 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 5550 5250 50  0001 C CNN
F 3 "~" H 5550 5250 50  0001 C CNN
	1    5550 5250
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C6
U 1 1 5C374B94
P 5550 5650
F 0 "C6" H 5800 5375 50  0000 L CNN
F 1 "100n" H 5642 5605 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 5550 5650 50  0001 C CNN
F 3 "~" H 5550 5650 50  0001 C CNN
	1    5550 5650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR018
U 1 1 5C374B9A
P 5675 5425
F 0 "#PWR018" H 5675 5175 50  0001 C CNN
F 1 "GND" H 5680 5252 50  0000 C CNN
F 2 "" H 5675 5425 50  0001 C CNN
F 3 "" H 5675 5425 50  0001 C CNN
	1    5675 5425
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR016
U 1 1 5C374BA0
P 5550 4975
F 0 "#PWR016" H 5550 4825 50  0001 C CNN
F 1 "+12V" H 5565 5148 50  0000 C CNN
F 2 "" H 5550 4975 50  0001 C CNN
F 3 "" H 5550 4975 50  0001 C CNN
	1    5550 4975
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR017
U 1 1 5C374BA6
P 5550 5800
F 0 "#PWR017" H 5550 5900 50  0001 C CNN
F 1 "-12V" H 5565 5973 50  0000 C CNN
F 2 "" H 5550 5800 50  0001 C CNN
F 3 "" H 5550 5800 50  0001 C CNN
	1    5550 5800
	-1   0    0    1   
$EndComp
Wire Wire Line
	5550 5150 5550 4975
Wire Wire Line
	5225 5150 5550 5150
Connection ~ 5550 5150
Wire Wire Line
	5550 5550 5550 5425
Wire Wire Line
	5550 5425 5675 5425
Connection ~ 5550 5425
Wire Wire Line
	5550 5425 5550 5350
Wire Wire Line
	5550 5750 5550 5800
Wire Wire Line
	5225 5750 5550 5750
Connection ~ 5550 5750
$Comp
L Amplifier_Operational:TL072 U3
U 3 1 5C37FE25
P 6100 5425
F 0 "U3" H 6058 5471 50  0000 L CNN
F 1 "TL072" H 6058 5380 50  0000 L CNN
F 2 "Housings_DIP:DIP-8_W7.62mm" H 6100 5425 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 6100 5425 50  0001 C CNN
	3    6100 5425
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C7
U 1 1 5C37FE2B
P 6325 5225
F 0 "C7" H 6417 5271 50  0000 L CNN
F 1 "100n" H 6417 5180 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 6325 5225 50  0001 C CNN
F 3 "~" H 6325 5225 50  0001 C CNN
	1    6325 5225
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C8
U 1 1 5C37FE31
P 6325 5625
F 0 "C8" H 6525 5400 50  0000 L CNN
F 1 "100n" H 6417 5580 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 6325 5625 50  0001 C CNN
F 3 "~" H 6325 5625 50  0001 C CNN
	1    6325 5625
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR024
U 1 1 5C37FE37
P 6450 5400
F 0 "#PWR024" H 6450 5150 50  0001 C CNN
F 1 "GND" H 6455 5227 50  0000 C CNN
F 2 "" H 6450 5400 50  0001 C CNN
F 3 "" H 6450 5400 50  0001 C CNN
	1    6450 5400
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR022
U 1 1 5C37FE3D
P 6325 4950
F 0 "#PWR022" H 6325 4800 50  0001 C CNN
F 1 "+12V" H 6340 5123 50  0000 C CNN
F 2 "" H 6325 4950 50  0001 C CNN
F 3 "" H 6325 4950 50  0001 C CNN
	1    6325 4950
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR023
U 1 1 5C37FE43
P 6325 5775
F 0 "#PWR023" H 6325 5875 50  0001 C CNN
F 1 "-12V" H 6340 5948 50  0000 C CNN
F 2 "" H 6325 5775 50  0001 C CNN
F 3 "" H 6325 5775 50  0001 C CNN
	1    6325 5775
	-1   0    0    1   
$EndComp
Wire Wire Line
	6325 5125 6325 4950
Wire Wire Line
	6000 5125 6325 5125
Connection ~ 6325 5125
Wire Wire Line
	6325 5525 6325 5400
Wire Wire Line
	6325 5400 6450 5400
Connection ~ 6325 5400
Wire Wire Line
	6325 5400 6325 5325
Wire Wire Line
	6325 5725 6325 5775
Wire Wire Line
	6000 5725 6325 5725
Connection ~ 6325 5725
Wire Wire Line
	1125 5775 1125 6075
Wire Wire Line
	1125 6075 1725 6075
Wire Wire Line
	1725 6075 1725 5675
Wire Wire Line
	1250 1400 2125 1400
$Comp
L Amplifier_Operational:TL072 U3
U 1 1 5C3A0951
P 2525 5600
F 0 "U3" H 2525 5967 50  0000 C CNN
F 1 "TL072" H 2525 5876 50  0000 C CNN
F 2 "Housings_DIP:DIP-8_W7.62mm" H 2525 5600 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 2525 5600 50  0001 C CNN
	1    2525 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2225 5700 2225 6000
Wire Wire Line
	2225 6000 2825 6000
Wire Wire Line
	2825 6000 2825 5600
$Comp
L Amplifier_Operational:TL072 U1
U 2 1 5C3A38A1
P 1400 6450
F 0 "U1" H 1400 6817 50  0000 C CNN
F 1 "TL072" H 1400 6726 50  0000 C CNN
F 2 "Housings_DIP:DIP-8_W7.62mm" H 1400 6450 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 1400 6450 50  0001 C CNN
	2    1400 6450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 6550 1100 6850
Wire Wire Line
	1100 6850 1700 6850
Wire Wire Line
	1700 6850 1700 6450
Wire Wire Line
	1700 6450 1900 6450
Connection ~ 1700 6450
$Comp
L Amplifier_Operational:TL072 U3
U 2 1 5C3A38C7
P 2725 6550
F 0 "U3" H 2725 6917 50  0000 C CNN
F 1 "TL072" H 2725 6826 50  0000 C CNN
F 2 "Housings_DIP:DIP-8_W7.62mm" H 2725 6550 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 2725 6550 50  0001 C CNN
	2    2725 6550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2425 6650 2425 6950
Wire Wire Line
	2425 6950 3025 6950
Wire Wire Line
	3025 6950 3025 6550
Wire Wire Line
	2250 6450 2425 6450
$Sheet
S 6995 5100 1375 450 
U 5C3AF132
F0 "eurorack_power" 50
F1 "eurorack_power.sch" 50
$EndSheet
$Sheet
S 6990 5965 1670 325 
U 5C3C0830
F0 "analogue logic" 50
F1 "analogic.sch" 50
$EndSheet
Text Label 725  1250 2    50   ~ 0
INN_1
Text Label 725  2400 2    50   ~ 0
INN_2
Text Label 750  3650 2    50   ~ 0
INN_3
Text Label 2150 3600 2    50   ~ 0
P1
Text Label 2150 4425 2    50   ~ 0
P2
Wire Wire Line
	2825 5600 3025 5600
Wire Wire Line
	3025 5600 3025 5625
Connection ~ 2825 5600
Wire Wire Line
	3025 6550 3325 6550
Wire Wire Line
	3325 6550 3325 6525
Connection ~ 3025 6550
Wire Wire Line
	1725 5675 1925 5675
Connection ~ 1725 5675
Wire Wire Line
	2225 5500 2125 5500
Wire Wire Line
	1100 6350 975  6350
Wire Wire Line
	975  6350 975  6325
Wire Wire Line
	1125 5575 950  5575
Text Label 950  5575 2    50   ~ 0
INBUF1
Text Label 975  6325 2    50   ~ 0
INBUF2
Text Label 2125 5500 2    50   ~ 0
INBUF3
Text Label 2250 6450 2    50   ~ 0
INBUF4
Text Label 1925 5675 0    50   ~ 0
OBUFF1
Text Label 1900 6450 1    50   ~ 0
OBUFF2
Text Label 3025 5625 0    50   ~ 0
OBUFF3
Text Label 3325 6525 0    50   ~ 0
OBUFF4
$Comp
L Connector:Conn_01x08_Male J5
U 1 1 5C575E4F
P 7425 3150
F 0 "J5" H 7398 3030 50  0000 R CNN
F 1 "Conn_01x08_Male" H 7398 3121 50  0000 R CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08_Pitch2.54mm" H 7425 3150 50  0001 C CNN
F 3 "~" H 7425 3150 50  0001 C CNN
	1    7425 3150
	-1   0    0    1   
$EndComp
Wire Wire Line
	7225 2750 7025 2750
Text Label 7025 2750 2    50   ~ 0
INBUF1
Text Label 7025 2850 2    50   ~ 0
INBUF2
Text Label 7025 2950 2    50   ~ 0
INBUF3
Text Label 7025 3050 2    50   ~ 0
INBUF4
Wire Wire Line
	7025 2850 7225 2850
Wire Wire Line
	7025 2950 7225 2950
Wire Wire Line
	7025 3050 7225 3050
Wire Wire Line
	7025 3150 7225 3150
Wire Wire Line
	7025 3250 7225 3250
Wire Wire Line
	7025 3350 7225 3350
Wire Wire Line
	7025 3450 7225 3450
Text Label 7025 3150 2    50   ~ 0
OBUFF1
Text Label 7025 3250 2    50   ~ 0
OBUFF2
Text Label 7025 3350 2    50   ~ 0
OBUFF3
Text Label 7025 3450 2    50   ~ 0
OBUFF4
$Comp
L Connector:Conn_01x08_Male J3
U 1 1 5C5951A6
P 7175 4025
F 0 "J3" H 7281 4503 50  0000 C CNN
F 1 "Conn_01x08_Male" H 7281 4412 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08_Pitch2.54mm" H 7175 4025 50  0001 C CNN
F 3 "~" H 7175 4025 50  0001 C CNN
	1    7175 4025
	1    0    0    -1  
$EndComp
Wire Wire Line
	7375 3725 7375 3825
Wire Wire Line
	7375 3925 7375 3825
Connection ~ 7375 3825
Wire Wire Line
	7375 3925 7375 4000
Connection ~ 7375 3925
Wire Wire Line
	7375 4025 7375 4125
Connection ~ 7375 4025
Wire Wire Line
	7375 4125 7375 4225
Connection ~ 7375 4125
Wire Wire Line
	7375 4225 7375 4325
Wire Wire Line
	7375 4325 7375 4425
Connection ~ 7375 4225
Connection ~ 7375 4325
$Comp
L power:GND #PWR021
U 1 1 5C5C8FDA
P 7550 4000
F 0 "#PWR021" H 7550 3750 50  0001 C CNN
F 1 "GND" H 7555 3827 50  0000 C CNN
F 2 "" H 7550 4000 50  0001 C CNN
F 3 "" H 7550 4000 50  0001 C CNN
	1    7550 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7375 4000 7550 4000
Connection ~ 7375 4000
Wire Wire Line
	7375 4000 7375 4025
$Comp
L Amplifier_Operational:TL072 U1
U 3 1 5C5DE0E7
P 3750 5425
F 0 "U1" H 3708 5471 50  0000 L CNN
F 1 "TL072" H 3708 5380 50  0000 L CNN
F 2 "Housings_DIP:DIP-8_W7.62mm" H 3750 5425 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 3750 5425 50  0001 C CNN
	3    3750 5425
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C23
U 1 1 5C5DE0ED
P 3975 5225
F 0 "C23" H 4067 5271 50  0000 L CNN
F 1 "100n" H 4067 5180 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 3975 5225 50  0001 C CNN
F 3 "~" H 3975 5225 50  0001 C CNN
	1    3975 5225
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C24
U 1 1 5C5DE0F3
P 3975 5625
F 0 "C24" H 4067 5671 50  0000 L CNN
F 1 "100n" H 4067 5580 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 3975 5625 50  0001 C CNN
F 3 "~" H 3975 5625 50  0001 C CNN
	1    3975 5625
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5C5DE0F9
P 4100 5400
F 0 "#PWR0101" H 4100 5150 50  0001 C CNN
F 1 "GND" H 4105 5227 50  0000 C CNN
F 2 "" H 4100 5400 50  0001 C CNN
F 3 "" H 4100 5400 50  0001 C CNN
	1    4100 5400
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0102
U 1 1 5C5DE0FF
P 3975 4950
F 0 "#PWR0102" H 3975 4800 50  0001 C CNN
F 1 "+12V" H 3990 5123 50  0000 C CNN
F 2 "" H 3975 4950 50  0001 C CNN
F 3 "" H 3975 4950 50  0001 C CNN
	1    3975 4950
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR0103
U 1 1 5C5DE105
P 3975 5775
F 0 "#PWR0103" H 3975 5875 50  0001 C CNN
F 1 "-12V" H 3990 5948 50  0000 C CNN
F 2 "" H 3975 5775 50  0001 C CNN
F 3 "" H 3975 5775 50  0001 C CNN
	1    3975 5775
	-1   0    0    1   
$EndComp
Wire Wire Line
	3975 5125 3975 4950
Wire Wire Line
	3650 5125 3975 5125
Connection ~ 3975 5125
Wire Wire Line
	3975 5525 3975 5400
Wire Wire Line
	3975 5400 4100 5400
Connection ~ 3975 5400
Wire Wire Line
	3975 5400 3975 5325
Wire Wire Line
	3975 5725 3975 5775
Wire Wire Line
	3650 5725 3975 5725
Connection ~ 3975 5725
Text Label 4825 2125 0    50   ~ 0
OUTT_1
$Comp
L Connector:Conn_01x06_Male J4
U 1 1 5C60713C
P 6925 2225
F 0 "J4" H 6898 2105 50  0000 R CNN
F 1 "Conn_01x06_Male" H 6898 2196 50  0000 R CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x06_Pitch2.54mm" H 6925 2225 50  0001 C CNN
F 3 "~" H 6925 2225 50  0001 C CNN
	1    6925 2225
	-1   0    0    1   
$EndComp
Text Notes 3000 1375 2    50   ~ 0
x2 on PCB only
Wire Wire Line
	6725 1925 6625 1925
Wire Wire Line
	6725 2025 6625 2025
Wire Wire Line
	6725 2125 6625 2125
Wire Wire Line
	6725 2225 6625 2225
Wire Wire Line
	6725 2325 6625 2325
Wire Wire Line
	6725 2425 6625 2425
Text Label 6625 1925 2    50   ~ 0
INN_1
Text Label 6625 2025 2    50   ~ 0
INN_2
Text Label 6625 2125 2    50   ~ 0
INN_3
Text Label 6625 2225 2    50   ~ 0
P1
Text Label 6625 2325 2    50   ~ 0
P2
Text Label 6625 2425 2    50   ~ 0
OUTT_1
$EndSCHEMATC
