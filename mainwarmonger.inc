Warmonger.inc v.3.7
#Event SomethingDied "#1# has been slain by #*#"
#Event SomethingDied "#*# have slain #*#"
#Event ShadowStep "Shadow does a shadow step."
#Event Wait4rez "You have been slain by #*#"
#Event NoTarg "You must first click on the being you wish to attack!"
#Event FarFarAway "Your target is too far away, get closer!"
#Event EQBC "<#1#> #2#"
#Event EQBC "[#1#(msg)] #2#"
#Event EQBC "[MQ2] #2#"
                |** Default variables.  **|
Sub SetupEZCommon
        /if (!${Defined[ClrEpic1]})                     /declare ClrEpic1 timer outer 48s
        /if (!${Defined[RogEpic1]})                     /declare RogEpic1 timer outer 0s
        /if (!${Defined[UCrune]})                               /declare UCrune timer outer 0s
        /if (!${Defined[RanEpic1]})                     /declare RanEpic1 timer outer 0s
        /if (!${Defined[SotA]})                                 /declare SotA timer outer 10s
        /if (!${Defined[BCPA]})                                 /declare BCPA timer outer 37s
        /if (!${Defined[WarEpicAggTimer]})              /declare WarEpicAggTimer timer outer 0s
        /if (!${Defined[WarEpicAggTimer2]})             /declare WarEpicAggTimer2 timer outer 0s
        /if (!${Defined[MA]})                                   /declare MA string outer
        /if (!${Defined[SA]})                                   /declare SA string outer
        /if (!${Defined[TA]})                                   /declare TA string outer
        /if (!${Defined[ClrMark]})                              /declare ClrMark string outer NULL
        /if (!${Defined[AFKProtectMe]})                 /declare AFKProtectMe int outer 0
        /if (!${Defined[War2Epic]})                             /declare War2Epic int outer 0
        /if (!${Defined[War2Epic2]})                    /declare War2Epic2 int outer 0
        /if (!${Defined[STGB]})                                 /declare STGB int outer 0
        /if (!${Defined[SpecCom]})                              /declare SpecCom int outer 0
        /if (!${Defined[T6KtH]})                                /declare T6KtH int outer 0
        /if (!${Defined[AMN]})                                  /declare AMN int outer 0
        /if (!${Defined[MyTar]})                                /declare MyTar int outer 0
        /if (!${Defined[RewardSpeed]})                  /declare RewardSpeed int outer 0
        /if (!${Defined[InstantRez]})                   /declare InstantRez int outer 120005
        /if (!${Defined[InstantCure]})                  /declare InstantCure int outer 120004
        /if (!${Defined[Cotc]})                                 /declare Cotc int outer 120002
        /if (!${Defined[Scepter]})                              /declare Scepter[10] string outer NULL
        /if (!${Defined[ScepterClk]})                   /declare ScepterClk string outer NULL
        /if (!${Defined[shield]})                               /declare shield[8] string outer NULL
        /if (!${Defined[DruRegen]})                             /declare DruRegen[5] string outer NULL
        /if (!${Defined[VivClick]})                             /declare VivClick[3] string outer NULL
        /if (!${Defined[BadIllusions]})                 /declare BadIllusions[${Math.Calc[${Ini[./WM/WM.ini,BadIllusions].Count[|]}-1]}] string outer
        /if (!${Defined[TrustedGoons]})                 /declare TrustedGoons[${Math.Calc[${Ini[./WM/WM.ini,TrustedPeople].Count[|]}-1]}] string outer
	/varset MA Maslow
        /if (${Ini[./WM/WM.ini,Tanks,MA].NotEqual[NULL]})               /varset MA ${Ini[./WM/WM.ini,Tanks,MA]}
        /if (${Ini[./WM/WM.ini,Tanks,SA].NotEqual[NULL]})               /varset SA ${Ini[./WM/WM.ini,Tanks,SA]}
        /if (${Ini[./WM/WM.ini,Tanks,TA].NotEqual[NULL]})               /varset TA ${Ini[./WM/WM.ini,Tanks,TA]}
        /if (${FindItemCount[=Fastest Travel (Reward Item)]})   /varset RewardSpeed 1
        /varset shield[1] Ancient Stonewall I
        /varset shield[2] Ancient Stonewall II
        /varset shield[3] Ancient Stonewall III
        /varset shield[4] Ancient Stonewall IV
        /varset shield[5] Ancient Stonewall V
        /varset shield[6] Ancient Stonewall VI
        /varset shield[7] Ancient Stonewall VII
        /varset shield[8] Ancient Stonewall VIII
        /varset DruRegen[1] Ancient: Druid Regeneration
        /varset DruRegen[2] Ancient: Druid Regeneration II
        /varset DruRegen[3] Timeless: Pack Regeneration
        /varset DruRegen[4] Timeless: Pack Regeneration II
        /varset DruRegen[5] Timeless: Pack Regeneration III
        /varset VivClick[1] Vivificate the Masses
        /varset VivClick[2] Vivificate the Masses II
        /varset VivClick[3] Vivificate the Masses III
        /varset Scepter[1] Sceptre of Time I
        /varset Scepter[2] Sceptre of Time II
        /varset Scepter[3] Sceptre of Time III
        /varset Scepter[4] Sceptre of Time IV
        /varset Scepter[5] Sceptre of Time V
        /varset Scepter[6] Sceptre of Time VI
        /varset Scepter[7] Sceptre of Time VII
        /varset Scepter[8] Sceptre of Time VIII
        /varset Scepter[9] Sceptre of Time IX
        /varset Scepter[10] Sceptre of Time X
        /if ((${Me.Book[Mark of Emperors III]}!=NULL) && ${ClrMark.Equal[NULL]}) /varset ClrMark Mark of Emperors III
        /if ((${Me.Book[Mark of Emperors II]}!=NULL) && ${ClrMark.Equal[NULL]}) /varset ClrMark Mark of Emperors II
/declare ScepCnt int local 0
        /for ScepCnt 1 to 10
                /if (${FindItemCount[=${Scepter[${ScepCnt}]}]}==1) /varset ScepterClk ${Scepter[${ScepCnt}]}
        /next ScepCnt
/return
Sub BadIllusionSetup
        /declare cntx int local
        /for cntx 1 to ${Math.Calc[${Ini[./WM/WM.ini,BadIllusions].Count[|]}-1]}
                /varset BadIllusions[${cntx}] ${Ini[./WM/WM.ini,BadIllusions,${cntx}]}
        /next cntx
/return
Sub GoonArrayFill
        /declare count int local
        /for count 1 to ${Math.Calc[${Ini[./WM/WM.ini,TrustedPeople].Count[|]}-1]}
                /varset TrustedGoons[${count}] ${Ini[./WM/WM.ini,TrustedPeople,${count}]}
        /next count
/return
                |** Am I rooted? (Yea that fuggin rooted.inc) If you are poisoned/diseased that nice cleric will viv it away. **|
Sub CheckDetrimental
        /declare ctr int local o
        /for ctr 0 to ${Group.Members}
        /if (${NetCure[${NetBots[${Group.Member[${ctr}].Name}].Buff}].Diseased} || ${NetCure[${NetBots[${Group.Member[${ctr}].Name}].Buff}].Poisoned}) {
                /if (!${FindItemCount[=Instant Cure Group (Reward Item)]}) /casting "Word of Vivification"
                /if (${FindItemCount[=Instant Cure Group (Reward Item)]}) /casting ${InstantCure}|item
        }
        /if (${NetCure[${NetBots[${Group.Member[${ctr}].Name}].Buff}].Rooted}) {
                /if (${FindItemCount[=Instant Cure Group (Reward Item)]}) /casting ${InstantCure}|item
                /if (!${FindItemCount[=Instant Cure Group (Reward Item)]}) /call Rooted
        }
        /if (${NetCure[${NetBots[${Group.Member[${ctr}].Name}].Buff}].Charmed} || ${NetCure[${NetBots[${Group.Member[${ctr}].Name}].Buff}].Mesmerized} || ${NetCure[${NetBots[${Group.Member[${ctr}].Name}].Buff}].Blinded}) {
                /if (${FindItemCount[=Instant Cure Group (Reward Item)]}) /casting ${InstantCure}|item
        }
        /next ctr
        /if (${Bool[${Group}==NULL]} && (${NetCure[${NetBots[${Me.CleanName}].Buff}].Diseased} || ${NetCure[${NetBots[${Me.CleanName}].Buff}].Poisoned})) /casting ${InstantCure}|item
        /if (${Me.Buff[Anguish Crippling Spasm].ID} && ${FindItemCount[=Instant Cure Group (Reward Item)]}) /casting ${InstantCure}|item
/return
                |** Dont attack corpses or players **|
Sub CheckCombatStatus
        /if (${NetBots[${Me.Name}].Attacking} && ${Target.Type.Equal[PC]} || ${Target.Type.Equal[corpse]}) /attack off
/return
                |** Updated Sub Spellbuffs 11/2012 - Couple of these are outdated but I'm leaving them as place holders for now. **|
Sub Spellbuffs
        /if (!${Me.State.Equal[BIND]}) {
                /if (${Me.Gem[Cloak of Anarchy]}>0 && !${Me.Buff[Cloak of Anarchy].ID}) /cast "Cloak of Anarchy"
                /if (${Me.Gem[Focus of Healing]}>0 && !${Me.Buff[Focus of Healing].ID}) /cast "Focus of Healing"
                /if (${Me.Gem[Amplify Healing]}>0 && !${Me.Buff[Amplify Healing].ID}) /cast "Amplify Healing"
                /if ((${FindItemCount[=Ultimate Charm v1]} || ${FindItemCount[=Ultimate Charm v2]}) && ${Me.Gem[Kaldar's Helping Hand]}>0 && !${Me.Buff[Kaldar's Helping Hand].ID} && (${T6KtH}==0)) /cast "Kaldar's Helping Hand"
                /if (${Me.Gem[Ward of the Hunter]}>0 && !${Me.Buff[Ward of the Hunter].ID} && (${T6KtH}==0)) /cast "Ward of the Hunter"
                /if (${Me.Gem[Secrets' Secret Ranger Secrets]}>0 && !${Me.Buff[Secrets' Secret Ranger Secrets].ID} && (${T6KtH}==0)) /cast "Secrets' Secret Ranger Secrets"
                /if (${Me.Gem[Form of the Werewolf]}>0 && !${Me.Buff[Form of the Werewolf].ID} && (${T6KtH}==0)) /cast "Form of the Werewolf"
                /if (${Me.Gem[Form of the Werewolf II]}>0 && !${Me.Buff[Form of the Werewolf II].ID} && (${T6KtH}==0)) /cast "Form of the Werewolf II"
                /if (${Me.Gem[Yaulp IX]}>0 && !${Me.Song[Yaulp IX].ID} && ${Me.SpellReady[Yaulp IX]} && (${Me.PctMana}>15) && ${NetBots[${Me.Name}].Attacking}) /cast "Yaulp IX"
                /if (${Me.Gem[Yaulp X]}>0 && !${Me.Song[Yaulp X].ID} && ${Me.SpellReady[Yaulp X]} && (${Me.PctMana}>15) && ${NetBots[${Me.Name}].Attacking}) /cast "Yaulp X"
                /if (${Me.Gem[Crusader Fury II]}>0 && !${Me.Buff[Crusader Fury II].ID} && (${T6KtH}==0)) /cast "Crusader Fury II"
                /if (${Window[CastingWindow].Open}) /delay 44 !${Window[CastingWindow].Open}
        }
/return
                |** Some common Clicky buffs **|
Sub Clickbuffs
        /if (!${Me.State.Equal[BIND]}) {
                /if (!${Me.Buff[Fastest Travel].ID} && (${T6KtH}==0) && (${FindItemCount[=Fastest Travel (Reward Item)]} && ${RewardSpeed}==1) && ${Zone.ID}!=111) /casting 120001|item
                /if (!${Me.Buff[Illusion: Skeleton].ID} && (${AMN}==1)) /casting 11646|item -targetid|${Me.ID}
                /if (${Me.Inventory[rightwrist].Spell.Name.Equal[Form of Defense IV]} && !${Me.Buff[Form of Defense IV].ID} && !${Me.Moving} && !${NetBots[${Me.Name}].Attacking} && (${T6KtH}==0)) /itemnotify 10 rightmouseup
                /if (${Me.Inventory[Charm].Spell.Name.Equal[Ultimate Rune]} && !${FindItem[Ultimate Charm v1].Timer} && !${Me.Buff[Ultimate Rune].ID} && (${T6KtH}==0)) /casting 112801|item
                /if (${Me.Inventory[Charm].Spell.Name.Equal[Ultimate Rune v2]} && !${FindItem[Ultimate Charm v2].Timer} && !${Me.Buff[Ultimate Rune v2].ID} && (${T6KtH}==0)) /casting 112802|item
/declare arShield int local 0
        /for arShield 1 to 8
                /if (${Me.Inventory[offhand].Spell.Name.Equal[${shield[${arShield}]}]} && !${Me.Song[${shield[${arShield}]}].ID} && ${SotA.Value}==0) {
                        /itemnotify back rightmouseup
                        /varset SotA 301s
                }
        /next arShield  
        } else {
                /return
        }
/return
                |** The meat of this include file, still being worked on every hour. Keep up some discs, do some combat abilities,
                        click some epics. Assist MA automatically, stick to that target, beat it down. Removed some distance checks for stick**|
Sub WarmongerCombat
        /if (${Me.Class.Name.Equal[Berserker]}) {
                /if (${NetBots[${Me.Name}].Attacking} && ${Window[CombatAbilityWnd].Child[CAW_CombatEffectLabel].Text.Equal[No Effect]} && ${Me.PctEndurance}>=50 && ${BCPA.Value}==0) {
                        /delay 20
                        /casting 112608|item
                        /delay 15
                        /varset BCPA 37s
                }
                /if (${Me.Inventory[Mainhand].Spell.Name.Equal[Berserker Epic 5.0 AoE]} && !${FindItem[Vengeful Taelosian Blood Axe Epic 5.0].Timer} && ${NetBots[${Me.Name}].Attacking} && ${Target.Type.Equal[NPC]}) /casting 89962|item
                /if (${Me.Inventory[Mainhand].Spell.Name.Equal[Berserker Epic 5.5 AoE]} && !${FindItem[Vengeful Taelosian Blood Axe Epic 5.5].Timer} && ${NetBots[${Me.Name}].Attacking} && ${Target.Type.Equal[NPC]}) /casting 113442|item
                /if (${Me.Inventory[Mainhand].Spell.Name.Equal[Berserker Epic 6.0 AoE]} && !${FindItem[Vengeful Taelosian Blood Axe Epic 6.0].Timer} && ${NetBots[${Me.Name}].Attacking} && ${Target.Type.Equal[NPC]}) /casting 113462|item
                /if (${Me.Inventory[Mainhand].Spell.Name.Equal[Berserker Epic 7.0 AoE]} && !${FindItem[Vengeful Taelosian Blood Axe Epic 7.0].Timer} && ${NetBots[${Me.Name}].Attacking} && ${Target.Type.Equal[NPC]}) /casting 131034|item
                /if (${Me.Inventory[Chest].Spell.Name.Equal[Bursting Berserking]} && !${FindItem[Brell Serilis's Mail IV].Timer} && ${NetBots[${Me.Name}].Attacking} && ${Target.Type.Equal[NPC]}) /casting 101345|item
                /if (!${Me.Song[Cry Havoc].ID} && ${Me.CombatAbilityReady[Cry Havoc]} && ${NetBots[${Me.Name}].Attacking} && ${Target.Type.Equal[NPC]} && ${Me.PctEndurance}>=10) /disc Cry Havoc
                /if (${Me.AbilityReady[Frenzy]} && ${Target.Type.Equal[NPC]} && ${NetBots[${Me.Name}].Attacking} && ${Target.Distance}<18) /doability Frenzy
                        /if (${NetBots[${MA}].InZone} && ${NetBots[${MA}].Attacking} && ${SpecCom}==0) {
                                /assist ${MA}
                                /delay 3 ${Target.Type.Equal[NPC]}
                                /if (${Target.Type.Equal[NPC]}) {
                                        /squelch /stick off
                                        /delay 1
                                        /if (${Stick.Status.NotEqual[on]}) /squelch /stick behind 15 uw
                                        /if (${Target.Distance}<=${Target.MaxRangeTo}) /attack on
                                        /if (${NetBots[${Me.Name}].Attacking} && ${Target.Type.Equal[NPC]} && ${Target.Distance}<7) /squelch /stick moveback 10 uw
                                }
                        }
        } else /if (${Me.Class.Name.Equal[Cleric]} && !${Me.State.Equal[BIND]}) {
                /if (${NetWorst.Request[pc all83 war82 pal82 group radius90]}>0) /casting "Word of Vivification"
		
/declare arVivClick int local 0
        /for arVivClick 1 to 3
                /if (!${Me.SpellReady[1]} && ${Me.Inventory[mainhand].Spell.Name.Equal[${VivClick[${arVivClick}]}]} && (${ClrEpic1.Value}==0) && (${NetWorst.Request[pc all83 group radius99]}>1)) {
                        /itemnotify 13 rightmouseup
                        /varset ClrEpic1 48s
                }
        /next arVivClick
                /if (${NetBots[${MA}].InZone} && ${NetBots[${MA}].Attacking} && ${SpecCom}==0) {
                        /assist ${MA}
                        /delay 3 ${Target.Type.Equal[NPC]}
                        /if (${Target.Type.Equal[NPC]}) {
                                /squelch /stick off
                                /delay 1
                                /if (${Stick.Status.NotEqual[on]}) /squelch /stick behind 15 uw
                                /if (${Target.Distance}<=${Target.MaxRangeTo}) /attack on
                                /if (${NetBots[${Me.Name}].Attacking} && ${Target.Type.Equal[NPC]} && ${Target.Distance}<7) /squelch /stick moveback 10 uw
                                
                        }
                }
        } else /if (${Me.Class.Name.Equal[Rogue]}) {
                /if (${RogEpic1.Value} == 0 && ${NetBots[${Me.Name}].Attacking} && ${Target.Type.Equal[NPC]}) {
                        /itemnotify 14 rightmouseup
                        /varset RogEpic1 16s
                }
                /if (!${Me.Song[Thief's eyes].ID} && ${Me.CombatAbilityReady[Thief's eyes]} && ${NetBots[${Me.Name}].Attacking} && ${Target.Type.Equal[NPC]}) /disc Thief's eyes
                /if (${Me.AbilityReady[Backstab]} && ${Target.Type.Equal[NPC]} && ${NetBots[${Me.Name}].Attacking} && ${Target.Distance}<20) /doability Backstab
                /if (${NetBots[${MA}].InZone} && ${NetBots[${MA}].Attacking} && ${SpecCom}==0) {
                        /assist ${MA}
                        /delay 3 ${Target.Type.Equal[NPC]}
                        /if (${Target.Type.Equal[NPC]}) {
                                /squelch /stick off
                                /delay 1
                                /if (${Stick.Status.NotEqual[on]}) /squelch /stick behind 15 uw
                                /if (${Target.Distance}<=${Target.MaxRangeTo}) /attack on
                                /if (${NetBots[${Me.Name}].Attacking} && ${Target.Type.Equal[NPC]} && ${Target.Distance}<7) /squelch /stick moveback 10 uw
                        }
                }
        } else /if (${Me.Class.Name.Equal[Paladin]}) {
                /if (${Me.Gem[Wave of Purity II]}>0 && ${Me.SpellReady[Wave of Purity II]} && (${Me.CurrentMana}>6500) && (${NetWorst.Request[pc all83 group radius90]}>1)) /casting "Wave of Purity II"
                /if (${NetBots[${MA}].InZone} && ${NetBots[${MA}].Attacking} && ${SpecCom}==0) {
                        /assist ${MA}
                        /delay 3 ${Target.Type.Equal[NPC]}
                        /if (${Target.Type.Equal[NPC]}) {
                                /squelch /stick off
                                /delay 1
                                /if (${Stick.Status.NotEqual[on]}) /squelch /stick 15 uw
                                /if (${Target.Distance}<=${Target.MaxRangeTo}) /attack on
                                /if (${NetBots[${Me.Name}].Attacking} && ${Target.Type.Equal[NPC]} && ${Target.Distance}<7) /squelch /stick moveback 10 uw
                        }
                        /if (${NetCure[${NetBots[${MA}].Buff}].Charmed}) {
                                /if (${NetBots[${Me.Name}].Attacking} && ${Target.Type.Equal[NPC]}) /varset MyTar ${Target.ID}
                                /target ${MA} pc
                                /delay 2s ${Target.ID}==${Spawn[${MA}].ID}
                                /cast 9
                                /delay 30 !${Window[CastingWindow].Open}
                                /if (${MyTar}!=0) /target id ${MyTar}
                                /attack on
                        }
                }
        } else /if (${Me.Class.Name.Equal[Ranger]}) {
                /if (${NetBots[${MA}].InZone} && ${NetBots[${MA}].Attacking} && ${SpecCom}==0) {
                        /assist ${MA}
                        /if (${Target.Type.Equal[NPC]} && ${Target.Distance}>40) /autofire on
                        /if (${Target.Type.Equal[NPC]} && ${Target.Distance}<40) /squelch /stick moveback 40
                }
                        /if (${RanEpic1.Value}==0 && ${Target.Type.Equal[NPC]} && ${Target.PctHPs}<96) {
                                /casting 99338|item
                                /varset RanEpic1 6s
                        }
        } else /if (${Me.Class.Name.Equal[Bard]}) {
                /if (${NetBots[${MA}].InZone} && ${NetBots[${MA}].Attacking} && ${SpecCom}==0) {
                        /assist ${MA}
                        /delay 5 ${Target.Type.Equal[NPC]}
                        /if (${Target.Type.Equal[NPC]}) {
                                /squelch /stick off
                                /delay 1
                                /if (${Stick.Status.NotEqual[on]}) /squelch /stick behind 15 uw
                                /if (${Target.Distance}<=${Target.MaxRangeTo}) /attack on
                                /if (${NetBots[${Me.Name}].Attacking} && ${Target.Type.Equal[NPC]} && ${Target.Distance}<7) /squelch /stick moveback 10 uw
                        }
                }
                        |** Monk disc 'Overwhelm' might not fire correctly. If you get spam comment out line with a pipe ' | ' **|
        } else /if (${Me.Class.Name.Equal[Monk]}) {
                /if (!${Me.Song[Fists of Wu].ID} && ${Me.CombatAbilityReady[Fists of Wu]} && ${NetBots[${Me.Name}].Attacking} && ${Target.Type.Equal[NPC]}) /disc Fists of Wu
                /if (${Me.CombatAbilityReady[Overwhelm]} && ${Window[CombatAbilityWnd].Child[CAW_CombatEffectLabel].Text.Equal[No Effect]} && ${NetBots[${Me.Name}].Attacking} && ${Target.Type.Equal[NPC]}) /disc Overwhelm
                /if (${Me.Inventory[Powersource].Spell.Name.Equal[Leesette's Kick of Fatality]} && !${FindItem[Leesettes Kick of Fatality].Timer} && ${NetBots[${Me.Name}].Attacking} && ${Target.Type.Equal[NPC]}) /casting 112622|item
                /if (${NetBots[${MA}].InZone} && ${NetBots[${MA}].Attacking} && ${SpecCom}==0) {
                        /assist ${MA}
                        /delay 5 ${Target.Type.Equal[NPC]}
                        /if (${Target.Type.Equal[NPC]}) {
                                /squelch /stick off
                                /delay 1
                                /if (${Stick.Status.NotEqual[on]}) /squelch /stick behind 15 uw
                                /if (${Target.Distance}<=${Target.MaxRangeTo}) /attack on
                                /if (${NetBots[${Me.Name}].Attacking} && ${Target.Type.Equal[NPC]} && ${Target.Distance}<7) /squelch /stick moveback 10 uw
                        }
                }
        } else /if (${Me.Class.Name.Equal[Shaman]}) {
                /if (${NetBots[${MA}].InZone} && ${NetBots[${MA}].Attacking} && ${SpecCom}==0) {
                        /assist ${MA}
                        /delay 3 ${Target.Type.Equal[NPC]}
                        /if (${Target.Type.Equal[NPC]}) {
                                /squelch /stick off
                                /delay 1
                                /if (${Stick.Status.NotEqual[on]}) /squelch /stick behind 15 uw
                                /if (${Target.Distance}<=${Target.MaxRangeTo}) /attack on
                                /if (${NetBots[${Me.Name}].Attacking} && ${Target.Type.Equal[NPC]} && ${Target.Distance}<7) /squelch /stick moveback 10 uw
                        }
                }
        } else /if (${Me.Class.Name.Equal[Druid]}) {
                /if (${NetBots[${MA}].InZone} && ${NetBots[${MA}].Attacking} && ${SpecCom}==0) {
                        /assist ${MA}
                        /delay 3 ${Target.Type.Equal[NPC]}
                        /if (${Target.Type.Equal[NPC]}) {
                                /squelch /stick off
                                /delay 1
                                /if (${Stick.Status.NotEqual[on]}) /squelch /stick behind 15 uw
                                /if (${Target.Distance}<=${Target.MaxRangeTo}) /attack on
                                /if (${NetBots[${Me.Name}].Attacking} && ${Target.Type.Equal[NPC]} && ${Target.Distance}<7) /squelch /stick moveback 10 uw
                                /if (${NetBots[${MA}].InZone}) {
                                        /if (!${NetBots[${MA}].Buff.Find[10096]} && ${Me.Gem[Skin of the Drake III]}>0 && ${Me.SpellReady[Skin of the Drake III]}) /casting "Skin of the Drake III" -targetid|${Spawn[PC ${MA}].ID}
                                }
                                /if (${Me.Inventory[Mainhand].Spell.Name.Equal[Ancient: Vine Grasp VIII]} && !${FindItem[Staff of Everliving brambles Epic 6.0].Timer} && ${NetBots[${Me.Name}].Attacking} && ${Target.Type.Equal[NPC]} && ${Target.PctHPs}<80) /casting 113464|item
                        }
                }
        } else /if (${Me.Class.Name.Equal[Shadowknight]}) {
                /if (${NetBots[${MA}].InZone} && ${NetBots[${MA}].Attacking} && ${SpecCom}==0) {
                        /assist ${MA}
                        /delay 5 ${Target.Type.Equal[NPC]}
                        /if (${Target.Type.Equal[NPC]}) {
                                /squelch /stick off
                                /delay 1
                                /if (${Stick.Status.NotEqual[on]}) /squelch /stick behind 15 uw
                                /if (${Target.Distance}<=${Target.MaxRangeTo}) /attack on
                                /if (${NetBots[${Me.Name}].Attacking} && ${Target.Type.Equal[NPC]} && ${Target.Distance}<7) /squelch /stick moveback 10 uw
                        }
                }
        } else /if (${Me.Class.Name.Equal[Beastlord]}) {
                /if (${NetBots[${MA}].InZone} && ${NetBots[${MA}].Attacking} && ${SpecCom}==0) {
                        /assist ${MA}
                        /delay 5 ${Target.Type.Equal[NPC]}
                        /if (${Target.Type.Equal[NPC]}) {
                                /squelch /stick off
                                /delay 1
                                /if (${Stick.Status.NotEqual[on]}) /squelch /stick behind 15 uw
                                /if (${Target.Distance}<=${Target.MaxRangeTo}) /attack on
                                /if (${NetBots[${Me.Name}].Attacking} && ${Target.Type.Equal[NPC]} && ${Target.Distance}<7) /squelch /stick moveback 10 uw
                        }
                }
        } else /if (${Me.Class.Name.Equal[Warrior]}) {
                /if (${Target.CleanName.Equal[Grenlok the Converter]} && (${Zone.ID}==317) && (${T6KtH}==0)) /bc set|kth
                /if (${Target.CleanName.Equal[Grenlok the Converter's corpse]} && (${Zone.ID}==317) && (${T6KtH}==1)) /bc clear|kth
                /if (!${Me.Song[Commanding Voice].ID} && ${Me.CombatAbilityReady[Commanding Voice]} && ${NetBots[${Me.Name}].Attacking} && ${Target.Type.Equal[NPC]}) /disc Commanding Voice
                /if ((${Me.ID} == ${Spawn[${MA}].ID}) && ${Me.Combat}) {
                        /if (${Me.TargetOfTarget.ID}!=${Me.ID} && ${War2Epic}<5) {
                                /casting "${ScepterClk}"|item
                                /varcalc War2Epic ${War2Epic}+1
                                /varset WarEpicAggTimer 10s
                        }
                        /if (${Target.Type.Equal[NPC]} && ${Target.PctHPs}<70 && ${War2Epic2}<5) {
                                /casting "${ScepterClk}"|item
                                /varcalc War2Epic2 ${War2Epic2}+1
                                /varset WarEpicAggTimer2 20s
                        }
                        /if (${WarEpicAggTimer.Value}==0) /varset War2Epic 0
                        /if (${WarEpicAggTimer2.Value}==0) /varset War2Epic2 0
                }
                /if ((${Me.ID} != ${Spawn[${MA}].ID}) && ${NetBots[${MA}].InZone} && ${NetBots[${MA}].Attacking} && ${SpecCom}==0) {
                        /assist ${MA}
                        /delay 5 ${Target.Type.Equal[NPC]}
                        /if (${Target.Type.Equal[NPC]}) {
                                /squelch /stick off
                                /delay 1
                                /if (${Stick.Status.NotEqual[on]}) /squelch /stick 15 uw
                                /if (${Target.Distance}<=${Target.MaxRangeTo}) /attack on
                                /if (${NetBots[${Me.Name}].Attacking} && ${Target.Type.Equal[NPC]} && ${Target.Distance}<9) /squelch /stick moveback 15 uw
                        }
                }
        } else {
                /return
        }
/return
                |** Combat handling for Charm/Fear. Seems to be working as intended. ${MA} gets charmed or feared and everyone else continues to beat ass **|
Sub SpecialCombat
/declare i string local
/declare x int local 0
        /if ((${NetCure[${NetBots[${MA}].Buff}].Charmed}>0) || (${NetCure[${NetBots[${MA}].Buff}].Feared}>0)) {
                /varset SpecCom 1
                /if (${SpawnCount[NPC radius 40]}) {
                        /target npc radius 40
                        /if (${Target.ID}==NULL) /return
                        /if (${Me.TargetOfTarget.ID}==NULL) /return
                        /for x 1 to ${NetBots.Counts} 
                        /varset i ${NetBots.Client.Token[${x}, ]}
                /if (${Me.TargetOfTarget.ID}==${NetBots[${i}].ID}) {
                        /squelch /stick off
                        /delay 1
                        /if (${Stick.Status.NotEqual[on]}) /squelch /stick 15 uw
                        /if (${Target.Distance}<=${Target.MaxRangeTo}) /attack on
                        /if (${NetBots[${Me.Name}].Attacking} && ${Target.Type.Equal[NPC]} && ${Target.Distance}<9) /squelch /stick moveback 15 uw
                }
                /next x
                }
        }
        /if ((${NetCure[${NetBots[${MA}].Buff}].Charmed}<=0) && (${NetCure[${NetBots[${MA}].Buff}].Feared}<=0)) /varset SpecCom 0
/return
                |** Work in progress- if MA died SA take over combat -12/12 I never did use this how I planned. Maybe one day **|
Sub SomePlayerDied
        /if (${Me.ID}==${Spawn[${MA}].ID}) /return
        /if (${Spawn[${MA}].Type.Equal[Corpse]}) {
                /if (${Zone.ID}==317) {
                        /if (${Spawn[NPC "Mata Muram" radius 50].ID}) {
                                /target id ${Spawn[NPC "Mata Muram"].ID}
                                /stick 15
                                /attack on
                        }
                } else {
                        /target npc radius 35
                        /delay 7
                        /attack on
                }
        }
/return
 
        |** If for some reason you are attacking with no target, turn attack off and restick to MA **|
Sub Event_NoTarg
        /attack off
        /if (${Me.ID}!=${Spawn[${MA}].ID}) {
        /squelch /target ${MA} pc
    /delay 1s
    /squelch /stick hold uw 15
        }
/return
                |** Bot went to never never land while attacking. Lets see if this fixs it **|
Sub Event_FarFarAway
        /if (${Me.ID} != ${Spawn[${MA}].ID}) {
                /if (${NetBots[${MA}].InZone} && ${NetBots[${MA}].Attacking} && ${NetBots[${Me.Name}].Attacking}) {
                        /attack off
                        /squelch /stick 13 uw
                        /if (${Target.Distance}<=${Target.MaxRangeTo}) /attack on
                } else /if (${NetBots[${SA}].InZone} && ${NetBots[${SA}].Attacking} && ${NetBots[${Me.Name}].Attacking}) {
                        /attack off
                        /squelch /stick 13 uw
                        /if (${Target.Distance}<=${Target.MaxRangeTo}) /attack on
                } else {
                        /attack off
                        /if (${NetBots[${MA}].InZone}) {
                                /target ${MA} pc
                                /delay 2s ${Target.ID}==${Spawn[${MA}].ID}
                                /squelch /stick hold 13 uw
                        }
                        /if (!${NetBots[${MA}].InZone} && ${NetBots[${SA}].InZone}) {
                                /target ${SA} pc
                                /delay 2s ${Target.ID}==${Spawn[${SA}].ID}
                                /squelch /stick hold 13 uw
                        }
                }
        }
/return
                |** Did we kill a npc or did a group member die or did something else die **|
Sub Event_SomethingDied(string Line, string DeathName)
        /if (${NetBots[${DeathName}].Level}) {
                /call SomePlayerDied
        } else {
                /call WMstickoff
        }
 /return
                |** Catch for shadow in HOH **|
Sub Event_ShadowStep
        /call WMstickoff
/return
                |** We killed something or something died near us, restick to MA and warrior reset Epic sword anger click count **| 
Sub WMstickoff
                |** check if anything is close to us and exit if true **|
        /if (${SpawnCount[NPC radius 30]}>=1) /return
                |** if using an afk ranger in poair dont do anything -- this shits really fucking old, like ancient as shit. /delete ranger works better.**|
        /if (${Zone.ID}==71) /return
                |** Everything Else (aka classes that dont suck more dick then a porn star) **|
    /if ((${Me.ID}!=${Spawn[${MA}].ID}) && !${NetBots[${MA}].Attacking}) {
                /varset MyTar 0
                :retar
                /delay 5
                /squelch /target ${MA} pc
                /delay 3
                /if (${Target.ID}==${Spawn[${MA}].ID}) {
                        /stick hold uw 15
                        /delay 2
                        /stick hold uw 15
                        /if (${Stick.Status.NotEqual[on]}) /squelch /stick hold uw 15
                        /if (${Bool[${Stick.MoveBehind}]}) {
                                /stick off
                                /stick off
                                /stick hold 15 uw
                        }
                }
                /if (${Target.ID}!=${Spawn[${MA}].ID}) /goto :retar
                /if (${Target.Type.Equal[Corpse]}) /return
        } else /if (${Me.Class.Name.Equal[Warrior]}) {
                /varset War2Epic 0
                /varset War2Epic2 0
        }
/return
                |** Requires Netbots, consents all connected clients. Requests rez. Mem spells if caster. Takes rez and loots body. 12/12 and it actually works, 12.99 + s/h will get you a copy in 6-12 weeks! Order today.**|
Sub Event_Wait4rez
        /echo Looks like you died. Consenting and waiting for rez
                /declare x int local 0
                /declare consentA string local
                        /for x 1 to ${NetBots.Counts}
                        /varset consentA ${NetBots.Client.Token[${x}, ]}
                        /consent ${consentA}
                /next x
        /doevents
        /if (${Me.Class.Name.Equal[Cleric]} || ${Me.Class.Name.Equal[Paladin]} || ${Me.Class.Name.Equal[Ranger]} || ${Me.Class.Name.Equal[Necromancer]} || ${Me.Class.Name.Equal[Beastlord]} || ${Me.Class.Name.Equal[Magician]} || ${Me.Class.Name.Equal[Bard]} || ${Me.Class.Name.Equal[Wizard]} || ${Me.Class.Name.Equal[Enchanter]} || ${Me.Class.Name.Equal[Shadowknight]} || ${Me.Class.Name.Equal[Shaman]} || ${Me.Class.Name.Equal[Druid]}) /nomodkey /memspellset 1
        /if (${Window[SpellBookWnd].Open}) /delay 30s !${Window[SpellBookWnd].Open}
        :WaitxRez
        /bc Rez|Me
                /delay 15s ${Window[ConfirmationDialogBox].Open}
        /if (!${Window[ConfirmationDialogBox].Open}) /goto :WaitxRez
                /nomodkey /notify ConfirmationDialogBox Yes_Button leftmouseup
                /delay 2s
                /delay 10m ${Me.State.NotEqual[ZONING]}
        :Wait4Corpse
                /target ${Me}'s
                /delay 1s
        /if (${Target.CleanName.NotEqual[${Me}'s corpse]}) /goto :Wait4Corpse
                /loot
                /delay 5s ${Window[LootWnd].Open}
                /nomodkey /notify LootWnd DoneButton leftmouseup
        /if (${Me.Class.Name.Equal[Shaman]} || ${Me.Class.Name.Equal[Druid]}) /tgb on
/return
                |** Partially working, FG rez or glove rez is not recomended and I wrote this based on instant cast rez item. Leaving in for future rewrite. **|
Sub RezIfAvailable(string PcName)
        /if (${Me.ID}==${Spawn[${MA}].ID}) /return
        /if (${Spawn[Corpse ${PcName}].ID}) {
                /if ((${Spawn[Corpse ${PcName}].Distance}<100) && ${FindItemCount[=Instant Resurrection (Reward Item)]}) {
                        /squelch /stick off
                        /target id ${Spawn[Corpse ${PcName}].ID}
                        /delay 1s
                        /casting ${InstantRez}|item
                        /delay 3
                        /keypress esc
                }
        }
        /call SomePlayerDied
/return
                |** Our EQBC Command list. Used for all of the in game commands. **|
Sub Event_EQBC(EQBCSay,EQBCSender,EQBCCommand)
        /declare x int local 0
                /for x 1 to ${NetBots.Counts}
                        /if (${EQBCCommand.Arg[1].Equal[Highlight]} && ${EQBCCommand.Arg[2].Equal[T5]} && ${EQBCCommand.Arg[3].Equal[${NetBots.Client.Token[${x}, ]}]}) {
                                /if (${Me.CleanName.Equal[${NetBots.Client.Token[${x}, ]}]}) /call HighlightT5
                        }
                /next x
        /if (${Me.CleanName.NotEqual[${EQBCSender}]} && ${EQBCCommand.Arg[1,|].Equal[coth]} && ${EQBCCommand.Arg[2,|].Equal[me]} && ${FindItemCount[=Call of the Companions (Reward Item)]}) /casting ${Cotc}|item
        /if (${EQBCCommand.Arg[1,|].Equal[Fast]} && ${EQBCCommand.Arg[2,|].Equal[on]}) /varset RewardSpeed 1
        /if (${EQBCCommand.Arg[1,|].Equal[Fast]} && ${EQBCCommand.Arg[2,|].Equal[off]}) {
                /varset RewardSpeed 0
                /if (${Me.Buff[Fastest Travel].ID}) /notify BuffWindow Buff${Math.Calc[${Me.Buff["Fastest Travel"].ID}-1].Int} leftmouseup
        }
        /if (${EQBCCommand.Arg[1].Equal[ReGroup]}) /call ReFormGroups
        /if (${EQBCCommand.Arg[1].Equal[add]} && ${EQBCCommand.Arg[2].Equal[illusion]}) /call AddRemoveResize Add ${EQBCCommand.Arg[3]}
        /if (${EQBCCommand.Arg[1].Equal[del]} && ${EQBCCommand.Arg[2].Equal[illusion]}) /call AddRemoveResize Del ${EQBCCommand.Arg[3]}
    /if (${Me.CleanName.NotEqual[${EQBCSender}]} && ${EQBCCommand.Arg[1,|].Equal[Rez]}) {
                /if (${EQBCCommand.Arg[2,|].Equal[Me]}) {
                        /call RezIfAvailable ${EQBCSender}
                }
        }
        /if (${EQBCCommand.Arg[1,|].Equal[set]} && ${EQBCCommand.Arg[2,|].Equal[kth]}) /varset T6KtH 1
        /if (${EQBCCommand.Arg[1,|].Equal[clear]} && ${EQBCCommand.Arg[2,|].Equal[kth]}) /varset T6KtH 0
        /if (${EQBCCommand.Arg[1,|].Equal[Summon]} && ${EQBCCommand.Arg[2,|].Equal[Steaks]}) /call DLFoodService
                |** cleric Mark of Emperors **|
        /if (${EQBCCommand.Arg[1,|].Equal[Markit]} && ${EQBCCommand.Arg[2,|].Equal[II]}) {
                /if (${Me.Gem[${ClrMark}]}>0 && ${NetBots[${Me.Name}].Attacking} && ${Me.PctMana}>10) {
                        /cast "${ClrMark}"
                        /delay 8
                }
        }
/return
                |** FOOD FOR ME AND FOOD FOR JEW **|
Sub DLFoodService
/if (${FindItemCount[Dead Dracnid]}==1) {
        /if (${FindItemCount[Special Dracnid Steak]} < 100) {
                :summonedsteaks
                /casting 112947|item
                /if (${Window[CastingWindow].Open}) /delay 40 !${Window[CastingWindow].Open}
                /autoinv
                /if (${FindItemCount[Special Dracnid Steak]} < 100) /goto :summonedsteaks
        }
}
/return
                |** I got tired of people casting gay illusion on me **|
Sub IllusionCheck
        /declare badill int local
        /for badill 1 to ${BadIllusions.Size}
                /if (${Me.Buff[Illusion: ${BadIllusions[${badill}]}].ID}) {
                /if (${Ini[./WM/WM.ini,BadIllusionStatus,${BadIllusions[${Badill}]}]}==TRUE) /notify BuffWindow Buff${Math.Calc[${Me.Buff["Illusion: ${BadIllusions[${badill}]}"].ID}-1].Int} leftmouseup
                }
        /next badill
/return
                |** Handles adding illusions to ini and if they should be clicked off or left alone **|
Sub AddRemoveResize(string ArType,string ArData)
/declare i int local
/declare j int local
/declare k string local
        /if (${ArType.Equal[Add]}) {
                /varset i ${Math.Calc[${BadIllusions.Size}+1]}
                /ini "./WM/WM.ini" "BadIllusions" "${i}" "${ArData}"
                /ini "./WM/WM.ini" "BadIllusionStatus" "${ArData}" "TRUE"
                /deletevar BadIllusions
                /declare BadIllusions[${Math.Calc[${Ini[./WM/WM.ini,BadIllusions].Count[|]}-1]}] string outer
                /call BadIllusionSetup
                /return
        } else /if (${ArType.Equal[Del]}) {
                /varset k ${ArData}
                /for j 1 to ${BadIllusions.Size}
                        /if (${BadIllusions[${j}].Equal[${k}]}) /ini "./WM/WM.ini" "BadIllusionStatus" "${k}" "FALSE"
                /next j
                /return
        }               
/return
                |** Not used in this macro:  **|
Sub InternalMoveTo(int y, int x, int z)
        /declare currentX int local 0
        /declare currentY int local 0
        /declare currentZ int local 0
        /squelch /moveto loc ${y} ${x} ${z}
        :waitUntilMovingFinished
                /if (${Math.Distance[${y},${x},${Me.Z}]} > 15 || ${Math.Distance[${currentY},${currentX},${currentZ}]} > 5) {
                        /varset currentX ${Me.X}
                        /varset currentY ${Me.Y}
                        /varset currentZ ${Me.Z}
                        /delay 1
                        /doevents
                        /goto :waitUntilMovingFinished
                }
/return