EESchema Schematic File Version 4
LIBS:finalsessioneurorack-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 3
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 3300 2050 0    60   ~ 0
euro_conn
Wire Wire Line
	3175 2325 3175 2375
$Comp
L power:-12V #PWR031
U 1 1 5C3AA4A4
P 2590 2810
F 0 "#PWR031" H 2590 2910 50  0001 C CNN
F 1 "-12V" H 2605 2983 50  0000 C CNN
F 2 "" H 2590 2810 50  0001 C CNN
F 3 "" H 2590 2810 50  0001 C CNN
	1    2590 2810
	-1   0    0    1   
$EndComp
Wire Wire Line
	3675 2575 3720 2575
Wire Wire Line
	3050 2525 3050 2575
Wire Wire Line
	3050 2575 3125 2575
Wire Wire Line
	2955 2575 3050 2575
Connection ~ 3050 2575
Wire Wire Line
	2670 2265 2670 2325
$Comp
L Device:D D3
U 1 1 5C3AA4C8
P 2740 2775
F 0 "D3" H 2740 2559 50  0000 C CNN
F 1 "D" H 2740 2650 50  0000 C CNN
F 2 "Diodes_ThroughHole:D_DO-35_SOD27_P10.16mm_Horizontal" H 2740 2775 50  0001 C CNN
F 3 "~" H 2740 2775 50  0001 C CNN
	1    2740 2775
	1    0    0    -1  
$EndComp
Wire Wire Line
	2590 2775 2590 2810
Wire Wire Line
	2970 2325 3050 2325
Wire Wire Line
	2890 2775 2955 2775
$Comp
L Connector_Generic:Conn_02x05_Odd_Even J1
U 1 1 5C3B711B
P 3375 2575
F 0 "J1" H 3425 2992 50  0000 C CNN
F 1 "Conn_02x05_Odd_Even" H 3425 2901 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x05_Pitch2.54mm" H 3375 2575 50  0001 C CNN
F 3 "~" H 3375 2575 50  0001 C CNN
	1    3375 2575
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR033
U 1 1 5C3B7442
P 3875 2575
F 0 "#PWR033" H 3875 2325 50  0001 C CNN
F 1 "GND" H 3880 2402 50  0000 C CNN
F 2 "" H 3875 2575 50  0001 C CNN
F 3 "" H 3875 2575 50  0001 C CNN
	1    3875 2575
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR032
U 1 1 5C3B74A9
P 2670 2265
F 0 "#PWR032" H 2670 2115 50  0001 C CNN
F 1 "+12V" H 2685 2438 50  0000 C CNN
F 2 "" H 2670 2265 50  0001 C CNN
F 3 "" H 2670 2265 50  0001 C CNN
	1    2670 2265
	1    0    0    -1  
$EndComp
$Comp
L Device:D D4
U 1 1 5C3AA4BD
P 2820 2325
F 0 "D4" H 2820 2541 50  0000 C CNN
F 1 "D" H 2820 2450 50  0000 C CNN
F 2 "Diodes_THT:D_DO-35_SOD27_P10.16mm_Horizontal" H 2820 2325 50  0001 C CNN
F 3 "~" H 2820 2325 50  0001 C CNN
	1    2820 2325
	-1   0    0    1   
$EndComp
$Comp
L Device:CP_Small C10
U 1 1 5C3B7C2F
P 3050 2425
F 0 "C10" H 3138 2471 50  0000 L CNN
F 1 "CP_Small" H 3138 2380 50  0000 L CNN
F 2 "Capacitors_ThroughHole:CP_Radial_D5.0mm_P2.00mm" H 3050 2425 50  0001 C CNN
F 3 "~" H 3050 2425 50  0001 C CNN
	1    3050 2425
	1    0    0    -1  
$EndComp
Connection ~ 3050 2325
$Comp
L Device:CP_Small C9
U 1 1 5C3B7CD7
P 2955 2675
F 0 "C9" H 3043 2721 50  0000 L CNN
F 1 "CP_Small" H 3043 2630 50  0000 L CNN
F 2 "Capacitors_ThroughHole:CP_Radial_D5.0mm_P2.00mm" H 2955 2675 50  0001 C CNN
F 3 "~" H 2955 2675 50  0001 C CNN
	1    2955 2675
	1    0    0    -1  
$EndComp
Connection ~ 2955 2775
Wire Wire Line
	2955 2775 3135 2775
Wire Wire Line
	3680 2325 3680 2375
Wire Wire Line
	3680 2375 3675 2375
Wire Wire Line
	3050 2325 3175 2325
Connection ~ 3175 2325
Wire Wire Line
	3175 2325 3680 2325
Wire Wire Line
	3675 2775 3675 2875
Wire Wire Line
	3675 2875 3135 2875
Wire Wire Line
	3135 2875 3135 2775
Connection ~ 3135 2775
Wire Wire Line
	3135 2775 3175 2775
Wire Wire Line
	3675 2675 3720 2675
Wire Wire Line
	3720 2675 3720 2575
Connection ~ 3720 2575
Wire Wire Line
	3720 2575 3875 2575
Wire Wire Line
	3175 2675 3125 2675
Wire Wire Line
	3125 2675 3125 2575
Connection ~ 3125 2575
Wire Wire Line
	3125 2575 3175 2575
Wire Wire Line
	3670 2475 3675 2475
Wire Wire Line
	3720 2475 3720 2575
Connection ~ 3675 2475
Wire Wire Line
	3675 2475 3720 2475
Wire Wire Line
	3175 2475 3125 2475
Wire Wire Line
	3125 2475 3125 2575
$EndSCHEMATC
