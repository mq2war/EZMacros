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
	/delay 1
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
   /keypress Num_4 hold   
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