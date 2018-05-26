sub warbuff

/declare weaponloc string local

|/if (${FindItemCount[Kreljnok's Sword of Defense Epic 5.0]}>0) 
|/varset weaponloc ${Kreljnok's Sword of Defense Epic 5.0]}

/windowstate InventoryWindow open
/delay 1s

/if (!${Window[pack1].Open}) {
/itemnotify pack1 rightmouseup
}
/delay 1s
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


sub warcheck

/if (${Me.Name.Equal[Maslow]}) {

/itemnotify back rightmouseup
/twist 11
/twist 14
/twist 11 14

/call warbuff

}

/if (${Me.Name.Equal[Usurp]}) {

/itemnotify back rightmouseup
/twist 11
/twist 14
/twist 11 14

/call warbuff


}

/return