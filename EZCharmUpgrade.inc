#Event Cfix "Your target is too far away, get closer!"
#Event Cfix "You can't hit them from here."
#Event Cfix "You cannot see your target."
#Event TooFar "Corpse too far away."
#Event NoLoot "You may not loot this corpse at this time."
#Event TooFarAway "#*#You are too far away to loot that corpse#*#"
#Event Summon "You have been summoned!"
#Event FG "You have entered Illsalin Marketplace."
|#GMSummoned
|#Say

|** We need to detect these variables **|



sub SetLootVar


|${Math.Rand[5]


/if (${Cursor.ID}) /autoinv
/if (!${Defined[x3]})           /declare x3 int outer
/if (!${Defined[y3]})           /declare y3 int outer
/if (!${Defined[inixint]})      /declare inixint int outer

/return 
sub SetupLDONvar
/if (${Cursor.ID}) /autoinv
/if (!${Ini[./wm/${Me.CleanName}_wmloot.ini,100,Version]}) /call LoadIni
/if (!${Defined[v1set]})        /declare v1set int outer 0
/if (!${Defined[myUpv1]})       /declare myUpv1 string outer NULL
/if (!${Defined[v1orc]})        /declare v1orc string outer
/if (!${Defined[v1sorc]})       /declare v1sorc string outer
/if (!${Defined[v1braw]})       /declare v1braw string outer
/if (!${Defined[v1guard]})      /declare v1guard string outer
/if (!${Defined[PackInv]})      /declare PackInv string outer
/if (!${Defined[MagicBoxSlot]}) /declare MagicBoxSlot string outer
/if (!${Defined[MyEpic]})       /declare MyEpic string outer NULL
/if (!${Defined[v1]})           /declare v1 string outer
/if (!${Defined[ocheck]})       /declare ocheck int outer 0
/if (!${Defined[scheck]})       /declare scheck int outer 0
/if (!${Defined[bcheck]})       /declare bcheck int outer 0
/if (!${Defined[gcheck]})       /declare gcheck int outer 0
/if (!${Defined[x3]})           /declare x3 int outer
/if (!${Defined[y3]})           /declare y3 int outer
/if (!${Defined[inixint]})      /declare inixint int outer
/if (${FindItemCount[Oracle's Charm LV]}>0)             /varset v1orc ${FindItem[Oracle's Charm]}
/if (${FindItemCount[Sorcer's Charm LV]}>0)             /varset v1sorc ${FindItem[Sorcer's Charm]}
/if (${FindItemCount[Brawler's Charm LV]}>0)    /varset v1braw ${FindItem[Brawler's Charm]}
/if (${FindItemCount[Guardian's Charm LV]}>0)   /varset v1guard ${FindItem[Guardian's Charm]}
/echo DEBUG [-+-] Loading Charm Keep selection to INI [-+-] DEBUG
/delay 10
/if (${FindItem[Oracle's Charm].Name.Arg[3, ].Right[2].Equal[V1]}||${FindItem[Oracle's Charm].Name.Arg[3, ].Right[2].Equal[V2]}||${FindItem[Oracle's Charm].Name.Arg[3, ].Right[2].Equal[V3]}||${FindItem[Oracle's Charm].Name.Arg[3, ].Right[2].Equal[V4]}||${FindItem[Oracle's Charm].Name.Arg[3, ].Right[2].Equal[V5]}||${FindItem[Oracle's Charm].Name.Arg[3, ].Right[2].Equal[V6]}||${FindItem[Oracle's Charm].Name.Arg[3, ].Right[2].Equal[V7]}||${FindItem[Oracle's Charm].Name.Arg[3, ].Right[2].Equal[V8]}||${FindItem[Oracle's Charm].Name.Arg[3, ].Right[2].Equal[V9]}) {
        /ini "./wm/${Me.CleanName}_wmloot.ini" "O" "Oracle's Upgrade" "Keep"
        /varset ocheck 1
}
/if (${FindItem[Sorcer's Charm].Name.Arg[3, ].Right[2].Equal[V1]}||${FindItem[Sorcer's Charm].Name.Arg[3, ].Right[2].Equal[V2]}||${FindItem[Sorcer's Charm].Name.Arg[3, ].Right[2].Equal[V3]}||${FindItem[Sorcer's Charm].Name.Arg[3, ].Right[2].Equal[V4]}||${FindItem[Sorcer's Charm].Name.Arg[3, ].Right[2].Equal[V5]}||${FindItem[Sorcer's Charm].Name.Arg[3, ].Right[2].Equal[V6]}||${FindItem[Sorcer's Charm].Name.Arg[3, ].Right[2].Equal[V7]}||${FindItem[Sorcer's Charm].Name.Arg[3, ].Right[2].Equal[V8]}||${FindItem[Sorcer's Charm].Name.Arg[3, ].Right[2].Equal[V9]}) {
        /ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Sorcerer's Upgrade" "Keep"
        /varset scheck 1
}
/if (${FindItem[Brawler's Charm].Name.Arg[3, ].Right[2].Equal[V1]}||${FindItem[Brawler's Charm].Name.Arg[3, ].Right[2].Equal[V2]}||${FindItem[Brawler's Charm].Name.Arg[3, ].Right[2].Equal[V3]}||${FindItem[Brawler's Charm].Name.Arg[3, ].Right[2].Equal[V4]}||${FindItem[Brawler's Charm].Name.Arg[3, ].Right[2].Equal[V5]}||${FindItem[Brawler's Charm].Name.Arg[3, ].Right[2].Equal[V6]}||${FindItem[Brawler's Charm].Name.Arg[3, ].Right[2].Equal[V7]}||${FindItem[Brawler's Charm].Name.Arg[3, ].Right[2].Equal[V8]}||${FindItem[Brawler's Charm].Name.Arg[3, ].Right[2].Equal[V9]}) {
        /ini "./wm/${Me.CleanName}_wmloot.ini" "B" "Brawler's Upgrade" "Keep"
        /varset bcheck 1
}
/if (${FindItem[Guardian's Charm].Name.Arg[3, ].Right[2].Equal[V1]}||${FindItem[Guardian's Charm].Name.Arg[3, ].Right[2].Equal[V2]}||${FindItem[Guardian's Charm].Name.Arg[3, ].Right[2].Equal[V3]}||${FindItem[Guardian's Charm].Name.Arg[3, ].Right[2].Equal[V4]}||${FindItem[Guardian's Charm].Name.Arg[3, ].Right[2].Equal[V5]}||${FindItem[Guardian's Charm].Name.Arg[3, ].Right[2].Equal[V6]}||${FindItem[Guardian's Charm].Name.Arg[3, ].Right[2].Equal[V7]}||${FindItem[Guardian's Charm].Name.Arg[3, ].Right[2].Equal[V8]}||${FindItem[Guardian's Charm].Name.Arg[3, ].Right[2].Equal[V9]}) {
        /ini "./wm/${Me.CleanName}_wmloot.ini" "G" "Guardian's Upgrade" "Keep"
        /varset gcheck 1
}
/echo DEBUG [-+-] Loading Charm Ignore selection to INI [-+-] DEBUG
/delay 10
/if (${ocheck}==1) /goto :scheck
        /if (${ocheck}==0 && ${FindItem[Oracle's Charm].Name.Arg[3, ].Right[2]}>24) /ini "./wm/${Me.CleanName}_wmloot.ini" "O" "Oracle's Upgrade" "Ignore"
:scheck
/if (${scheck}==1) /goto :bcheck
        /if (${scheck}==0 && ${FindItem[Sorcer's Charm].Name.Arg[3, ].Right[2]}>24) /ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Sorcerer's Upgrade" "Ignore"
:bcheck
/if (${bcheck}==1) /goto :gcheck
        /if (${bcheck}==0 && ${FindItem[Brawler's Charm].Name.Arg[3, ].Right[2]}>24) /ini "./wm/${Me.CleanName}_wmloot.ini" "B" "Brawler's Upgrade" "Ignore"
:gcheck
/if (${gcheck}==1) /goto :checkdone
        /if (${gcheck}==0 && ${FindItem[Guardian's Charm].Name.Arg[3, ].Right[2]}>24) /ini "./wm/${Me.CleanName}_wmloot.ini" "G" "Guardian's Upgrade" "Ignore"
:checkdone
/declare EpicChecker int local 0
/if (${Me.Class.ShortName.Equal[DRU]}) {
        /for EpicChecker 1 to ${Math.Calc[${Ini[./wm/wm2.ini,DruEpic].Count[|]}-1]}
                /if (${FindItemCount[=${Ini[./wm/wm2.ini,DruEpic,${EpicChecker}].Arg[1,^]}]}>0) /varset MyEpic ${Ini[./wm/wm2.ini,DruEpic,${EpicChecker}].Arg[1,^]}
        /next EpicChecker
}
/echo DEBUG [-+-] Finished Loading Charm Data to INI [-+-] DEBUG
/delay 10
/deletevar ocheck
/deletevar scheck
/deletevar bcheck
/deletevar gcheck
/deletevar EpicChecker
/echo DEBUG [-+-] Check wm2.ini settings and bind keys as required [-+-]
/if (!${Ini[./wm/wm2.ini,100,${Me.CleanName}]}) {
        /ini "./wm/wm2.ini" "100" "${Me.CleanName}" "1"
        /bind FIRST_PERSON_CAMERA P
        /bind CMD_TOGGLE_TICKET_WND clear
}
/return
                |** This should handle the charm upgrades more efficently **|
Sub CheckCharms
:dblcheck
/if (${Cursor.ID}) /autoinv
/if (${v1set}!=1 && ${FindItemCount[Oracle's Upgrade]}>0) {
        /varset v1 ${v1orc}
        /varset myUpv1 Oracle's
        /varset v1set 1
}
/if (${v1set}!=1 && ${FindItemCount[Sorcerer's Upgrade]}>0) {
        /varset v1 ${v1sorc}
        /varset myUpv1 Sorcerer's
        /varset v1set 1
}
/if (${v1set}!=1 && ${FindItemCount[Brawler's Upgrade]}>0) {
        /varset v1 ${v1braw}
        /varset myUpv1 Brawler's
        /varset v1set 1
}
/if (${v1set}!=1 && ${FindItemCount[Guardian's Upgrade]}>0) {
        /varset v1 ${v1guard}
        /varset myUpv1 Guardian's
        /varset v1set 1
}
/delay 5
/if (${v1set}!=1) /multiline ; /echo No Charm Found, exiting routine ; /return
/delay 15
/if (${v1.Arg[2,V]}>24) /return
/declare bag int local 0
/if (!${Window[InventoryWindow].Open}) /nomodkey /keypress inventory
/delay 3s ${Window[InventoryWindow].Open}
/for bag 1 to 8
/if (${InvSlot[pack${bag}].Item.Container}) /nomodkey /itemnotify pack${bag} rightmouseup
/next bag
/delay 15
/varset MagicBoxSlot ${FindItem[=A Magic Box].InvSlot.Name}
/varset PackInv ${FindItem[=${myUpv1} Upgrade].InvSlot.Pack.Name}
/nomodkey /ctrlkey /itemnotify ${FindItem[=${myUpv1} Upgrade].InvSlot} leftmouseup
/delay 5s ${Cursor.ID}
/nomodkey /itemnotify in ${MagicBoxSlot} 1 leftmouseup
/delay 5s !${Cursor.ID}
/nomodkey /itemnotify ${FindItem[=${v1}].InvSlot} leftmouseup
/delay 5s ${Cursor.ID}
/nomodkey /itemnotify in ${MagicBoxSlot} 2 leftmouseup
/delay 5s !${Cursor.ID}
/for bag 1 to 8
/if (${InvSlot[pack${bag}].Item.Name.NotEqual[A Magic Box]}) /nomodkey /itemnotify pack${bag} rightmouseup
/next bag
/delay 30
/if (${Window[${MagicBoxSlot}].Open}) /combine ${MagicBoxSlot}
/delay 5s ${Cursor.ID}
/if (${Cursor.ID}) /autoinv
/if (${Window[${MagicBoxSlot}].Open}) /nomodkey /itemnotify ${MagicBoxSlot} rightmouseup
/if (${Window[InventoryWindow].Open}) /nomodkey /keypress inventory
/deletevar v1set
/deletevar bag
/deletevar myUpv1
/deletevar v1
/deletevar PackInv
/call SetupLDONvar
/goto :dblcheck
/return
                |** For looting we're going to try this hack of ninjadvloot.inc **|
Sub LootIt

/call CheckFG

/declare LootTotal int local -1 


/delay 5

/if (${SpawnCount[GM]} > 0) {
/delay 30s
/goto :start
} 


/if (${Zone.Name.Equal[nexus]}) {
/camp
/delay 40s
/endmacro
}

/if (${Zone.Name.Equal[Illsalin Marketplace]}) {
/camp
/delay 40s
/endmacro
}

/if (${SpawnCount[rare radius ${Param0}]}) {
		
		/target rare
/open		
}
/if (${SpawnCount[anguish radius ${Param0}]}) {
		
		/target anguish
/open		
}


/if (${Cursor.ID}) /autoinv
/declare CurrentInisetting string local
/if (!${Me.FreeInventory}) /multiline ; /echo Inventory error, please fix it.;/popup Inventory Error. Fix and Restart Macro;/mqlog LootError - ${Time.Date} - ${Time} - ${Me.CleanName} - ${Zone.ID};/autoinv;/endmac
:looting

/echo in Loot It
/if (${SpawnCount[CORPSE radius ${Param0}]}) {
        /target id ${Spawn[CORPSE radius ${Param0}].ID}
        /stick 8
        /delay 300 ${Target.Distance}<=10
        /loot
		/doevents 
        /delay 1
		
:LootLag 
/if (${LootTotal}!=${Corpse.Items}) { 
/echo In Loot Lag
/varset LootTotal ${Corpse.Items} 
/delay 3 
/goto :LootLag 
} 


|	/echo ${Window[LootWnd].FirstChild[LW_CorpseName].Text}

|	/if (${Window[LootWnd].FirstChild[LW_CorpseName].Text.Equal[Chest's corpse]}) {

|		/keypress esc
|		/keypress forward 
|		/keypress forward 

|                /notify LootWnd LW_DoneButton leftmouseup
|                /goto :looting

|}
        /if (!${Corpse.Items}) /keypress esc
        /delay 3
        /if (!${Corpse.Items}) {
                /nomodkey /notify LootWnd LW_DoneButton leftmouseup
                /goto :looting
        }
/for x3 ${Corpse.Items} downto 1


|/if (${Corpse.Item[${x3}].Name.Equal[Guardian's Upgrade v2]}) {
 
|/gu Guardian found
|}

/if (${Corpse.Item[${x3}].Name.Equal[Unholy Shackles II]}) {
 
/gu Shackles found

/t maslow Shackles Found!
}

/if (${Corpse.Item[${x3}].Name.Equal[Hungering Pyre II]}) {
 
/gu Shackles found

/t maslow Pyre Found!
}

/if (${Corpse.Item[${x3}].Name.Equal[Insinuations of Mori II]}) {
 
/gu Shackles found

/t maslow Shackles Found!
}


/if (${Corpse.Item[${x3}].Name.Equal[Red Toned Diamond]}) {
 
/gu RDT found

/t maslow Shackles Found!
}

/if (${Corpse.Item[${x3}].Name.Equal[Silver Toned Diamond]}) {
 
/gu STD found

/t maslow Shackles Found!
}

/if (${Corpse.Item[${x3}].Name.Equal[Mount: Crack'n Crazy Traveler]}) {
 
/gu Shackles found

/t maslow Mount found!
}
|/if (${Corpse.Item[${x3}].Name.Equal[Shiny Snake Skin]}) {
 
|/gu Shiny Snake Skin found

|/t maslow Shackles Found!
|}


|/if (${Corpse.Item[${x3}].Name.Equal[Sorcerer's Upgrade v2]}) {
 
|/gu Sorc found
|}

/if (${Corpse.Item[${x3}].Name.Find[Green Veeshan Scales]}) {
 /itemnotify loot${x3} rightmouseup
 /delay 15 ${Window[ConfirmationDialogBox].Open} || !${Corpse.Item[${i}].NoDrop}
 /if (${Window[ConfirmationDialogBox].Open}) /nomodkey /notify ConfirmationDialogBox Yes_Button leftmouseup
 /delay 15 ${Cursor.ID} || ${WhichButton.NotEqual[left]}

}




/if (${Corpse.Item[${x3}].Name.Find[Silver Veeshan Scales]}) {
 /itemnotify loot${x3} rightmouseup
 /delay 15 ${Window[ConfirmationDialogBox].Open} || !${Corpse.Item[${i}].NoDrop}
 /if (${Window[ConfirmationDialogBox].Open}) /nomodkey /notify ConfirmationDialogBox Yes_Button leftmouseup
 /delay 15 ${Cursor.ID} || ${WhichButton.NotEqual[left]}

}

/if (${Corpse.Item[${x3}].Name.Find[Red Veeshan Scales]}) {
 /itemnotify loot${x3} rightmouseup
 /delay 15 ${Window[ConfirmationDialogBox].Open} || !${Corpse.Item[${i}].NoDrop}
 /if (${Window[ConfirmationDialogBox].Open}) /nomodkey /notify ConfirmationDialogBox Yes_Button leftmouseup
 /delay 15 ${Cursor.ID} || ${WhichButton.NotEqual[left]}

}


/if (${Corpse.Item[${x3}].Name.Equal[H-One N-One Quest Token]}) {
 /itemnotify loot${x3} rightmouseup
 /delay 15 ${Window[ConfirmationDialogBox].Open} || !${Corpse.Item[${i}].NoDrop}
 /if (${Window[ConfirmationDialogBox].Open}) /nomodkey /notify ConfirmationDialogBox Yes_Button leftmouseup
 /delay 15 ${Cursor.ID} || ${WhichButton.NotEqual[left]}

}

/if (${Corpse.Item[${x3}].Name.Equal[Split Paw Quest Token]}) {
 /itemnotify loot${x3} rightmouseup
 /delay 15 ${Window[ConfirmationDialogBox].Open} || !${Corpse.Item[${i}].NoDrop}
 /if (${Window[ConfirmationDialogBox].Open}) /nomodkey /notify ConfirmationDialogBox Yes_Button leftmouseup
 /delay 15 ${Cursor.ID} || ${WhichButton.NotEqual[left]}

}

/if (${Corpse.Item[${x3}].Name.Find[20,000 AA Experience Crystal]}) {
 /itemnotify loot${x3} rightmouseup
 /delay 15 ${Window[ConfirmationDialogBox].Open} || !${Corpse.Item[${i}].NoDrop}
 /if (${Window[ConfirmationDialogBox].Open}) /nomodkey /notify ConfirmationDialogBox Yes_Button leftmouseup
 /delay 15 ${Cursor.ID} || ${WhichButton.NotEqual[left]}

}

/if (${Corpse.Item[${x3}].Name.Find[50,000 AA Experience Crystal]}) {
 /itemnotify loot${x3} rightmouseup
 /delay 15 ${Window[ConfirmationDialogBox].Open} || !${Corpse.Item[${i}].NoDrop}
 /if (${Window[ConfirmationDialogBox].Open}) /nomodkey /notify ConfirmationDialogBox Yes_Button leftmouseup
 /delay 15 ${Cursor.ID} || ${WhichButton.NotEqual[left]}

}


/if (${Corpse.Item[${x3}].Name.Find[Red Toned Diamond]}) {
 /itemnotify loot${x3} rightmouseup
 /delay 15 ${Window[ConfirmationDialogBox].Open} || !${Corpse.Item[${i}].NoDrop}
 /if (${Window[ConfirmationDialogBox].Open}) /nomodkey /notify ConfirmationDialogBox Yes_Button leftmouseup
 /delay 15 ${Cursor.ID} || ${WhichButton.NotEqual[left]}

}


|/if (${Corpse.Item[${x3}].Name.Find[Silver Toned Diamond]}) {
| /itemnotify loot${x3} rightmouseup
 |/delay 15 ${Window[ConfirmationDialogBox].Open} || !${Corpse.Item[${i}].NoDrop}
 |/if (${Window[ConfirmationDialogBox].Open}) /nomodkey /notify ConfirmationDialogBox Yes_Button leftmouseup
 |/delay 15 ${Cursor.ID} || ${WhichButton.NotEqual[left]}

|}

/if (${Corpse.Item[${x3}].ID} && !${Select[${Ini[./wm/${Me.CleanName}_wmloot.ini,"${Corpse.Item[${x3}].Name.Left[1]}","${Corpse.Item[${x3}]}"]},Ignore,Keep]}) {
        /ini "./wm/${Me.CleanName}_wmloot.ini" "${Corpse.Item[${x3}].Name.Left[1]}" "${Corpse.Item[${x3}]}" Ignore
}
/varset CurrentInisetting ${Ini[./wm/${Me.CleanName}_wmloot.ini,"${Corpse.Item[${x3}].Name.Left[1]}","${Corpse.Item[${x3}]}"]}
/if (${CurrentInisetting.Equal[Keep]}) {
 /itemnotify loot${x3} rightmouseup
 /delay 15 ${Window[ConfirmationDialogBox].Open} || !${Corpse.Item[${i}].NoDrop}
   /if (${Window[ConfirmationDialogBox].Open}) /nomodkey /notify ConfirmationDialogBox Yes_Button leftmouseup
   /delay 15 ${Cursor.ID} || ${WhichButton.NotEqual[left]}
}
/delay 2
/next x3
/nomodkey /notify LootWnd LW_DoneButton leftmouseup
/if (${SpawnCount[CORPSE radius ${Param0}]}) /goto :looting
/delay 1
}
/if (${FindItemCount[=Oracle's Upgrade]}>0) /call CheckCharms Oracle's
/if (${FindItemCount[=Sorcerer's Upgrade]}>0) /call CheckCharms Sorcerer's
/if (${FindItemCount[=Brawler's Upgrade]}>0) {
/call CheckCharms Brawler's
/beep
}
/if (${FindItemCount[=Guardian's Upgrade]}>0) /call CheckCharms Guardian's
/return
 
|** Call this sub and pass it the floor to have it return otherwise it'll stay in nexus **|
Sub ThereAndBackAgain
/if (${Me.Inventory[feet].Spell.Name.Equal[Nexus Gate]}) { /itemnotify feet rightmouseup } else /if (${Me.Inventory[Charm].Spell.Name.Equal[Nexus Gate]}) { /itemnotify charm rightmouseup } else { /multiline ; /echo No Nexus Gate found in common slot. Sucks to be you.;/mqlog GateError (you suck)- ${Time.Date} - ${Time} - ${Me.CleanName};/endmac }
/delay 10m ${Me.State.NotEqual[ZONING]}
/call InternalMoveTo -59.26 -0.50
/call InternalMoveTo -127.47 17.01
/call InternalMoveTo -200.08 53.04
/call InternalMoveTo -232.51 54.36
/target Tsukasa
/delay 1s ${Target.CleanName.Equal[Tsukasa]}
/say sell all your credit tokens
/say sell all your armor cards
/delay 5s
/if (!${param0}) /multiline ; /echo You did not specify a floor to return to. Ending Macro.;/mqlog FloorError - ${Time.Date} - ${Time} - ${Me.CleanName};/endmac
/target a miner
/delay 1s ${Target.CleanName.Equal[A Miner]}
/stick 7
/delay 10s ${Target.Distance}<10
/say Teleport to level ${param0}
/return
 
Sub InternalMoveTo(int y, int x)

/doevents
/if (${Zone.Name.Equal[Illsalin Marketplace]}) {
/camp
/delay 40s
/endmacro
}

/call CheckFG

    /declare currentX int local 0
    /declare currentY int local 0
    /declare currentZ int local 0
	/declare mcounter int local 0
	/declare random in local 0
	/varset mcounter 0
	       
	/moveto loc ${y} ${x}
        
	:waitformove
	/delay 3
	/doevents

	/if (${mcounter} == 25) {
	/return
	}
	
	/echo target loc y ${y}
	/echo target loc x ${x}
	/echo My Y  ${Me.Y}
	/echo My X ${Me.X}
	/echo ${Math.Distance[${Me.Y},${Me.X},0:${y},${x}]}

	/if (${Math.Distance[${Me.Y},${Me.X}:${y},${x}]}>10) {
	/echo in WaitForMove
	/moveto loc ${y} ${x}
	|/delay 1s
	/varcalc mcounter ${mcounter} + 1
	/goto :waitformove
    }
	



/return

Sub RanInternalMoveTo(int y, int x)

/doevents
/if (${Zone.Name.Equal[Illsalin Marketplace]}) {
/camp
/delay 40s
/endmacro
}

    /declare currentX int local 0
    /declare currentY int local 0
    /declare currentZ int local 0
	/declare mcounter int local 0
	/declare random int local 0
	/varset mcounter 0
	/echo moving to loc ${y} ${x}       
	/moveto loc ${y} ${x}
        
	:waitformove
	/delay 3
	/doevents

	/if (${mcounter} == 25) {
	/return
	}
	
	|/echo target loc y ${y}
	|/echo target loc x ${x}
	|/echo My Y  ${Me.Y}
	|/echo My X ${Me.X}
    |/echo ${Math.Distance[${Me.Y},${Me.X},0:${y},${x}]}

	/if (${Math.Distance[${Me.Y},${Me.X}:${y},${x}]}>10) {
	|/echo in WaitForMove
	/moveto loc ${y} ${x}
	|/delay 1s
	/varcalc mcounter ${mcounter} + 1
	/goto :waitformove
    }
	
/if (${random}==0 || ${random}==2) { 	
   /keypress y hold   
   /delay ${Math.Rand[3]}
   /keypress y
   /varcalc random ${random} + 1
   
	}

/if (${random}==1 || ${random}==3) {
	
   /keypress Num_6 hold
   /delay ${Math.Rand[4]}
   /keypress Num_6
	 /varcalc random ${random} + 1
	}

	/if (${random}==4) {
	
	/varset random 0
	
	}

/keypress forward
/return


Sub HoHInternalMoveTo(int y, int x)

/if (${Zone.Name.Equal[Illsalin Marketplace]}) {
/camp
/delay 40s
/endmacro
}

/call CheckFG

        /declare currentX int local 0
        /declare currentY int local 0
        /declare currentZ int local 0
	/declare mcounter int local 0
	/varset mcounter 0

	
       
	/moveto loc ${y} ${x}
	/bct hoh //cast 1
	/delay 2s
	/bct hoh //moveto loc ${y} ${x}
	/delay 2s
        
	:waitformove
	/if (${mcounter} == 10) {
	/return
	}
	
	/call Rooted
	/echo target loc y ${y}
	/echo target loc x ${x}
	/echo My Y  ${Me.Y}
	/echo My X ${Me.X}
	/echo ${Math.Distance[${Me.Y},${Me.X},0:${y},${x}]}

	/if (${Math.Distance[${Me.Y},${Me.X}:${y},${x}]}>10) {
	/echo in WaitForMove
	/moveto loc ${y} ${x}
	/bct hoh //cast 1
	/delay 2s
	/bct hoh //moveto loc ${y} ${x}
	/delay 2s
	/varset mcounter ${Math.Calc[${mcounter} + 1]}
	/goto :waitformove
        }
        
	
                
/return
 
Sub KillAllMobs(int maxWeightTimeBetweenAttacking, int distance)
/declare killtime timer local 400
/declare tacvi timer local 1200
/if (${Cursor.ID}) /autoinv
/declare MobWaitTime int inner 0        
/declare baseLocY int inner 0
/declare baseLocX int inner 0
/varset baseLocY ${Me.Y}
/varset baseLocX ${Me.X}

:loop_KillAllMobs

/call CheckFG

/if (${killtime.Value} == 0 && !${Zone.Name.Equal[Tacvi, The Broken Temple]}) {
/return
} 

/if (${tacvi.Value} == 0 && ${Zone.Name.Equal[Tacvi, The Broken Temple]}) {

/return
} 


/if (${Target.CleanName.Equal[A Gatekeeper]}) {
        /keypress esc
        /return
}

/if (${Target.CleanName.Equal[Greetings]}) {
        /keypress esc
        /return
}

/if (${Target.CleanName.Equal[Chest]}) {
        /keypress esc
        /return
}
/if (${Target.CleanName.Equal[Emissary of Water]}) {
        /keypress esc
	/call LootIt 50
        /return

}

/if (${Target.CleanName.Equal[Emissary of Fire]}) {
        /keypress esc
	/echo calling LootIt
	/call LootIt 50
        /return

}

/if (${Target.CleanName.Equal[Emissary of Earth]}) {
    /keypress esc
	/return

}

/if (${Target.CleanName.Equal[Emissary of Ice]}) {
        /keypress esc
	/call LootIt 50
        /return

}


/doevents
/echo this is distance ${distance}
/echo This is spawn count  ${SpawnCount[NPC radius ${distance}]}
        /if (${SpawnCount[NPC radius ${distance}]}) {

                /target NPC radius ${distance}
		
 		/echo ${Target.CleanName}

		/if (${Target.CleanName.Equal[Chest]}) {
       		 /keypress esc
       		 /return
		}

		/if (${Target.CleanName.Equal[Emissary of Fire]}) {
       			/keypress esc
			/echo calling LootIt
			/call LootIt 50
        		/return

		}
		/if (${Target.CleanName.Equal[Emissary of Water]}) {
       			/keypress esc
			/echo calling LootIt
			/call LootIt 50
        		/return

		}
		/if (${Target.CleanName.Equal[Emissary of Earth]}) {
       			/keypress esc
			/echo calling LootIt
			/call LootIt 50
        		/return

		}
		/if (${Target.CleanName.Equal[Emissary of Ice]}) {
       			/keypress esc
			/echo calling LootIt
			/call LootIt 50
        		/return

		}
		/stick 2 front
		
		/attack on
		
		/delay 3s 
        :target
		/if (${Target.ID}) {
		/stick 2 front
		/face
  		/attack on
		/delay 3s
		/goto :target
		}

		
		
               | /if (${Me.Class.ShortName.Equal[DRU]}) {
               |   /if ($!{FindItem[${MyEpic}].Timer}) /casting "${MyEpic}"|item
                |     }
                /if (${Me.Class.ShortName.Equal[SHM]}) {
                                /if (${Me.Gem[Spirit of the Kraken]}>0 && !${Me.Buff[Spirit of the Kraken].ID}) {
                                        /if (${Me.SpellReady[Spirit of the Kraken]}) /cast "Spirit of the Kraken"
                                }
                        }


	
		/delay 1s                              
		/call RanInternalMoveTo ${baseLocY} ${baseLocX} 


		
		| account for root
		| may want to change
		

                /goto :loop_KillAllMobs
        } 
/return


|Kill All Mobs with a Party

Sub PartyKillAllMobs(int maxWeightTimeBetweenAttacking, int distance, string channel)
/if (${Cursor.ID}) /autoinv
/declare MobWaitTime int inner 0        
/declare baseLocY int inner 0
/declare baseLocX int inner 0
/varset baseLocY ${Me.Y}
/varset baseLocX ${Me.X}

:loop_KillAllMobs
/call CheckFG
/if (${Target.CleanName.Equal[A Gatekeeper]}) {
        /keypress esc
        /return
}

/if (${Target.CleanName.Equal[Emissary of Water]}) {
        /keypress esc
        /return

}

/if (${Target.CleanName.Equal[Emissary of Fire]}) {
        /keypress esc
        /return

}

/if (${Target.CleanName.Equal[Emissary of Earth]}) {
        /keypress esc
        /return

}

/if (${Target.CleanName.Equal[Emissary of Ice]}) {
        /keypress esc
		
        /return

}

/if (${Target.CleanName.Equal[Kronos]}) {
        |/beep
}
/doevents
/echo this is distance ${distance}
/echo This is spawn count  ${SpawnCount[NPC radius ${distance}]}
        /if (${SpawnCount[NPC radius ${distance}]}) {

                /target NPC radius ${distance}
				
				/if (${Target.CleanName.Equal[Emissary of Ice]}) {
        /keypress esc
		
        /return

}
		 				
		/stick 3 front
		/attack on
		/multiline ; /bct ${channel} //target ID ${Target.ID} ;  /bct ${channel} //stick 6 !front; /bct ${channel} //attack on; /bct cast //target ID ${Target.ID} ; /bct cast //pet attack

		/delay 3s 

		/if (${Target.ID}) {
	
  		/stick 3 front
		/attack on
		/multiline ; /bct ${channel} //target ID ${Target.ID} ;  /bct ${channel} //stick 6 !front ; /bct ${channel} //attack on;
		/delay 3s
		|/varset killtime 100
		}
		
                /if (${Me.Class.ShortName.Equal[DRU]}) {
                  /if ($!{FindItem[${MyEpic}].Timer}) /casting "${MyEpic}"|item
                     }
                /if (${Me.Class.ShortName.Equal[SHM]}) {
                                /if (${Me.Gem[Spirit of the Kraken]}>0 && !${Me.Buff[Spirit of the Kraken].ID}) {
                                        /if (${Me.SpellReady[Spirit of the Kraken]}) /cast "Spirit of theKraken"
                                }
                        }
                              

                

		/if (!${Target.ID}) {
		
		/delay 1s
		/call InternalMoveTo ${baseLocY} ${baseLocX}
		} else  {

		/delay 3s

		}

		
		
		| account for root
		| may want to change
		
	

                /goto :loop_KillAllMobs
        }       
/return

Sub HoHKillAllMobs(int maxWeightTimeBetweenAttacking, int distance)
/declare killtime timer local 1200
/if (${Cursor.ID}) /autoinv
/declare MobWaitTime int inner 0        
/declare baseLocY int inner 0
/declare baseLocX int inner 0
/varset baseLocY ${Me.Y}
/varset baseLocX ${Me.X}

:loop_KillAllMobs

/call CheckFG


/delay 5

/if (${killtime.Value} == 0) {
/return
}

/if (${Target.CleanName.Equal[A Gatekeeper]}) {
        /keypress esc
        /return
}

/if (${Target.CleanName.Equal[Greetings]}) {
        /keypress esc
        /return
}

/if (${Target.CleanName.Equal[Chest]}) {
        /keypress esc
        /return
}
/if (${Target.CleanName.Equal[Emissary of Water]}) {
        /keypress esc
        /return

}

/if (${Target.CleanName.Equal[Emissary of Fire]}) {
        /keypress esc
        /return

}

/if (${Target.CleanName.Equal[Emissary of Earth]}) {
        /keypress esc
        /return

}

/if (${Target.CleanName.Equal[Emissary of Ice]}) {
        /keypress esc
        /return

}


/doevents
/echo this is distance ${distance}
/echo This is spawn count  ${SpawnCount[NPC radius ${distance}]}
        /if (${SpawnCount[NPC radius ${distance}]}) {

                /target NPC radius ${distance}
		
 		/echo ${Target.CleanName}

		/if (${Target.CleanName.Equal[Chest]}) {
       		 /keypress esc
       		 /return
		}
		/stick 3 front
		/attack on

		/delay 3s 

		/if (${Target.ID}) {
  		/stick 3 front
		/attack on
		/delay 2s
		|/varset killtime 100
		}

               | /if (${Me.Class.ShortName.Equal[DRU]}) {
               |   /if ($!{FindItem[${MyEpic}].Timer}) /casting "${MyEpic}"|item
                |     }
                /if (${Me.Class.ShortName.Equal[SHM]}) {
                                /if (${Me.Gem[Spirit of the Kraken]}>0 && !${Me.Buff[Spirit of the Kraken].ID}) {
                                        /if (${Me.SpellReady[Spirit of the Kraken]}) /cast "Spirit of the Kraken"
                                }
                        }
	
		/delay 1s  
		/bct hoh //cast 1                            
		/call HoHInternalMoveTo ${baseLocY} ${baseLocX}

		
		/delay 1s

		| account for root
		| may want to change
		

                /goto :loop_KillAllMobs
        } 
/return





                |** Door clicking **|
Sub Doors
/squelch /doortarget
:MoveToDoor
/if (${DoorTarget.Distance} > 6) {
        /squelch /face fast door
        /look 0
        /nomodkey /keypress forward hold
        /delay 3
        /nomodkey /keypress forward
        /goto :MoveToDoor
} else {
/keypress centerview
:openmeow
/delay 3
/keypress u
/click left center
/click left center
/delay 5
/if (!${Switch.Open}) /goto :openmeow
}
/return
                |** had to use plugin to handle doors in this zone **|
Sub OpenDoors
/if (${Bool[${Plugin[MQ2Doors].Name}]}) /plugin mq2doors unload
/delay 20
/if (!${Bool[${Plugin[MQ2Doors].Name}]}) /plugin mq2doors load
/delay 20
/if (${Plugin[MQ2Doors].Name.Length}) /toggledoors on
/delay 20
/call InternalMoveTo -559 -67
/return
                |** EVENT CFIX **|
Sub Event_Cfix
/if (${Me.Heading.ShortName.Equal[N]} || ${Me.Heading.ShortName.Equal[NE]} || ${Me.Heading.ShortName.Equal[NW]} || ${Me.Heading.ShortName.Equal[S]} || ${Me.Heading.ShortName.Equal[SW]} || ${Me.Heading.ShortName.Equal[SE]}) {
        /keypress forward
        /keypress back
        /delay 3
        /moveto loc ${Me.Y} ${Target.X}
        /delay 10
        /if (${Target.ID}) /face fast
        /if (${Target.ID}) /stick moveback 20
        /return
} else /if (${Me.Heading.ShortName.Equal[E]} || ${Me.Heading.ShortName.Equal[ENE]} || ${Me.Heading.ShortName.Equal[ESE]} || ${Me.Heading.ShortName.Equal[W]} || ${Me.Heading.ShortName.Equal[WSW]} || ${Me.Heading.ShortName.Equal[WNW]}) {
        /keypress forward
        /keypress back
        /delay 3
        /moveto loc ${Target.Y} ${Me.X}
        /delay 10
        /if (${Target.ID}) /face fast
        /if (${Target.ID}) /stick moveback 20
        /return
}
/return
                |** Root Checker **|
Sub Rooted
:checkroot
        /if (${Me.Buff[NPC Root].ID} || ${Me.Buff[NPC Root II].ID} || ${Me.Buff[Ensnaring Roots].ID} || ${Me.Buff[Entrapping Roots].ID} || ${Me.Buff[Engulfing Roots].ID} || ${Me.Buff[Root].ID} || ${Me.Buff[Grasping Roots].ID} || ${Me.Buff[Enveloping Roots].ID} || ${Me.Buff[Ghoul Root].ID} || ${Me.Buff[GelatRoot].ID} || ${Me.Buff[Vengeance of Root].ID} || ${Me.Buff[Engorging Roots].ID} || ${Me.Buff[Penetrating Roots].ID} || ${Me.Buff[Strong Root].ID} || ${Me.Buff[Earthen Roots].ID} || ${Me.Buff[Savage Roots].ID} || ${Me.Buff[Shackleroot].ID} || ${Me.Buff[Root of Weakness].ID} || ${Me.Buff[Ghoul Root I].ID} || ${Me.Buff[Ghoul Root II].ID} || ${Me.Buff[Ghoul Root III].ID} || ${Me.Buff[Ghoul Root IV].ID} || ${Me.Buff[Weakening Roots].ID} || ${Me.Buff[Entrapping Roots of Battle].ID} || ${Me.Buff[Anguish Root].ID}) {
        /casting 13401|item
        /goto :checkroot
        }
/return


Sub Event_TooFarAway

/hidecorpse all
/hidecorpse none
/hidecorpse looted

/return

Sub Event_TooFar

/hidecorpse all
/hidecorpse none
/hidecorpse looted

/return

Sub Event_FG

/beep
/beep
/camp


/return


Sub Event_NoLoot

/hidecorpse all
/hidecorpse none
/hidecorpse looted

/return


Sub Event_Summoned
/echo in Summoned

/face 180
/delay 5
/call KillFace 60
/call LootIt 60



/return


Sub CheckFG

/if (${Zone.Name.Equal[Illsalin Marketplace]}) {
/camp
/delay 40s
/endmacro
}
/return 

Sub AbyssKillAllMobs(int maxWeightTimeBetweenAttacking, int distance)
/declare killtime timer local 1200
/if (${Cursor.ID}) /autoinv
/declare MobWaitTime int inner 0        
/declare baseLocY int inner 0
/declare baseLocX int inner 0
/varset baseLocY ${Me.Y}
/varset baseLocX ${Me.X}

:loop_KillAllMobs

/call CheckFG

|/if (${killtime.Value} == 0) {
|/return
}

/if (${Target.CleanName.Equal[A Gatekeeper]}) {
        /keypress esc
        /return
}

/if (${Target.CleanName.Equal[Greetings]}) {
        /keypress esc
        /return
}

/if (${Target.CleanName.Equal[Chest]}) {
        /keypress esc
        /return
}
/if (${Target.CleanName.Equal[Emissary of Water]}) {
        /keypress esc
        /return

}

/if (${Target.CleanName.Equal[Emissary of Fire]}) {
        /keypress esc
        /return

}

/if (${Target.CleanName.Equal[Emissary of Earth]}) {
        /keypress esc
        /return

}

/if (${Target.CleanName.Equal[Emissary of Ice]}) {
        /keypress esc
        /return

		/if (${Target.CleanName.Equal[A Wandering Trader]}) {
        /keypress esc
        /return

}


/doevents
/echo this is distance ${distance}
/echo This is spawn count  ${SpawnCount[NPC radius ${distance}]}
        /if (${SpawnCount[NPC radius ${distance}]}) {

                /target NPC radius ${distance}
				/stick 2
		
 		/echo ${Target.CleanName}

		/if (${Target.CleanName.Equal[Chest]}) {
       		 /keypress esc
       		 /return
		}
		/stick 3 front
		:kill
		/attack on

		/delay 2s 

		/if (${Target.ID}) {
  		/attack on
		/delay 2s
		|/varset killtime 100
		}

		/if (${Target.PctHPs}==100) {
		/echo Mob is Bugged

			/return

		}
		
		/if (${Target.ID}) {
		/goto :kill
  		
		}

               | /if (${Me.Class.ShortName.Equal[DRU]}) {
               |   /if ($!{FindItem[${MyEpic}].Timer}) /casting "${MyEpic}"|item
                |     }
                /if (${Me.Class.ShortName.Equal[SHM]}) {
                                /if (${Me.Gem[Spirit of the Kraken]}>0 && !${Me.Buff[Spirit of the Kraken].ID}) {
                                        /if (${Me.SpellReady[Spirit of the Kraken]}) /cast "Spirit of the Kraken"
                                }
                        }
	
		/delay 1s                              
		/call InternalMoveTo ${baseLocY} ${baseLocX}

		
		| account for root
		| may want to change
		

                /goto :loop_KillAllMobs
        } 
/return

sub KillFace(int distance)
/if (${Cursor.ID}) /autoinv
/declare count int local 0        
/declare baseLocY int inner 0
/declare baseLocX int inner 0
/varset baseLocY ${Me.Y}
/varset baseLocX ${Me.X}

/keypress forward

/echo This is spawn count  ${SpawnCount[NPC radius ${distance}]}
       
	    /varset count 0
		:fight
		
		/if (${Target.CleanName.Equal[Kronos]}) {
		|/beep		
		}
		
		/if (${Target.CleanName.Equal[Emissary of Ice]}) {
		/keypress esc
		/return
		}
		
		/if (${Target.CleanName.Equal[Emissary of Water]}) {
		/keypress esc
		/return
		}
		
		/if (${Target.CleanName.Equal[Ture]}) {
		/target npc discord radius 20
		
		}
		/if (${Taget.CleanName.Equal[Keldovan the Harrier]}) {
		
		/echo Target is ${Target.CleanName}
		/target npc water radius 20
		}
		/if (${Taget.CleanName.Equal[Vilria the Keeper]}) {
		/disc Savage Onslaught
		/target npc fire radius 20
		}
		
		/if (${Target.CleanName.Equal[Cerberus]}) {
		
		/disc Furious
		/target npc raging radius 20
		
		}
		

		
		|varset count ${Math.Calc[${count} + 1]}
		/varcalc count ${count} + 1
	  	/delay 5
		/if (${SpawnCount[NPC radius ${distance}]}) {
		
		/goto :destroy		
		
		} else {
		/goto :end
		}
		
		:destroy
		/if (${Target.ID}) {
		
		/attack on
		/face fast
		/stick moveback 10				
				
		} 
							
		/if (${SpawnCount[NPC radius ${distance}]} == 0 && !${Target.ID}) {
		
		/delay 2s
	
		/if (!${Target.ID}) {
		  /goto :end
		}
         }
		/delay 2s
		
                /if (!${Target.ID}) {
		  /target npc radius 20
		}

			
		/goto :fight
		}
		
		:end
	
		/delay 1  
		/call InternalMoveTo ${baseLocY} ${baseLocX}
		

/return

                |** Default .ini settings **|
Sub LoadIni
/echo Creating ini file for this character. File located relative to your MQ2 folder: /wm/YourName_wmloot.ini
/ini "./wm/${Me.CleanName}_wmloot.ini" "100" "Version" "1.0"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "A Key" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Wrist" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Ear" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Feet" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Earring" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Finger" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Hands" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Back" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Shoulder" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Neck" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Head" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Arms" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Waist" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Face" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Chest" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Legs" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment of HP" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment of HP Regen" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment of Mana" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment of Mana Regen" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment of Shield" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment of Damage Shield" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Gemstone of the Ages" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "200" "20,0000 AA Experience Crystal" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "300" "50,0000 AA Experience Crystal" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "G" "Gemstone of the Ages" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "B" "Bag of Platinum Pieces" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "B" "Bag of Food" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "B" "Big Bag of Platinum" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "B" "Brawler's Upgrade" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "G" "Guardian's Upgrade" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "G" "Greater Lightstone" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "B" "Brawler's Upgrade v2" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "B" "Broken Spider Legs" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "R" "Ruined Spider Silk" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "B" "Poor Quality Metal" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "B" "Black Sapphire" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "B" "Black Pearl" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "B" "Blue Diamond" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "B" "Burned Out Lightstone" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "B" "Bag of Food" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "B" "Big Chest of Platinum" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "B" "Bristlebane's Treasure Vault (Triple Loot Instance)" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "B" "Broken Spider Legs" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "M" "Medium Quality Metal" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "P" "Poor Quality Metal" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "M" "Shiny Snake Skin "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "M" "Medium Quality Animal Skin" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "F" "Fading Lightstone" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "F" "Fish Meat" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "F" "Foxy's Gambling Coin" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "P" "Poisoned Water" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "P" "Poor Quality Animal Skin" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "L" "Low Quality Animal Skin" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "L" "Large Fish Bones" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "L" "Large Fire Beetle Leg" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "R" "Ruined Spider Silk" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Sharp Snake Fang" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "L" "Large Fire Beetle Eye" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "L" "Leaf Scarab Tarsus" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "R" "Rotten Snake Egg" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "L" "Leaf Scarab Carapace" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "C" "Cloth Cap" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "C" "Big Chest of Platinum" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "C" "Contained Fire" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "C" "Chest of Platinum" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "C" "Charm Prism Upgrade" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "C" "Cursed Bone Chips" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "C" "Citrine Gemstone of Vitality I" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "D" "Diamond" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "D" "Dragon Seal" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "D" "Dragon Ore for Cloth Multiclass" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "D" "Dragon Ore for Leather Multiclass" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "D" "Dragon Ore for Plate Multiclass" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "D" "Dragon Ore for Chain Multiclass" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "D" "Dragon Ore for Leather Multiclass" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "D" "Dragon Ore for Ranger" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "D" "Dragon Ore for Wizard" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "D" "Dragon Ore for Enchanter" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "D" "Dragon Ore for Magician" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "D" "Dragon Ore for Rogue" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "D" "Dragon Ore for "Druid" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "D" "Dragon Ore for Necromancer" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Emerald" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Dragons Minor" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Gods Minor" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Gods Major" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of The Abyss" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Anguish" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Loping Plains" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Frozen Shadow III" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Temple Veeshan" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Earth Crystal" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Dragons Major" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Qvic" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Old Commons" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Cazic Thule" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Frozen Shadow II" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Frozen Shadow I" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Frozen Shadow III" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Frozen Shadow V" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Green Veeshan Scales" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Red Veeshan Scales" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Silver Veeshan Scales" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Expensive Blue Diamond" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Epic Book 5.5 page 2 of 10" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Epic Book 5.5 page 5 of 10" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Epic Book 5.5 page 9 of 10" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Epic Book 5.5 page 7 of 10" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Epic Book 5.5 page 8 of 10" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "F" "Falcon's Gloves" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "F" "Fire Emerald" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "F" "Fire Opal" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "F" "Flawless Blue Diamond(Quest Item) "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "F" "Flawless Diamond(Quest Item)" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "F" "Flawless Fire Emerald(Quest Item)" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "F" "Fire Crystal" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "G" "Guardian's Upgrade" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "G" "Guardian's Upgrade v2" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "G" "Glowing Lightstone" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "G" "Glowing Sun Shard" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "H" "Huge Bag of Platinum" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "H" "Heavy Bag of Platinum" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "H" "High Quality Animal Skin" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "I" "Iron Torque" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "I" "Ice Crystal" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "J" "Jester's Boots" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "J" "Jacinth" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "K" "King's Chest" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "K" "King's Crown" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "K" "Knight's Arms" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "L" "LDoN 10 Credits" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "L" "LDoN 50 Credits" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "L" "LDoN 100 Credits" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "L" "LDoN 200 Credits" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "L" "Leaf of Vitality I" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "L" "Leaf of Loping Plains I" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "L" "Low Quality Animal Skin" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "M" "Marching Orders" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "M" "Minor Rainbow Crystal" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "M" "Medium Quality Metal" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "L" "Lesser Rainbow Crystal" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "L" "Large Fire Beeetle Leg" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "L" "Large Fire Beeetle Eye" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "L" "Lesser Rainbow Crystal" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "M" "Rainbow Crystal" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "N" "Note from Corbin" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "O" "Opal" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "O" "Oracle's Upgrade" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "O" "Oracle's Upgrade v2" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "P" "Peasant's Bracer" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "P" "Poisoned Water" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "P" "Peridot" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "P" "Pirate's Coin" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "Q" "Queen's Legs" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "Q" "Queen's Legs" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "Q" "Vampire Hunter Legs Pattern" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "Q" "Vampire Hunter Chest Pattern" "Keep
/ini "./wm/${Me.CleanName}_wmloot.ini" "Q" "Vampire Hunter Tunic Pattern" "Keep
/ini "./wm/${Me.CleanName}_wmloot.ini" "Q" "Vampire Hunter Bracer Pattern" "Keep
/ini "./wm/${Me.CleanName}_wmloot.ini" "Q" "Vampire Hunter Gloves Pattern" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "R" "Ruby" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "R" "Red Toned Diamond" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "R" "Ruined Animal Skin" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "R" "Rotten Snake Egg" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Stone of Heroic Resistance V" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Stone of Heroic Resistance VI" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Stone of Heroic Resistance VII" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Stone of Heroic Resistance VIII" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Stone of Heroic Resistance III" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Stone of Heroic Resistance II" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Stone of Heroic Resistance IX" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Stone of Heroic Resistance X" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Pirate's Coin" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Scorpion's Spear (Zone-Wide Pull)" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Snake's Bane" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Sapphire" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Shadow Blood" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Silver Toned Diamond" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Slimy Sapphire of Cowardice III" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Smelly Fish Oil" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Sorcerer's Upgrade" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Sorcerer's Upgrade v2" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Superior Lightstone" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Star Ruby" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Strong Spider Silk" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "Tinker Wrench" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "The Prince of Darkness Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "The Lightbringer Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "The Goblin King's Treasure Chest (Double Loot Instance)" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "The Oceanlord Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "The Faceless Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "H-One N-One Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "The Tranquil Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "Split Paw Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "The MCP Quest Token" "Keep"


/ini "./wm/${Me.CleanName}_wmloot.ini" "U" "Used Napkin" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "V" "Vial of Velium Vapors" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "W" "Worthless Coin" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "W" "Water Crystal" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "X" "Xakra Bile" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "Y" "Yulcabis' Axe" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "Z" "Zealot's Incarnadine Sword" "Ignore"



/return