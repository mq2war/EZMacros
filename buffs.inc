sub soa

/if (${Me.Name.Equal[Maslow]}||${Me.Name.Equal[Usurp]}) {

/itemnotify back rightmouseup

}



/return

sub xpbuff

/twist off

/if (${Me.Name.Equal[Maslow]}) {


/windowstate InventoryWindow open
/delay 1s

/if (!${Window[pack1].Open}) {
/itemnotify pack1 rightmouseup
}
/delay 1s
/nomodkey /ctrlkey /itemnotify ${FindItem[=Easy Experience v1 (Reward Item)].InvSlot} leftmouseup
/delay 1s
/itemnotify pack4 leftmouseup
/delay 1s
/itemnotify pack4 rightmouseup
/itemnotify pack4 rightmouseup
/delay 1s
/itemnotify pack4 leftmouseup
/delay 1s
/autoinv

}

/return

sub warbuff

/declare petloc string local
/declare epicloc string local
/declare counter string local
/varset counter 0

:sw
/varcalc counter ${counter} + 1

/itemnotify back rightmouseup
/delay 5
/itemnotify mainhand rightmouseup
/delay 1s

/windowstate InventoryWindow open
/delay 1s
/if (!${Window[pack1].Open}) {
/itemnotify pack1 rightmouseup
}
/delay 1s





:pet

/call pet


/target ${Me.Pet}
/delay 2
/face
/say buff me

/if (${counter}<4) {  

/if (!${Me.Song[Warrior's Defense VIII].ID}) /goto :sw

/if (!${Me.Song[Ancient Stonewall XII].ID} && ${Me.Name.Equal[Maslow]}) /goto :sw
/if (!${Me.Song[Ancient Stonewall XII].ID} && ${Me.Name.Equal[Usurp]}) /goto :sw

}

/windowstate InventoryWindow close

:end

/if (${Cursor.ID}) {
/echo item still on cursor
/itemnotify pack4 leftmouseup
}
/delay 5
/echo Final Auto Inv


/if (${Window[pack1].Open}) {
/itemnotify pack1 rightmouseup
}

/return




sub pet 

/declare petloc string local

:pet


/varset petloc ${FindItem[=Insane Goblin Familiar (Halloween Reward)].InvSlot}
/itemnotify ${petloc} rightmouseup
/delay 3
|/delay 1s
|put pet in pack4 inv slot
|/itemnotify pack4 leftmouseup
|/delay 1s
|summon pet
|/itemnotify pack4 rightmouseup
|/delay 2s
|/itemnotify pack4 leftmouseup
|/delay 2s
|/nomodkey /ctrlkey /itemnotify ${petloc} leftmouseup


/return

sub epic
/declare epicloc string local

/if (!${Window[pack1].Open}) {
/itemnotify pack1 rightmouseup
}
/delay 2s

/delay 1s
/varset epicloc ${FindItem[=Kreljnok's Sword of Defense Epic 7.0].InvSlot}
/nomodkey /ctrlkey /itemnotify ${epicloc} leftmouseup

/delay 2s
/if (!${Cursor.Name.Equal[Kreljnok's Sword of Defense Epic 7.0]}) {
/echo in first !
/itemnotify ${epicloc} leftmouseup
}
/delay 1s
/itemnotify pack4 leftmouseup
/delay 2s
/itemnotify pack4 rightmouseup
/delay 2s
/itemnotify pack4 rightmouseup
/delay 1s

/itemnotify ${FindItem[=Kreljnok's Sword of Defense Epic 7.0].InvSlot} leftmouseup
/if (${Cursor.Name.Equal[Kreljnok's Sword of Defense Epic 7.0]}) {
/delay 2s
} else {
/itemnotify ${FindItem[=Kreljnok's Sword of Defense Epic 7.0].InvSlot} leftmouseup
}
/delay 2s
/nomodkey /ctrlkey /itemnotify ${epicloc} leftmouseup 


/return


sub pets


/bca //pet leave

/delay 1s


/bca //keypress =

/delay 1s

/bca //keypress =

/delay 5



/bct variable //pet leave
/bct lateral //pet leave
/bct necro //pet leave

/delay 3
/bct lateral //itemnotify mainhand rightmouseup
/bct lastride //itemnotify mainhand rightmouseup
/bct variable //itemnotify mainhand rightmouseup
/bct warhorse //itemnotify mainhand rightmouseup
/bct atisa //itemnotify mainhand rightmouseup
/bct imeltface //itemnotify mainhand rightmouseup

/delay 6s

/bca //target ${Me.Pet}
/delay 2
/bca //say buff me
/delay 2
/bca //say arm yourself

/bct variable //macro petbuff

/return

sub six

/return

sub seven

/return


sub petbuff

/bct variable //target pet

/bct variable //cast 7

/delay 2s

/bct variable //cast 3

/delay 2s

/bct variable //cast 8

/delay 1s

/bct necro //target pet

/bct necro //useitem 11
/delay 4
/bct necro //cast "Glyph of Darkness"


/return


sub buffcheck

|| Should set buffsham, buffdrood and buffcleric variables



/if (!${Me.Buff[Ancestral Honor 10].ID})  {

|shaman
|Mass Buff
/bct pellets /keypress 9
/delay 4
/bct pellets //useitem 13

|druid

|Mass Buff
/bct delegate //keypress 9
/delay 4
/bct delegate //cast "Blessing of Ancient Oak III"

|cleric

/bct timesink //keypress 9
/delay 4

/bct timesink //cast "Armor of the Crab III"

/delay 2s






}





/return



sub buffup

/call uaig

/bct zerk //useitem 21

/bct monk //keypress 9

/bct cleric //cast "Armor of the Martyr III"

/bct pal //cast "Kaldar's Helping Hand II"

/delay 15

/bct pal //cast "Gift of the Avenger II"

/bct shaman //cast "Form of the Ancient Spirits II"

/bct necro //cast "Cloak of the Night II"

/delay 4

/bct necro //cast "Cloak of the Night III"

/bct ranger //cast 7

/bct sk //cast 9

/delay 2s

/bct sk //cast "Cloak of Anarchy II"

/bct ranger //cast "Howl of the Huntmaster II"

/bct cleric //cast "Amplify Healing"

/bca //useitem 11

/delay 15

/call afterzone

/call pets

/bct pal //macro palbuff

/bct shaman //cast "Tiny Terror"

/bct ranger //cast "Brushcoat II"


/bca //useitem 8

/delay 3s

/useitem 24 5

/delay 1s








/return



sub afterzone


/bct sk //cast "Call of the Void V"
/bct drood //cast "Form of the Werewolf II"
/bct shaman //cast "Form of Ancient Spirits II



/return


sub uaig


|/if (!${Me.Buff[Insane Goblin Blessing].ID}) { 
/echo test    
/useitem 2

/delay 5

|}

/return

sub ig

/declare petloc string local


/varset petloc ${FindItem[=Insane Goblin Familiar (Halloween Reward)].InvSlot}
/itemnotify ${petloc} rightmouseup
/delay 3



/return

