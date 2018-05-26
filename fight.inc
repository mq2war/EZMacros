Sub KillAllOLD(string party)

/echo IN KILLALLOLD

|party represents a bool true or false
|put your party in bccmd channel farm

/if (${Cursor.ID}) /autoinv
/declare MobWaitTime int inner 0        
/declare baseLocY int inner 0
/declare baseLocX int inner 0
/varset baseLocY ${Me.Y}
/varset baseLocX ${Me.X}
:loop_KillAllMobs
/if (${Target.CleanName.Equal[A Gatekeeper]}) {
        /keypress esc
        /return
}
/if (${Target.CleanName.Equal[Greetings]}) {
        /keypress esc
        /return
}
/if (${Target.CleanName.Equal[Waypoint]}) {
        /keypress esc
        /return
}
/doevents
        /if (${SpawnCount[NPC radius 80]}) {
                /target NPC radius 80
                /delay 5s (${Target.ID})
                /if (!${NetBots[${Me.Name}].Attacking}) {
                        /attack on
                        /stick 10
                        /if (${party.Equal[true]}) {
			/bct farm //target ID ${Target.ID}
			/bct farm //stick 2
			/bct farm //attack on
			}
                        /delay 1s
                        /if (${Me.Class.ShortName.Equal[DRU]}) {
                                /if ($!{FindItem[${MyEpic}].Timer}) /casting "${MyEpic}"|item
                        }
                        /if (${Me.Class.ShortName.Equal[SHM]}) {
                                /if (${Me.Gem[Spirit of the Kraken]}>0 && !${Me.Buff[Spirit of the Kraken].ID}) {
                                        /if (${Me.SpellReady[Spirit of the Kraken]}) /cast "Spirit of theKraken"
                                }
                        }
                }
                /if (${NetBots[${Me.Name}].Attacking} && !${Target.ID}) /multiline ; /attack off ; /bct farm //attack off ;
        }
        /if (!${NetBots[${Me.Name}].Attacking} || ${Math.Distance[${baseLocY},${baseLocX},${Me.Z}]} > 40) {
                /if (${Math.Distance[${baseLocY},${baseLocX},${Me.Z}]} > 15 ) { /call InternalMoveTo ${baseLocY} ${baseLocX} }
        }
        /if (${MobWaitTime} < ${maxWeightTimeBetweenAttacking}) {
                /if (!${SpawnCount[NPC radius 80]}) {
                        /delay 1s
                        /varset MobWaitTime ${Math.Calc[${MobWaitTime} + 1]}
                } else { /varset MobWaitTime 0 }
                /goto :loop_KillAllMobs
        }       
/return

Sub KillAll(string party)

/echo IN KILLALL
:KillAll

|party represents a bool true or false
|put your party in bccmd channel farm

/if (${Cursor.ID}) /autoinv
/declare MobWaitTime int inner 0        
/declare baseLocY int inner 0
/declare baseLocX int inner 0
/varset baseLocY ${Me.Y}
/varset baseLocX ${Me.X}
:loop_KillAllMobs
/if (${Target.CleanName.Equal[A Gatekeeper]}) {
        /keypress esc
        /return
}
/if (${Target.CleanName.Equal[Greetings]}) {
        /keypress esc
        /return
}
/if (${Target.CleanName.Equal[Waypoint]}) {
        /keypress esc
        /return
}
/doevents
/echo ${SpawnCount[NPC radius 80]}
        /if (${SpawnCount[NPC radius 80]}) {

	/echo Spawn Found 
                /target NPC radius 80
                /delay 5s (${Target.ID})
                /if (!${NetBots[${Me.Name}].Attacking}) {
                        /attack on
                        /stick 10
                        /if (${party.Equal[true]}) {
			/bct farm //target ID ${Target.ID}
			/bct farm //stick 2
			/bct farm //attack on
			}
                        /delay 1s
                        /if (${Me.Class.ShortName.Equal[DRU]}) {
                                /if ($!{FindItem[${MyEpic}].Timer}) /casting "${MyEpic}"|item
                        }
                        /if (${Me.Class.ShortName.Equal[SHM]}) {
                                /if (${Me.Gem[Spirit of the Kraken]}>0 && !${Me.Buff[Spirit of the Kraken].ID}) {
                                        /if (${Me.SpellReady[Spirit of the Kraken]}) /cast "Spirit of theKraken"
                                }
                        }
                }
                /if (${NetBots[${Me.Name}].Attacking} && !${Target.ID}) /multiline ; /attack off ; /bct farm //attack off ;
        }
        /if (!${NetBots[${Me.Name}].Attacking} || ${Math.Distance[${baseLocY},${baseLocX},${Me.Z}]} > 40) {
                /if (${Math.Distance[${baseLocY},${baseLocX},${Me.Z}]} > 15 ) { /call InternalMoveTo ${baseLocY} ${baseLocX} }
        }
        /if (${MobWaitTime} < 20) {
                /if (!${SpawnCount[NPC radius 80]}) {
                        /delay 1s
                        /varset MobWaitTime ${Math.Calc[${MobWaitTime} + 1]}
                } else { /varset MobWaitTime 0 }
                /goto :KillAll
        }       
/return