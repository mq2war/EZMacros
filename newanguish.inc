#Event FG "You have entered Illsalin Marketplace."
sub entrance

/call RanInternalMoveTo -2276.55 -12.33
/call RanInternalMoveTo -2142.28 -10.12
/call RanInternalMoveTo -1931.24 7.06
/call RanInternalMoveTo -1839.03 43.72
/call RanInternalMoveTo -1740.21 79.34
/call RanInternalMoveTo -1646.19 111.69
/call RanInternalMoveTo -1526.36 127.58
/call RanInternalMoveTo -1526.36 127.58
/call RanInternalMoveTo -1331.58 93.79
/call RanInternalMoveTo -1067.12 20.61
/call RanInternalMoveTo -1067.12 20.61
/call RanInternalMoveTo -920.84 -24.10
/call getitem ${Param2} ${Param3}
/face heading 180
/delay 1s
/call KillFace 60
/if (!${SpawnCount[NPC radius 40]}) {
/call coh
} else {
/call KillFace 60
/delay 3s
/call KillFace 60
/call coh
}
/if (${Param1.Equal[true]}) {
/call LootIt 60
} else {
/bct ${Param0} //macro hohloot
}
/call storeweapon ${Param2} ${Param3}
/call RanInternalMoveTo -816.81 -57.04
/call RanInternalMoveTo -658.50 -91.51
/face heading 180
/delay 1s
/call KillFace 60
/if (!${SpawnCount[NPC radius 40]}) {
/call coh
} else {
/call KillFace 60
/delay 3s
/call KillFace 60
/call coh
}}
  
		
/delay 3s
/if (${Param1.Equal[true]}) {
/call LootIt 60
} else {
/bct ${Param0} //macro hohloot
}
/call RanInternalMoveTo -465.07 -64.72
/call RanInternalMoveTo -251.79 -21.80
/call RanInternalMoveTo 249.15 1.16
/call RanInternalMoveTo 257.62 -0.81
/call RanInternalMoveTo 567.55 2.92
/face heading 180
/delay 1s
/call KillFace 60
/if (!${SpawnCount[NPC radius 40]}) {
/call coh
} else {
/call KillFace 60
/delay 3s
/call KillFace 60
/call coh
}}
/call RanInternalMoveTo 546.63 42.93
/call RanInternalMoveTo 546.00 -39.78
/call RanInternalMoveTo 567.55 2.92
/delay 1s
/call KillFace 60
/if (!${SpawnCount[NPC radius 40]}) {
/call coh
} else {
/call KillFace 60
/delay 3s
/call KillFace 60
/call coh
}
  
/delay 3s
/if (${Param1.Equal[true]}) {
/call LootIt 60
} else {
/bct ${Param0} //macro hohloot
}
/call RanInternalMoveTo 604.11 -83.69

/call RanInternalMoveTo 681.43 -146.92
/call RanInternalMoveTo 701.38 -311.29
/call KillFace 40
/delay 1s
/if (!${SpawnCount[NPC radius 40]}) {
/call coh
} else {
/call KillFace 60
/delay 3s
/call KillFace 60
/call coh
}
       
/delay 3s
/if (${Param1.Equal[true]}) {
/call LootIt 60
} else {
/bct ${Param0} //macro hohloot
}
/call RanInternalMoveTo 703.03 -137.95
/call RanInternalMoveTo 783.49 -103.02
/call RanInternalMoveTo 825.71 -26.30
/call RanInternalMoveTo 807.17 110.21
/call RanInternalMoveTo 706.23 155.71
/call RanInternalMoveTo 684.43 155.70
/call KillFace 60
 /if (!${SpawnCount[NPC radius 40]}) {
/call coh
} else {
/call KillFace 60
/delay 3s
/call KillFace 60
/call coh
}
/delay 3s
/call coh
/delay 2s
/if (${Param1.Equal[true]}) {
/call LootIt 60
} else {
/bct ${Param0} //macro hohloot
}
/delay 30s

/return


sub coh

/if (${Param1.Equal[true]}) /return

/echo "CoH"
/delay 2s
/itemnotify ammo rightmouseup
/delay 3s
/itemnotify ammo rightmouseup
/delay 2s

/return

sub gren

/call RanInternalMoveTo 762.87 121.33
/call RanInternalMoveTo 805.48 112.70
/call RanInternalMoveTo 846.37 17.30
/call zonecheck
/call RanInternalMoveTo 1454.38 3.03
/call RanInternalMoveTo 1473.94 7.4
/call RanInternalMoveTo 1662.11 -47.14
/face heading 180
/call KillFace 60
/if (${Param1.Equal[true]}) {
/call LootIt 60
} else {
/call coh
/delay 5s
/bct ${Param0} //macro hohloot
}
	
/delay 3s
/call coh
/delay 2s
/if (${Param1.Equal[true]}) {
/call LootIt 60
} else {
/bct ${Param0} //macro hohloot
}
/call zonecheck
/call RanInternalMoveTo 1548.06 -107.82
/call RanInternalMoveTo 1646.52 -147.19
/call RanInternalMoveTo 1766.95 -97.69
/call RanInternalMoveTo 1811.13 -5.21
/call RanInternalMoveTo 1743.02 111.63
/call zonecheck
/call RanInternalMoveTo 1651.78 161.03
/call RanInternalMoveTo 1561.20 103.50
/call RanInternalMoveTo 1656.62 57.46
/call KillFace 60
/call LootIt 60

/call zonecheck

/delay 10s

/return


sub bozak


/twist 11


/call RanInternalMoveTo 2860.78 53.56
/call KillFace 60

/call RanInternalMoveTo 2841.22 192.45
/call KillFace 60

/call RanInternalMoveTo 2935.73 184.43

/call RanInternalMoveTo 2863.44 182.81
/face heading 0
/delay 2s
/call KillFace 60
/delay 2s
/call KillFace 60
/if (!${SpawnCount[NPC radius 40]}) {
/call coh
} else {
/call KillFace 60
/call coh
}
/call KillFace 60
/delay 3s

/call coh

/bct ${Param0} //macro hohloot

/delay 20s

/call RanInternalMoveTo 2841.22 192.45
/call KillFace 60

/call RanInternalMoveTo 2860.78 53.56


/call RanInternalMoveTo 2860.97 60.25
/call coh
/delay 5s
/call coh

/return 

sub ture
/call RanInternalMoveTo 3057.27 593.91

/call RanInternalMoveTo 2883.03 593.91

/face heading 0
/keypress back
/call KillFace 60
/call KillFace 60
/delay 2s
/call coh
/delay 5s

/bct ${Param0} //macro hohloot
/delay 15s

/call RanInternalMoveTo 3157.57 587.43

/call RanInternalMoveTo 2938.61 607.99
/face heading 0 fast
/keypress back
/delay 1s
/call KillFace 60
/if (!${SpawnCount[NPC radius 60]} == 0) {
/call coh
} else {
/call KillFace 60
/call coh
}
/call KillFace 60
/delay 3s

/call coh

/bct ${Param0} //macro hohloot
/delay 30s

/call RanInternalMoveTo 2863.16 611.97
/call coh

/return


sub solo
/twist off
/call RanInternalMoveTo -2276.55 -12.33
/call RanInternalMoveTo -2142.28 -10.12
/call RanInternalMoveTo -1931.24 7.06
/call RanInternalMoveTo -1839.03 43.72
/call RanInternalMoveTo -1740.21 79.34
/call zonecheck
/call RanInternalMoveTo -1646.19 111.69
/call RanInternalMoveTo -1526.36 127.58
/call RanInternalMoveTo -1526.36 127.58
/call RanInternalMoveTo -1331.58 93.79
/call RanInternalMoveTo -1067.12 20.61
/call zonecheck
/call RanInternalMoveTo -920.84 -24.10
/call RanInternalMoveTo -658.50 -91.51
/call RanInternalMoveTo -465.07 -64.72
/call RanInternalMoveTo -251.79 -21.80
|Cerberus
/call RanInternalMoveTo 249.15 1.16
/call RanInternalMoveTo 257.62 -0.81
/face heading 180
/delay 4
/call KillFace 60		
/delay 2s
/if (${Param1.Equal[true]}) {
/call LootIt 60
} else {
/call coh
/delay 5s
/bct ${Param0} //macro hohloot
}
/call zonecheck
/twist off
/call RanInternalMoveTo 213.09 -0.65
/call RanInternalMoveTo 567.55 2.92
/call RanInternalMoveTo 546.63 42.93
/call RanInternalMoveTo 546.00 -39.78
/call RanInternalMoveTo 567.55 2.92
/call RanInternalMoveTo 604.11 -83.69
/call RanInternalMoveTo 681.43 -146.92
/call RanInternalMoveTo 701.38 -311.29
/call KillFace 60       
/delay 1s
/if (${Param1.Equal[true]}) {
/call LootIt 60
} else {
/call coh
/delay 5s
/bct ${Param0} //macro hohloot
}
/call zonecheck
/twist off
/call RanInternalMoveTo 703.03 -137.95
/call RanInternalMoveTo 783.49 -103.02
/call RanInternalMoveTo 825.71 -26.30
/call RanInternalMoveTo 807.17 110.21
/call RanInternalMoveTo 706.23 155.71
/call RanInternalMoveTo 684.43 155.70
/call KillFace 30

/if (${Param1.Equal[true]}) {
/call LootIt 60
} else {
/call coh
/delay 5s
/bct ${Param0} //macro hohloot
}

/call zonecheck

/return


sub anguish3
/call RanInternalMoveTo -1951.53 -9.90
/call RanInternalMoveTo -1549.64 145.46
/echo At First Kill
/call KillFace 30	
/echo Out of KillFace	
/delay 2s
/call LootIt 60
/call RanInternalMoveTo -1477.55 138.10
/call RanInternalMoveTo -1322.55 82.68
/call RanInternalMoveTo -1255.08 6.67
/call RanInternalMoveTo -1135.66 50.59
/call RanInternalMoveTo -703.72 -98.69
/call RanInternalMoveTo -237.53 -10.49
/echo At 2nd Kill
/call KillFace 40
/call LootIt 60
/echo Out of KillFace		
/delay 2s
/call RanInternalMoveTo 235.92 67.45
/call RanInternalMoveTo 148.23 -231.72
/call RanInternalMoveTo 227.53 -3.35
/call RanInternalMoveTo 553.27 -2.85
/call RanInternalMoveTo 603.34 -99.75
/call RanInternalMoveTo 695.31 -147.12
/call RanInternalMoveTo 715.70 -313.02
/call RanInternalMoveTo 698.01 -249.11
/call RanInternalMoveTo 711.67 -18.76
/call RanInternalMoveTo 701.39 163.76
/call KillFace 40		
/call LootIt 60
/call InternalMoveTo 706.59 135.94
/call InternalMoveTo 809.59 110.14
/call RanInternalMoveTo 827.89 33.07
/call RanInternalMoveTo 930.43 3.33
/call KillFace 40		
/delay 2s
/call LootIt 60
/call RanInternalMoveTo 1512.92 3.33
/call RanInternalMoveTo 1624.94 170.99
/call RanInternalMoveTo 1616.91 -67.13
/call RanInternalMoveTo 1863.22 4.13
/call KillFace 40		
/delay 2s
/call LootIt 60



/return

sub anguish2

/declare random int inner
/varset random ${Math.Ran[1]}

/call RanInternalMoveTo -2438.89 -8.75
/call RanInternalMoveTo -2319.65 -16.07
/call RanInternalMoveTo -1845.36 24.77
/call RanInternalMoveTo -1566.91 153.55
/call RanInternalMoveTo -1277.09 41.76
/call KillFace 40		
/call LootIt 60
/call RanInternalMoveTo -952.10 8.64
/call RanInternalMoveTo -662.58 -98.11
/call RanInternalMoveTo -243.65 -30.70
/call RanInternalMoveTo 223.29 47.09
/call KillFace 40		
/call LootIt 60

/if (${random}==0) {
/call RanInternalMoveTo 188.42,7.45
} else {
/call InternalMoveTo 223.89,7.02
}
/call RanInternalMoveTo 546.04 -6.29
/call RanInternalMoveTo 616.10 -111.15
/call RanInternalMoveTo 703.98 -180.07
/call RanInternalMoveTo 703.98 -311.22
/call RanInternalMoveTo 700.73 -302.44
/call RanInternalMoveTo 707.62 -22.72
/call RanInternalMoveTo 699.26 114.97
/call RanInternalMoveTo 702.16 200.33
/call KillFace 40		
/call LootIt 60
/call RanInternalMoveTo 807.52 88.58
/call RanInternalMoveTo 825.22 19.26
/call RanInternalMoveTo 1063.00 -4.16
/call RanInternalMoveTo 1241.14 17.81
/call RanInternalMoveTo 1611.30 17.81
/call InternalMoveTo 1602.30 7.66
/call KillFace 40		
/call LootIt 60
/delay 10s

/return

sub Event_FG

/beep
/beep
/camp

/return

sub zonecheck

/if (!${Zone.Name.Equal[Anguish, the Fallen Palace]}) {
/beep

/endmacro
}

/return