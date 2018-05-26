sub hoh(string party)

/echo ${party}

|party is a string representing true or false

|pass in channel as param
/echo ${Ini[locs.ini,HOH,hstartloc]}
/moveto loc ${Ini[locs.ini,HOH,hloc1]}
|need separate channel
/if (${party.Equal[true]}) {
/bca //moveto loc ${Ini[locs.ini,HOH,hloc1]}
}
/delay 5s
/face heading 90
/if (${party.Equal[true]}) {
/bca //face heading 90
}
/moveto loc ${Ini[locs.ini,HOH,hloc2]}
/if (${party.Equal[true]}) {
/bca //moveto loc ${Ini[locs.ini,HOH,hloc2]}
}
/delay 6s
| call combat
/call KillAll ${party}
/call LootIt 45
/moveto loc ${Ini[locs.ini,HOH,hloc3]}
/if (${party.Equal[true]}) {
/bca //moveto loc ${Ini[locs.ini,HOH,hloc3]}
}
/delay 3s
/call KillAll ${party}
/call LootIt 45

/if (${party.Equal[true]}) {
/bca //face heading 0
}
/face heading 0
/moveto loc ${Ini[locs.ini,HOH,hloc4]}
/if (${party.Equal[true]}) {
/bca //moveto loc ${Ini[locs.ini,HOH,hloc4]}
}
/delay 6s
/echo at loc 4
/call KillAll ${party}
/call LootIt 45
/moveto loc ${Ini[locs.ini,HOH,hloc5]}
/if (${party.Equal[true]}) {
/bca //moveto loc ${Ini[locs.ini,HOH,hloc5]}
}
/delay 3s
/echo At Loc 5
/face heading 90
/moveto loc ${Ini[locs.ini,HOH,hloc6]}
/if (${party.Equal[true]}) {
/bca //moveto loc ${Ini[locs.ini,HOH,hloc6]}
}
/delay 4s
/echo At Loc 6
/call KillAll ${party}
/call LootIt 45
/moveto loc ${Ini[locs.ini,HOH,hloc7]}
/if (${party.Equal[true]}) {
/bca //moveto loc ${Ini[locs.ini,HOH,hloc7]}
}
/delay 4s
/face heading 180
/if (${party.Equal[true]}) {
/bca //face heading 180
}
/call KillAll ${party}
/call LootIt 45
/moveto loc ${Ini[locs.ini,HOH,hloc8]}
/if (${party.Equal[true]}) {
/bca //moveto loc ${Ini[locs.ini,HOH,hloc8]}
/echo At Loc 8
/delay 4s
/call KillAll ${party}
/call LootIt 45

/moveto loc ${Ini[locs.ini,HOH,hloc7]}
/if (${party.Equal[true]}) {
/bca //moveto loc ${Ini[locs.ini,HOH,hloc7]}
}
/delay 4s
/face heading 90
/moveto loc ${Ini[locs.ini,HOH,hloc9]}
/if (${party.Equal[true]}) {
/bca //moveto loc ${Ini[locs.ini,HOH,hloc9]}
}

/delay 4s
/call KillAll ${party}
/call LootIt 45

}
/return

sub move(float moveloc, string dsec)

/moveto loc moveloc
/bca //moveto loc moveloc
/delay dsec
/face heading 90

/return