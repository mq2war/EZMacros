#Event repop "You already repop this zone within last 10 minutes."

sub CreateInstance


/declare bag int local

/varset bag 1

|open bag 1

|/windowstate InventoryWindow open
|/delay 2s

|/casting 

|/if (!${Window[pack${bag}].Open}) {
|/itemnotify pack${bag} rightmouseup
|/delay 2s
|}
|/itemnotify ${FindItem[=${myUpv1} Upgrade].InvSlot}
|/itemnotify in pack${bag} 2 leftmouseup
|/delay 1s
|put in slot 9
|/itemnotify pack8 leftmouseup
|/delay 1s
|/itemnotify pack8 rightmouseup
|/delay 2s
|/target npc radius 20
|/delay 1s

|/itemnotify pack8 leftmouseup
|/delay 2s

|/itemnotify in pack1 2 leftmouseup

/say waypoint
/delay 1s
|/say Delete Raid
|/delay 1s
|/say Create Raid Instance
|/delay 1s
/say Enter Raid
/delay 30s
/say Repop Instance
/delay 1s
/if (${Window[LargeDialogWindow].Open} && ${Window[LargeDialogWindow].Child[LDW_TextBox].Text.Find[Click Yes to Delete Instance.]}) /nomodkey /notify LargeDialogWindow LDW_YesButton leftmouseup
/delay 1s


/delay 30s

/echo Ready


|close bag 1

/windowstate ContainerWindow close


/return

sub CreateInstanceParty


/declare bag int local

/varset bag 1

|open bag 1

/windowstate InventoryWindow open
/delay 2s

|/casting 

|/if (!${Window[pack${bag}].Open}) {
|/itemnotify pack${bag} rightmouseup
|/delay 2s
}
|/itemnotify ${FindItem[=${myUpv1} Upgrade].InvSlot}
|/itemnotify in pack${bag} 2 leftmouseup
|/delay 1s
|put in slot 9
|/itemnotify pack8 leftmouseup
|/delay 1s
|/itemnotify pack8 rightmouseup
|/delay 2s
|/target npc radius 20
|/delay 1s

|/itemnotify pack8 leftmouseup
|/delay 2s

|/itemnotify in pack1 2 leftmouseup

/say waypoint
/delay 1s
/say Create Raid Instance
/delay 1s


/say Delete Raid

/say Enter Raid
|/delay 1s
|/if (${Window[LargeDialogWindow].Open} && ${Window[LargeDialogWindow].Child[LDW_TextBox].Text.Find[Click Yes to Delete Instance.]}) /nomodkey /notify LargeDialogWindow LDW_YesButton leftmouseup
|/delay 1s

|/bca //target ID ${Target.ID}
|/bca //stick 2
|/delay 2s

|/bca //say Create Guild Instance
|/delay 4s 
|/bca //target ID ${Target.ID}
|/bca //stick 2
|/bca //say Create Guild Instance

|/say Enter Guild Instance


/delay 30s

/echo Ready


|close bag 1

/windowstate ContainerWindow close


/return

sub CreateTacviInstance

/declare choice string local

/varset choice ${Ini[tacvi.ini,instance,type]} 

/echo ${choice}

/declare bag int local

/varset bag 1

|open bag 1

|/windowstate InventoryWindow open
|/delay 2s

|/casting 

|/if (!${Window[pack${bag}].Open}) {
|/itemnotify pack${bag} rightmouseup
|/delay 2s
|}
|/itemnotify ${FindItem[=${myUpv1} Upgrade].InvSlot}
|/itemnotify in pack${bag} 2 leftmouseup
|/delay 1s
|put in slot 9
|/itemnotify pack8 leftmouseup
|/delay 1s
|/itemnotify pack8 rightmouseup
|/delay 2s
|/target npc radius 20
|/delay 1s

|/itemnotify pack8 leftmouseup
|/delay 2s

|/itemnotify in pack1 2 leftmouseup


/say waypoint
/delay 1s
/if (${choice.Equal[raid]}) {
/say Delete Raid
/delay 1s
/say Create Raid Instance
/delay 1s
/say Enter Raid

}

/if (${choice.Equal[guild]}) {
/say Delete Guild
/delay 1s
/say Create Guild Instance
/delay 1s
/say Enter Guild

}

/if (${choice.Equal[solo]}) {
/say Delete Solo
/delay 1s
/say Create Solo Instance
/delay 2s
/say Enter Solo

}


/delay 1s
/if (${Window[LargeDialogWindow].Open} && ${Window[LargeDialogWindow].Child[LDW_TextBox].Text.Find[Click Yes to Delete Instance.]}) /nomodkey /notify LargeDialogWindow LDW_YesButton leftmouseup
/delay 1s


/delay 30s

/echo Ready


|close bag 1

/windowstate ContainerWindow close


/return


sub guildreturn

/if (!${Zone.Name.Equal[The Halls of Honor]}) {
/camp
/delay 40s
/endmacro
}

/target npc radius 40

/if (${Target.ID}) {

/call KillAllMobs 10 40
/delay 1s
/call KillAllMobs 10 40
/call LootIt 45


}

/twist off

/delay 5

/echo ${Param0}

/if (${Me.Name.Equal[Peign]}||${Me.Name.Equal[Usurp]}) {

/delay 3m
/say Repop Instance
/doevents
/delay 30s

} else {
/itemnotify rightfinger rightmouseup
/delay 40s

/if (${Math.Distance[${Me.Y},${Me.X}:-338.00,-2710.00]}>10) {

/call KillAllMobs 10 40
/delay 1s
/call KillAllMobs 10 40
/call LootIt 45


/itemnotify rightfinger rightmouseup


}

}



| need to parameterize this

/if (${Param0.Equal[raid]}) {

/say enter raid
/say raid join Peign
/say raid join Usurp

}

|/delay 2s

/if (${Param0.Equal[guild]}) {

/say enter guild

}

/if (${Param0.Equal[solo]}) {

/say enter solo

}

/delay 40s

/return

sub partyguildreturn

/if (!${Zone.Name.Equal[The Halls of Honor]}) {
/camp
/bct hoh //camp
/delay 40s
/endmacro
}

/target npc radius 40

/if (${Target.ID}) {

/call KillAllMobs 10 40
/delay 1s
/call KillAllMobs 10 40
/call LootIt 45


}

/twist off

/delay 2s

/echo ${Param0}

/bct hoh //twist off
/delay 2s


/bct hoh //itemnotify rightfinger rightmouseup
/itemnotify rightfinger rightmouseup
/delay 35s

/bct hoh //macro hohcheck

/delay 35s

/if (${Math.Distance[${Me.Y},${Me.X}:-338.00,-2710.00]}>10) {

/call KillAllMobs 10 40
/delay 1s
/call KillAllMobs 10 40
/call LootIt 45



/bct hoh //itemnotify rightfinger rightmouseup
/itemnotify rightfinger rightmouseup



}


| need to parameterize this

/if (${Param0.Equal[raid]}) {

/say enter raid

/say raid join Peign
/bct hoh //say raid join Peign


}

|/delay 2s

/if (${Param0.Equal[guild]}) {

/say enter guild
/bct hoh //say enter guild
}




/delay 40s





/return


sub abyssguild


/bct ${Param0} //say leave instance
/delay 1m
/bct ${Param0} //say delete guild
/bct ${Param0} //say create guild instance
/bct ${Param0} //say enter guild



/return

Sub Event_Repop

/delay 3m
/say repop instance

/return





