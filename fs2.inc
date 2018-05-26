
sub fs2(int bag, int slot)

/twist off
/call warbuff
/pet leave

/delay 1s

/call storeweapon ${bag} ${slot}

/call RanInternalMoveTo 297.89 769.55
/call RanInternalMoveTo 314.87 760.20
/call RanInternalMoveTo 351.91 713.96
/call RanInternalMoveTo 371.40 702.44
/call RanInternalMoveTo 376.72 790.11
/call RanInternalMoveTo 379.28 862.50
/call RanInternalMoveTo 387.95 820.42
/call RanInternalMoveTo 420.50 821.99
/call RanInternalMoveTo 442.28 812.31
/call RanInternalMoveTo 433.81 867.64
/call RanInternalMoveTo 449.20 827.57
/call RanInternalMoveTo 490.40 817.74
/call RanInternalMoveTo 498.00 866.73
/call RanInternalMoveTo 521.24 816.11
/call RanInternalMoveTo 558.15 813.64
/call RanInternalMoveTo 553.01 846.92
/call RanInternalMoveTo 570.78 805.04
/call RanInternalMoveTo 570.38 720.11
/call RanInternalMoveTo 564.99 607.97
/call RanInternalMoveTo 560.42 496.14
/call RanInternalMoveTo 550.16 431.38
/call RanInternalMoveTo 545.73 487.76
/call RanInternalMoveTo 484.08 490.59
/call RanInternalMoveTo 493.91 445.84
/call RanInternalMoveTo 503.83 498.97
/call RanInternalMoveTo 447.06 490.83
/call RanInternalMoveTo 439.75 437.28
/call RanInternalMoveTo 442.90 490.18
/call RanInternalMoveTo 440.24 600.61
/call RanInternalMoveTo 440.20 602.15
/call RanInternalMoveTo 341.29 595.63
/call RanInternalMoveTo 332.07 546.29
/call RanInternalMoveTo 305.89 502.92
/call RanInternalMoveTo 255.64 522.10
/call RanInternalMoveTo 215.21 521.07
/call RanInternalMoveTo 197.05 606.45
/call RanInternalMoveTo 199.25 717.12
/call RanInternalMoveTo 229.96 767.20
/call RanInternalMoveTo 230.14 779.76
/call RanInternalMoveTo 226.37 789.63
/call RanInternalMoveTo 258.87 806.94

/delay 2s

/call getitem ${bag} ${slot}

/delay 1s

/call NewKillFace 30

/call RanInternalMoveTo 258.87 806.94

/call NewKillFace 30

/return

