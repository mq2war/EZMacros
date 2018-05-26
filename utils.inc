sub cycle

/declare count int local 0

:getmobs
/if (${count} < 15) {
/keypress `
/delay 5
/keypress 8
/keypress `
/delay 5
/keypress 8
/delay 5

/varset count ${Math.Calc[${count} + 1]}

}

/return


sub setloc
| need to declare mey and mex global in calling script
/deletevar * global
/declare mex int global
/declare mey int global
/delay 2

/varset mey ${Me.Loc.Arg[0,,]}
/echo ${mey}
/varset mex ${Me.Loc.Arg[2,,]}
/echo ${mex}
/delay 2

|/varset mey ${Me.Y}
|/varset mex ${Me.X}
/delay 5
/if (${mey}==0) {

/varset mey ${Me.Y}

}

/if (${mex}==0) {

/varset mex ${Me.X}

}


/return

sub lootgo
/declare baseLocY int inner 0
/declare baseLocX int inner 0
/varset baseLocY ${Me.Y}
/varset baseLocX ${Me.X}

/hidecorpse looted

:loot
/if (${SpawnCount[corpse radius ${Param0}]} > 0) { 

/if (${Cursor.ID}) /autoinv

/call LootIt ${Param0}

} 

/call InternalMoveTo ${baseLocY} ${baseLocX} 

/return


sub buffup 

/if (${Me.Class.Equal[Paladin]}) {

/if (${Me.SpellReady[Focus of Healing]} && !${Me.Buff[Focus of Healing].ID}) /cast "Focus of Healing"

/if (${Me.SpellReady[Kaldar's Helping Hand II]} && !${Me.Buff[Kaldar's Helping Hand II].ID}) /cast "Kaldar's Helping Hand II"

/cast "Crab Two Shoes Will Heal You"

}


/return

sub succor

/twist off



/windowstate InventoryWindow open
/delay 1s

/if (!${Window[pack1].Open}) {
/itemnotify pack1 rightmouseup
}
/delay 1s
/nomodkey /ctrlkey /itemnotify ${FindItem[=Succor (Reward Item)].InvSlot} leftmouseup
/delay 1s
/itemnotify pack4 leftmouseup
/delay 1s
/itemnotify pack4 rightmouseup
/itemnotify pack4 rightmouseup
/delay 1s
/itemnotify pack4 leftmouseup
/delay 1s
/autoinv





/return

sub storeweapon(int bag, int slot)

| Currently puts item in Slot 8 of passed bag #



|  Pass inventory slot to place weapon

/declare weaponslot

/if (${Cursor.ID}) /autoinv

/delay 2


|  Open Inventory

/windowstate InventoryWindow open
/delay 1s

/call openpack ${bag} ${slot}

/delay 1s

/if (${Me.Inventory[pack8].Items} < 10 ) {


| Find empty slot in bag  -   end if no empty slot




| Grab weapon

/itemnotify mainhand leftmouseup

 }  else {

/echo No empty bag slot 
/beep

/goto :end

}

|| Cursor check, if no item, return

/if (!${Cursor.ID}) {

/echo No Item On Cursor 

/goto :end


}


/delay 3

| Put in empty slot in bag

 /itemnotify in pack${bag} 8 leftmouseup

| Close Windows

/delay 3

/autoinv

/call closepack ${bag}


:end


/return


sub getitem(int bag, int slot)

/call openpack ${bag}

/delay 3


/itemnotify in pack${bag} ${slot} leftmouseup

/delay 4

/autoinv

/delay 4

/call closepack ${bag}

/return

sub closepack(int bag)

|Close Pack
/if (${Window[pack${bag}].Open}) {
/itemnotify pack${bag} rightmouseup
}

/if (${Window[InventoryWindow].Open}) /keypress inventory

/return

sub openpack(int bag)
|  Open pack 
/if (!${Window[pack${bag}].Open}) {
/itemnotify pack${bag} rightmouseup
}

/return

sub acceptrez


/if (${Window[ConfirmationDialogBox].Open} && !${Window[SpellBookWnd].Open} && ${Window[ConfirmationDialogBox].Child[CD_TextOutput].Text.Find[Resurrect]}) {
	/notify ConfirmationDialogBox Yes_Button leftmouseup
}

/return


sub itemcount


/echo ${Param0}

/if (${FindItemCount[${Param0}]}>0)  {

	/gu ${FindItemCount[${Param0}]}



}  

}

/return


sub rainbow


/if (${FindItemCount[Lesser Rainbow Crystal]}>0)  {

	/gu Lesser ${FindItemCount[Lesser Rainbow Crystal]}



}  

}

/if (${FindItemCount[Minor Rainbow Crystal]}>0)  {

	/gu Lesser ${FindItemCount[Minor Rainbow Crystal]}



}  

}

/return

sub gsoacount


/if (${FindItemCount[Gemstone of the Ages]}>0)  {

	/gu ${FindItemCount[Gemstone of the Ages]}



}  

}

/return

/return

sub chromecount


/if (${FindItemCount[Immaculate Chromatium Fragment]}>0)  {

	/gu ${FindItemCount[Immaculate Chromatium Fragment]}



}  

}

/return