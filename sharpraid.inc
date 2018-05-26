
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

/call getit 12 ${Param0}

/delay 6

| 

/delay 6


|/goto :start

/return


sub wild

|:start

/keypress forward
/target clear

/face heading 270
/delay 5


/call NewRanInternalMoveTo 2500.88 -1392.59
/call InternalMoveTo 2532.25 -1484.00



/delay 2

  /call getit 12 ${Param0}

/delay 12


| 

/delay 6 

|/goto :start

/return


sub side

:start


/target clear


/call NewRanInternalMoveTo -269.43 1671.40
/call InternalMoveTo -203.70 1662.47

/delay 2

  /call getit 12 ${Param0}

/delay 12



| 

/delay 6 

|/goto :start

/return


sub south
:start


/target clear

/call NewRanInternalMoveTo -1552.60 -1462.34
/call InternalMoveTo -1561.39 -1551.82

  /call getit 12 ${Param0}

/delay 12
|
| 

/delay 6

|/goto :start


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

/if (${Param1.Equal[true]}) {


    /call sharpspawn

} else {

/call sharp
    

}

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
/bct ${mage} //target pc ${Param0}
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




/return

sub sharpspawn

/echo ${sharpcount}

/target clear

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
/call port ${mage} ${Param0}
}

/return