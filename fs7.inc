
Sub fs7
/deletevar * global
/declare doors int global


| Hardcoded for warrior  -  11 is RoA
/echo In Sub FS7
/twist off
/call warbuff
/pet leave

/call toggledoors

|/twist 11

/call topfloor

/call lowerfirst

/call lowersecond

/call lowerthird

/call topsecond


/return

sub toggledoors

/varset doors ${Ini[toggledoors.ini,KeyOne,value1]}

|requires global int doors be set
/echo ${doors}
/echo in toggledoors
/plugin mq2doors unload
/delay 5
/plugin mq2doors
/delay 5
/if (${doors}==0) {
/toggledoors on
} else {
/toggledoors off
}
/return



Sub ClickDoor

/declare attempt bool false
/declare pixelX int -500
/keypress centerview
/if (!${Defined[clickedPortal]}) {
	/declare clickedPortal bool outer false
}
/varset clickedPortal 0

/echo Attempting to click the portal...

:DoClicks
/keypress centerview
/doortarget
	/doevents
	/if (!${Switch.Open}) {
		/if (!${attempt}) {
			/varset attempt 1
            /keypress u
            /delay 5
			/click left center
            /delay 1s
            /click left center
			/goto :DoClicks
		} else /if (${pixelX}<500 && !${Switch.Open}) {
            /keypress y
            /keypress u
			/click left ${pixelX} -10
			/varcalc pixelX ${pixelX}+10
			/delay 0.2s ${clickedPortal}
			/goto :DoClicks
		} else /if (!${Switch.Open}) {
			/echo Could not opendoor...
			/return 0
		}
	}
/return 1


Sub opendoor


/keypress centerview
:open
/delay 3
/keypress u
/click left center
/click left center
/delay 5
/if (!${Switch.Open} && ${count}<6) {

			/click left ${pixelX} -10
			/varcalc pixelX ${pixelX}+10
			/delay 0.2s ${clickedPortal}
			/goto :openmeow
} 


/return

sub topfloor

/call RanInternalMoveTo 332.44 21.13
/call RanInternalMoveTo 334.85 40.22
/call RanInternalMoveTo 332.44 21.13
/useitem 15
/call KillFaceGlobal 20
/target clear
/call RanInternalMoveTo 332.44 21.13
/call InternalMoveTo 385.17 21.04
/face heading 0
/call ClickDoor
/keypress esc
/call RanInternalMoveTo 424.01 20.11
/call KillFaceGlobal 20
/call RanInternalMoveTo 424.01 20.11
/call InternalMoveTo 412.24 9.60
/call RanInternalMoveTo 402.93 30.00
/call InternalMoveTo 398.95 47.76
/face heading 90
/delay 1s
/face heading 90
/call ClickDoor
/keypress esc
/call RanInternalMoveTo 398.95 65.09
/call RanInternalMoveTo 453.20 62.70
/delay 1s

/useitem 15


/return


sub farmit

/hidecorpse all

/call Tserrina


/useitem 8
/useitem 13

/call RanInternalMoveTo 332.44 21.13
/call RanInternalMoveTo 334.85 40.22
/call RanInternalMoveTo 332.44 21.13
/useitem 15
/call KillFaceGlobal 20
/target clear
/call RanInternalMoveTo 332.44 21.13
/call InternalMoveTo 385.17 21.04
/face heading 0
/call ClickDoor
/keypress esc
/call RanInternalMoveTo 424.01 20.11
/call KillFaceGlobal 20
/call RanInternalMoveTo 424.01 20.11
/call InternalMoveTo 412.24 9.60
/call RanInternalMoveTo 402.93 30.00
/call InternalMoveTo 398.95 47.76
/face heading 90
/delay 1s
/face heading 90
/call ClickDoor
/keypress esc
/call RanInternalMoveTo 398.95 65.09
/call RanInternalMoveTo 453.20 62.70
/delay 1s

/useitem 15


/return



sub lowerfirst

/call RanInternalMoveTo 455.27 93.92
/call RanInternalMoveTo 536.32 93.55
/call RanInternalMoveTo 564.62 27.53
/call RanInternalMoveTo 547.09 53.11
/call KillFaceGlobal 20
/target clear
/call RanInternalMoveTo 547.09 53.11
/delay 1s
/call KillFaceGlobal 20
/target clear
/stick off
/attack off
/delay 2s
/call InternalMoveTo 558.60 6.86
/useitem 15
/call InternalMoveTo 622.90 8.39
/call InternalMoveTo 622.56 -5.44
/call InternalMoveTo 622.90 8.39
/call KillFaceGlobal 20
/target clear
/delay 2s
/stick off
/attack off
/stick off
/attack off
/delay 1s


/return

sub lowersecond

/call InternalMoveTo 623.13 5.03
/call InternalMoveTo 664.77 7.08
/call InternalMoveTo 663.63 30.24
/call InternalMoveTo 664.77 7.08
/call InternalMoveTo 720.27 7.12
/call InternalMoveTo 720.40 31.68
/call InternalMoveTo 720.27 7.12
/call InternalMoveTo 550.40 7.24
/call InternalMoveTo 558.24 8.01
/call InternalMoveTo 561.30 47.45
/keypress esc
/delay 1s
/call KillFaceGlobal 20 
/target clear
/delay 2s
/keypress esc
/call KillFaceGlobal2 20
/target clear
/target clear
/stick off
/attack off
/delay 1s
/call InternalMoveTo 561.30 47.45



/return

sub lowerthird

/call InternalMoveTo 547.77 -26.07
/call InternalMoveTo 538.96 -33.97
/call InternalMoveTo 511.27 -11.25

/call KillFaceGlobal2  20 
/target clear
/delay 2s
/call KillFaceGlobal2  20
/target clear
/delay 2s
/stick off
/attack off
/call InternalMoveTo 511.27 -11.25
/call InternalMoveTo 538.78 -0.63
/call InternalMoveTo 533.42 19.69
/call InternalMoveTo 515.61 17.72
/call InternalMoveTo 514.00 -1.00
/call InternalMoveTo 528.31 -7.99
/call InternalMoveTo 541.55 10.81
/call InternalMoveTo 540.92 91.61
/call InternalMoveTo 456.54 91.81
/call InternalMoveTo 454.66 54.09
/keypress esc
/call KillFaceGlobal2 20 
/target clear
/delay 2s
/call KillFaceGlobal2 20
/delay 1s
/target clear
/stick off
/attack off
/call InternalMoveTo 454.66 54.09


/return

sub bottomfarm

/hidecorpse all
/moveto set dist 1
/moveto set loose off



/useitem 8
/delay 2
/useitem 13

/delay 3

/call shrink

/target clear


|/call KillFaceGlobal2 20

/call InternalMoveTo 828.62 6.08

/call InternalMoveTo 720.27 7.12
/target clear
/call InternalMoveTo 720.40 31.68
/target clear
/call InternalMoveTo 720.27 7.12
/call InternalMoveTo 664.82 7.45
/call rightmove
/delay 5
|/call KillFaceGlobal2 30 ${Me.Y} ${Me.X}
/call InternalMoveTo 622.90 8.39
/call InternalMoveTo 622.56 -5.44
/call InternalMoveTo 622.57 -4.44
/call InternalMoveTo 622.90 8.39
/call InternalMoveTo 640.69 7.58

/call svart
/call InternalMoveTo 720.04 7.03
/call svart
/call InternalMoveTo 828.62 6.08
/face heading 180
/delay 1s
/useitem 17
/call KillFaceGlobal 20 ${Me.Y} ${Me.X}
/call InternalMoveTo 828.62 6.08
/call KillFaceGlobal2 20
/delay 1s
/useitem 23 5
/call KillFaceGlobal 20 ${Me.Y} ${Me.X}
/call InternalMoveTo 828.62 6.08
/face heading 180
/attack on
/useitem 21
/call killbats
/face heading 180

/return

sub killbats
/target clear
/target npc bat radius 20
/target npc vampire radius 20

/if (${Target.ID}) {

/call KillFaceGlobal 20 ${Me.Y} ${Me.X}

} else  {

  /gu all done

}

/return


sub topsecond

/call RanInternalMoveTo 454.13 -17.66

/call InternalMoveTo 460.92 -21.88
/keypress esc
/call KillFaceGlobal 20 ${Me.Y} ${Me.X}
/call InternalMoveTo 460.92 -21.88
/call InternalMoveTo 398.72 -21.73

/face heading 90
/delay 1s
/face heading 90
/call ClickDoor
/keypress esc

|return trip

/call Tserrina

:returntrip
/call InternalMoveTo 395.08 21.46
/face heading 180
/delay 1s
/face heading 180
/call ClickDoor
/keypress esc

/call InternalMoveTo 256.84 21.34
/call KillFaceGlobal 20 ${Me.Y} ${Me.X}
/call InternalMoveTo 256.84 21.34
/face heading 0
/delay 5s

/call KillFaceGlobal 20 ${Me.Y} ${Me.X}



/return

sub rightmove

/echo in right
/target clear
/keypress Num_6 hold   
/delay 10
/target clear
/keypress Num_6

/target clear
/keypress Num_4 hold   
/delay 10
/target clear
/keypress Num_4
   


/return


sub svart

/if (${SpawnCount[Advisor Svartmane]}) {
  
          /echo Svart Found
          /gu Svart spawned asshole
          /delay 1
		  /popup Tserrina Up
          /beep
		  /mqpause
}



/return 

sub Tserrina

/if (${SpawnCount[Tserrina Syl`Tor]}) {
  
          /echo Tserrina Found
          /gu Tserrina spawned asshole
          /delay 1
		  /popup Tserrina Up
          /beep
		  /attack on
		  /mqpause
}


/return 


sub shrink

/echo in shrink
/target ${Me}

/delay 3

/useitem 6

/delay 3s

/useitem 6



/return

sub leftmove
/echo in left
/target clear
/keypress Num_4 hold   
/delay 10
/target clear
/keypress Num_4

/target clear
/keypress Num_6 hold   
/delay 10
/target clear
/keypress Num_6


/return
