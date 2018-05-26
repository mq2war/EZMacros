
#Event Closed "#*#This portal is currently closed#*#"
#event Death "You have been slain#*#"


sub bandit

:start 

/target clear

/face heading 270
/delay 5
/face heading 270

/call NewRanInternalMoveTo 1158.12 377.49

/call InternalMoveTo 1129.87 348.26

/call getit 4 ${Param0}

/delay 6

/call mage

/delay 6


/goto :start

/return


sub wild

:start

/keypress forward
/target clear

/face heading 270
/delay 5


/call NewRanInternalMoveTo 2500.88 -1392.59
/call InternalMoveTo 2532.25 -1484.00



/delay 2

/call getit 4 ${Param0}

/delay 12


/call mage

/delay 6 

/goto :start

/return


sub side

:start


/target clear


/call NewRanInternalMoveTo -269.43 1671.40
/call InternalMoveTo -203.70 1662.47

/delay 2

/call getit 4 ${Param0}

/delay 12



/call mage

/delay 6 

/goto :start

/return


sub south
:start


/target clear

/call NewRanInternalMoveTo -1552.60 -1462.34
/call InternalMoveTo -1561.39 -1551.82

/call getit 4 ${Param0}

/delay 12
|
/call mage

/delay 6

/goto :start


/return 

sub getit(int time)

/call stable

/target clear

/target an open portal radius 800

/if (${Target.ID}) {


/face fast

/delay 2

/stick 20

/delay 2s

/keypress forward hold ${time}
/delay 3
|
/keypress forward hold ${time}
/keypress forward
/delay 3

/varcalc sharpcount ${sharpcount} + 1

/echo this is sharpcount ${sharpcount}

/doevents

/if (${Param0}) {

    /call sharpspawn

} else {

/call sharp
    

}

} else {

    /target clear
    /call port ${mage} ${runner}
}

/return


sub runit(int time)

/call stable

/target clear

/target an open portal radius 800

/if (${Target.ID}) {


/face fast


/delay 2

/call InternalMoveTo ${Target.Y} ${Target.X}


/stick 20

/delay 2s

/keypress forward hold ${time}
/delay 3
|
/keypress forward hold ${time}
/keypress forward
/delay 3

/varcalc sharpcount ${sharpcount} + 1

/echo this is sharpcount ${sharpcount}

/doevents
/call sharpspawn

} else {

    /target clear
    /call port ${mage} ${runner}
}

/return



sub mage


/doevents
/call stable

/echo In Mage


/delay 3
/bct ${mage} //target pc ${runner}
/delay 1s


/bct ${mage} //cast "Call of the Hero"


/return

sub runport


/declare side float inner
/declare south float inner
/declare bandit float inner
/declare wild float inner



/varset side -198.00
/varset south -1540.63
/varset bandit 1100.50
/varset wild 2526.63


/call stable

/echo ${Target.Y}
/echo ${south}
/target open

/if (!${Target.ID}) {

/delay 30s
/call stable

}

/if (${Target.Y}==${side}) {
	/echo Side Portal Active
    |/call group ${Param0} ${Param1} ratio
    |/delay 10s
    /varset portloc side
    /call side ${Param0}
    }

/if (${Target.Y}==${south}) {
	/echo South Portal Active

    |/call group ${Param0} ${Param1} fraz
    |/delay 10s
    /varset portloc south
    /call south ${Param0}
    }

/if (${Target.Y}==${bandit}) {
	/echo Bandit Portal Active
    |/call group ${Param0} ${Param1} usurp
    |/delay 10s
    /varset portloc bandit
    /call bandit ${Param0}
    }

/if (${Target.Y}==${wild}) {
	/echo wild Portal Active
    |/call group ${Param0} ${Param1} peign
    |/delay 10s
    /varset portloc wild
    /call wild ${Param0}
    }

/return


sub port

|Param0 mage
|Param1 runner

/declare side float inner
/declare south float inner
/declare bandit float inner
/declare wild float inner



/varset side -198.00
/varset south -1540.63
/varset bandit 1100.50
/varset wild 2526.63


/call stable

/echo ${Target.Y}
/echo ${south}
/target open

/if (!${Target.ID}) {

/delay 30s
/call stable

}

/if (${Target.Y}==${side}) {
	/echo Side Portal Active
    /call group ${Param0} ${Param1} ratio
    /delay 10s
    /varset portloc side
    /call side
    }

/if (${Target.Y}==${south}) {
	/echo South Portal Active

    /call group ${Param0} ${Param1} fraz
    /delay 10s
    /varset portloc south
    /call south
    }

/if (${Target.Y}==${bandit}) {
	/echo Bandit Portal Active
    /call group ${Param0} ${Param1} usurp
    /delay 10s
    /varset portloc bandit
    /call bandit
    }

/if (${Target.Y}==${wild}) {
	/echo wild Portal Active
    /call group ${Param0} ${Param1} peign
    /delay 10s
    /varset portloc wild
    /call wild
    }

/return


sub groupport

|Param0 mage
|Param1 runner

/declare side float inner
/declare south float inner
/declare bandit float inner
/declare wild float inner



/varset side -198.00
/varset south -1540.63
/varset bandit 1100.50
/varset wild 2526.63


/call stable

/echo ${Target.Y}
/echo ${south}
/target open

/if (!${Target.ID}) {

/delay 30s
/call stable

}

/if (${Target.Y}==${side}) {
	/echo Side Portal Active
    /call newgroup variable ratio
    /delay 10s
    /varset portloc side
    /call side
    }

/if (${Target.Y}==${south}) {
	/echo South Portal Active

    /call newgroup variable fraz
    /delay 10s
    /varset portloc south
    /call south
    }

/if (${Target.Y}==${bandit}) {
	/echo Bandit Portal Active
    /call newgroup variable usurp
    /delay 10s
    /varset portloc bandit
    /call bandit
    }

/if (${Target.Y}==${wild}) {
	/echo wild Portal Active
    /call newgroup variable peign
    /delay 10s
    /varset portloc wild
    /call wild
    }

/return

sub newgroup


/declare grouplist string inner
/declare size int local
/declare x int local

/varset grouplist malev,diatribe,soliloquy,manifesto,atisa

/call disband ${Param0}
/call disband ${Param1}

/bct ${Param1}  //invite ${Param0}

/delay 1s

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

sub group

/bct ${Param0} //disband
/delay 3
/bct ${Param1} //disband


/bct ${Param2} //invite ${Param0}
/delay 5
/bct ${Param2} //invite ${Param1}
/delay 5
/bct ${Param2} //invite ${Param0}
/delay 5
/bct ${Param2} //invite ${Param1}
/delay 5

/bct ${Param2} //useitem 23 1
/delay 15

/call stable

/return


Sub Event_Closed
/echo in Closed

/target clear
/call port ${mage} ${runner}

/return

sub Event_Death

/gu I'm dead

/say enter guild maslow sunderock

/delay 30s

/call port ${mage} ${runner}

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


/call port ${mage} ${runner}




}


/return

sub sharpspawn

/echo ${sharpcount}

/target npc sharp

/if (${Target.ID})  {

/gu Sharp found

/ini sharpcount sharpfound ${GameTime} ${portloc} ${sharpcount}


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
/call port ${mage} ${runner}
}

/return