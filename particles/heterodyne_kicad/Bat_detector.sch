EESchema Schematic File Version 4
LIBS:Bat_detector-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Bat Detector"
Date "2020-06-05"
Rev "1.0"
Comp "Marcel Meyer Garcia"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L 4xxx:4066 U3
U 1 1 5EDA0106
P 4700 1900
F 0 "U3" H 4700 1725 50  0000 C CNN
F 1 "4066" H 4700 1632 50  0000 C CNN
F 2 "SMD_Packages:SOIC-14_N" H 4700 1900 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4066b.pdf" H 4700 1900 50  0001 C CNN
	1    4700 1900
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:4066 U3
U 2 1 5EDA09C4
P 4700 2850
F 0 "U3" H 4700 2675 50  0000 C CNN
F 1 "4066" H 4700 2582 50  0000 C CNN
F 2 "SMD_Packages:SOIC-14_N" H 4700 2850 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4066b.pdf" H 4700 2850 50  0001 C CNN
	2    4700 2850
	1    0    0    -1  
$EndComp
$Comp
L 4xxx:4066 U3
U 3 1 5EDA105D
P 5470 4655
F 0 "U3" V 5517 4526 50  0000 R CNN
F 1 "4066" V 5424 4526 50  0000 R CNN
F 2 "SMD_Packages:SOIC-14_N" H 5470 4655 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4066b.pdf" H 5470 4655 50  0001 C CNN
	3    5470 4655
	0    -1   -1   0   
$EndComp
$Comp
L 4xxx:4066 U3
U 4 1 5EDA188A
P 4150 5000
F 0 "U3" V 4197 4871 50  0000 R CNN
F 1 "4066" V 4104 4871 50  0000 R CNN
F 2 "SMD_Packages:SOIC-14_N" H 4150 5000 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4066b.pdf" H 4150 5000 50  0001 C CNN
	4    4150 5000
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C1
U 1 1 5EDA2176
P 1800 2200
F 0 "C1" V 1545 2200 50  0000 C CNN
F 1 "22n" V 1638 2200 50  0000 C CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1838 2050 50  0001 C CNN
F 3 "~" H 1800 2200 50  0001 C CNN
	1    1800 2200
	0    1    1    0   
$EndComp
Text GLabel 1500 2200 0    50   Input ~ 0
IN
Wire Wire Line
	1500 2200 1650 2200
$Comp
L Device:L L1
U 1 1 5EDA8472
P 2050 2350
F 0 "L1" H 2005 2303 50  0000 R CNN
F 1 "3.3m" H 2005 2396 50  0000 R CNN
F 2 "Inductors_SMD:L_Wuerth_HCI-5040" H 2050 2350 50  0001 C CNN
F 3 "~" H 2050 2350 50  0001 C CNN
	1    2050 2350
	1    0    0    1   
$EndComp
$Comp
L Device:R R1
U 1 1 5EDA8B9F
P 2250 2350
F 0 "R1" H 2320 2397 50  0000 L CNN
F 1 "220" H 2320 2304 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 2180 2350 50  0001 C CNN
F 3 "~" H 2250 2350 50  0001 C CNN
	1    2250 2350
	1    0    0    -1  
$EndComp
Text GLabel 2050 2550 3    50   BiDi ~ 0
VGND
Wire Wire Line
	2050 2500 2050 2550
Wire Wire Line
	2250 2500 2050 2500
Connection ~ 2050 2500
Wire Wire Line
	2050 2200 1950 2200
Wire Wire Line
	2050 2200 2250 2200
Connection ~ 2050 2200
$Comp
L Device:R R2
U 1 1 5EDC1316
P 3200 2750
F 0 "R2" V 2990 2750 50  0000 C CNN
F 1 "100" V 3083 2750 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3130 2750 50  0001 C CNN
F 3 "~" H 3200 2750 50  0001 C CNN
	1    3200 2750
	0    1    1    0   
$EndComp
$Comp
L Device:R R5
U 1 1 5EDC594C
P 3750 2500
F 0 "R5" V 3540 2500 50  0000 C CNN
F 1 "100" V 3633 2500 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3680 2500 50  0001 C CNN
F 3 "~" H 3750 2500 50  0001 C CNN
	1    3750 2500
	0    1    1    0   
$EndComp
Wire Wire Line
	3600 2500 3400 2500
Wire Wire Line
	3400 2500 3400 2750
Wire Wire Line
	3400 2750 3450 2750
Wire Wire Line
	3350 2750 3400 2750
Connection ~ 3400 2750
Wire Wire Line
	3900 2500 4050 2500
Wire Wire Line
	4050 2500 4050 2850
Text GLabel 3350 2950 0    50   BiDi ~ 0
VGND
Wire Wire Line
	3350 2950 3450 2950
Wire Wire Line
	2250 2200 2750 2200
Wire Wire Line
	2750 2200 2750 2750
Wire Wire Line
	2750 2750 3050 2750
Connection ~ 2250 2200
$Comp
L Bat_detector-rescue:LMC555xN-Timer U1
U 1 1 5EDEB7DE
P 2300 4500
F 0 "U1" H 1950 4950 50  0000 C CNN
F 1 "ILC555" H 2000 4850 50  0000 C CNN
F 2 "SMD_Packages:SOIC-8-N" H 2950 4100 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lmc555.pdf" H 3150 4100 50  0001 C CNN
	1    2300 4500
	1    0    0    -1  
$EndComp
Text Notes 1600 1750 0    50   ~ 0
25kHz 2nd order\nhigh-pass filter
Wire Wire Line
	4050 2850 4400 2850
Wire Notes Line
	3000 2250 4150 2250
Wire Notes Line
	4150 2250 4150 3150
Wire Notes Line
	4150 3150 3000 3150
Wire Notes Line
	3000 3150 3000 2250
Text Notes 3000 3250 0    50   ~ 0
inverting stage, unity gain
$Comp
L Device:C C2
U 1 1 5EE0EBD0
P 2900 4950
F 0 "C2" H 3015 4997 50  0000 L CNN
F 1 "10n" H 3015 4904 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2938 4800 50  0001 C CNN
F 3 "~" H 2900 4950 50  0001 C CNN
	1    2900 4950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5EE131C8
P 2300 5100
F 0 "#PWR02" H 2300 4850 50  0001 C CNN
F 1 "GND" H 2305 4925 50  0000 C CNN
F 2 "" H 2300 5100 50  0001 C CNN
F 3 "" H 2300 5100 50  0001 C CNN
	1    2300 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 4900 2300 5100
Wire Wire Line
	2300 5100 2900 5100
Connection ~ 2300 5100
Wire Wire Line
	2800 4700 2900 4700
Wire Wire Line
	2900 4700 2900 4800
$Comp
L power:VCC #PWR01
U 1 1 5EE16023
P 2300 4000
F 0 "#PWR01" H 2300 3850 50  0001 C CNN
F 1 "VCC" H 2315 4175 50  0000 C CNN
F 2 "" H 2300 4000 50  0001 C CNN
F 3 "" H 2300 4000 50  0001 C CNN
	1    2300 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2300 4000 2300 4100
Wire Wire Line
	1800 4300 1800 3750
Wire Wire Line
	1800 3750 2900 3750
Wire Wire Line
	2900 3750 2900 4700
Connection ~ 2900 4700
$Comp
L Device:R R4
U 1 1 5EE19A34
P 3200 4650
F 0 "R4" H 3270 4697 50  0000 L CNN
F 1 "100" H 3270 4604 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3130 4650 50  0001 C CNN
F 3 "~" H 3200 4650 50  0001 C CNN
	1    3200 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 4700 1800 4700
Wire Wire Line
	1700 5350 3200 5350
Wire Wire Line
	3200 4500 2800 4500
Wire Wire Line
	3200 4800 3200 5350
Wire Wire Line
	1700 4700 1700 5350
Connection ~ 1700 4700
NoConn ~ 1800 4500
$Comp
L Device:R_POT P1
U 1 1 5EE20BCD
P 3200 3750
F 0 "P1" H 3131 3703 50  0000 R CNN
F 1 "2k2" H 3131 3796 50  0000 R CNN
F 2 "Potentiometers:Potentiometer_Trimmer_Piher_PT-10v10_Horizontal_Px10.0mm_Py5.0mm" H 3200 3750 50  0001 C CNN
F 3 "~" H 3200 3750 50  0001 C CNN
	1    3200 3750
	-1   0    0    1   
$EndComp
Wire Wire Line
	2900 3750 3050 3750
Connection ~ 2900 3750
NoConn ~ 3200 3600
Wire Wire Line
	2300 4000 1700 4000
Wire Wire Line
	1700 4000 1700 4700
Connection ~ 2300 4000
Wire Notes Line
	1600 3500 3500 3500
Wire Notes Line
	3500 3500 3500 5550
Wire Notes Line
	3500 5550 1600 5550
Wire Notes Line
	1600 5550 1600 3500
Text Notes 1600 5650 0    50   ~ 0
local oscillator (LO)  approx. 21kHz ... 400kHz
Wire Wire Line
	2800 4300 3050 4300
Wire Wire Line
	3050 4300 3050 4050
Wire Wire Line
	3050 4050 3850 4050
Text GLabel 4550 4050 2    50   Output ~ 0
LO
Connection ~ 3850 4050
Wire Wire Line
	3850 4050 4550 4050
$Comp
L power:GND #PWR04
U 1 1 5EE5E33A
P 4150 5350
F 0 "#PWR04" H 4150 5100 50  0001 C CNN
F 1 "GND" H 4155 5175 50  0000 C CNN
F 2 "" H 4150 5350 50  0001 C CNN
F 3 "" H 4150 5350 50  0001 C CNN
	1    4150 5350
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR03
U 1 1 5EE5E80A
P 4150 4350
F 0 "#PWR03" H 4150 4200 50  0001 C CNN
F 1 "VCC" H 4250 4450 50  0000 C CNN
F 2 "" H 4150 4350 50  0001 C CNN
F 3 "" H 4150 4350 50  0001 C CNN
	1    4150 4350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R6
U 1 1 5EE5EE51
P 4150 4550
F 0 "R6" H 4220 4597 50  0000 L CNN
F 1 "10k" H 4220 4504 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4080 4550 50  0001 C CNN
F 3 "~" H 4150 4550 50  0001 C CNN
	1    4150 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 4050 3850 5000
Connection ~ 4150 4700
Wire Wire Line
	4150 4700 4550 4700
Wire Wire Line
	4150 4350 4150 4400
Wire Wire Line
	4150 5300 4150 5350
Text GLabel 4550 4700 2    50   Output ~ 0
~LO
Wire Notes Line
	3900 4150 4500 4150
Wire Notes Line
	4500 4150 4500 5600
Wire Notes Line
	4500 5600 3900 5600
Wire Notes Line
	3900 5600 3900 4150
Text Notes 3900 5700 0    50   ~ 0
digital inverter
$Comp
L power:GND #PWR07
U 1 1 5EE84E77
P 5170 5005
F 0 "#PWR07" H 5170 4755 50  0001 C CNN
F 1 "GND" H 5175 4830 50  0000 C CNN
F 2 "" H 5170 5005 50  0001 C CNN
F 3 "" H 5170 5005 50  0001 C CNN
	1    5170 5005
	1    0    0    -1  
$EndComp
Wire Wire Line
	5170 4655 5170 4955
Wire Wire Line
	5470 4955 5170 4955
Connection ~ 5170 4955
Wire Wire Line
	5170 4955 5170 5005
NoConn ~ 5470 4355
Wire Notes Line
	5070 4305 5820 4305
Wire Notes Line
	5820 4305 5820 5255
Wire Notes Line
	5820 5255 5070 5255
Wire Notes Line
	5070 5255 5070 4305
Text Notes 5070 5355 0    50   ~ 0
unused
Text GLabel 4700 1550 1    50   Input ~ 0
LO
Wire Wire Line
	4700 1550 4700 1600
Text GLabel 4700 2500 1    50   Input ~ 0
~LO
Wire Wire Line
	4700 2500 4700 2550
Wire Wire Line
	5000 1900 5050 1900
Wire Wire Line
	5050 2850 5000 2850
Wire Notes Line
	4350 1350 5200 1350
Wire Notes Line
	5200 1350 5200 3200
Wire Notes Line
	5200 3200 4350 3200
Wire Notes Line
	4350 3200 4350 1350
Text Notes 4350 3300 0    50   ~ 0
balanced mixer
$Comp
L Device:C C3
U 1 1 5EEB9013
P 6650 2600
F 0 "C3" H 6765 2647 50  0000 L CNN
F 1 "100n" H 6765 2554 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 6688 2450 50  0001 C CNN
F 3 "~" H 6650 2600 50  0001 C CNN
	1    6650 2600
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:MCP6004 U2
U 1 1 5EECC3E3
P 3750 2850
F 0 "U2" H 3900 3000 50  0000 C CNN
F 1 "MCP6004" H 3850 3100 50  0000 C CNN
F 2 "SMD_Packages:SOIC-14_N" H 3700 2950 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 3800 3050 50  0001 C CNN
	1    3750 2850
	1    0    0    1   
$EndComp
$Comp
L Amplifier_Operational:MCP6004 U2
U 2 1 5EECD368
P 3750 1900
F 0 "U2" H 3650 1600 50  0000 C CNN
F 1 "MCP6004" H 3800 1700 50  0000 C CNN
F 2 "SMD_Packages:SOIC-14_N" H 3700 2000 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 3800 2100 50  0001 C CNN
	2    3750 1900
	1    0    0    1   
$EndComp
$Comp
L Amplifier_Operational:MCP6004 U2
U 3 1 5EED068D
P 5900 2350
F 0 "U2" H 5900 1980 50  0000 C CNN
F 1 "MCP6004" H 5900 2073 50  0000 C CNN
F 2 "SMD_Packages:SOIC-14_N" H 5850 2450 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 5950 2550 50  0001 C CNN
	3    5900 2350
	1    0    0    1   
$EndComp
$Comp
L Amplifier_Operational:MCP6004 U2
U 4 1 5EED1AB0
P 7600 2450
F 0 "U2" H 7600 2820 50  0000 C CNN
F 1 "MCP6004" H 7600 2727 50  0000 C CNN
F 2 "SMD_Packages:SOIC-14_N" H 7550 2550 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 7650 2650 50  0001 C CNN
	4    7600 2450
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:MCP6004 U2
U 5 1 5EED4B98
P 8625 4855
F 0 "U2" H 8584 4902 50  0000 L CNN
F 1 "MCP6004" H 8584 4809 50  0000 L CNN
F 2 "SMD_Packages:SOIC-14_N" H 8575 4955 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 8675 5055 50  0001 C CNN
	5    8625 4855
	1    0    0    -1  
$EndComp
Connection ~ 4050 2850
Wire Wire Line
	4050 1900 4400 1900
Wire Wire Line
	3450 1800 3350 1800
Wire Wire Line
	3350 1800 3350 1500
Wire Wire Line
	3350 1500 4050 1500
Wire Wire Line
	4050 1500 4050 1900
Connection ~ 4050 1900
Wire Wire Line
	2750 2000 2750 2200
Wire Wire Line
	2750 2000 3450 2000
Connection ~ 2750 2200
Wire Notes Line
	4150 1350 4150 2150
Wire Notes Line
	4150 2150 3000 2150
Wire Notes Line
	3000 2150 3000 1350
Wire Notes Line
	3000 1350 4150 1350
Text Notes 3000 1300 0    50   ~ 0
unity gain buffer stage
Text GLabel 6650 2850 3    50   BiDi ~ 0
VGND
Wire Wire Line
	6650 2750 6650 2850
Wire Wire Line
	6650 2350 6650 2450
Wire Wire Line
	5050 1900 5050 2450
Wire Wire Line
	5600 2450 5050 2450
Connection ~ 5050 2450
Wire Wire Line
	5050 2450 5050 2850
Wire Wire Line
	5600 2250 5550 2250
Wire Wire Line
	5550 2250 5550 1850
Wire Wire Line
	5550 1850 6200 1850
Wire Wire Line
	6200 1850 6200 2350
$Comp
L Device:R R7
U 1 1 5EF6C19B
P 6450 2350
F 0 "R7" V 6240 2350 50  0000 C CNN
F 1 "220" V 6333 2350 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6380 2350 50  0001 C CNN
F 3 "~" H 6450 2350 50  0001 C CNN
	1    6450 2350
	0    1    1    0   
$EndComp
Wire Wire Line
	6600 2350 6650 2350
Wire Wire Line
	6300 2350 6200 2350
Connection ~ 6200 2350
Wire Notes Line
	5450 1750 7000 1750
Wire Notes Line
	7000 1750 7000 3200
Wire Notes Line
	7000 3200 5450 3200
Wire Notes Line
	5450 3200 5450 1750
Text Notes 5450 3300 0    50   ~ 0
unity gain buffer + 7kHz low-pass filter
$Comp
L Device:C C5
U 1 1 5EFDF596
P 9075 4905
F 0 "C5" H 9190 4952 50  0000 L CNN
F 1 "100n" H 9190 4859 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 9113 4755 50  0001 C CNN
F 3 "~" H 9075 4905 50  0001 C CNN
	1    9075 4905
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C6
U 1 1 5EFDFCF6
P 9525 4905
F 0 "C6" H 9644 4952 50  0000 L CNN
F 1 "10µ" H 9644 4859 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 9563 4755 50  0001 C CNN
F 3 "~" H 9525 4905 50  0001 C CNN
	1    9525 4905
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR09
U 1 1 5EFE7185
P 9075 5455
F 0 "#PWR09" H 9075 5205 50  0001 C CNN
F 1 "GND" H 9080 5280 50  0000 C CNN
F 2 "" H 9075 5455 50  0001 C CNN
F 3 "" H 9075 5455 50  0001 C CNN
	1    9075 5455
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR08
U 1 1 5EFE789A
P 9075 4255
F 0 "#PWR08" H 9075 4105 50  0001 C CNN
F 1 "VCC" H 9090 4430 50  0000 C CNN
F 2 "" H 9075 4255 50  0001 C CNN
F 3 "" H 9075 4255 50  0001 C CNN
	1    9075 4255
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 2550 7250 2550
Wire Wire Line
	7250 2550 7250 2750
Wire Wire Line
	6650 2350 7300 2350
Connection ~ 6650 2350
Wire Notes Line
	7150 1750 7150 3350
Wire Notes Line
	7150 3350 9950 3350
Wire Notes Line
	9950 3350 9950 1750
Wire Notes Line
	9950 1750 7150 1750
Text Notes 7150 3450 0    50   ~ 0
output driver stage for headphones
Text Notes 2450 3650 0    50   ~ 0
frequency control
Text Notes 6775 5805 0    50   ~ 0
power supply + decoupling
Wire Notes Line
	2500 2900 1600 2900
Wire Notes Line
	1600 2900 1600 1800
Wire Notes Line
	1600 1800 2500 1800
Wire Notes Line
	2500 1800 2500 2900
Wire Wire Line
	8025 4355 8525 4355
Wire Wire Line
	9075 4355 9075 4255
Wire Wire Line
	8525 4355 8525 4555
Connection ~ 8525 4355
Wire Wire Line
	8525 4355 9075 4355
Wire Wire Line
	8525 5155 8525 5355
Wire Wire Line
	8525 5355 8025 5355
Wire Wire Line
	9075 5355 8525 5355
Connection ~ 8525 5355
Wire Wire Line
	9075 5355 9075 5455
Connection ~ 9075 5355
Wire Wire Line
	9525 5355 9075 5355
Wire Wire Line
	9075 4355 9390 4355
Connection ~ 9075 4355
Wire Wire Line
	9525 4355 9525 4755
Wire Wire Line
	9075 4355 9075 4755
Wire Wire Line
	9525 5055 9525 5355
Wire Wire Line
	9075 5055 9075 5355
$Comp
L 4xxx:4066 U3
U 5 1 5F07CE91
P 8025 4855
F 0 "U3" H 7625 4955 50  0000 L CNN
F 1 "4066" H 7575 4855 50  0000 L CNN
F 2 "SMD_Packages:SOIC-14_N" H 8025 4855 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/cd4066b.pdf" H 8025 4855 50  0001 C CNN
	5    8025 4855
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5EE335F2
P 7450 2750
F 0 "R3" V 7240 2750 50  0000 C CNN
F 1 "10K" V 7333 2750 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 7380 2750 50  0001 C CNN
F 3 "~" H 7450 2750 50  0001 C CNN
	1    7450 2750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7300 2750 7250 2750
NoConn ~ 7900 2900
Wire Wire Line
	7425 5355 8025 5355
Connection ~ 8025 5355
Connection ~ 8025 4355
Wire Notes Line
	9875 5705 6725 5705
Wire Notes Line
	6725 5705 6725 3805
Wire Notes Line
	6725 3805 9875 3805
Wire Notes Line
	9875 3805 9875 5705
Wire Wire Line
	3200 3900 3200 4500
Connection ~ 3200 4500
Wire Wire Line
	7425 4355 8025 4355
$Comp
L Device:C C4
U 1 1 604C3279
P 2960 7020
F 0 "C4" H 3075 7067 50  0000 L CNN
F 1 "1µ" H 3075 6974 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 2998 6870 50  0001 C CNN
F 3 "~" H 2960 7020 50  0001 C CNN
	1    2960 7020
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR05
U 1 1 604C3280
P 2760 7470
F 0 "#PWR05" H 2760 7220 50  0001 C CNN
F 1 "GND" H 2765 7295 50  0000 C CNN
F 2 "" H 2760 7470 50  0001 C CNN
F 3 "" H 2760 7470 50  0001 C CNN
	1    2760 7470
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:MCP6002-xSN U4
U 1 1 604C3286
P 4310 7070
F 0 "U4" H 4310 7440 50  0000 C CNN
F 1 "MCP6002-xSN" H 4310 7347 50  0000 C CNN
F 2 "SMD_Packages:SOIC-8-N" H 4310 7070 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 4310 7070 50  0001 C CNN
	1    4310 7070
	1    0    0    1   
$EndComp
$Comp
L Amplifier_Operational:MCP6002-xSN U4
U 2 1 604C328D
P 5610 6970
F 0 "U4" H 5610 6600 50  0000 C CNN
F 1 "MCP6002-xSN" H 5610 6693 50  0000 C CNN
F 2 "SMD_Packages:SOIC-8-N" H 5610 6970 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 5610 6970 50  0001 C CNN
	2    5610 6970
	1    0    0    1   
$EndComp
$Comp
L Amplifier_Operational:MCP6002-xSN U4
U 3 1 604C3294
P 2660 7170
F 0 "U4" H 2810 7220 50  0000 R CNN
F 1 "MCP6002-xSN" H 3210 7120 50  0000 R CNN
F 2 "SMD_Packages:SOIC-8-N" H 2660 7170 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 2660 7170 50  0001 C CNN
	3    2660 7170
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R9
U 1 1 604C329B
P 3710 7320
F 0 "R9" H 3640 7273 50  0000 R CNN
F 1 "10k" H 3640 7366 50  0000 R CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3640 7320 50  0001 C CNN
F 3 "~" H 3710 7320 50  0001 C CNN
	1    3710 7320
	1    0    0    1   
$EndComp
$Comp
L Device:R R8
U 1 1 604C32A2
P 3710 7020
F 0 "R8" H 3640 6973 50  0000 R CNN
F 1 "10k" H 3640 7066 50  0000 R CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 3640 7020 50  0001 C CNN
F 3 "~" H 3710 7020 50  0001 C CNN
	1    3710 7020
	1    0    0    1   
$EndComp
$Comp
L Device:C C7
U 1 1 604C32A9
P 3360 7320
F 0 "C7" H 3245 7273 50  0000 R CNN
F 1 "100n" H 3245 7366 50  0000 R CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 3398 7170 50  0001 C CNN
F 3 "~" H 3360 7320 50  0001 C CNN
	1    3360 7320
	1    0    0    1   
$EndComp
Wire Wire Line
	4010 6970 3960 6970
Wire Wire Line
	3960 6970 3960 6770
Wire Wire Line
	3960 6770 4660 6770
Wire Wire Line
	4660 6770 4660 7070
Wire Wire Line
	4660 7070 4610 7070
Wire Wire Line
	3360 7170 3710 7170
Connection ~ 3710 7170
Wire Wire Line
	3710 7170 4010 7170
Wire Wire Line
	5310 7070 4660 7070
Connection ~ 4660 7070
$Comp
L Device:R R10
U 1 1 604C32BA
P 5060 6870
F 0 "R10" V 4850 6870 50  0000 C CNN
F 1 "10k" V 4943 6870 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4990 6870 50  0001 C CNN
F 3 "~" H 5060 6870 50  0001 C CNN
	1    5060 6870
	0    -1   1    0   
$EndComp
$Comp
L Device:R R11
U 1 1 604C32C1
P 5610 6420
F 0 "R11" V 5400 6420 50  0000 C CNN
F 1 "100k" V 5493 6420 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5540 6420 50  0001 C CNN
F 3 "~" H 5610 6420 50  0001 C CNN
	1    5610 6420
	0    -1   1    0   
$EndComp
Wire Wire Line
	5460 6420 5260 6420
Wire Wire Line
	5260 6420 5260 6870
Wire Wire Line
	5260 6870 5310 6870
Wire Wire Line
	5260 6870 5210 6870
Connection ~ 5260 6870
Wire Wire Line
	5760 6420 5960 6420
Wire Wire Line
	5960 6420 5960 6970
Wire Wire Line
	5960 6970 5940 6970
$Comp
L Device:C C8
U 1 1 604C32D0
P 4610 6220
F 0 "C8" V 4355 6220 50  0000 C CNN
F 1 "1µ" V 4448 6220 50  0000 C CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 4648 6070 50  0001 C CNN
F 3 "~" H 4610 6220 50  0001 C CNN
	1    4610 6220
	0    -1   1    0   
$EndComp
Wire Wire Line
	4460 6220 4360 6220
Wire Wire Line
	4760 6220 4860 6220
Wire Wire Line
	4860 6220 4860 6870
Wire Wire Line
	4860 6870 4910 6870
$Comp
L power:GND #PWR06
U 1 1 604C32DB
P 4705 6410
F 0 "#PWR06" H 4705 6160 50  0001 C CNN
F 1 "GND" H 4705 6460 50  0000 C CNN
F 2 "" H 4705 6410 50  0001 C CNN
F 3 "" H 4705 6410 50  0001 C CNN
	1    4705 6410
	1    0    0    -1  
$EndComp
Wire Wire Line
	2760 7470 2960 7470
Wire Wire Line
	3360 7470 3710 7470
Connection ~ 3360 7470
Wire Wire Line
	2760 6870 2960 6870
Text GLabel 2760 6870 1    50   Input ~ 0
Vcc
Text GLabel 4360 6420 2    50   Input ~ 0
Vcc
Connection ~ 2760 7470
Wire Wire Line
	6210 6970 6170 6970
Connection ~ 2960 6870
Wire Wire Line
	2960 7170 2960 7470
Connection ~ 2960 7470
Wire Wire Line
	2960 7470 3360 7470
$Comp
L power:GND #PWR010
U 1 1 604C32EF
P 6210 7370
F 0 "#PWR010" H 6210 7120 50  0001 C CNN
F 1 "GND" H 6215 7195 50  0000 C CNN
F 2 "" H 6210 7370 50  0001 C CNN
F 3 "" H 6210 7370 50  0001 C CNN
	1    6210 7370
	1    0    0    -1  
$EndComp
Text GLabel 4910 7070 3    50   Input ~ 0
VGND
$Comp
L Connector:Conn_01x03_Male J1
U 1 1 604C330E
P 4160 6320
F 0 "J1" H 4266 6598 50  0000 C CNN
F 1 "Conn_01x03_Male" H 4266 6507 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 4160 6320 50  0001 C CNN
F 3 "~" H 4160 6320 50  0001 C CNN
	1    4160 6320
	1    0    0    -1  
$EndComp
Wire Wire Line
	4360 6320 4705 6320
Wire Wire Line
	4705 6320 4705 6410
Text GLabel 6135 6820 2    50   Input ~ 0
IN
Wire Wire Line
	6135 6820 6075 6820
Wire Wire Line
	6075 6820 6075 6970
Text GLabel 9390 4220 2    50   Input ~ 0
Vcc
Wire Wire Line
	9390 4220 9390 4355
Connection ~ 9390 4355
Wire Wire Line
	9390 4355 9525 4355
Wire Wire Line
	7900 2450 7900 2750
Wire Wire Line
	7600 2750 7900 2750
$Comp
L Device:R R13
U 1 1 604C7CC0
P 8105 2450
F 0 "R13" V 7895 2450 50  0000 C CNN
F 1 "1K" V 7988 2450 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 8035 2450 50  0001 C CNN
F 3 "~" H 8105 2450 50  0001 C CNN
	1    8105 2450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7900 2450 7955 2450
Connection ~ 7900 2450
$Comp
L Device:CP C9
U 1 1 604CCB22
P 8435 2450
F 0 "C9" H 8554 2497 50  0000 L CNN
F 1 "10u" H 8554 2404 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 8473 2300 50  0001 C CNN
F 3 "~" H 8435 2450 50  0001 C CNN
	1    8435 2450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8255 2450 8285 2450
Text Notes 7080 3975 0    50   ~ 0
3.3v supply\n
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M1
U 1 1 604E988D
P 8935 2650
F 0 "M1" H 8608 2612 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR-PJ398" H 8935 2650 45  0001 L BNN
F 2 "new_kicad:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 8965 2800 20  0001 C CNN
F 3 "" H 8935 2650 60  0001 C CNN
	1    8935 2650
	-1   0    0    1   
$EndComp
Wire Wire Line
	8585 2450 8635 2450
$Comp
L power:GND #PWR013
U 1 1 604FB1AF
P 8635 2805
F 0 "#PWR013" H 8635 2555 50  0001 C CNN
F 1 "GND" H 8640 2630 50  0000 C CNN
F 2 "" H 8635 2805 50  0001 C CNN
F 3 "" H 8635 2805 50  0001 C CNN
	1    8635 2805
	1    0    0    -1  
$EndComp
Wire Wire Line
	8635 2750 8635 2805
$Comp
L Device:R R12
U 1 1 604FFBC3
P 7250 2920
F 0 "R12" V 7040 2920 50  0000 C CNN
F 1 "1K" V 7133 2920 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 7180 2920 50  0001 C CNN
F 3 "~" H 7250 2920 50  0001 C CNN
	1    7250 2920
	1    0    0    -1  
$EndComp
Text GLabel 7250 3120 3    50   BiDi ~ 0
VGND
Wire Wire Line
	7250 3070 7250 3120
Wire Wire Line
	7250 2750 7250 2770
Connection ~ 7250 2750
$Comp
L Regulator_Linear:LM1117-3.3 U5
U 1 1 60509379
P 7005 4675
F 0 "U5" H 7005 4917 50  0000 C CNN
F 1 "LM1117-3.3" H 7005 4826 50  0000 C CNN
F 2 "TO_SOT_Packages_SMD:TO-252-2_Rectifier" H 7005 4675 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/lm1117.pdf" H 7005 4675 50  0001 C CNN
	1    7005 4675
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR012
U 1 1 605094C1
P 7005 5030
F 0 "#PWR012" H 7005 4780 50  0001 C CNN
F 1 "GND" H 7010 4855 50  0000 C CNN
F 2 "" H 7005 5030 50  0001 C CNN
F 3 "" H 7005 5030 50  0001 C CNN
	1    7005 5030
	1    0    0    -1  
$EndComp
Wire Wire Line
	7005 4975 7005 4995
Wire Wire Line
	7005 4995 7425 4995
Connection ~ 7005 4995
Wire Wire Line
	7005 4995 7005 5030
Wire Wire Line
	7425 4995 7425 5355
Wire Wire Line
	7305 4675 7425 4675
Wire Wire Line
	7425 4355 7425 4675
$Comp
L Connector:Conn_01x02_Female J2
U 1 1 6052A96A
P 6405 4775
F 0 "J2" H 6299 4450 50  0000 C CNN
F 1 "Conn_01x02_Female" H 6299 4541 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 6405 4775 50  0001 C CNN
F 3 "~" H 6405 4775 50  0001 C CNN
	1    6405 4775
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR011
U 1 1 6052ABEE
P 6645 4775
F 0 "#PWR011" H 6645 4525 50  0001 C CNN
F 1 "GND" H 6650 4600 50  0000 C CNN
F 2 "" H 6645 4775 50  0001 C CNN
F 3 "" H 6645 4775 50  0001 C CNN
	1    6645 4775
	1    0    0    -1  
$EndComp
Wire Wire Line
	6605 4675 6650 4675
Wire Wire Line
	6605 4775 6645 4775
$Comp
L Connector:Conn_01x02_Female J3
U 1 1 605395A1
P 6410 6970
F 0 "J3" H 6437 6946 50  0000 L CNN
F 1 "Conn_01x02_Female" H 6437 6855 50  0000 L CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" H 6410 6970 50  0001 C CNN
F 3 "~" H 6410 6970 50  0001 C CNN
	1    6410 6970
	1    0    0    -1  
$EndComp
Wire Wire Line
	6210 7070 6210 7370
Wire Wire Line
	2960 6870 3710 6870
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 60548C4D
P 6650 4470
F 0 "#FLG0101" H 6650 4545 50  0001 C CNN
F 1 "PWR_FLAG" H 6650 4644 50  0000 C CNN
F 2 "" H 6650 4470 50  0001 C CNN
F 3 "~" H 6650 4470 50  0001 C CNN
	1    6650 4470
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 4470 6650 4675
Connection ~ 6650 4675
Wire Wire Line
	6650 4675 6705 4675
$Comp
L Device:R R14
U 1 1 6055C6CC
P 6020 7075
F 0 "R14" V 6185 7065 50  0000 C CNN
F 1 "OPT" V 6110 7070 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 5950 7075 50  0001 C CNN
F 3 "~" H 6020 7075 50  0001 C CNN
	1    6020 7075
	0    -1   1    0   
$EndComp
Wire Wire Line
	6170 7075 6170 6970
Connection ~ 6170 6970
Wire Wire Line
	6170 6970 6075 6970
Wire Wire Line
	5870 7075 5870 7020
Wire Wire Line
	5870 7020 5940 7020
Wire Wire Line
	5940 7020 5940 6970
Connection ~ 5940 6970
Wire Wire Line
	5940 6970 5910 6970
$EndSCHEMATC
