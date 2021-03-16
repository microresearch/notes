EESchema Schematic File Version 4
LIBS:licht_array-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L licht-rescue:CP_Small-Device-licht-rescue C?
U 1 1 6050247C
P 2190 2280
AR Path="/604F46FB/6050247C" Ref="C?"  Part="1" 
AR Path="/6050247C" Ref="C6"  Part="1" 
F 0 "C6" H 2330 2335 50  0000 L CNN
F 1 "10UF" H 2278 2235 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 2190 2280 50  0001 C CNN
F 3 "~" H 2190 2280 50  0001 C CNN
	1    2190 2280
	-1   0    0    1   
$EndComp
$Comp
L licht-rescue:C_Small-Device-licht-rescue C?
U 1 1 60502483
P 1690 1030
AR Path="/604F46FB/60502483" Ref="C?"  Part="1" 
AR Path="/60502483" Ref="C3"  Part="1" 
F 0 "C3" H 1782 1076 50  0000 L CNN
F 1 "100N" H 1390 980 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1690 1030 50  0001 C CNN
F 3 "~" H 1690 1030 50  0001 C CNN
	1    1690 1030
	1    0    0    -1  
$EndComp
$Comp
L licht-rescue:Conn_02x05_Odd_Even-Connector_Generic-licht-rescue J?
U 1 1 6050248A
P 2590 1580
AR Path="/604F46FB/6050248A" Ref="J?"  Part="1" 
AR Path="/6050248A" Ref="J1"  Part="1" 
F 0 "J1" H 2640 1997 50  0000 C CNN
F 1 "Conn_02x05_Odd_Even" H 2640 1906 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x05_Pitch2.54mm" H 2590 1580 50  0001 C CNN
F 3 "~" H 2590 1580 50  0001 C CNN
	1    2590 1580
	1    0    0    -1  
$EndComp
$Comp
L licht-rescue:D-Device-licht-rescue D?
U 1 1 60502491
P 2240 1130
AR Path="/604F46FB/60502491" Ref="D?"  Part="1" 
AR Path="/60502491" Ref="D1"  Part="1" 
F 0 "D1" H 2240 1346 50  0000 C CNN
F 1 "BAT" H 2240 1255 50  0000 C CNN
F 2 "Diodes_SMD:D_SOD-123" H 2240 1130 50  0001 C CNN
F 3 "~" H 2240 1130 50  0001 C CNN
	1    2240 1130
	0    1    1    0   
$EndComp
$Comp
L licht-rescue:+12V-power-licht-rescue #PWR?
U 1 1 60502498
P 2240 930
AR Path="/604F46FB/60502498" Ref="#PWR?"  Part="1" 
AR Path="/60502498" Ref="#PWR07"  Part="1" 
F 0 "#PWR07" H 2240 780 50  0001 C CNN
F 1 "+12V" H 2255 1103 50  0000 C CNN
F 2 "" H 2240 930 50  0001 C CNN
F 3 "" H 2240 930 50  0001 C CNN
	1    2240 930 
	1    0    0    -1  
$EndComp
$Comp
L licht-rescue:+12V-power-licht-rescue #PWR?
U 1 1 6050249E
P 2390 5675
AR Path="/604F46FB/6050249E" Ref="#PWR?"  Part="1" 
AR Path="/6050249E" Ref="#PWR01"  Part="1" 
F 0 "#PWR01" H 2390 5525 50  0001 C CNN
F 1 "+12V" H 2405 5848 50  0000 C CNN
F 2 "" H 2390 5675 50  0001 C CNN
F 3 "" H 2390 5675 50  0001 C CNN
	1    2390 5675
	1    0    0    -1  
$EndComp
$Comp
L licht-rescue:GND-power-licht-rescue #PWR?
U 1 1 605024A4
P 2240 1530
AR Path="/604F46FB/605024A4" Ref="#PWR?"  Part="1" 
AR Path="/605024A4" Ref="#PWR08"  Part="1" 
F 0 "#PWR08" H 2240 1280 50  0001 C CNN
F 1 "GND" H 2240 1645 50  0000 C CNN
F 2 "" H 2240 1530 50  0001 C CNN
F 3 "" H 2240 1530 50  0001 C CNN
	1    2240 1530
	1    0    0    -1  
$EndComp
Wire Wire Line
	2890 1430 2390 1430
Wire Wire Line
	2390 1780 2390 1880
Wire Wire Line
	2390 1880 2890 1880
Wire Wire Line
	2890 1880 2890 1780
Wire Wire Line
	2890 1380 2890 1280
Wire Wire Line
	2890 1280 2390 1280
Wire Wire Line
	2390 1280 2390 1380
Wire Wire Line
	2240 1530 2390 1530
Connection ~ 2390 1530
$Comp
L licht-rescue:D-Device-licht-rescue D?
U 1 1 605024B3
P 2240 2030
AR Path="/604F46FB/605024B3" Ref="D?"  Part="1" 
AR Path="/605024B3" Ref="D2"  Part="1" 
F 0 "D2" H 2240 2246 50  0000 C CNN
F 1 "BAT" H 2240 2155 50  0000 C CNN
F 2 "Diodes_SMD:D_SOD-123" H 2240 2030 50  0001 C CNN
F 3 "~" H 2240 2030 50  0001 C CNN
	1    2240 2030
	0    1    1    0   
$EndComp
$Comp
L licht-rescue:-12V-power-licht-rescue #PWR?
U 1 1 605024BA
P 2440 2180
AR Path="/604F46FB/605024BA" Ref="#PWR?"  Part="1" 
AR Path="/605024BA" Ref="#PWR09"  Part="1" 
F 0 "#PWR09" H 2440 2280 50  0001 C CNN
F 1 "-12V" H 2455 2353 50  0000 C CNN
F 2 "" H 2440 2180 50  0001 C CNN
F 3 "" H 2440 2180 50  0001 C CNN
	1    2440 2180
	1    0    0    -1  
$EndComp
$Comp
L licht-rescue:-12V-power-licht-rescue #PWR?
U 1 1 605024C0
P 2465 6765
AR Path="/604F46FB/605024C0" Ref="#PWR?"  Part="1" 
AR Path="/605024C0" Ref="#PWR02"  Part="1" 
F 0 "#PWR02" H 2465 6865 50  0001 C CNN
F 1 "-12V" H 2480 6938 50  0000 C CNN
F 2 "" H 2465 6765 50  0001 C CNN
F 3 "" H 2465 6765 50  0001 C CNN
	1    2465 6765
	1    0    0    -1  
$EndComp
Wire Wire Line
	2240 1880 2390 1880
Connection ~ 2390 1880
Wire Wire Line
	2240 1280 2390 1280
Connection ~ 2390 1280
Wire Wire Line
	2240 930  2240 980 
$Comp
L licht-rescue:CP_Small-Device-licht-rescue C?
U 1 1 605024CB
P 1890 1030
AR Path="/604F46FB/605024CB" Ref="C?"  Part="1" 
AR Path="/605024CB" Ref="C4"  Part="1" 
F 0 "C4" H 2030 1085 50  0000 L CNN
F 1 "10UF" H 1978 985 50  0000 L CNN
F 2 "SMD_Packages:SMD-1206_Pol" H 1890 1030 50  0001 C CNN
F 3 "~" H 1890 1030 50  0001 C CNN
	1    1890 1030
	1    0    0    -1  
$EndComp
$Comp
L licht-rescue:GND-power-licht-rescue #PWR?
U 1 1 605024D2
P 1890 1180
AR Path="/604F46FB/605024D2" Ref="#PWR?"  Part="1" 
AR Path="/605024D2" Ref="#PWR05"  Part="1" 
F 0 "#PWR05" H 1890 930 50  0001 C CNN
F 1 "GND" H 1890 1295 50  0000 C CNN
F 2 "" H 1890 1180 50  0001 C CNN
F 3 "" H 1890 1180 50  0001 C CNN
	1    1890 1180
	1    0    0    -1  
$EndComp
$Comp
L licht-rescue:GND-power-licht-rescue #PWR?
U 1 1 605024D8
P 2190 2430
AR Path="/604F46FB/605024D8" Ref="#PWR?"  Part="1" 
AR Path="/605024D8" Ref="#PWR06"  Part="1" 
F 0 "#PWR06" H 2190 2180 50  0001 C CNN
F 1 "GND" V 2190 2545 50  0000 C CNN
F 2 "" H 2190 2430 50  0001 C CNN
F 3 "" H 2190 2430 50  0001 C CNN
	1    2190 2430
	1    0    0    -1  
$EndComp
Wire Wire Line
	1890 1130 1890 1180
Wire Wire Line
	2190 2380 2190 2430
$Comp
L licht-rescue:C_Small-Device-licht-rescue C?
U 1 1 605024E0
P 2040 2280
AR Path="/604F46FB/605024E0" Ref="C?"  Part="1" 
AR Path="/605024E0" Ref="C5"  Part="1" 
F 0 "C5" H 2132 2326 50  0000 L CNN
F 1 "100N" H 1955 2120 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2040 2280 50  0001 C CNN
F 3 "~" H 2040 2280 50  0001 C CNN
	1    2040 2280
	1    0    0    -1  
$EndComp
Wire Wire Line
	1690 1130 1890 1130
Wire Wire Line
	2040 2380 2190 2380
$Comp
L licht-rescue:R_Small-Device-licht-rescue R?
U 1 1 605024E9
P 6615 1610
AR Path="/604F46FB/605024E9" Ref="R?"  Part="1" 
AR Path="/605024E9" Ref="R5"  Part="1" 
F 0 "R5" H 6674 1656 50  0000 L CNN
F 1 "470R" H 6674 1565 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 6615 1610 50  0001 C CNN
F 3 "~" H 6615 1610 50  0001 C CNN
	1    6615 1610
	-1   0    0    1   
$EndComp
$Comp
L licht-rescue:CP_Small-Device-licht-rescue C?
U 1 1 605024F0
P 5090 1690
AR Path="/604F46FB/605024F0" Ref="C?"  Part="1" 
AR Path="/605024F0" Ref="C7"  Part="1" 
F 0 "C7" V 5020 1515 50  0000 L CNN
F 1 "10PF" V 4975 1615 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 5090 1690 50  0001 C CNN
F 3 "~" H 5090 1690 50  0001 C CNN
	1    5090 1690
	0    -1   -1   0   
$EndComp
$Comp
L Device:D_Photo D?
U 1 1 605024F7
P 4700 1145
AR Path="/604F46FB/605024F7" Ref="D?"  Part="1" 
AR Path="/605024F7" Ref="D3"  Part="1" 
F 0 "D3" V 4696 1067 50  0000 R CNN
F 1 "D_Photo" V 4625 1590 50  0000 R CNN
F 2 "Opto-Devices:PhotoDiode_BPW82" H 4650 1145 50  0001 C CNN
F 3 "~" H 4650 1145 50  0001 C CNN
	1    4700 1145
	0    -1   -1   0   
$EndComp
$Comp
L licht-rescue:GND-power-licht-rescue #PWR?
U 1 1 605024FE
P 4525 1045
AR Path="/604F46FB/605024FE" Ref="#PWR?"  Part="1" 
AR Path="/605024FE" Ref="#PWR010"  Part="1" 
F 0 "#PWR010" H 4525 795 50  0001 C CNN
F 1 "GND" H 4525 1160 50  0000 C CNN
F 2 "" H 4525 1045 50  0001 C CNN
F 3 "" H 4525 1045 50  0001 C CNN
	1    4525 1045
	1    0    0    -1  
$EndComp
Wire Wire Line
	4525 1045 4700 1045
Wire Wire Line
	4700 1045 4830 1045
Connection ~ 4700 1045
Wire Wire Line
	4700 1345 4825 1345
Wire Wire Line
	4830 1345 4830 1245
$Comp
L licht-rescue:R_Small-Device-licht-rescue R?
U 1 1 60502509
P 5090 1420
AR Path="/604F46FB/60502509" Ref="R?"  Part="1" 
AR Path="/60502509" Ref="R3"  Part="1" 
F 0 "R3" V 5190 1480 50  0000 L CNN
F 1 "10K" V 5205 1270 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 5090 1420 50  0001 C CNN
F 3 "~" H 5090 1420 50  0001 C CNN
	1    5090 1420
	0    1    1    0   
$EndComp
Wire Wire Line
	4825 1345 4825 1420
Wire Wire Line
	4825 1420 4890 1420
Connection ~ 4825 1345
Wire Wire Line
	4825 1345 4830 1345
Wire Wire Line
	5190 1420 5430 1420
Wire Wire Line
	5430 1420 5430 1145
Wire Wire Line
	4890 1420 4890 1690
Wire Wire Line
	4890 1690 4990 1690
Connection ~ 4890 1420
Wire Wire Line
	4890 1420 4990 1420
Wire Wire Line
	5190 1690 5430 1690
Wire Wire Line
	5430 1690 5430 1420
Connection ~ 5430 1420
$Comp
L licht-rescue:GND-power-licht-rescue #PWR?
U 1 1 6050251D
P 6615 1755
AR Path="/604F46FB/6050251D" Ref="#PWR?"  Part="1" 
AR Path="/6050251D" Ref="#PWR012"  Part="1" 
F 0 "#PWR012" H 6615 1505 50  0001 C CNN
F 1 "GND" H 6770 1675 50  0000 C CNN
F 2 "" H 6615 1755 50  0001 C CNN
F 3 "" H 6615 1755 50  0001 C CNN
	1    6615 1755
	1    0    0    -1  
$EndComp
Wire Wire Line
	6615 1450 6615 1480
Wire Wire Line
	6615 1710 6615 1755
$Comp
L Device:R_POT RV?
U 1 1 60502525
P 7195 1700
AR Path="/604F46FB/60502525" Ref="RV?"  Part="1" 
AR Path="/60502525" Ref="RV1"  Part="1" 
F 0 "RV1" V 6988 1700 50  0000 C CNN
F 1 "100K" V 7079 1700 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Trimmer_Piher_PT-10v10_Horizontal_Px10.0mm_Py5.0mm" H 7195 1700 50  0001 C CNN
F 3 "~" H 7195 1700 50  0001 C CNN
	1    7195 1700
	0    1    1    0   
$EndComp
$Comp
L licht-rescue:R_Small-Device-licht-rescue R?
U 1 1 6050252C
P 6885 1700
AR Path="/604F46FB/6050252C" Ref="R?"  Part="1" 
AR Path="/6050252C" Ref="R6"  Part="1" 
F 0 "R6" H 6944 1746 50  0000 L CNN
F 1 "4.7K" H 6944 1655 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 6885 1700 50  0001 C CNN
F 3 "~" H 6885 1700 50  0001 C CNN
	1    6885 1700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7215 1350 7345 1350
Wire Wire Line
	7345 1350 7345 1700
Wire Wire Line
	7345 1850 7345 1700
Connection ~ 7345 1700
Wire Wire Line
	6985 1700 7045 1700
Wire Wire Line
	6785 1700 6675 1700
Wire Wire Line
	6675 1700 6675 1480
Wire Wire Line
	6675 1480 6615 1480
Connection ~ 6615 1480
Wire Wire Line
	6615 1480 6615 1510
$Comp
L licht-rescue:R_Small-Device-licht-rescue R?
U 1 1 6050253D
P 8365 1450
AR Path="/604F46FB/6050253D" Ref="R?"  Part="1" 
AR Path="/6050253D" Ref="R7"  Part="1" 
F 0 "R7" H 8424 1496 50  0000 L CNN
F 1 "1K" H 8424 1405 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 8365 1450 50  0001 C CNN
F 3 "~" H 8365 1450 50  0001 C CNN
	1    8365 1450
	0    -1   -1   0   
$EndComp
Connection ~ 7345 1350
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M?
U 1 1 60502546
P 8800 1650
AR Path="/604F46FB/60502546" Ref="M?"  Part="1" 
AR Path="/60502546" Ref="M1"  Part="1" 
F 0 "M1" H 8473 1612 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 8800 1650 45  0001 L BNN
F 2 "new_kicad:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 8830 1800 20  0001 C CNN
F 3 "" H 8800 1650 50  0001 C CNN
	1    8800 1650
	-1   0    0    1   
$EndComp
$Comp
L licht-rescue:GND-power-licht-rescue #PWR?
U 1 1 6050254D
P 8455 1750
AR Path="/604F46FB/6050254D" Ref="#PWR?"  Part="1" 
AR Path="/6050254D" Ref="#PWR013"  Part="1" 
F 0 "#PWR013" H 8455 1500 50  0001 C CNN
F 1 "GND" H 8455 1865 50  0000 C CNN
F 2 "" H 8455 1750 50  0001 C CNN
F 3 "" H 8455 1750 50  0001 C CNN
	1    8455 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	8455 1750 8500 1750
Wire Wire Line
	8465 1450 8500 1450
$Comp
L licht-rescue:C_Small-Device-licht-rescue C?
U 1 1 60502555
P 2700 6645
AR Path="/604F46FB/60502555" Ref="C?"  Part="1" 
AR Path="/60502555" Ref="C2"  Part="1" 
F 0 "C2" H 2792 6691 50  0000 L CNN
F 1 "100N" H 2400 6595 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2700 6645 50  0001 C CNN
F 3 "~" H 2700 6645 50  0001 C CNN
	1    2700 6645
	1    0    0    -1  
$EndComp
$Comp
L licht-rescue:GND-power-licht-rescue #PWR?
U 1 1 6050255C
P 2715 5935
AR Path="/604F46FB/6050255C" Ref="#PWR?"  Part="1" 
AR Path="/6050255C" Ref="#PWR04"  Part="1" 
F 0 "#PWR04" H 2715 5685 50  0001 C CNN
F 1 "GND" V 2715 6050 50  0000 C CNN
F 2 "" H 2715 5935 50  0001 C CNN
F 3 "" H 2715 5935 50  0001 C CNN
	1    2715 5935
	1    0    0    -1  
$EndComp
$Comp
L licht-rescue:C_Small-Device-licht-rescue C?
U 1 1 60502562
P 2580 6035
AR Path="/604F46FB/60502562" Ref="C?"  Part="1" 
AR Path="/60502562" Ref="C1"  Part="1" 
F 0 "C1" H 2672 6081 50  0000 L CNN
F 1 "100N" H 2280 5985 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2580 6035 50  0001 C CNN
F 3 "~" H 2580 6035 50  0001 C CNN
	1    2580 6035
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL084 U?
U 1 1 60502569
P 5130 1145
AR Path="/604F46FB/60502569" Ref="U?"  Part="1" 
AR Path="/60502569" Ref="U1"  Part="1" 
F 0 "U1" H 5130 1512 50  0000 C CNN
F 1 "TL084" H 5130 1421 50  0000 C CNN
F 2 "SMD_Packages:SOIC-14_N" H 5080 1245 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl081.pdf" H 5180 1345 50  0001 C CNN
	1    5130 1145
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL084 U?
U 2 1 60502570
P 6000 1245
AR Path="/604F46FB/60502570" Ref="U?"  Part="2" 
AR Path="/60502570" Ref="U1"  Part="2" 
F 0 "U1" H 6000 1612 50  0000 C CNN
F 1 "TL084" H 6000 1521 50  0000 C CNN
F 2 "SMD_Packages:SOIC-14_N" H 5950 1345 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl081.pdf" H 6050 1445 50  0001 C CNN
	2    6000 1245
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL084 U?
U 3 1 60502577
P 6915 1350
AR Path="/604F46FB/60502577" Ref="U?"  Part="3" 
AR Path="/60502577" Ref="U1"  Part="3" 
F 0 "U1" H 6915 1717 50  0000 C CNN
F 1 "TL084" H 6915 1626 50  0000 C CNN
F 2 "SMD_Packages:SOIC-14_N" H 6865 1450 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl081.pdf" H 6965 1550 50  0001 C CNN
	3    6915 1350
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL084 U?
U 4 1 6050257E
P 7920 1450
AR Path="/604F46FB/6050257E" Ref="U?"  Part="4" 
AR Path="/6050257E" Ref="U1"  Part="4" 
F 0 "U1" H 7920 1817 50  0000 C CNN
F 1 "TL084" H 7920 1726 50  0000 C CNN
F 2 "SMD_Packages:SOIC-14_N" H 7870 1550 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl081.pdf" H 7970 1650 50  0001 C CNN
	4    7920 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 1250 6615 1250
Wire Wire Line
	7195 1850 7345 1850
$Comp
L Amplifier_Operational:TL084 U?
U 5 1 605025B6
P 2490 6235
AR Path="/604F46FB/605025B6" Ref="U?"  Part="5" 
AR Path="/605025B6" Ref="U1"  Part="5" 
F 0 "U1" H 2448 6281 50  0000 L CNN
F 1 "TL084" H 2448 6190 50  0000 L CNN
F 2 "SMD_Packages:SOIC-14_N" H 2440 6335 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl081.pdf" H 2540 6435 50  0001 C CNN
	5    2490 6235
	1    0    0    -1  
$EndComp
$Comp
L licht-rescue:R_Small-Device-licht-rescue R?
U 1 1 605025D2
P 2390 5810
AR Path="/604F46FB/605025D2" Ref="R?"  Part="1" 
AR Path="/605025D2" Ref="R1"  Part="1" 
F 0 "R1" V 2490 5870 50  0000 L CNN
F 1 "10R" V 2505 5660 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 2390 5810 50  0001 C CNN
F 3 "~" H 2390 5810 50  0001 C CNN
	1    2390 5810
	-1   0    0    1   
$EndComp
$Comp
L licht-rescue:R_Small-Device-licht-rescue R?
U 1 1 605025D9
P 2390 6665
AR Path="/604F46FB/605025D9" Ref="R?"  Part="1" 
AR Path="/605025D9" Ref="R2"  Part="1" 
F 0 "R2" V 2490 6725 50  0000 L CNN
F 1 "10R" V 2505 6515 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 2390 6665 50  0001 C CNN
F 3 "~" H 2390 6665 50  0001 C CNN
	1    2390 6665
	-1   0    0    1   
$EndComp
Wire Wire Line
	2390 5675 2390 5710
Wire Wire Line
	2390 5910 2390 5925
Wire Wire Line
	2390 6535 2390 6545
Wire Wire Line
	2390 6765 2465 6765
$Comp
L licht-rescue:CP_Small-Device-licht-rescue C?
U 1 1 605025E9
P 5570 1145
AR Path="/604F46FB/605025E9" Ref="C?"  Part="1" 
AR Path="/605025E9" Ref="C8"  Part="1" 
F 0 "C8" V 5500 970 50  0000 L CNN
F 1 "100NF" V 5455 1070 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 5570 1145 50  0001 C CNN
F 3 "~" H 5570 1145 50  0001 C CNN
	1    5570 1145
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5430 1145 5470 1145
Connection ~ 5430 1145
Wire Wire Line
	5670 1145 5700 1145
Wire Wire Line
	5700 1345 5700 1545
Wire Wire Line
	5700 1545 6300 1545
Wire Wire Line
	6300 1545 6300 1250
Connection ~ 6300 1250
Wire Wire Line
	6300 1250 6300 1245
Wire Wire Line
	7620 1550 7620 1765
Wire Wire Line
	7620 1765 8220 1765
Wire Wire Line
	8220 1765 8220 1450
Wire Wire Line
	8220 1450 8265 1450
Connection ~ 8220 1450
Wire Wire Line
	2580 5935 2715 5935
Wire Wire Line
	2390 5925 2480 5925
Wire Wire Line
	2480 5925 2480 6135
Wire Wire Line
	2480 6135 2580 6135
Connection ~ 2390 5925
Wire Wire Line
	2390 5925 2390 5935
$Comp
L licht-rescue:GND-power-licht-rescue #PWR?
U 1 1 60502604
P 2700 6780
AR Path="/604F46FB/60502604" Ref="#PWR?"  Part="1" 
AR Path="/60502604" Ref="#PWR03"  Part="1" 
F 0 "#PWR03" H 2700 6530 50  0001 C CNN
F 1 "GND" V 2700 6895 50  0000 C CNN
F 2 "" H 2700 6780 50  0001 C CNN
F 3 "" H 2700 6780 50  0001 C CNN
	1    2700 6780
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 6745 2700 6780
Wire Wire Line
	2700 6545 2390 6545
Connection ~ 2390 6545
Wire Wire Line
	2390 6545 2390 6565
$Comp
L licht-rescue:R_Small-Device-licht-rescue R?
U 1 1 60502617
P 5625 1470
AR Path="/604F46FB/60502617" Ref="R?"  Part="1" 
AR Path="/60502617" Ref="R4"  Part="1" 
F 0 "R4" H 5684 1516 50  0000 L CNN
F 1 "100K" H 5350 1485 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 5625 1470 50  0001 C CNN
F 3 "~" H 5625 1470 50  0001 C CNN
	1    5625 1470
	-1   0    0    1   
$EndComp
$Comp
L licht-rescue:GND-power-licht-rescue #PWR?
U 1 1 6050261E
P 5625 1610
AR Path="/604F46FB/6050261E" Ref="#PWR?"  Part="1" 
AR Path="/6050261E" Ref="#PWR011"  Part="1" 
F 0 "#PWR011" H 5625 1360 50  0001 C CNN
F 1 "GND" H 5780 1530 50  0000 C CNN
F 2 "" H 5625 1610 50  0001 C CNN
F 3 "" H 5625 1610 50  0001 C CNN
	1    5625 1610
	1    0    0    -1  
$EndComp
Wire Wire Line
	5625 1570 5625 1610
Wire Wire Line
	5670 1145 5670 1370
Wire Wire Line
	5670 1370 5625 1370
Wire Wire Line
	2390 1430 2390 1480
Wire Wire Line
	2390 1530 2390 1580
Wire Wire Line
	2890 1430 2890 1480
Wire Wire Line
	1690 930  1890 930 
Wire Wire Line
	2040 2180 2190 2180
Connection ~ 5670 1145
$Comp
L licht-rescue:R_Small-Device-licht-rescue R?
U 1 1 6050BA68
P 6625 2930
AR Path="/604F46FB/6050BA68" Ref="R?"  Part="1" 
AR Path="/6050BA68" Ref="R20"  Part="1" 
F 0 "R20" H 6684 2976 50  0000 L CNN
F 1 "470R" H 6684 2885 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 6625 2930 50  0001 C CNN
F 3 "~" H 6625 2930 50  0001 C CNN
	1    6625 2930
	-1   0    0    1   
$EndComp
$Comp
L licht-rescue:CP_Small-Device-licht-rescue C?
U 1 1 6050BA6F
P 5100 3010
AR Path="/604F46FB/6050BA6F" Ref="C?"  Part="1" 
AR Path="/6050BA6F" Ref="C16"  Part="1" 
F 0 "C16" V 5030 2835 50  0000 L CNN
F 1 "10PF" V 4985 2935 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 5100 3010 50  0001 C CNN
F 3 "~" H 5100 3010 50  0001 C CNN
	1    5100 3010
	0    -1   -1   0   
$EndComp
$Comp
L Device:D_Photo D?
U 1 1 6050BA76
P 4710 2465
AR Path="/604F46FB/6050BA76" Ref="D?"  Part="1" 
AR Path="/6050BA76" Ref="D4"  Part="1" 
F 0 "D4" V 4706 2387 50  0000 R CNN
F 1 "D_Photo" V 4635 2910 50  0000 R CNN
F 2 "Opto-Devices:PhotoDiode_BPW82" H 4660 2465 50  0001 C CNN
F 3 "~" H 4660 2465 50  0001 C CNN
	1    4710 2465
	0    -1   -1   0   
$EndComp
$Comp
L licht-rescue:GND-power-licht-rescue #PWR?
U 1 1 6050BA7D
P 4535 2365
AR Path="/604F46FB/6050BA7D" Ref="#PWR?"  Part="1" 
AR Path="/6050BA7D" Ref="#PWR026"  Part="1" 
F 0 "#PWR026" H 4535 2115 50  0001 C CNN
F 1 "GND" H 4535 2480 50  0000 C CNN
F 2 "" H 4535 2365 50  0001 C CNN
F 3 "" H 4535 2365 50  0001 C CNN
	1    4535 2365
	1    0    0    -1  
$EndComp
Wire Wire Line
	4535 2365 4710 2365
Wire Wire Line
	4710 2365 4840 2365
Connection ~ 4710 2365
Wire Wire Line
	4710 2665 4835 2665
Wire Wire Line
	4840 2665 4840 2565
$Comp
L licht-rescue:R_Small-Device-licht-rescue R?
U 1 1 6050BA88
P 5100 2740
AR Path="/604F46FB/6050BA88" Ref="R?"  Part="1" 
AR Path="/6050BA88" Ref="R14"  Part="1" 
F 0 "R14" V 5200 2800 50  0000 L CNN
F 1 "10K" V 5215 2590 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 5100 2740 50  0001 C CNN
F 3 "~" H 5100 2740 50  0001 C CNN
	1    5100 2740
	0    1    1    0   
$EndComp
Wire Wire Line
	4835 2665 4835 2740
Wire Wire Line
	4835 2740 4900 2740
Connection ~ 4835 2665
Wire Wire Line
	4835 2665 4840 2665
Wire Wire Line
	5200 2740 5440 2740
Wire Wire Line
	5440 2740 5440 2465
Wire Wire Line
	4900 2740 4900 3010
Wire Wire Line
	4900 3010 5000 3010
Connection ~ 4900 2740
Wire Wire Line
	4900 2740 5000 2740
Wire Wire Line
	5200 3010 5440 3010
Wire Wire Line
	5440 3010 5440 2740
Connection ~ 5440 2740
$Comp
L licht-rescue:GND-power-licht-rescue #PWR?
U 1 1 6050BA9C
P 6625 3075
AR Path="/604F46FB/6050BA9C" Ref="#PWR?"  Part="1" 
AR Path="/6050BA9C" Ref="#PWR032"  Part="1" 
F 0 "#PWR032" H 6625 2825 50  0001 C CNN
F 1 "GND" H 6780 2995 50  0000 C CNN
F 2 "" H 6625 3075 50  0001 C CNN
F 3 "" H 6625 3075 50  0001 C CNN
	1    6625 3075
	1    0    0    -1  
$EndComp
Wire Wire Line
	6625 2770 6625 2800
Wire Wire Line
	6625 3030 6625 3075
$Comp
L Device:R_POT RV?
U 1 1 6050BAA4
P 7205 3020
AR Path="/604F46FB/6050BAA4" Ref="RV?"  Part="1" 
AR Path="/6050BAA4" Ref="RV2"  Part="1" 
F 0 "RV2" V 6998 3020 50  0000 C CNN
F 1 "100K" V 7089 3020 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Trimmer_Piher_PT-10v10_Horizontal_Px10.0mm_Py5.0mm" H 7205 3020 50  0001 C CNN
F 3 "~" H 7205 3020 50  0001 C CNN
	1    7205 3020
	0    1    1    0   
$EndComp
$Comp
L licht-rescue:R_Small-Device-licht-rescue R?
U 1 1 6050BAAB
P 6895 3020
AR Path="/604F46FB/6050BAAB" Ref="R?"  Part="1" 
AR Path="/6050BAAB" Ref="R23"  Part="1" 
F 0 "R23" H 6954 3066 50  0000 L CNN
F 1 "4.7K" H 6954 2975 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 6895 3020 50  0001 C CNN
F 3 "~" H 6895 3020 50  0001 C CNN
	1    6895 3020
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7225 2670 7355 2670
Wire Wire Line
	7355 2670 7355 3020
Wire Wire Line
	7355 3170 7355 3020
Connection ~ 7355 3020
Wire Wire Line
	6995 3020 7055 3020
Wire Wire Line
	6795 3020 6685 3020
Wire Wire Line
	6685 3020 6685 2800
Wire Wire Line
	6685 2800 6625 2800
Connection ~ 6625 2800
Wire Wire Line
	6625 2800 6625 2830
$Comp
L licht-rescue:R_Small-Device-licht-rescue R?
U 1 1 6050BABC
P 8375 2770
AR Path="/604F46FB/6050BABC" Ref="R?"  Part="1" 
AR Path="/6050BABC" Ref="R26"  Part="1" 
F 0 "R26" H 8434 2816 50  0000 L CNN
F 1 "1K" H 8434 2725 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 8375 2770 50  0001 C CNN
F 3 "~" H 8375 2770 50  0001 C CNN
	1    8375 2770
	0    -1   -1   0   
$EndComp
Connection ~ 7355 2670
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M?
U 1 1 6050BAC5
P 8810 2970
AR Path="/604F46FB/6050BAC5" Ref="M?"  Part="1" 
AR Path="/6050BAC5" Ref="M2"  Part="1" 
F 0 "M2" H 8483 2932 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 8810 2970 45  0001 L BNN
F 2 "new_kicad:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 8840 3120 20  0001 C CNN
F 3 "" H 8810 2970 50  0001 C CNN
	1    8810 2970
	-1   0    0    1   
$EndComp
$Comp
L licht-rescue:GND-power-licht-rescue #PWR?
U 1 1 6050BACC
P 8465 3070
AR Path="/604F46FB/6050BACC" Ref="#PWR?"  Part="1" 
AR Path="/6050BACC" Ref="#PWR035"  Part="1" 
F 0 "#PWR035" H 8465 2820 50  0001 C CNN
F 1 "GND" H 8465 3185 50  0000 C CNN
F 2 "" H 8465 3070 50  0001 C CNN
F 3 "" H 8465 3070 50  0001 C CNN
	1    8465 3070
	1    0    0    -1  
$EndComp
Wire Wire Line
	8465 3070 8510 3070
Wire Wire Line
	8475 2770 8510 2770
$Comp
L Amplifier_Operational:TL084 U?
U 1 1 6050BAD4
P 5140 2465
AR Path="/604F46FB/6050BAD4" Ref="U?"  Part="1" 
AR Path="/6050BAD4" Ref="U2"  Part="1" 
F 0 "U2" H 5140 2832 50  0000 C CNN
F 1 "TL084" H 5140 2741 50  0000 C CNN
F 2 "SMD_Packages:SOIC-14_N" H 5090 2565 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl081.pdf" H 5190 2665 50  0001 C CNN
	1    5140 2465
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL084 U?
U 2 1 6050BADB
P 6010 2565
AR Path="/604F46FB/6050BADB" Ref="U?"  Part="2" 
AR Path="/6050BADB" Ref="U2"  Part="2" 
F 0 "U2" H 6010 2932 50  0000 C CNN
F 1 "TL084" H 6010 2841 50  0000 C CNN
F 2 "SMD_Packages:SOIC-14_N" H 5960 2665 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl081.pdf" H 6060 2765 50  0001 C CNN
	2    6010 2565
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL084 U?
U 3 1 6050BAE2
P 6925 2670
AR Path="/604F46FB/6050BAE2" Ref="U?"  Part="3" 
AR Path="/6050BAE2" Ref="U2"  Part="3" 
F 0 "U2" H 6925 3037 50  0000 C CNN
F 1 "TL084" H 6925 2946 50  0000 C CNN
F 2 "SMD_Packages:SOIC-14_N" H 6875 2770 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl081.pdf" H 6975 2870 50  0001 C CNN
	3    6925 2670
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL084 U?
U 4 1 6050BAE9
P 7930 2770
AR Path="/604F46FB/6050BAE9" Ref="U?"  Part="4" 
AR Path="/6050BAE9" Ref="U2"  Part="4" 
F 0 "U2" H 7930 3137 50  0000 C CNN
F 1 "TL084" H 7930 3046 50  0000 C CNN
F 2 "SMD_Packages:SOIC-14_N" H 7880 2870 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl081.pdf" H 7980 2970 50  0001 C CNN
	4    7930 2770
	1    0    0    -1  
$EndComp
Wire Wire Line
	6310 2570 6625 2570
Wire Wire Line
	7205 3170 7355 3170
$Comp
L licht-rescue:CP_Small-Device-licht-rescue C?
U 1 1 6050BAF9
P 5580 2465
AR Path="/604F46FB/6050BAF9" Ref="C?"  Part="1" 
AR Path="/6050BAF9" Ref="C19"  Part="1" 
F 0 "C19" V 5510 2290 50  0000 L CNN
F 1 "100NF" V 5465 2390 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 5580 2465 50  0001 C CNN
F 3 "~" H 5580 2465 50  0001 C CNN
	1    5580 2465
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5440 2465 5480 2465
Connection ~ 5440 2465
Wire Wire Line
	5680 2465 5710 2465
Wire Wire Line
	5710 2665 5710 2865
Wire Wire Line
	5710 2865 6310 2865
Wire Wire Line
	6310 2865 6310 2570
Connection ~ 6310 2570
Wire Wire Line
	6310 2570 6310 2565
Wire Wire Line
	7630 2870 7630 3085
Wire Wire Line
	7630 3085 8230 3085
Wire Wire Line
	8230 3085 8230 2770
Wire Wire Line
	8230 2770 8275 2770
Connection ~ 8230 2770
$Comp
L licht-rescue:R_Small-Device-licht-rescue R?
U 1 1 6050BB0E
P 5635 2790
AR Path="/604F46FB/6050BB0E" Ref="R?"  Part="1" 
AR Path="/6050BB0E" Ref="R17"  Part="1" 
F 0 "R17" H 5694 2836 50  0000 L CNN
F 1 "100K" H 5360 2805 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 5635 2790 50  0001 C CNN
F 3 "~" H 5635 2790 50  0001 C CNN
	1    5635 2790
	-1   0    0    1   
$EndComp
$Comp
L licht-rescue:GND-power-licht-rescue #PWR?
U 1 1 6050BB15
P 5635 2930
AR Path="/604F46FB/6050BB15" Ref="#PWR?"  Part="1" 
AR Path="/6050BB15" Ref="#PWR029"  Part="1" 
F 0 "#PWR029" H 5635 2680 50  0001 C CNN
F 1 "GND" H 5790 2850 50  0000 C CNN
F 2 "" H 5635 2930 50  0001 C CNN
F 3 "" H 5635 2930 50  0001 C CNN
	1    5635 2930
	1    0    0    -1  
$EndComp
Wire Wire Line
	5635 2890 5635 2930
Wire Wire Line
	5680 2465 5680 2690
Wire Wire Line
	5680 2690 5635 2690
Connection ~ 5680 2465
$Comp
L licht-rescue:R_Small-Device-licht-rescue R?
U 1 1 6050F4A2
P 6640 4225
AR Path="/604F46FB/6050F4A2" Ref="R?"  Part="1" 
AR Path="/6050F4A2" Ref="R22"  Part="1" 
F 0 "R22" H 6699 4271 50  0000 L CNN
F 1 "470R" H 6699 4180 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 6640 4225 50  0001 C CNN
F 3 "~" H 6640 4225 50  0001 C CNN
	1    6640 4225
	-1   0    0    1   
$EndComp
$Comp
L licht-rescue:CP_Small-Device-licht-rescue C?
U 1 1 6050F4A9
P 5115 4305
AR Path="/604F46FB/6050F4A9" Ref="C?"  Part="1" 
AR Path="/6050F4A9" Ref="C18"  Part="1" 
F 0 "C18" V 5045 4130 50  0000 L CNN
F 1 "10PF" V 5000 4230 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 5115 4305 50  0001 C CNN
F 3 "~" H 5115 4305 50  0001 C CNN
	1    5115 4305
	0    -1   -1   0   
$EndComp
$Comp
L Device:D_Photo D?
U 1 1 6050F4B0
P 4725 3760
AR Path="/604F46FB/6050F4B0" Ref="D?"  Part="1" 
AR Path="/6050F4B0" Ref="D6"  Part="1" 
F 0 "D6" V 4721 3682 50  0000 R CNN
F 1 "D_Photo" V 4650 4205 50  0000 R CNN
F 2 "Opto-Devices:PhotoDiode_BPW82" H 4675 3760 50  0001 C CNN
F 3 "~" H 4675 3760 50  0001 C CNN
	1    4725 3760
	0    -1   -1   0   
$EndComp
$Comp
L licht-rescue:GND-power-licht-rescue #PWR?
U 1 1 6050F4B7
P 4550 3660
AR Path="/604F46FB/6050F4B7" Ref="#PWR?"  Part="1" 
AR Path="/6050F4B7" Ref="#PWR028"  Part="1" 
F 0 "#PWR028" H 4550 3410 50  0001 C CNN
F 1 "GND" H 4550 3775 50  0000 C CNN
F 2 "" H 4550 3660 50  0001 C CNN
F 3 "" H 4550 3660 50  0001 C CNN
	1    4550 3660
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 3660 4725 3660
Wire Wire Line
	4725 3660 4855 3660
Connection ~ 4725 3660
Wire Wire Line
	4725 3960 4850 3960
Wire Wire Line
	4855 3960 4855 3860
$Comp
L licht-rescue:R_Small-Device-licht-rescue R?
U 1 1 6050F4C2
P 5115 4035
AR Path="/604F46FB/6050F4C2" Ref="R?"  Part="1" 
AR Path="/6050F4C2" Ref="R16"  Part="1" 
F 0 "R16" V 5215 4095 50  0000 L CNN
F 1 "10K" V 5230 3885 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 5115 4035 50  0001 C CNN
F 3 "~" H 5115 4035 50  0001 C CNN
	1    5115 4035
	0    1    1    0   
$EndComp
Wire Wire Line
	4850 3960 4850 4035
Wire Wire Line
	4850 4035 4915 4035
Connection ~ 4850 3960
Wire Wire Line
	4850 3960 4855 3960
Wire Wire Line
	5215 4035 5455 4035
Wire Wire Line
	5455 4035 5455 3760
Wire Wire Line
	4915 4035 4915 4305
Wire Wire Line
	4915 4305 5015 4305
Connection ~ 4915 4035
Wire Wire Line
	4915 4035 5015 4035
Wire Wire Line
	5215 4305 5455 4305
Wire Wire Line
	5455 4305 5455 4035
Connection ~ 5455 4035
$Comp
L licht-rescue:GND-power-licht-rescue #PWR?
U 1 1 6050F4D6
P 6640 4370
AR Path="/604F46FB/6050F4D6" Ref="#PWR?"  Part="1" 
AR Path="/6050F4D6" Ref="#PWR034"  Part="1" 
F 0 "#PWR034" H 6640 4120 50  0001 C CNN
F 1 "GND" H 6795 4290 50  0000 C CNN
F 2 "" H 6640 4370 50  0001 C CNN
F 3 "" H 6640 4370 50  0001 C CNN
	1    6640 4370
	1    0    0    -1  
$EndComp
Wire Wire Line
	6640 4065 6640 4095
Wire Wire Line
	6640 4325 6640 4370
$Comp
L Device:R_POT RV?
U 1 1 6050F4DE
P 7220 4315
AR Path="/604F46FB/6050F4DE" Ref="RV?"  Part="1" 
AR Path="/6050F4DE" Ref="RV4"  Part="1" 
F 0 "RV4" V 7013 4315 50  0000 C CNN
F 1 "100K" V 7104 4315 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Trimmer_Piher_PT-10v10_Horizontal_Px10.0mm_Py5.0mm" H 7220 4315 50  0001 C CNN
F 3 "~" H 7220 4315 50  0001 C CNN
	1    7220 4315
	0    1    1    0   
$EndComp
$Comp
L licht-rescue:R_Small-Device-licht-rescue R?
U 1 1 6050F4E5
P 6910 4315
AR Path="/604F46FB/6050F4E5" Ref="R?"  Part="1" 
AR Path="/6050F4E5" Ref="R25"  Part="1" 
F 0 "R25" H 6969 4361 50  0000 L CNN
F 1 "4.7K" H 6969 4270 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 6910 4315 50  0001 C CNN
F 3 "~" H 6910 4315 50  0001 C CNN
	1    6910 4315
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7240 3965 7370 3965
Wire Wire Line
	7370 3965 7370 4315
Wire Wire Line
	7370 4465 7370 4315
Connection ~ 7370 4315
Wire Wire Line
	7010 4315 7070 4315
Wire Wire Line
	6810 4315 6700 4315
Wire Wire Line
	6700 4315 6700 4095
Wire Wire Line
	6700 4095 6640 4095
Connection ~ 6640 4095
Wire Wire Line
	6640 4095 6640 4125
$Comp
L licht-rescue:R_Small-Device-licht-rescue R?
U 1 1 6050F4F6
P 8390 4065
AR Path="/604F46FB/6050F4F6" Ref="R?"  Part="1" 
AR Path="/6050F4F6" Ref="R28"  Part="1" 
F 0 "R28" H 8449 4111 50  0000 L CNN
F 1 "1K" H 8449 4020 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 8390 4065 50  0001 C CNN
F 3 "~" H 8390 4065 50  0001 C CNN
	1    8390 4065
	0    -1   -1   0   
$EndComp
Connection ~ 7370 3965
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M?
U 1 1 6050F4FF
P 8825 4265
AR Path="/604F46FB/6050F4FF" Ref="M?"  Part="1" 
AR Path="/6050F4FF" Ref="M4"  Part="1" 
F 0 "M4" H 8498 4227 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 8825 4265 45  0001 L BNN
F 2 "new_kicad:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 8855 4415 20  0001 C CNN
F 3 "" H 8825 4265 50  0001 C CNN
	1    8825 4265
	-1   0    0    1   
$EndComp
$Comp
L licht-rescue:GND-power-licht-rescue #PWR?
U 1 1 6050F506
P 8480 4365
AR Path="/604F46FB/6050F506" Ref="#PWR?"  Part="1" 
AR Path="/6050F506" Ref="#PWR037"  Part="1" 
F 0 "#PWR037" H 8480 4115 50  0001 C CNN
F 1 "GND" H 8480 4480 50  0000 C CNN
F 2 "" H 8480 4365 50  0001 C CNN
F 3 "" H 8480 4365 50  0001 C CNN
	1    8480 4365
	1    0    0    -1  
$EndComp
Wire Wire Line
	8480 4365 8525 4365
Wire Wire Line
	8490 4065 8525 4065
$Comp
L Amplifier_Operational:TL084 U?
U 1 1 6050F50E
P 5155 3760
AR Path="/604F46FB/6050F50E" Ref="U?"  Part="1" 
AR Path="/6050F50E" Ref="U4"  Part="1" 
F 0 "U4" H 5155 4127 50  0000 C CNN
F 1 "TL084" H 5155 4036 50  0000 C CNN
F 2 "SMD_Packages:SOIC-14_N" H 5105 3860 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl081.pdf" H 5205 3960 50  0001 C CNN
	1    5155 3760
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL084 U?
U 2 1 6050F515
P 6025 3860
AR Path="/604F46FB/6050F515" Ref="U?"  Part="2" 
AR Path="/6050F515" Ref="U4"  Part="2" 
F 0 "U4" H 6025 4227 50  0000 C CNN
F 1 "TL084" H 6025 4136 50  0000 C CNN
F 2 "SMD_Packages:SOIC-14_N" H 5975 3960 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl081.pdf" H 6075 4060 50  0001 C CNN
	2    6025 3860
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL084 U?
U 3 1 6050F51C
P 6940 3965
AR Path="/604F46FB/6050F51C" Ref="U?"  Part="3" 
AR Path="/6050F51C" Ref="U4"  Part="3" 
F 0 "U4" H 6940 4332 50  0000 C CNN
F 1 "TL084" H 6940 4241 50  0000 C CNN
F 2 "SMD_Packages:SOIC-14_N" H 6890 4065 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl081.pdf" H 6990 4165 50  0001 C CNN
	3    6940 3965
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL084 U?
U 4 1 6050F523
P 7945 4065
AR Path="/604F46FB/6050F523" Ref="U?"  Part="4" 
AR Path="/6050F523" Ref="U4"  Part="4" 
F 0 "U4" H 7945 4432 50  0000 C CNN
F 1 "TL084" H 7945 4341 50  0000 C CNN
F 2 "SMD_Packages:SOIC-14_N" H 7895 4165 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl081.pdf" H 7995 4265 50  0001 C CNN
	4    7945 4065
	1    0    0    -1  
$EndComp
Wire Wire Line
	6325 3865 6640 3865
Wire Wire Line
	7220 4465 7370 4465
$Comp
L licht-rescue:CP_Small-Device-licht-rescue C?
U 1 1 6050F533
P 5595 3760
AR Path="/604F46FB/6050F533" Ref="C?"  Part="1" 
AR Path="/6050F533" Ref="C21"  Part="1" 
F 0 "C21" V 5525 3585 50  0000 L CNN
F 1 "100NF" V 5480 3685 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 5595 3760 50  0001 C CNN
F 3 "~" H 5595 3760 50  0001 C CNN
	1    5595 3760
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5455 3760 5495 3760
Connection ~ 5455 3760
Wire Wire Line
	5695 3760 5725 3760
Wire Wire Line
	5725 3960 5725 4160
Wire Wire Line
	5725 4160 6325 4160
Wire Wire Line
	6325 4160 6325 3865
Connection ~ 6325 3865
Wire Wire Line
	6325 3865 6325 3860
Wire Wire Line
	7645 4165 7645 4380
Wire Wire Line
	7645 4380 8245 4380
Wire Wire Line
	8245 4380 8245 4065
Wire Wire Line
	8245 4065 8290 4065
Connection ~ 8245 4065
$Comp
L licht-rescue:R_Small-Device-licht-rescue R?
U 1 1 6050F548
P 5650 4085
AR Path="/604F46FB/6050F548" Ref="R?"  Part="1" 
AR Path="/6050F548" Ref="R19"  Part="1" 
F 0 "R19" H 5709 4131 50  0000 L CNN
F 1 "100K" H 5375 4100 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 5650 4085 50  0001 C CNN
F 3 "~" H 5650 4085 50  0001 C CNN
	1    5650 4085
	-1   0    0    1   
$EndComp
$Comp
L licht-rescue:GND-power-licht-rescue #PWR?
U 1 1 6050F54F
P 5650 4225
AR Path="/604F46FB/6050F54F" Ref="#PWR?"  Part="1" 
AR Path="/6050F54F" Ref="#PWR031"  Part="1" 
F 0 "#PWR031" H 5650 3975 50  0001 C CNN
F 1 "GND" H 5805 4145 50  0000 C CNN
F 2 "" H 5650 4225 50  0001 C CNN
F 3 "" H 5650 4225 50  0001 C CNN
	1    5650 4225
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 4185 5650 4225
Wire Wire Line
	5695 3760 5695 3985
Wire Wire Line
	5695 3985 5650 3985
Connection ~ 5695 3760
$Comp
L licht-rescue:R_Small-Device-licht-rescue R?
U 1 1 60515E44
P 6625 5455
AR Path="/604F46FB/60515E44" Ref="R?"  Part="1" 
AR Path="/60515E44" Ref="R21"  Part="1" 
F 0 "R21" H 6684 5501 50  0000 L CNN
F 1 "470R" H 6684 5410 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 6625 5455 50  0001 C CNN
F 3 "~" H 6625 5455 50  0001 C CNN
	1    6625 5455
	-1   0    0    1   
$EndComp
$Comp
L licht-rescue:CP_Small-Device-licht-rescue C?
U 1 1 60515E4B
P 5100 5535
AR Path="/604F46FB/60515E4B" Ref="C?"  Part="1" 
AR Path="/60515E4B" Ref="C17"  Part="1" 
F 0 "C17" V 5030 5360 50  0000 L CNN
F 1 "10PF" V 4985 5460 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 5100 5535 50  0001 C CNN
F 3 "~" H 5100 5535 50  0001 C CNN
	1    5100 5535
	0    -1   -1   0   
$EndComp
$Comp
L Device:D_Photo D?
U 1 1 60515E52
P 4710 4990
AR Path="/604F46FB/60515E52" Ref="D?"  Part="1" 
AR Path="/60515E52" Ref="D5"  Part="1" 
F 0 "D5" V 4706 4912 50  0000 R CNN
F 1 "D_Photo" V 4635 5435 50  0000 R CNN
F 2 "Opto-Devices:PhotoDiode_BPW82" H 4660 4990 50  0001 C CNN
F 3 "~" H 4660 4990 50  0001 C CNN
	1    4710 4990
	0    -1   -1   0   
$EndComp
$Comp
L licht-rescue:GND-power-licht-rescue #PWR?
U 1 1 60515E59
P 4535 4890
AR Path="/604F46FB/60515E59" Ref="#PWR?"  Part="1" 
AR Path="/60515E59" Ref="#PWR027"  Part="1" 
F 0 "#PWR027" H 4535 4640 50  0001 C CNN
F 1 "GND" H 4535 5005 50  0000 C CNN
F 2 "" H 4535 4890 50  0001 C CNN
F 3 "" H 4535 4890 50  0001 C CNN
	1    4535 4890
	1    0    0    -1  
$EndComp
Wire Wire Line
	4535 4890 4710 4890
Wire Wire Line
	4710 4890 4840 4890
Connection ~ 4710 4890
Wire Wire Line
	4710 5190 4835 5190
Wire Wire Line
	4840 5190 4840 5090
$Comp
L licht-rescue:R_Small-Device-licht-rescue R?
U 1 1 60515E64
P 5100 5265
AR Path="/604F46FB/60515E64" Ref="R?"  Part="1" 
AR Path="/60515E64" Ref="R15"  Part="1" 
F 0 "R15" V 5200 5325 50  0000 L CNN
F 1 "10K" V 5215 5115 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 5100 5265 50  0001 C CNN
F 3 "~" H 5100 5265 50  0001 C CNN
	1    5100 5265
	0    1    1    0   
$EndComp
Wire Wire Line
	4835 5190 4835 5265
Wire Wire Line
	4835 5265 4900 5265
Connection ~ 4835 5190
Wire Wire Line
	4835 5190 4840 5190
Wire Wire Line
	5200 5265 5440 5265
Wire Wire Line
	5440 5265 5440 4990
Wire Wire Line
	4900 5265 4900 5535
Wire Wire Line
	4900 5535 5000 5535
Connection ~ 4900 5265
Wire Wire Line
	4900 5265 5000 5265
Wire Wire Line
	5200 5535 5440 5535
Wire Wire Line
	5440 5535 5440 5265
Connection ~ 5440 5265
$Comp
L licht-rescue:GND-power-licht-rescue #PWR?
U 1 1 60515E78
P 6625 5600
AR Path="/604F46FB/60515E78" Ref="#PWR?"  Part="1" 
AR Path="/60515E78" Ref="#PWR033"  Part="1" 
F 0 "#PWR033" H 6625 5350 50  0001 C CNN
F 1 "GND" H 6780 5520 50  0000 C CNN
F 2 "" H 6625 5600 50  0001 C CNN
F 3 "" H 6625 5600 50  0001 C CNN
	1    6625 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6625 5295 6625 5325
Wire Wire Line
	6625 5555 6625 5600
$Comp
L Device:R_POT RV?
U 1 1 60515E80
P 7205 5545
AR Path="/604F46FB/60515E80" Ref="RV?"  Part="1" 
AR Path="/60515E80" Ref="RV3"  Part="1" 
F 0 "RV3" V 6998 5545 50  0000 C CNN
F 1 "100K" V 7089 5545 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Trimmer_Piher_PT-10v10_Horizontal_Px10.0mm_Py5.0mm" H 7205 5545 50  0001 C CNN
F 3 "~" H 7205 5545 50  0001 C CNN
	1    7205 5545
	0    1    1    0   
$EndComp
$Comp
L licht-rescue:R_Small-Device-licht-rescue R?
U 1 1 60515E87
P 6895 5545
AR Path="/604F46FB/60515E87" Ref="R?"  Part="1" 
AR Path="/60515E87" Ref="R24"  Part="1" 
F 0 "R24" H 6954 5591 50  0000 L CNN
F 1 "4.7K" H 6954 5500 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 6895 5545 50  0001 C CNN
F 3 "~" H 6895 5545 50  0001 C CNN
	1    6895 5545
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7225 5195 7355 5195
Wire Wire Line
	7355 5195 7355 5545
Wire Wire Line
	7355 5695 7355 5545
Connection ~ 7355 5545
Wire Wire Line
	6995 5545 7055 5545
Wire Wire Line
	6795 5545 6685 5545
Wire Wire Line
	6685 5545 6685 5325
Wire Wire Line
	6685 5325 6625 5325
Connection ~ 6625 5325
Wire Wire Line
	6625 5325 6625 5355
$Comp
L licht-rescue:R_Small-Device-licht-rescue R?
U 1 1 60515E98
P 8375 5295
AR Path="/604F46FB/60515E98" Ref="R?"  Part="1" 
AR Path="/60515E98" Ref="R27"  Part="1" 
F 0 "R27" H 8434 5341 50  0000 L CNN
F 1 "1K" H 8434 5250 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 8375 5295 50  0001 C CNN
F 3 "~" H 8375 5295 50  0001 C CNN
	1    8375 5295
	0    -1   -1   0   
$EndComp
Connection ~ 7355 5195
$Comp
L allcolours-rescue:AUDIO-JACKERTHENVAR-PJ398 M?
U 1 1 60515EA1
P 8810 5495
AR Path="/604F46FB/60515EA1" Ref="M?"  Part="1" 
AR Path="/60515EA1" Ref="M3"  Part="1" 
F 0 "M3" H 8483 5457 45  0000 R CNN
F 1 "AUDIO-JACKERTHENVAR" H 8810 5495 45  0001 L BNN
F 2 "new_kicad:Jack_3.5mm_QingPu_WQP-PJ398SM_Vertical_CircularHoles" H 8840 5645 20  0001 C CNN
F 3 "" H 8810 5495 50  0001 C CNN
	1    8810 5495
	-1   0    0    1   
$EndComp
$Comp
L licht-rescue:GND-power-licht-rescue #PWR?
U 1 1 60515EA8
P 8465 5595
AR Path="/604F46FB/60515EA8" Ref="#PWR?"  Part="1" 
AR Path="/60515EA8" Ref="#PWR036"  Part="1" 
F 0 "#PWR036" H 8465 5345 50  0001 C CNN
F 1 "GND" H 8465 5710 50  0000 C CNN
F 2 "" H 8465 5595 50  0001 C CNN
F 3 "" H 8465 5595 50  0001 C CNN
	1    8465 5595
	1    0    0    -1  
$EndComp
Wire Wire Line
	8465 5595 8510 5595
Wire Wire Line
	8475 5295 8510 5295
$Comp
L Amplifier_Operational:TL084 U?
U 1 1 60515EB0
P 5140 4990
AR Path="/604F46FB/60515EB0" Ref="U?"  Part="1" 
AR Path="/60515EB0" Ref="U3"  Part="1" 
F 0 "U3" H 5140 5357 50  0000 C CNN
F 1 "TL084" H 5140 5266 50  0000 C CNN
F 2 "SMD_Packages:SOIC-14_N" H 5090 5090 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl081.pdf" H 5190 5190 50  0001 C CNN
	1    5140 4990
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL084 U?
U 2 1 60515EB7
P 6010 5090
AR Path="/604F46FB/60515EB7" Ref="U?"  Part="2" 
AR Path="/60515EB7" Ref="U3"  Part="2" 
F 0 "U3" H 6010 5457 50  0000 C CNN
F 1 "TL084" H 6010 5366 50  0000 C CNN
F 2 "SMD_Packages:SOIC-14_N" H 5960 5190 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl081.pdf" H 6060 5290 50  0001 C CNN
	2    6010 5090
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL084 U?
U 3 1 60515EBE
P 6925 5195
AR Path="/604F46FB/60515EBE" Ref="U?"  Part="3" 
AR Path="/60515EBE" Ref="U3"  Part="3" 
F 0 "U3" H 6925 5562 50  0000 C CNN
F 1 "TL084" H 6925 5471 50  0000 C CNN
F 2 "SMD_Packages:SOIC-14_N" H 6875 5295 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl081.pdf" H 6975 5395 50  0001 C CNN
	3    6925 5195
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL084 U?
U 4 1 60515EC5
P 7930 5295
AR Path="/604F46FB/60515EC5" Ref="U?"  Part="4" 
AR Path="/60515EC5" Ref="U3"  Part="4" 
F 0 "U3" H 7930 5662 50  0000 C CNN
F 1 "TL084" H 7930 5571 50  0000 C CNN
F 2 "SMD_Packages:SOIC-14_N" H 7880 5395 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl081.pdf" H 7980 5495 50  0001 C CNN
	4    7930 5295
	1    0    0    -1  
$EndComp
Wire Wire Line
	6310 5095 6625 5095
Wire Wire Line
	7205 5695 7355 5695
$Comp
L licht-rescue:CP_Small-Device-licht-rescue C?
U 1 1 60515ED5
P 5580 4990
AR Path="/604F46FB/60515ED5" Ref="C?"  Part="1" 
AR Path="/60515ED5" Ref="C20"  Part="1" 
F 0 "C20" V 5510 4815 50  0000 L CNN
F 1 "100NF" V 5465 4915 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 5580 4990 50  0001 C CNN
F 3 "~" H 5580 4990 50  0001 C CNN
	1    5580 4990
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5440 4990 5480 4990
Connection ~ 5440 4990
Wire Wire Line
	5680 4990 5710 4990
Wire Wire Line
	5710 5190 5710 5390
Wire Wire Line
	5710 5390 6310 5390
Wire Wire Line
	6310 5390 6310 5095
Connection ~ 6310 5095
Wire Wire Line
	6310 5095 6310 5090
Wire Wire Line
	7630 5395 7630 5610
Wire Wire Line
	7630 5610 8230 5610
Wire Wire Line
	8230 5610 8230 5295
Wire Wire Line
	8230 5295 8275 5295
Connection ~ 8230 5295
$Comp
L licht-rescue:R_Small-Device-licht-rescue R?
U 1 1 60515EEA
P 5635 5315
AR Path="/604F46FB/60515EEA" Ref="R?"  Part="1" 
AR Path="/60515EEA" Ref="R18"  Part="1" 
F 0 "R18" H 5694 5361 50  0000 L CNN
F 1 "100K" H 5360 5330 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 5635 5315 50  0001 C CNN
F 3 "~" H 5635 5315 50  0001 C CNN
	1    5635 5315
	-1   0    0    1   
$EndComp
$Comp
L licht-rescue:GND-power-licht-rescue #PWR?
U 1 1 60515EF1
P 5635 5455
AR Path="/604F46FB/60515EF1" Ref="#PWR?"  Part="1" 
AR Path="/60515EF1" Ref="#PWR030"  Part="1" 
F 0 "#PWR030" H 5635 5205 50  0001 C CNN
F 1 "GND" H 5790 5375 50  0000 C CNN
F 2 "" H 5635 5455 50  0001 C CNN
F 3 "" H 5635 5455 50  0001 C CNN
	1    5635 5455
	1    0    0    -1  
$EndComp
Wire Wire Line
	5635 5415 5635 5455
Wire Wire Line
	5680 4990 5680 5215
Wire Wire Line
	5680 5215 5635 5215
Connection ~ 5680 4990
Text Notes 7590 6915 0    79   ~ 16
Array of 4 lichts without trigger 15/3/2021
Connection ~ 1890 930 
Wire Wire Line
	1890 930  2240 930 
Connection ~ 1890 1130
Connection ~ 2190 2180
Wire Wire Line
	2190 2180 2240 2180
Connection ~ 2190 2380
Connection ~ 2240 930 
Connection ~ 2240 2180
Wire Wire Line
	2240 2180 2440 2180
Connection ~ 2390 1480
Wire Wire Line
	2390 1480 2390 1530
Connection ~ 2390 1580
Wire Wire Line
	2390 1580 2390 1680
Connection ~ 2890 1480
Wire Wire Line
	2890 1480 2890 1580
Connection ~ 2890 1580
Wire Wire Line
	2890 1580 2890 1680
$Comp
L licht-rescue:+12V-power-licht-rescue #PWR?
U 1 1 6052CBB9
P 1195 4025
AR Path="/604F46FB/6052CBB9" Ref="#PWR?"  Part="1" 
AR Path="/6052CBB9" Ref="#PWR014"  Part="1" 
F 0 "#PWR014" H 1195 3875 50  0001 C CNN
F 1 "+12V" H 1210 4198 50  0000 C CNN
F 2 "" H 1195 4025 50  0001 C CNN
F 3 "" H 1195 4025 50  0001 C CNN
	1    1195 4025
	1    0    0    -1  
$EndComp
$Comp
L licht-rescue:-12V-power-licht-rescue #PWR?
U 1 1 6052CBBF
P 1270 5115
AR Path="/604F46FB/6052CBBF" Ref="#PWR?"  Part="1" 
AR Path="/6052CBBF" Ref="#PWR016"  Part="1" 
F 0 "#PWR016" H 1270 5215 50  0001 C CNN
F 1 "-12V" H 1285 5288 50  0000 C CNN
F 2 "" H 1270 5115 50  0001 C CNN
F 3 "" H 1270 5115 50  0001 C CNN
	1    1270 5115
	1    0    0    -1  
$EndComp
$Comp
L licht-rescue:C_Small-Device-licht-rescue C?
U 1 1 6052CBC5
P 1505 4995
AR Path="/604F46FB/6052CBC5" Ref="C?"  Part="1" 
AR Path="/6052CBC5" Ref="C12"  Part="1" 
F 0 "C12" H 1597 5041 50  0000 L CNN
F 1 "100N" H 1205 4945 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1505 4995 50  0001 C CNN
F 3 "~" H 1505 4995 50  0001 C CNN
	1    1505 4995
	1    0    0    -1  
$EndComp
$Comp
L licht-rescue:GND-power-licht-rescue #PWR?
U 1 1 6052CBCC
P 1520 4285
AR Path="/604F46FB/6052CBCC" Ref="#PWR?"  Part="1" 
AR Path="/6052CBCC" Ref="#PWR019"  Part="1" 
F 0 "#PWR019" H 1520 4035 50  0001 C CNN
F 1 "GND" V 1520 4400 50  0000 C CNN
F 2 "" H 1520 4285 50  0001 C CNN
F 3 "" H 1520 4285 50  0001 C CNN
	1    1520 4285
	1    0    0    -1  
$EndComp
$Comp
L licht-rescue:C_Small-Device-licht-rescue C?
U 1 1 6052CBD2
P 1385 4385
AR Path="/604F46FB/6052CBD2" Ref="C?"  Part="1" 
AR Path="/6052CBD2" Ref="C10"  Part="1" 
F 0 "C10" H 1477 4431 50  0000 L CNN
F 1 "100N" H 1085 4335 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1385 4385 50  0001 C CNN
F 3 "~" H 1385 4385 50  0001 C CNN
	1    1385 4385
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL084 U?
U 5 1 6052CBD9
P 1295 4585
AR Path="/604F46FB/6052CBD9" Ref="U?"  Part="5" 
AR Path="/6052CBD9" Ref="U2"  Part="5" 
F 0 "U2" H 1253 4631 50  0000 L CNN
F 1 "TL084" H 1253 4540 50  0000 L CNN
F 2 "SMD_Packages:SOIC-14_N" H 1245 4685 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl081.pdf" H 1345 4785 50  0001 C CNN
	5    1295 4585
	1    0    0    -1  
$EndComp
$Comp
L licht-rescue:R_Small-Device-licht-rescue R?
U 1 1 6052CBE0
P 1195 4160
AR Path="/604F46FB/6052CBE0" Ref="R?"  Part="1" 
AR Path="/6052CBE0" Ref="R8"  Part="1" 
F 0 "R8" V 1295 4220 50  0000 L CNN
F 1 "10R" V 1310 4010 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 1195 4160 50  0001 C CNN
F 3 "~" H 1195 4160 50  0001 C CNN
	1    1195 4160
	-1   0    0    1   
$EndComp
$Comp
L licht-rescue:R_Small-Device-licht-rescue R?
U 1 1 6052CBE7
P 1195 5015
AR Path="/604F46FB/6052CBE7" Ref="R?"  Part="1" 
AR Path="/6052CBE7" Ref="R9"  Part="1" 
F 0 "R9" V 1295 5075 50  0000 L CNN
F 1 "10R" V 1310 4865 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 1195 5015 50  0001 C CNN
F 3 "~" H 1195 5015 50  0001 C CNN
	1    1195 5015
	-1   0    0    1   
$EndComp
Wire Wire Line
	1195 4025 1195 4060
Wire Wire Line
	1195 4260 1195 4275
Wire Wire Line
	1195 4885 1195 4895
Wire Wire Line
	1195 5115 1270 5115
Wire Wire Line
	1385 4285 1520 4285
Wire Wire Line
	1195 4275 1285 4275
Wire Wire Line
	1285 4275 1285 4485
Wire Wire Line
	1285 4485 1385 4485
Connection ~ 1195 4275
Wire Wire Line
	1195 4275 1195 4285
$Comp
L licht-rescue:GND-power-licht-rescue #PWR?
U 1 1 6052CBF8
P 1505 5130
AR Path="/604F46FB/6052CBF8" Ref="#PWR?"  Part="1" 
AR Path="/6052CBF8" Ref="#PWR018"  Part="1" 
F 0 "#PWR018" H 1505 4880 50  0001 C CNN
F 1 "GND" V 1505 5245 50  0000 C CNN
F 2 "" H 1505 5130 50  0001 C CNN
F 3 "" H 1505 5130 50  0001 C CNN
	1    1505 5130
	1    0    0    -1  
$EndComp
Wire Wire Line
	1505 5095 1505 5130
Wire Wire Line
	1505 4895 1195 4895
Connection ~ 1195 4895
Wire Wire Line
	1195 4895 1195 4915
$Comp
L licht-rescue:+12V-power-licht-rescue #PWR?
U 1 1 60539FE5
P 1250 5675
AR Path="/604F46FB/60539FE5" Ref="#PWR?"  Part="1" 
AR Path="/60539FE5" Ref="#PWR015"  Part="1" 
F 0 "#PWR015" H 1250 5525 50  0001 C CNN
F 1 "+12V" H 1265 5848 50  0000 C CNN
F 2 "" H 1250 5675 50  0001 C CNN
F 3 "" H 1250 5675 50  0001 C CNN
	1    1250 5675
	1    0    0    -1  
$EndComp
$Comp
L licht-rescue:-12V-power-licht-rescue #PWR?
U 1 1 60539FEB
P 1325 6765
AR Path="/604F46FB/60539FEB" Ref="#PWR?"  Part="1" 
AR Path="/60539FEB" Ref="#PWR017"  Part="1" 
F 0 "#PWR017" H 1325 6865 50  0001 C CNN
F 1 "-12V" H 1340 6938 50  0000 C CNN
F 2 "" H 1325 6765 50  0001 C CNN
F 3 "" H 1325 6765 50  0001 C CNN
	1    1325 6765
	1    0    0    -1  
$EndComp
$Comp
L licht-rescue:C_Small-Device-licht-rescue C?
U 1 1 60539FF1
P 1560 6645
AR Path="/604F46FB/60539FF1" Ref="C?"  Part="1" 
AR Path="/60539FF1" Ref="C13"  Part="1" 
F 0 "C13" H 1652 6691 50  0000 L CNN
F 1 "100N" H 1260 6595 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1560 6645 50  0001 C CNN
F 3 "~" H 1560 6645 50  0001 C CNN
	1    1560 6645
	1    0    0    -1  
$EndComp
$Comp
L licht-rescue:GND-power-licht-rescue #PWR?
U 1 1 60539FF8
P 1575 5935
AR Path="/604F46FB/60539FF8" Ref="#PWR?"  Part="1" 
AR Path="/60539FF8" Ref="#PWR021"  Part="1" 
F 0 "#PWR021" H 1575 5685 50  0001 C CNN
F 1 "GND" V 1575 6050 50  0000 C CNN
F 2 "" H 1575 5935 50  0001 C CNN
F 3 "" H 1575 5935 50  0001 C CNN
	1    1575 5935
	1    0    0    -1  
$EndComp
$Comp
L licht-rescue:C_Small-Device-licht-rescue C?
U 1 1 60539FFE
P 1440 6035
AR Path="/604F46FB/60539FFE" Ref="C?"  Part="1" 
AR Path="/60539FFE" Ref="C11"  Part="1" 
F 0 "C11" H 1532 6081 50  0000 L CNN
F 1 "100N" H 1140 5985 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1440 6035 50  0001 C CNN
F 3 "~" H 1440 6035 50  0001 C CNN
	1    1440 6035
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL084 U?
U 5 1 6053A005
P 1350 6235
AR Path="/604F46FB/6053A005" Ref="U?"  Part="5" 
AR Path="/6053A005" Ref="U3"  Part="5" 
F 0 "U3" H 1308 6281 50  0000 L CNN
F 1 "TL084" H 1308 6190 50  0000 L CNN
F 2 "SMD_Packages:SOIC-14_N" H 1300 6335 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl081.pdf" H 1400 6435 50  0001 C CNN
	5    1350 6235
	1    0    0    -1  
$EndComp
$Comp
L licht-rescue:R_Small-Device-licht-rescue R?
U 1 1 6053A00C
P 1250 5810
AR Path="/604F46FB/6053A00C" Ref="R?"  Part="1" 
AR Path="/6053A00C" Ref="R10"  Part="1" 
F 0 "R10" V 1350 5870 50  0000 L CNN
F 1 "10R" V 1365 5660 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 1250 5810 50  0001 C CNN
F 3 "~" H 1250 5810 50  0001 C CNN
	1    1250 5810
	-1   0    0    1   
$EndComp
$Comp
L licht-rescue:R_Small-Device-licht-rescue R?
U 1 1 6053A013
P 1250 6665
AR Path="/604F46FB/6053A013" Ref="R?"  Part="1" 
AR Path="/6053A013" Ref="R11"  Part="1" 
F 0 "R11" V 1350 6725 50  0000 L CNN
F 1 "10R" V 1365 6515 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 1250 6665 50  0001 C CNN
F 3 "~" H 1250 6665 50  0001 C CNN
	1    1250 6665
	-1   0    0    1   
$EndComp
Wire Wire Line
	1250 5675 1250 5710
Wire Wire Line
	1250 5910 1250 5925
Wire Wire Line
	1250 6535 1250 6545
Wire Wire Line
	1250 6765 1325 6765
Wire Wire Line
	1440 5935 1575 5935
Wire Wire Line
	1250 5925 1340 5925
Wire Wire Line
	1340 5925 1340 6135
Wire Wire Line
	1340 6135 1440 6135
Connection ~ 1250 5925
Wire Wire Line
	1250 5925 1250 5935
$Comp
L licht-rescue:GND-power-licht-rescue #PWR?
U 1 1 6053A024
P 1560 6780
AR Path="/604F46FB/6053A024" Ref="#PWR?"  Part="1" 
AR Path="/6053A024" Ref="#PWR020"  Part="1" 
F 0 "#PWR020" H 1560 6530 50  0001 C CNN
F 1 "GND" V 1560 6895 50  0000 C CNN
F 2 "" H 1560 6780 50  0001 C CNN
F 3 "" H 1560 6780 50  0001 C CNN
	1    1560 6780
	1    0    0    -1  
$EndComp
Wire Wire Line
	1560 6745 1560 6780
Wire Wire Line
	1560 6545 1250 6545
Connection ~ 1250 6545
Wire Wire Line
	1250 6545 1250 6565
$Comp
L licht-rescue:+12V-power-licht-rescue #PWR?
U 1 1 6054920F
P 2340 3960
AR Path="/604F46FB/6054920F" Ref="#PWR?"  Part="1" 
AR Path="/6054920F" Ref="#PWR022"  Part="1" 
F 0 "#PWR022" H 2340 3810 50  0001 C CNN
F 1 "+12V" H 2355 4133 50  0000 C CNN
F 2 "" H 2340 3960 50  0001 C CNN
F 3 "" H 2340 3960 50  0001 C CNN
	1    2340 3960
	1    0    0    -1  
$EndComp
$Comp
L licht-rescue:-12V-power-licht-rescue #PWR?
U 1 1 60549215
P 2415 5050
AR Path="/604F46FB/60549215" Ref="#PWR?"  Part="1" 
AR Path="/60549215" Ref="#PWR023"  Part="1" 
F 0 "#PWR023" H 2415 5150 50  0001 C CNN
F 1 "-12V" H 2430 5223 50  0000 C CNN
F 2 "" H 2415 5050 50  0001 C CNN
F 3 "" H 2415 5050 50  0001 C CNN
	1    2415 5050
	1    0    0    -1  
$EndComp
$Comp
L licht-rescue:C_Small-Device-licht-rescue C?
U 1 1 6054921B
P 2650 4930
AR Path="/604F46FB/6054921B" Ref="C?"  Part="1" 
AR Path="/6054921B" Ref="C15"  Part="1" 
F 0 "C15" H 2742 4976 50  0000 L CNN
F 1 "100N" H 2350 4880 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2650 4930 50  0001 C CNN
F 3 "~" H 2650 4930 50  0001 C CNN
	1    2650 4930
	1    0    0    -1  
$EndComp
$Comp
L licht-rescue:GND-power-licht-rescue #PWR?
U 1 1 60549222
P 2665 4220
AR Path="/604F46FB/60549222" Ref="#PWR?"  Part="1" 
AR Path="/60549222" Ref="#PWR025"  Part="1" 
F 0 "#PWR025" H 2665 3970 50  0001 C CNN
F 1 "GND" V 2665 4335 50  0000 C CNN
F 2 "" H 2665 4220 50  0001 C CNN
F 3 "" H 2665 4220 50  0001 C CNN
	1    2665 4220
	1    0    0    -1  
$EndComp
$Comp
L licht-rescue:C_Small-Device-licht-rescue C?
U 1 1 60549228
P 2530 4320
AR Path="/604F46FB/60549228" Ref="C?"  Part="1" 
AR Path="/60549228" Ref="C14"  Part="1" 
F 0 "C14" H 2622 4366 50  0000 L CNN
F 1 "100N" H 2230 4270 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 2530 4320 50  0001 C CNN
F 3 "~" H 2530 4320 50  0001 C CNN
	1    2530 4320
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL084 U?
U 5 1 6054922F
P 2440 4520
AR Path="/604F46FB/6054922F" Ref="U?"  Part="5" 
AR Path="/6054922F" Ref="U4"  Part="5" 
F 0 "U4" H 2398 4566 50  0000 L CNN
F 1 "TL084" H 2398 4475 50  0000 L CNN
F 2 "SMD_Packages:SOIC-14_N" H 2390 4620 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl081.pdf" H 2490 4720 50  0001 C CNN
	5    2440 4520
	1    0    0    -1  
$EndComp
$Comp
L licht-rescue:R_Small-Device-licht-rescue R?
U 1 1 60549236
P 2340 4095
AR Path="/604F46FB/60549236" Ref="R?"  Part="1" 
AR Path="/60549236" Ref="R12"  Part="1" 
F 0 "R12" V 2440 4155 50  0000 L CNN
F 1 "10R" V 2455 3945 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 2340 4095 50  0001 C CNN
F 3 "~" H 2340 4095 50  0001 C CNN
	1    2340 4095
	-1   0    0    1   
$EndComp
$Comp
L licht-rescue:R_Small-Device-licht-rescue R?
U 1 1 6054923D
P 2340 4950
AR Path="/604F46FB/6054923D" Ref="R?"  Part="1" 
AR Path="/6054923D" Ref="R13"  Part="1" 
F 0 "R13" V 2440 5010 50  0000 L CNN
F 1 "10R" V 2455 4800 50  0000 L CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 2340 4950 50  0001 C CNN
F 3 "~" H 2340 4950 50  0001 C CNN
	1    2340 4950
	-1   0    0    1   
$EndComp
Wire Wire Line
	2340 3960 2340 3995
Wire Wire Line
	2340 4195 2340 4210
Wire Wire Line
	2340 4820 2340 4830
Wire Wire Line
	2340 5050 2415 5050
Wire Wire Line
	2530 4220 2665 4220
Wire Wire Line
	2340 4210 2430 4210
Wire Wire Line
	2430 4210 2430 4420
Wire Wire Line
	2430 4420 2530 4420
Connection ~ 2340 4210
Wire Wire Line
	2340 4210 2340 4220
$Comp
L licht-rescue:GND-power-licht-rescue #PWR?
U 1 1 6054924E
P 2650 5065
AR Path="/604F46FB/6054924E" Ref="#PWR?"  Part="1" 
AR Path="/6054924E" Ref="#PWR024"  Part="1" 
F 0 "#PWR024" H 2650 4815 50  0001 C CNN
F 1 "GND" V 2650 5180 50  0000 C CNN
F 2 "" H 2650 5065 50  0001 C CNN
F 3 "" H 2650 5065 50  0001 C CNN
	1    2650 5065
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 5030 2650 5065
Wire Wire Line
	2650 4830 2340 4830
Connection ~ 2340 4830
Wire Wire Line
	2340 4830 2340 4850
Wire Wire Line
	7345 1350 7620 1350
Wire Wire Line
	7355 2670 7630 2670
Wire Wire Line
	7370 3965 7645 3965
Wire Wire Line
	7355 5195 7630 5195
$EndSCHEMATC
