#include healing.inc 

sub fs5(int bag, int slot)

:start

/if (${SpawnCount[GM]} > 0) {
/echo GM here
/delay 30s
/goto :start
} else {
/if (!${Zone.Name.Equal[The Tower of Frozen Shadow]}) {

/echo in zone ${Zone.Name}
/mqpause

}

/twist off
/call warbuff
/pet leave

/delay 1s

/call storeweapon ${bag} ${slot}

/call RanInternalMoveTo 172.45 -152.62
/call RanInternalMoveTo 244.01 -150.87
/call RanInternalMoveTo 357.61 -148.08
/call RanInternalMoveTo 402.91 -127.53
/call RanInternalMoveTo 456.32 -92.78
/call RanInternalMoveTo 496.30 -128.13
/call InternalMoveTo 498.57 -165.39
/call RanInternalMoveTo 460.50 -199.55
/call RanInternalMoveTo 430.90 -208.51
/call RanInternalMoveTo 364.08 -151.91
/call RanInternalMoveTo 333.25 -155.87
/call RanInternalMoveTo 349.97 -216.65
/call RanInternalMoveTo 384.60 -234.72
/call RanInternalMoveTo 433.35 -249.83
/call RanInternalMoveTo 475.94 -250.50
/call RanInternalMoveTo 524.90 -187.94
/call RanInternalMoveTo 529.04 -163.14
/call RanInternalMoveTo 530.15 -119.41
/call RanInternalMoveTo 464.41 -54.34
/call RanInternalMoveTo 428.94 -58.25
/call RanInternalMoveTo 388.99 -62.68
/call RanInternalMoveTo 336.24 -115.53
/call RanInternalMoveTo 336.24 -157.96
/call RanInternalMoveTo 304.33 -156.55
/call RanInternalMoveTo 224.02 -155.01
/keypress -

/face heading 0


/delay 1s

/call getitem ${bag} ${slot}

/delay 1s

/bct delegate //macro druidheal maslow
/call NewKillFace 30

/call NewKillFace 30

/bct delegate //endmacro

/call RanInternalMoveTo 188.79 -155.99

/call druidpostpull delegate

/return
