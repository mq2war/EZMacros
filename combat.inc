sub NewKillFace(int distance)
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
		/delay 1s
            /if (${SpawnCount[NPC radius ${distance}]}) {
		
		/goto :destroy		
		
		}
		}

		/goto :end
		/varset count 0
		}
		
		:destroy
        /delay 7
		/if (${Target.ID}) {
		
		/attack on
		/face fast
		/stick moveback 10				
				
		} 
							
		/if (${SpawnCount[NPC radius ${distance}]} == 0 || !${Target.ID}) {
		
		/delay 2s
	
		/if (!${Target.ID}) {
		/varset count 0
		  /goto :end
		}
         }
		/delay 1s
		|/bca //cast 1

			
		/goto :fight
		}
		
		:end
        
        /if (${SpawnCount[Tserrina Syl`Tor]}) {
  
          /echo Tserrina Found
          /gu Tserrina spawned asshole
          /delay 1
          /beep
}

 /if (${SpawnCount[Svartmane]}) {
  
          /echo Svartmane Found
          /gu Svartmane spawned asshole
          /delay 1
          /beep
          /beep
          /pause
}
	
		/delay 1  
		/call InternalMoveTo ${baseLocY} ${baseLocX}

		
		

/return

sub KillFaceGlobal(int distance, int mey, int mex)
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
		/attack on

	
		/varcalc count ${count} + 1

	  	/delay 4

		/if (${SpawnCount[NPC radius ${distance}]}) {
		
		/goto :destroy		
		
		}
         
		/goto :end

		}
		
		:destroy

        /delay 5
		/if (${Target.ID}) {
		
		/attack on
		/face fast
		/stick moveback 10				
				
		} 
							
		/if (${SpawnCount[NPC radius ${distance}]} == 0 || !${Target.ID}) {
		
		/delay 1s
	
		/if (!${Target.ID}) {
						  
				  /goto :end
		}


         }
					
		/goto :fight

		}
		
		:end

		/if (${Target.ID}) {
		
		/attack on
		/face fast
		/stick moveback 10
		/delay 1s
		/goto :destroy				
				
		} 
        
        /if (${SpawnCount[Tserrina Syl`Tor]}) {
  
          /echo Tserrina Found
          /gu Tserrina spawned asshole
		  /beep
          /delay 1
          /beep
		  /mqpause
}

 /if (${SpawnCount[Svartmane]}) {
  
          /echo Svartmane Found
          /gu Svartmane spawned asshole
		  /beep
          /delay 1
          /beep
          /beep
          /mqpause
}
	
		/delay 1
		/echo killface move to ${mey} ${mex}
		/moveto ${mey} ${mex}
		/delay 5
		

/return

sub KillFaceGlobal2(int distance, float mey, float mex)
/if (${Cursor.ID}) /autoinv

/declare count int inner
|/declare mey int inner 0
|/declare mex int inner 0

|/varset mey ${Me.Y}
|/varset mex ${Me.X}



/echo This is spawn count  ${SpawnCount[NPC radius ${distance}]}
       
	    /varset count 0

		:fight
		/attack on
		
		| deal with unique mobs -  need to drive via ini file
		/call specialcombat

        /if (${SpawnCount[NPC radius ${distance}]}) {
        /echo ${SpawnCount[NPC radius ${distance}]}
		/delay 2
		/goto :destroy

		} else {

        /echo No Spawns Found
		/goto :end


		}


		:destroy
        
		/delay 7
		
		/if (${Target.ID}) {
 
        | Frozenshadow code

		/call bat 30 1
		

		/echo Target Found First check
		
		/attack on
		/face fast
		/stick 12 front
	    /delay 5s
		/goto :fight

		} else {

          /delay 15

		  /if (${Target.ID}) { 

		  /call bat 30 1

		  /echo Target found 2nd check

		  /goto :destroy


		  } else {
		
            /echo Going to End
	        /goto :end

		  }

		}


          :end
          /stick off
          /attack off
 
		
		  /if (${Target.ID}) { 

		  /call bat 30 1

		  /echo Target found 3rd check

		  /goto :destroy


		  }


/if (${SpawnCount[Tserrina Syl`Tor]}) {
  
          /echo Tserrina Found
          /gu Tserrina spawned asshole
          /delay 1
          /beep
		  /popup Tserrina Up
		  /mqpause
}

 /if (${SpawnCount[Svartmane]}) {
  
          /echo Svartmane Found
          /gu Svartmane spawned asshole
          /delay 1
          /beep
          /beep
          /mqpause
}
	

	/stick off
    /attack off
 
    |/delay 15
		
	
	|:nospawn

	|/echo killface move to ${mey} ${mex}

    |/moveto loc ${mey} ${mex} 
    |/delay 5



/return


sub KillFaceNoVamp(int distance, float mey, float mex)
/if (${Cursor.ID}) /autoinv

/declare count int inner
|/declare mey int inner 0
|/declare mex int inner 0

|/varset mey ${Me.Y}
|/varset mex ${Me.X}



/echo This is spawn count  ${SpawnCount[NPC radius ${distance}]}
       
	    /varset count 0

		:fight
		/attack on
		
		| deal with unique mobs -  need to drive via ini file
		/call specialcombat

        /if (${SpawnCount[NPC radius ${distance}]}) {
        /echo ${SpawnCount[NPC radius ${distance}]}
		/delay 2
		/goto :destroy

		} else {

        /echo No Spawns Found
		/goto :end


		}


		:destroy
        
		/delay 7
		
		/call bat 30

		/if (${Target.ID} && !${Target.CleanName.Equal[an enraged vampire]}) {
 
        | Frozenshadow code

		/call bat 30
		

		/echo Target Found First check
		
		/attack on
		/face fast
		/stick 12 front
	    /delay 5s
		/goto :fight

		} else {
            
		  /stick off
		  /target clear
          /delay 15

		  /if (${Target.ID} && !${Target.CleanName.Equal[an enraged vampire]}) { 

		  /call bat 30

		  /echo Target found 2nd check

		  /goto :destroy


		  } else {
		
            /echo Going to End
	        /goto :end

		  }

		}


          :end
          /stick off
          /attack off
		  /target clear
		  /delay 5
 
		
		  /if (${Target.ID} && !${Target.CleanName.Equal[an enraged vampire]}) { 

		  /call bat 30

		  /echo Target found 3rd check

		  /goto :destroy


		  }


/if (${SpawnCount[Tserrina Syl`Tor]}) {
  
          /echo Tserrina Found
          /gu Tserrina spawned asshole
          /delay 1
		  /popup Tserrina Up
          /beep
		  /mqpause
}

 /if (${SpawnCount[Svartmane]}) {
  
          /echo Svartmane Found
          /gu Svartmane spawned asshole
          /delay 1
          /beep
          /beep
          /mqpause
}
	

	/stick off
    /attack off
	/target clear
 
    |/delay 15
		
	
	|:nospawn

	|/echo killface move to ${mey} ${mex}

    |/moveto loc ${mey} ${mex} 
    |/delay 5



/return




sub bat(int distance)


| Do not send Param1 to skip vamps
    /if (!${Param1}) {
       /if (${Target.CleanName.Equal[an enraged vampire]}) { 
       /attack off
	   /target clear
	   /face heading 90

	   }

	   }

       /if (${SpawnCount[a shrouded bat radius ${distance}]}) {

        /target npc bat radius ${distance}
		/attack on

		}

/return

sub specialcombat

        /if (${Target.CleanName.Equal[Kronos]}) {
		|/beep		
		}
		
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

		



/return


sub autoattack

| Param0 = tank

/declare fists int inner
/declare uw int inner
/declare zerk int inner
/declare ninja int inner
/declare nerf int inner
/declare firsttime int inner
/declare burn int inner
/declare boom int inner
/declare aoe int inner
/declare pcount int inner
/declare pcount2 int inner
/declare ua2 int inner

/varset fists 0
/varset uw 0
/varset zerk 0
/varset ninja 0
/varset nerf 0
/varset firsttime 1
/varset burn 0
/varset boom 0
/varset aoe 0
/varset ua2 0


/varset pcount ${SpawnCount[PC radius 200]}


/target npc radius 30
/attack on
/delay 1
/keypress 2





/if (${Target.ID}) {

/stick 14 front

/face fast

/itemnotify charm rightmouseup

/disc Cyclone Blade
/attack on
/delay 1

/keypress 2
/delay 1
/bct ang //target ID ${Target.ID}
/bct rog //target ID ${Target.ID}
/bct ang //stick 12 uw !front
/bct rog //stick 12 uw behind
/delay 1
/bct ang //attack on
/bct rog //attack on
/delay 2

|| Hardcoded currently
/if (${Param0.Equal[maslow]})  {

/bct shaman //macro shaman ${Param0}
/bct drood //macro druidheal ${Param0}
/bct wiz //macro wiznuke ${Param0}
/bct necro //macro necro ${Param0}


}

} else {

/target npc radius 30
/attack on
/delay 1
/keypress 2

}

/attack on
/disc Commanding Voice
/delay 1
/itemnotify rightfinger rightmouseup


/bct ua //useitem 17


/bct recluse //itemnotify powersource rightmouseup
/delay 1
/bct recluse //cast "Gale Force III"
|/delay 2
|/bct lateral //pet attack

/useitem 23 4
/delay 1s

/bct wiz //itemnotify mainhand rightmouseup



:start

/echo In Autoattack

/bct pet //pet attack

/doability kick
|/bct g1 //doability kick

/useitem 23 4
| add code to check health and tell cleric to healme
/attack on

/if (${Target.ID}) {


/stick 14 front

/keypress forward hold

/delay 4

/keypress forward

/attack on
/delay 1


/bct ang //target ID ${Target.ID}

/bct rog //target ID ${Target.ID}


/delay 1
/bct rog //stick 12 uw behind

/bct ang //stick 15 uw !front
/delay 1
/bct ang //attack on

/bct rog //attack on

|/bct variable //target ID ${Target.ID}
|/bct variable //cast 1
|/bct variable //pet attack



} else {


/target npc radius 50
/attack on
/delay 1
/keypress 2

/if (!${Target.ID})  {

/bca //endmacro

/goto :end


}


}





/attack on




/if (${firstime}==1) {




/bct peign //cast "Vile Tightness"
/bct lateral //assist Maslow
/delay 1
/bct lateral //cast "Insanity VI"
/bct recluse //itemnotify ranged rightmouseup


/delay 5

/bct recluse //cast 9
/bct peign //cast "Blood Ablaze IV"
/bct zerk //itemnotify mainhand rightmouseup


/bct ninja //itemnotify ammo rightmouseup
/bct recluse //itemnotify powersource rightmouseup
/bct undermine //target ID ${Target.ID}
/delay 1
/bct undermine //cast 6


}


/varcalc uw ${uw} + 1
/varcalc zerk ${zerk} + 1
/varcalc ninja ${ninja} + 1
/varcalc burn ${burn} + 1
/varcalc boom ${boom} + 1
/varcalc aoe ${aoe} + 1
/varcalc ua2 ${ua2} + 1
/varcalc firsttime ${firsttime} + 1


| Boom

/if (${boom}==2) {



|/delay 2
|/bct lateral //cast "Insanity VI"
/bct peign //cast "Blood Ablaze IV"
/delay 3
/varset boom 0
}

/if (${ua2}==2) {

/bct ua2 //useitem 17

}

/if (${aoe}==8) {
/delay 5
/bct peign //cast 4
/delay 2
/bct lateral //assist Maslow
/delay 2
/bct lateral //cast "Breathless V"


/varset aoe 0
}

|  Maslow BP clicky

/if (${fists}==24) {



}


|  Fists
/if (${fists}==6) {
/bct recluse //cast 9
/bct peign //cast 3
/delay 2
/bct recluse //itemnotify ranged rightmouseup
/bct goft //disc Fists of Wu
/bct uberitis //disc Fists of Wu
/disc Commanding Voice
/bct undermine //target ID ${Target.ID}
/delay 1
/bct undermine //cast 3
/varset fists 0
}

/if (${burn}==25) {


/bct recluse //cast "Burning Tinder III"
/delay 15
/bct recluse //cast "Gale Force III"

/bct ua //useitem 17


/varset burn 0


}

/if (${ua2}==27) {

/bct ua2 //useitem 17

/varset ua2 3

}

|| Zerk Weapon

/if (${nerf}==3) {
/bct zerk //itemnotify mainhand rightmouseup
/bct peign //cast "Vile Tightness IV"
/varset nerf 0
/delay 2


}


|| Zerk Chest
/if (${zerk}==4) {

/varset zerk 0
/delay 4

/bct peign //cast "Blood Ablaze IV"
/bct drood //mqpause
/delay 1
|/bct drood //target ID ${Target.ID}
/bct drood //itemnotify mainhand rightmouseup
/delay 1

/bct drood //target ${Me.ID}
/bct drood //mqpause

}

|| Ninja
/if (${ninja}==15) {

/bct ninja //itemnotify ammo rightmouseup
/bct recluse //itemnotify powersource rightmouseup
/varset ninja 0
/delay 2

/itemnotify rightfinger rightmouseup

/bct undermine //target ID ${Target.ID}
/delay 1
/bct undermine //cast 6


}


|/echo Ninja Count:  ${ninja}
/delay 8


/attack on
/delay 4


/varcalc fists ${fists} + 1
/varcalc nerf ${nerf} + 1

/varset pcount2 ${SpawnCount[PC radius 200]}


/if (${pcount2} < ${pcount}) {

/call rez

}

/doevents

/goto :start


:end

/target npc radius 50



/if (${Target.ID})  {



/goto :start


}





/return



sub Event_Frenzy

|/gu in frenzy

/bct submit //cast "Wave of Purity III"

/bct timesink //itemnotify mainhand rightmouseup

/bct fraz //cast "Wave of Purity III"

/return



sub rez

/useitem 23 3

/delay 2


/bca //notify ConfirmationDialogBox Yes_Button leftmouseup

|/call acceptrez


/return
