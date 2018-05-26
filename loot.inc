#Event TooFar "Corpse too far away."
#Event NoLoot "You may not loot this corpse at this time."
#Event Looted "Someone is already looting that corpse."
#Event TooFarAway "#*#You are too far away to loot that corpse#*#"


sub SetLootVar


|${Math.Rand[5]


/if (${Cursor.ID}) /autoinv
/if (!${Defined[x3]})           /declare x3 int outer
/if (!${Defined[y3]})           /declare y3 int outer
/if (!${Defined[inixint]})      /declare inixint int outer

/return 



Sub LootIt



/echo ${Param0}
/echo ${Param1}
/echo ${Param2}
/echo ${Param3}



|  Parms 1 = Green Scales  2 = Red Scales  3 = Silver Scales
|  Set to 1 to loot    /call LootIt 100 1 0 0

/if (${Cursor.ID}) /autoinv
/if (!${Ini[./wm/${Me.CleanName}_wmloot.ini,100,Version]}) /call LoadIni


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
        /delay 2
		
:LootLag 
/if (${LootTotal}!=${Corpse.Items}) { 
/echo In Loot Lag
/varset LootTotal ${Corpse.Items} 
/delay 2
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
        /delay 2
        /if (!${Corpse.Items}) {
                /nomodkey /notify LootWnd LW_DoneButton leftmouseup
                /goto :looting
        }
/for x3 ${Corpse.Items} downto 1




|/if (${Corpse.Item[${x3}].Name.Equal[Sorcerer's Upgrade v2]}) {
 
|/gu Sorc found
|}

/if (${Param1}==1) {

/call Green

}

/if (${Param2}==1) {

/call Red

}

/if (${Param3}==1) {

/call Silver

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
/delay 2
}

/return


Sub Green


/if (${Corpse.Item[${x3}].Name.Find[Green Veeshan Scales]}) {
 /itemnotify loot${x3} rightmouseup
 /delay 15 ${Window[ConfirmationDialogBox].Open} || !${Corpse.Item[${i}].NoDrop}
 /if (${Window[ConfirmationDialogBox].Open}) /nomodkey /notify ConfirmationDialogBox Yes_Button leftmouseup
 /delay 15 ${Cursor.ID} || ${WhichButton.NotEqual[left]}

}



/return 


Sub Red



/if (${Corpse.Item[${x3}].Name.Find[Red Veeshan Scales]}) {
 /itemnotify loot${x3} rightmouseup
 /delay 15 ${Window[ConfirmationDialogBox].Open} || !${Corpse.Item[${i}].NoDrop}
 /if (${Window[ConfirmationDialogBox].Open}) /nomodkey /notify ConfirmationDialogBox Yes_Button leftmouseup
 /delay 15 ${Cursor.ID} || ${WhichButton.NotEqual[left]}

}

/return


Sub Silver

/if (${Corpse.Item[${x3}].Name.Find[Silver Veeshan Scales]}) {
 /itemnotify loot${x3} rightmouseup
 /delay 15 ${Window[ConfirmationDialogBox].Open} || !${Corpse.Item[${i}].NoDrop}
 /if (${Window[ConfirmationDialogBox].Open}) /nomodkey /notify ConfirmationDialogBox Yes_Button leftmouseup
 /delay 15 ${Cursor.ID} || ${WhichButton.NotEqual[left]}

}

/return 


Sub CheckFG

/if (${Zone.Name.Equal[Illsalin Marketplace]}) {
/camp
/delay 40s
/endmacro
}
/return 


Sub Event_Looted

/stick moveback 30
/stick moveback 30

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

Sub LoadDestroy
/echo Creating ini file for this character. File located relative to your MQ2 folder: /wm/YourName_destroyloot.ini
/ini "./wm/${Me.CleanName}_destroyloot.ini" "100" "Version" "1.0"
/ini "./wm/${Me.CleanName}_destroyloot.ini" "A" "Gemstone of the Ages" "Keep"
/ini "./wm/${Me.CleanName}_destroyloot.ini" "G" "Gemstone of the Ages" "Keep"
/ini "./wm/${Me.CleanName}_destroyloot.ini" "B" "Big Bag of Platinum" "Keep"
/ini "./wm/${Me.CleanName}_destroyloot.ini" "E" "Expensive Blue Diamond" "Keep"
/ini "./wm/${Me.CleanName}_destroyloot.ini" "H" "Huge Bag of Platinum" "Keep"
/ini "./wm/${Me.CleanName}_destroyloot.ini" "L" "Lesser Rainbow Crystal" "Keep"
/ini "./wm/${Me.CleanName}_destroyloot.ini" "L" "Large Brick of High Quality Ore" "Keep"
/ini "./wm/${Me.CleanName}_destroyloot.ini" "M" "Minor Rainbow Crystal" "Keep"
/ini "./wm/${Me.CleanName}_destroyloot.ini" "S" "Superior Lightstone" "Keep"
/ini "./wm/${Me.CleanName}_destroyloot.ini" "S" "Small Brick of High Quality Ore" "Keep"
/ini "./wm/${Me.CleanName}_destroyloot.ini" "S" "Small Piece of High Quality Ore" "Keep"
/ini "./wm/${Me.CleanName}_destroyloot.ini" "T" "The Prince of Darkness Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_destroyloot.ini" "T" "The Lightbringer Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_destroyloot.ini" "T" "The Oceanlord Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_destroyloot.ini" "T" "The Faceless Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_destroyloot.ini" "T" "H-One N-One Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_destroyloot.ini" "T" "The Tranquil Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_destroyloot.ini" "T" "Split Paw Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_destroyloot.ini" "T" "The MCP Quest Token" "Keep"


/return



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
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment of HP" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment of HP Regen" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment of Mana" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment of Mana Regen" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment of Shield" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment of Damage Shield" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Gemstone of the Ages" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "G" "Gemstone of the Ages" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "B" "Bag of Platinum Pieces" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "B" "Bag of Food" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "B" "Big Bag of Platinum" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "B" "Brawler's Upgrade" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "G" "Guardian's Upgrade" "Keep"
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
/ini "./wm/${Me.CleanName}_wmloot.ini" "B" "Broken Spider Legs" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "B" "Bristlebane's Treasure Vault (Triple Loot Instance)" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "M" "Medium Quality Metal" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "P" "Poor Quality Metal" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "M" "Medium Quality Animal Skin" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "F" "Fading Lightstone" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "F" "Fish Meat" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "F" "Glowing Sun Shard" "Keep"
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
/ini "./wm/${Me.CleanName}_wmloot.ini" "C" "Citrine Gemstone of Vitality I" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "D" "Diamond" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "D" "Soul of the Basilisk Den Mother" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "D" "Den Mother's Hide Belt" "Keep"
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
/ini "./wm/${Me.CleanName}_wmloot.ini" "D" "Dark Blade" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Emerald" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Dragons Minor" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Gods Minor" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Gods Major" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of The Abyss" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Anguish" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Loping Plains" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Frozen Shadow III" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Temple Veeshan" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Sunderock" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Earth Crystal" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Dragons Major" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Qvic" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Cazic Thule" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Frozen Shadow II" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Frozen Shadow I" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Frozen Shadow III" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Frozen Shadow V" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Green Veeshan Scales" "Ignore"
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
/ini "./wm/${Me.CleanName}_wmloot.ini" "H" "High Quality Metal" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "L" "Large Fire Beetle Carapace" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "H" "Heavy Bag of Platinum" "Keep"
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
/ini "./wm/${Me.CleanName}_wmloot.ini" "L" "Leaf of Vitality I" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "L" "Leaf of Loping Plains I" "Ignore"
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
/ini "./wm/${Me.CleanName}_wmloot.ini" "O" "Oracle's Upgrade" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "O" "Oracle's Upgrade v2" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "P" "Peasant's Bracer" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "P" "Poisoned Water" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "P" "Peridot" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "Q" "Queen's Legs" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "Q" "Queen's Legs" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "Q" "Vampire Hunter Legs Pattern" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "Q" "Vampire Hunter Chest Pattern" "Keep
/ini "./wm/${Me.CleanName}_wmloot.ini" "Q" "Vampire Hunter Tunic Pattern" "Keep
/ini "./wm/${Me.CleanName}_wmloot.ini" "Q" "Vampire Hunter Bracer Pattern" "Keep
/ini "./wm/${Me.CleanName}_wmloot.ini" "Q" "Vampire Hunter Gloves Pattern" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "R" "Ruby" "Ignore"
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
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Scorpion's Spear (Zone-Wide Pull)" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Snake's Bane" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Sapphire" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Shadow Blood" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Sharp Snake Fang" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Soul of the Sharpclaw Tuff Grimefoot" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Shiny Snake Skin" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Smelly Fish Oil" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Slimy Sapphire of Cowardice III" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Sorcerer's Upgrade" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Sorcerer's Upgrade v2" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Superior Lightstone" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Star Ruby" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Strong Spider Silk" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "Tinker Wrench" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "The Prince of Darkness Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "The Lightbringer Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "The Oceanlord Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "The Faceless Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "H-One N-One Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "The Tranquil Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "Split Paw Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "The MCP Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "The Goblin King's Treasure Chest (Double Loot Instance)" "Keep"


/ini "./wm/${Me.CleanName}_wmloot.ini" "U" "Used Napkin" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "V" "Vial of Velium Vapors" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "W" "Worthless Coin" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "W" "Water Crystal" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "X" "Xakra Bile" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "Y" "Yulcabis' Axe" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "Z" "Zealot's Incarnadine Sword" "Ignore"



/return

Sub LoadNewIni
/echo Creating ini file for this character. File located relative to your MQ2 folder: /wm/YourName_wmloot.ini
/ini "./wm/${Me.CleanName}_wmloot.ini" "100" "Version" "1.0"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "A Key" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Wrist" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Ear" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Feet" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Earring" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Finger" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Hands" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Back" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Shoulder" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Neck" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Head" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Arms" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Waist" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Face" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Chest" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment Legs" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment of HP" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment of HP Regen" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment of Mana" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment of Mana Regen" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment of Shield" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Anguish Augment of Damage Shield" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "A" "Gemstone of the Ages" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "G" "Gemstone of the Ages" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "B" "Bristlebane's Treasure Vault (Triple Loot Instance)" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "B" "Bag of Platinum Pieces" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "B" "Bag of Food" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "B" "Big Bag of Platinum" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "B" "Brawler's Upgrade" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "G" "Guardian's Upgrade" "Keep"
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
/ini "./wm/${Me.CleanName}_wmloot.ini" "B" "Broken Spider Legs" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "M" "Medium Quality Metal" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "P" "Poor Quality Metal" "Ignore"
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
/ini "./wm/${Me.CleanName}_wmloot.ini" "C" "Citrine Gemstone of Vitality I" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "D" "Diamond" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "D" "Dragon Seal" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "D" "Den Mother's Hide Belt" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "D" "Dragon Ore for Cloth Multiclass" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "D" "Dragon Ore for Leather Multiclass" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "D" "Dragon Ore for Plate Multiclass" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "D" "Dragon Ore for Chain Multiclass" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "D" "Dragon Ore for Leather Multiclass" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "D" "Dark Blade" "Ignore"
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
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Sunderock" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Earth Crystal" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Dragons Major" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Qvic" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Cazic Thule" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Frozen Shadow II" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Frozen Shadow I" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Frozen Shadow III" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Essence of Frozen Shadow V" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Green Veeshan Scales" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Red Veeshan Scales" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "E" "Silver Veeshan Scales" "Ignore"
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
/ini "./wm/${Me.CleanName}_wmloot.ini" "H" "Huge Bag of Platinum" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "H" "Heavy Bag of Platinum" "Keep"
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
/ini "./wm/${Me.CleanName}_wmloot.ini" "L" "Leaf of Vitality I" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "L" "Leaf of Loping Plains I" "Ignore"
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
/ini "./wm/${Me.CleanName}_wmloot.ini" "O" "Oracle's Upgrade" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "O" "Oracle's Upgrade v2" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "P" "Peasant's Bracer" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "P" "Poisoned Water" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "P" "Peridot" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "Q" "Queen's Legs" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "Q" "Queen's Legs" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "Q" "Vampire Hunter Legs Pattern" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "Q" "Vampire Hunter Chest Pattern" "Keep
/ini "./wm/${Me.CleanName}_wmloot.ini" "Q" "Vampire Hunter Tunic Pattern" "Keep
/ini "./wm/${Me.CleanName}_wmloot.ini" "Q" "Vampire Hunter Bracer Pattern" "Keep
/ini "./wm/${Me.CleanName}_wmloot.ini" "Q" "Vampire Hunter Gloves Pattern" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "R" "Ruby" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "R" "Ruined Animal Skin" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "R" "Rotten Snake Egg" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "D" "Soul of the Basilisk Den Mother" "Keep
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Stone of Heroic Resistance V" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Stone of Heroic Resistance VI" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Stone of Heroic Resistance VII" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Stone of Heroic Resistance VIII" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Stone of Heroic Resistance III" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Stone of Heroic Resistance II" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Stone of Heroic Resistance IX" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Stone of Heroic Resistance X" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Soul of the Sharpclaw Tuff Grimefoot" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Snake's Bane" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Sapphire" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Shadow Blood" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Sharp Snake Fang" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Slimy Sapphire of Cowardice III" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Sorcerer's Upgrade" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Sorcerer's Upgrade v2" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Superior Lightstone" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Star Ruby" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Strong Spider Silk" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "S" "Scorpion's Spear (Zone-Wide Pull)" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "Tinker Wrench" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "The Prince of Darkness Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "The Lightbringer Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "The Oceanlord Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "The Faceless Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "H-One N-One Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "The Tranquil Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "Split Paw Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "The MCP Quest Token" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "T" "The Goblin King's Treasure Chest (Double Loot Instance)" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "U" "Used Napkin" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "V" "Vial of Velium Vapors" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "W" "Worthless Coin" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "W" "Water Crystal" "Keep"
/ini "./wm/${Me.CleanName}_wmloot.ini" "X" "Xakra Bile" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "Y" "Yulcabis' Axe" "Ignore"
/ini "./wm/${Me.CleanName}_wmloot.ini" "Z" "Zealot's Incarnadine Sword" "Ignore"



/return


Sub LootDestroy

| will loot items in destroyloot.ini, else will destroy


:start

|/if (!${Zone.Name.Equal[Old Commonlands]}) {
|/gu Not in Oldcommons, ending loot.   
|/endmacro
|}

:checkcursor
/if (${Cursor.ID}) {
        
/autoinv
/goto :checkcursor
}


/if (!${Ini[./wm/${Me.CleanName}_destroyloot.ini,100,Version]}) /call LoadDestroy


/declare LootTotal int local -1 



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
        /delay 2
		
:LootLag 
/if (${LootTotal}!=${Corpse.Items}) { 
/echo In Loot Lag
/varset LootTotal ${Corpse.Items} 
/delay 2
/goto :LootLag 
} 


        /if (!${Corpse.Items}) /keypress esc
        /delay 2
        /if (!${Corpse.Items}) {
                /nomodkey /notify LootWnd LW_DoneButton leftmouseup
                /goto :looting
        }
/for x3 ${Corpse.Items} downto 1


/varset CurrentInisetting ${Ini[./wm/${Me.CleanName}_destroyloot.ini,"${Corpse.Item[${x3}].Name.Left[1]}","${Corpse.Item[${x3}]}"]}
/if (${CurrentInisetting.Equal[Keep]}) {
 /itemnotify loot${x3} rightmouseup
 /delay 12 ${Window[ConfirmationDialogBox].Open} || !${Corpse.Item[${i}].NoDrop}
   /if (${Window[ConfirmationDialogBox].Open}) /nomodkey /notify ConfirmationDialogBox Yes_Button leftmouseup
   /delay 12 ${Cursor.ID} || ${WhichButton.NotEqual[left]}
} else {



        |/gu in destroy
        /itemnotify loot${x3} leftmouseup

        /delay 4 ${Window[ConfirmationDialogBox].Open} || !${Corpse.Item[${i}].NoDrop}
        /if (${Window[ConfirmationDialogBox].Open}) /nomodkey /notify ConfirmationDialogBox Yes_Button leftmouseup
        /delay 4 ${Cursor.ID} || ${WhichButton.NotEqual[left]}
        /delay 3
        /call destroy

}
/delay 2
/next x3
/nomodkey /notify LootWnd LW_DoneButton leftmouseup
/if (${SpawnCount[CORPSE radius ${Param0}]}) /goto :looting
/delay 2
}





/return


Sub destroy

|/gu in sub destroy

:check
/if (${Cursor.ID}) {
        
/destroy

/delay 2

/destroy

/goto :check
}



/return
