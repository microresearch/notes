EESchema Schematic File Version 4
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
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
L Device:C C?
U 1 1 5EA9A1BC
P 3950 3500
F 0 "C?" H 4065 3547 50  0000 L CNN
F 1 "1µ" H 4065 3454 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 3988 3350 50  0001 C CNN
F 3 "~" H 3950 3500 50  0001 C CNN
	1    3950 3500
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5EA9A271
P 3750 3950
F 0 "#PWR?" H 3750 3700 50  0001 C CNN
F 1 "GND" H 3755 3775 50  0000 C CNN
F 2 "" H 3750 3950 50  0001 C CNN
F 3 "" H 3750 3950 50  0001 C CNN
	1    3750 3950
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:MCP6002-xSN U?
U 1 1 5EB7CD0E
P 5300 3550
F 0 "U?" H 5300 3920 50  0000 C CNN
F 1 "MCP6002-xSN" H 5300 3827 50  0000 C CNN
F 2 "my_components:SOIC-8_elongated_pads_MARCEL" H 5300 3550 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 5300 3550 50  0001 C CNN
	1    5300 3550
	1    0    0    1   
$EndComp
$Comp
L Amplifier_Operational:MCP6002-xSN U?
U 2 1 5EB7CD4F
P 6600 3450
F 0 "U?" H 6600 3080 50  0000 C CNN
F 1 "MCP6002-xSN" H 6600 3173 50  0000 C CNN
F 2 "my_components:SOIC-8_elongated_pads_MARCEL" H 6600 3450 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 6600 3450 50  0001 C CNN
	2    6600 3450
	1    0    0    1   
$EndComp
$Comp
L Amplifier_Operational:MCP6002-xSN U?
U 3 1 5EB7CDA9
P 3650 3650
F 0 "U?" H 3800 3700 50  0000 R CNN
F 1 "MCP6002-xSN" H 4200 3600 50  0000 R CNN
F 2 "my_components:SOIC-8_elongated_pads_MARCEL" H 3650 3650 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21733j.pdf" H 3650 3650 50  0001 C CNN
	3    3650 3650
	-1   0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5EB7D26B
P 4700 3800
F 0 "R?" H 4630 3753 50  0000 R CNN
F 1 "10k" H 4630 3846 50  0000 R CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4630 3800 50  0001 C CNN
F 3 "~" H 4700 3800 50  0001 C CNN
	1    4700 3800
	1    0    0    1   
$EndComp
$Comp
L Device:R R?
U 1 1 5EB7D303
P 4700 3500
F 0 "R?" H 4630 3453 50  0000 R CNN
F 1 "10k" H 4630 3546 50  0000 R CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 4630 3500 50  0001 C CNN
F 3 "~" H 4700 3500 50  0001 C CNN
	1    4700 3500
	1    0    0    1   
$EndComp
$Comp
L Device:C C?
U 1 1 5EB7D450
P 4350 3800
F 0 "C?" H 4235 3753 50  0000 R CNN
F 1 "100n" H 4235 3846 50  0000 R CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4388 3650 50  0001 C CNN
F 3 "~" H 4350 3800 50  0001 C CNN
	1    4350 3800
	1    0    0    1   
$EndComp
Wire Wire Line
	5000 3450 4950 3450
Wire Wire Line
	4950 3450 4950 3250
Wire Wire Line
	4950 3250 5650 3250
Wire Wire Line
	5650 3250 5650 3550
Wire Wire Line
	5650 3550 5600 3550
Wire Wire Line
	4350 3650 4700 3650
Connection ~ 4700 3650
Wire Wire Line
	4700 3650 5000 3650
Wire Wire Line
	6300 3550 5650 3550
Connection ~ 5650 3550
$Comp
L Device:R R?
U 1 1 5EB7EE7D
P 6050 3350
F 0 "R?" V 5840 3350 50  0000 C CNN
F 1 "10k" V 5933 3350 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 5980 3350 50  0001 C CNN
F 3 "~" H 6050 3350 50  0001 C CNN
	1    6050 3350
	0    -1   1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5EB7EEF6
P 6600 2900
F 0 "R?" V 6390 2900 50  0000 C CNN
F 1 "100k" V 6483 2900 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric_Pad1.15x1.40mm_HandSolder" V 6530 2900 50  0001 C CNN
F 3 "~" H 6600 2900 50  0001 C CNN
	1    6600 2900
	0    -1   1    0   
$EndComp
Wire Wire Line
	6450 2900 6250 2900
Wire Wire Line
	6250 2900 6250 3350
Wire Wire Line
	6250 3350 6300 3350
Wire Wire Line
	6250 3350 6200 3350
Connection ~ 6250 3350
Wire Wire Line
	6750 2900 6950 2900
Wire Wire Line
	6950 2900 6950 3450
Wire Wire Line
	6950 3450 6900 3450
$Comp
L Device:C C?
U 1 1 5EB7F363
P 5600 2700
F 0 "C?" V 5345 2700 50  0000 C CNN
F 1 "1µ" V 5438 2700 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5638 2550 50  0001 C CNN
F 3 "~" H 5600 2700 50  0001 C CNN
	1    5600 2700
	0    -1   1    0   
$EndComp
Wire Wire Line
	5450 2700 5350 2700
Wire Wire Line
	5750 2700 5850 2700
Wire Wire Line
	5850 2700 5850 3350
Wire Wire Line
	5850 3350 5900 3350
$Comp
L power:GND #PWR?
U 1 1 5EB7F702
P 5695 2890
F 0 "#PWR?" H 5695 2640 50  0001 C CNN
F 1 "GND" H 5695 2940 50  0000 C CNN
F 2 "" H 5695 2890 50  0001 C CNN
F 3 "" H 5695 2890 50  0001 C CNN
	1    5695 2890
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 3950 3950 3950
Wire Wire Line
	4350 3950 4700 3950
Connection ~ 4350 3950
Wire Wire Line
	3750 3350 3950 3350
Text GLabel 3750 3350 1    50   Input ~ 0
Vcc
Text GLabel 5350 2900 2    50   Input ~ 0
Vcc
Connection ~ 3750 3950
Wire Wire Line
	7200 3450 6950 3450
Connection ~ 6950 3450
Connection ~ 3950 3350
Wire Wire Line
	3950 3350 4350 3350
Wire Wire Line
	3950 3650 3950 3950
Connection ~ 3950 3950
Wire Wire Line
	3950 3950 4350 3950
$Comp
L power:GND #PWR?
U 1 1 5EB80AF0
P 7200 3850
F 0 "#PWR?" H 7200 3600 50  0001 C CNN
F 1 "GND" H 7205 3675 50  0000 C CNN
F 2 "" H 7200 3850 50  0001 C CNN
F 3 "" H 7200 3850 50  0001 C CNN
	1    7200 3850
	1    0    0    -1  
$EndComp
Text GLabel 7200 3550 0    50   Input ~ 0
Vcc
$Comp
L power:PWR_FLAG #FLG?
U 1 1 5EB80EF0
P 4350 3350
F 0 "#FLG?" H 4350 3425 50  0001 C CNN
F 1 "PWR_FLAG" H 4350 3526 50  0000 C CNN
F 2 "" H 4350 3350 50  0001 C CNN
F 3 "~" H 4350 3350 50  0001 C CNN
	1    4350 3350
	1    0    0    -1  
$EndComp
Connection ~ 4350 3350
Wire Wire Line
	4350 3350 4700 3350
Text GLabel 5900 3550 3    50   Input ~ 0
VGND
$Comp
L Connector:Conn_01x04_Male J?
U 1 1 5EB810B1
P 7400 3650
F 0 "J?" H 7372 3529 50  0000 R CNN
F 1 "Conn_01x04_Male" H 7372 3622 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Horizontal" H 7400 3650 50  0001 C CNN
F 3 "~" H 7400 3650 50  0001 C CNN
	1    7400 3650
	-1   0    0    1   
$EndComp
Text GLabel 7200 3650 0    50   Input ~ 0
VGND
Wire Wire Line
	7200 3750 7200 3850
$Comp
L power:PWR_FLAG #FLG?
U 1 1 5EB81914
P 4350 3950
F 0 "#FLG?" H 4350 4025 50  0001 C CNN
F 1 "PWR_FLAG" H 4350 4125 50  0000 C CNN
F 2 "" H 4350 3950 50  0001 C CNN
F 3 "~" H 4350 3950 50  0001 C CNN
	1    4350 3950
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x03_Male J?
U 1 1 604BFAAE
P 5150 2800
F 0 "J?" H 5256 3078 50  0000 C CNN
F 1 "Conn_01x03_Male" H 5256 2987 50  0000 C CNN
F 2 "" H 5150 2800 50  0001 C CNN
F 3 "~" H 5150 2800 50  0001 C CNN
	1    5150 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 2800 5695 2800
Wire Wire Line
	5695 2800 5695 2890
$EndSCHEMATC
