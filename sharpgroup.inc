
#Event Closed "#*#This portal is currently closed#*#"
#event Death "You have been slain#*#"


sub bandit

/varset area bandit
:start 


/target clear

/face heading 270
/delay 5
/face heading 270

/call NewRanInternalMoveTo 1158.12 377.49

/call InternalMoveTo 1129.87 348.26

/call getit 6 usurp

/delay 6

/call mage usurp

/delay 2s


/goto :start

/return


sub wild

/varset area wild

:start

/keypress forward
/target clear

/face heading 270
/delay 5


/call InternalMoveTo 2532.25 -1484.00



/delay 2

/call getit 6 peign

/delay 15


/call mage peign

/delay 2s 

/goto :start

/return


sub side

/varset area side

| Ratio is coh holder -  hardcoded

:start


/target clear


/call NewRanInternalMoveTo -269.43 1671.40
/call InternalMoveTo -203.70 1662.47

/delay 2

/call getit 6 ratio

/delay 12


/call mage ratio

/delay 2s

/goto :start

/return


sub south
:start


/target clear

/call NewRanInternalMoveTo -1552.60 -1462.34
/call InternalMoveTo -1561.39 -1551.82

/call getit 6 fraz

/delay 12

/call mage fraz

/delay 2s

/goto :start


/return 

sub getit

/target clear

/target an open portal radius 800

/delay 4

/if (${Target.ID}) {

/face fast

/delay 2

/useitem 23 1



/delay 6s    

/face fast

/stick 5


/delay 3s

/gu holding 1
/keypress forward hold ${Param0}



/varcalc sharpcount ${sharpcount} + 1

/echo this is sharpcount ${sharpcount}

/call sharp
    


} else {

    /bct mage target clear
    /call mage ${Param1}
    /delay 2s
    /gu in getit
    /gu portal closed
    /endmacro
    
}

/return



sub mage


| ${Param0}  group coh holder

/doevents


/echo In Mage

/bct ${mage} target clear
/delay 3
/bct ${mage} //target pc ${Param0}
/delay 1s


/bct ${mage} //cast "Call of the Hero"


/return



sub groupport


/declare side float inner
/declare south float inner
/declare bandit float inner
/declare wild float inner



/varset side -198.00
/varset south -1540.63
/varset bandit 1100.50
/varset wild 2526.63


/echo ${Target.Y}

/target open

/if (!${Target.ID}) {

/delay 30s

/target open

}

/if (${Target.Y}==${side}) {
	/echo Side Portal Active
    /call newgroup variable ratio
    /delay 10s
    /varset portloc ${side}
    
    /bct ratio //gu side
    /bct ratio //macro sharpside
    }

/if (${Target.Y}==${south}) {
	/echo South Portal Active

    /call newgroup variable fraz
    /delay 10s
    /varset portloc ${south}
  
    /bct fraz //gu south
    /bct fraz //macro sharpsouth
    }

/if (${Target.Y}==${bandit}) {
	/echo Bandit Portal Active
    /call newgroup variable usurp
    /delay 10s
    /varset portloc ${bandit}
  

    /bct usurp //gu bandit
    /bct usurp //macro sharpbandit

    }

/if (${Target.Y}==${wild}) {
	/echo wild Portal Active
    /call newgroup variable peign
    /delay 10s
    /varset portloc ${wild}
       
    /bct peign //gu wild
    /bct peign //macro sharpwild
    }

/return

sub newgroup


/declare grouplist string inner
/declare size int local
/declare x int local

/varset grouplist malev,diatribe,soliloquy,manifesto,atisa

/call disband ${Param0}

/delay 2s

/call disband ${Param1}

/delay 2s

/bct ${Param1}  //invite ${Param0}

/delay 15



/bct ${Param1} //useitem 23 1

/delay 6s

/call disband ${Param0}

/delay 15

/for x 1 to 5 {

    /call disband ${grouplist.Arg[${x},,]}

    /delay 15

    /bct ${Param1} //gu ${grouplist.Arg[${x},,]}
    /bct ${Param1} //invite ${grouplist.Arg[${x},,]}
    /delay 15



}



/next x


/bct ${Param1} //useitem 23 1

/delay 6s


/return


sub disband

/bct ${Param0}  //raiddisband
/bct ${Param0}  //disband


/return


sub cleanup


/return


Sub Event_Closed
/echo in Closed

/target clear

/call mage ${Me.Name}

/gu portal closed


/return

sub Event_Death

/gu I'm dead

/say enter guild maslow sunderock

/delay 30s

/call groupport 

/return


sub sharp

/echo ${sharpcount}

/keypress forward

/target clear

/target npc sharp

/if (${Target.ID})  {

/gu Sharp found

/ini sharpcount sharpfound ${GameTime} ${portloc} ${sharpcount}

|Call farmsharp with looter

/bct maslow //macro farmsharp recluse


/mqpause


/call groupport




}


/return




sub stable

/if (${SpawnCount[GM]} > 0) {
/echo GM here
/delay 30s
/goto :start
} else {
/if (!${Zone.Name.Equal[Sunderock Springs]}) {

/echo in zone ${Zone.Name}
/say enter guild maslow sunderock
/delay 30s
/call groupport
}

/return