
sub entrance 

/call InternalMoveTo -1256.21 -3607.71


/call InternalMoveTo -1280.50 -3448.45

/call InternalMoveTo -1228.81 -3259.10
/call KillFace 60
/delay 1s



/call InternalMoveTo -1357.22 -3248.22
/call KillFace 60
/delay 1s

/call LootIt 100

/call InternalMoveTo -1372.65 -3010.25
/call KillFace 60
/delay 1s

/call LootIt 100

/call InternalMoveTo -1183.40 -3038.33
/call KillFace 60
/delay 1s

/call LootIt 100

/call InternalMoveTo -1096.61 -3118.75
/call KillFace 60
/delay 1s

/call LootIt 100

/call InternalMoveTo -990.81 -3048.06
/call KillFace 60
/delay 1s

/call LootIt 100

/call InternalMoveTo -829.11 -3016.85
/call KillFace 60
/delay 1s

/call LootIt 100

/call InternalMoveTo -771.91 -3060.36
/call KillFace 60
/delay 1s

/call LootIt 100


/call InternalMoveTo -495.34 -3373.33
/call KillFace 60
/delay 1s

/call LootIt 100

/call InternalMoveTo -759.85 -3354.83
/call KillFace 60
/delay 1s

/call LootIt 100


/call InternalMoveTo -710.58 -3410.54
/call KillFace 60
/delay 1s

/call LootIt 100

/call InternalMoveTo -433.99 -3078.56
/call KillFace 60
/delay 1s

/call LootIt 100

/call InternalMoveTo -213.25 -3252.29
/call KillFace 60
/delay 1s

/call LootIt 100

/call InternalMoveTo 231.96 -3043.81
/call KillFace 60
/delay 1
/call LootIt 100

/call InternalMoveTo 239.46 -2983.21
/call KillFace 60
/delay 1
/call LootIt 100

/call InternalMoveTo 101.87 -2997.78
/call KillFace 60
/delay 1
/call LootIt 100

/call InternalMoveTo 637.77 -3005.18
/call KillFace 60
/delay 1
/call LootIt 100

/call InternalMoveTo 712.29 -3448.26
/call KillFace 60
/delay 1
/call LootIt 100


/return

sub buffme
/windowstate InventoryWindow open
/delay 1s

/if (!${Window[pack1].Open}) {
/itemnotify pack1 rightmouseup
}
/delay 2s
/itemnotify in pack1 7 leftmouseup
/delay 1s
/itemnotify pack4 leftmouseup
/delay 1s
/itemnotify pack4 rightmouseup
/itemnotify pack4 rightmouseup
/delay 1s
/itemnotify pack4 leftmouseup
/delay 1s
/autoinv

/if (${Window[pack1].Open}) {
/itemnotify pack1 rightmouseup
}

/windowstate InventoryWindow close


/return 