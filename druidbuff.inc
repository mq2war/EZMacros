1.| WarmongerKraken.inc v.3.0
2. 
3.|** Ancient: Druid Regeneration II **|
4.Sub DruRegen
5./declare idNeedingBuff int local 0
6./declare arDruRegen int local 0
7.        /for arDruRegen 1 to 5
8.                /if (${Me.Gem[${DruRegen[${arDruRegen}]}]}>0 && ${Cast.Ready[${DruRegen[${arDruRegen}]}]} && ${Me.PctMana}>20) {
9.                        /call ShmCheckBuff "${DruRegen[${arDruRegen}]}" 175
10.                        /varset idNeedingBuff ${Macro.Return}
11.                        /if (${idNeedingBuff}) {
12.                                /target id ${idNeedingBuff}
13.                                /delay 5 ${Target.ID}==${Spawn[${idNeedingBuff}].ID}
14.                                /if (${Target.ID}==${idNeedingBuff}) {
15.                                        /casting "${DruRegen[${arDruRegen}]}"
16.                                        /if (${Window[CastingWindow].Open}) /delay 30 !${Window[CastingWindow].Open}
17.                                }
18.                        }
19.                }
20.        /next arDruRegen
21./return
22.                |** Shaman Buffs **|
23.Sub CastShmBuffs
24.        /if (${STGB}==0) {
25.                /tgb on
26.                /varset STGB 1
27.        }
28.        /declare idNeedingBuff int local 0
29.        /if (${Cast.Ready[Champion]} && ${Me.PctMana}>20) {
30.                /call ShmCheckBuff "Champion" 100
31.                /varset idNeedingBuff ${Macro.Return}
32.                        /if (${idNeedingBuff}) {
33.                                /target id ${idNeedingBuff}
34.                                /delay 5 ${Target.ID}==${Spawn[${idNeedingBuff}].ID}
35.                                /if (${Target.ID}==${idNeedingBuff}) {
36.                                        /casting 5417
37.                                        /delay 3s
38.                                }
39.                        }
40.        }
41.        /doevents
42.        /if (${Cast.Ready[Talisman of Might]} && ${Me.PctMana}>20) {
43.                /call ShmCheckBuff "Talisman of Might" 100
44.                /varset idNeedingBuff ${Macro.Return}
45.                        /if (${idNeedingBuff}) {
46.                                /target id ${idNeedingBuff}
47.                                /delay 5 ${Target.ID}==${Spawn[${idNeedingBuff}].ID}
48.                                /if (${Target.ID}==${idNeedingBuff}) {
49.                                        /casting 5409
50.                                        /delay 3s
51.                                }
52.                        }
53.        }
54.        /doevents
55.        /if (${Cast.Ready[Talisman of Alacrity]} && ${Me.PctMana}>20) {
56.                /call ShmCheckBuff "Talisman of Alacrity" 100
57.                /varset idNeedingBuff ${Macro.Return}
58.                        /if (${idNeedingBuff}) {
59.                                /target id ${idNeedingBuff}
60.                                /delay 5 ${Target.ID}==${Spawn[${idNeedingBuff}].ID}
61.                                /if (${Target.ID}==${idNeedingBuff}) {
62.                                        /casting 3391
63.                                        /delay 3s
64.                                }
65.                        }
66.        }
67.        /doevents
68.        /if (${Cast.Ready[Spirit of the Kraken]} && ${Me.PctMana}>25) {
69.                /call ShmCheckBuff "Spirit of the Kraken" 100
70.                /varset idNeedingBuff ${Macro.Return}
71.                        /if (${idNeedingBuff}) {
72.                                /target id ${idNeedingBuff}
73.                                /delay 5 ${Target.ID}==${Spawn[${idNeedingBuff}].ID}
74.                                /if (${Target.ID}==${idNeedingBuff}) {
75.                                        /casting 9835
76.                                        /delay 1s
77.                                }
78.                        }
79.        }
80./return
81. 
82.Sub ShmCheckBuff(string BuffName, int range)
83.        /declare WhoNeedsBuff int local 0
84.        /declare ctr int local 0
85.        /for ctr 1 to 40
86.                /if (${Bool[${NetBots.Client.Arg[${ctr}]}]}) {
87.                        /if (${Spawn[pc ${NetBots.Client.Arg[${ctr}]}].Distance}<= ${range}) {
88.                                /call DoesClientHaveBuff "${NetBots.Client.Arg[${ctr}]}" "${BuffName.Arg[1,|]}"
89.                                /if (!${Macro.Return}) {
90.                                        /if (${Bool[${BuffName.Arg[2,|]}]}) {
91.                                                /call DoesClientHaveBuff "${NetBots.Client.Arg[${ctr}]}" "${BuffName.Arg[2,|]}"
92.                                                /if (!${Macro.Return}) {
93.                                                        /varset WhoNeedsBuff ${Spawn[pc ${NetBots.Client.Arg[${ctr}]}].ID}
94.                                                        /varset ctr 9999 | break
95.                                                }
96.                                        } else {
97.                                                /varset WhoNeedsBuff ${Spawn[pc ${NetBots.Client.Arg[${ctr}]}].ID}
98.                                                /varset ctr 9999 | break
99.                                        }
100.                                }
101.                        }
102.                } else {
103.                        /varset ctr 9999 | break
104.                }
105.        /next ctr
106./return ${WhoNeedsBuff}
107.                        
108.Sub DoesClientHaveBuff(string ClientName, string BuffName)
109.        /declare hasBuff int local 0
110.        /declare foundBuffName string local
111.        /declare ctr int local 0
112.        /for ctr 0 to 25
113.                /if (${Bool[${NetBots[${ClientName}].Buff[${ctr}]}]}) {
114.                        /varset foundBuffName ${NetBots[${ClientName}].Buff[${ctr}].Name}
115.                        /if (${Spell[${foundBuffName}].ID}) {
116.                                /if (${Spell[${foundBuffName}].Name.Equal[${BuffName}]}) {
117.                                        /varset hasBuff 1
118.                                        /varset ctr 27
119.                                }
120.                        }
121.                }
122.        /next ctr
123./return ${hasBuff}