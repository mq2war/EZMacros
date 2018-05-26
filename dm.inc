sub beltloot


/declare belt string inner
/declare beltcheck string inner
/declare tooncount int inner
/varset tooncount 8

/declare toons[${tooncount}] string inner





/varset belt recluse,goft,pellets,peign,ratio,submit,uberitis,usurp


/ini beltcheck belt check "False"

/varset beltcheck ${Ini[beltcheck.ini,belt,check]} 

/echo ${beltcheck}
    
    /declare i                      int     local   0
    
    /for i 1 to ${tooncount}

        |  Read Ini

        /varset beltcheck ${Ini[beltcheck.ini,belt,check]} 
        /if (${beltcheck.Equal[False]}) { 
        /echo ${belt.Arg[${i},,]}
        |/varset arString[${i}] ${myString.Mid[${i},1]}
        |Adding to array  -  not needed but a good example
        /varset toons[${i}] ${masked.Arg[${i},,]}
        
        | Remove Citrines from Ini 1
        |call macro, check belt check, run check belt if 0 loot set ini value to True
        /echo Calling beltcheck

        /bct ${belt.Arg[${i},,]} //macro beltcheck

        /delay 10s

        }  else  {

        | /goto :end

        }

    /next i


:end

|| Hardcoded to Ranger for Citrines

|/bct recluse //macro lootgo3 60

/return



sub beltcheck

|/if (${FindItemCount[Den Mother's Hide Belt]}>0)  {




/if (${FindItemCount[Den Mother's Hide Belt]}>0)  {

/echo Found Item    
/gu found item
/goto :end


}  else  {


| update ini
/echo Updating INI
/ini beltcheck belt check "True"
/gu Item not found, should end

/call LootIt 60
|from loot.inc    -  should be included in macro   #include loot.inc


:end


}


/return


sub dmpull



|Param0 - Instance flag true or False
|If true will return to calling macro for instance hop
|Else will stay and farm 

|  Setup mitigation

/useitem 8
/useitem 13


/attack on


:start

/echo In DM Pull

/call target

/if (${Target.ID}) {

    /call combat maslow
}


/target npc spawnling


/if (${SpawnCount[Basilisk Spawnling]}) {
  


/call getsome

/call combat maslow


/goto :start
          

}  else {


   /call target

   /if (${Target.ID}) { 

      /goto :start

   }


    /if (${Param0.Equal[False]})  {


        /call getback
    
        /delay 2m
        /goto :start

       }


}

/call getback

/bca //macro acceptrez

/keypress 9

/delay 5s

/bca //endmacro

/return


sub combat

/echo in Combat

/stick 180
/keypress 8
/delay 5
/call RanInternalMoveTo ${yloc} ${xloc}
/face fast
/call autoattack ${Param0}


/call rez

/bca //macro corpse

/hidecorpse all

/bca //hidecorpse looted

/call beltloot




/return


sub target 

/target npc radius 45

/if (${Target.ID}) {

    
    /call getsome
   


}


/return

sub getsome

    /bct ang //target ID ${Me.ID}
    /bct ang //stick behind 20
    /delay 1s
    /face fast
    /stick 180
    /delay 3s
    /keypress 8
    /delay 2s
    /pet attack
    /useitem 23 4

   | /bct usurp //useitem 23 3
   


/return 


sub getback

/echo in Get Back
/attack off

/echo ${Me.Y}
/echo ${Me.X}

/call target

/bct ang //target ID ${Me.ID}
/bct ang //stick 20 behind
/delay 15
/bct ang //stick off

/if (${Math.Distance[${Me.Y},${Me.X}:${yloc},${xloc}]}>400) {

| hardcoded names

/target variable

/delay 1s

/if  (${Target.ID}) {  

/call mage variable maslow

/target clear

}  else  {

    /echo Mage dead

    /call RanInternalMoveTo -178.78 -844.39

    /target clear

    |/bct usurp //useitem 23 3
}

    
}
/call RanInternalMoveTo ${yloc} ${xloc}
    /delay 5s
    /keypress 9
    /delay 5s


/return


sub mage

/echo in mage
/doevents


/echo In Mage

/target clear

/delay 3
/bct ${Param0} //target pc ${Param1}
/delay 1s


/bct ${Param0} //cast "Call of the Hero"

/delay 3s


/return
