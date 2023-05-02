






//----------------------------------------------------------------------------------------------------------------------------------------
//	Hungering Arrow - Proc [Gear of Dreadlands - 4 pieces]

IsBuffActive(0,P69_ItemPassive_Unique_Ring_011)
&(!IsBuffActive(4,P69_ItemPassive_Unique_Ring_010))

//\\----------------------------------------------------------------------------------------------------------------------------------------////



//----------------------------------------------------------------------------------------------------------------------------------------
//	Hungering Arrow - Maintain [Gear of Dreadlands - Momentum]

IsBuffActive(0,P69_ItemPassive_Unique_Ring_010)
&BuffTimeLeft(10,P69_ItemPassive_Unique_Ring_010)<2000

//\\----------------------------------------------------------------------------------------------------------------------------------------////


//----------------------------------------------------------------------------------------------------------------------------------------
//	Hungering Arrow - Increase [Gear of Dreadlands - Momentum]

IsBuffActive(0,P69_ItemPassive_Unique_Ring_010)
&BuffStackCount(10, P69_ItemPassive_Unique_Ring_010)<20
&(BuffTimeLeft(0,X1_DemonHunter_Vengeance)>1000|BuffTimeLeft(1,DemonHunter_ShadowPower)>1000|IsBuffActive(0,DemonHunter_SmokeScreen))

//\\----------------------------------------------------------------------------------------------------------------------------------------////



IsBuffActive(0,DemonHunter_SmokeScreen)



//----------------------------------------------------------------------------------------------------------------------------------------
//	Hungering Arrow - Maintain [Wraps of Clarity]

IsBuffActive(0,P3_ItemPassive_Unique_Ring_038)
&BuffTimeLeft(1,P3_ItemPassive_Unique_Ring_038)<1000

//\\----------------------------------------------------------------------------------------------------------------------------------------////







//----------------------------------------------------------------------------------------------------------------------------------------
//	Hungering Arrow - Proc [Focus]

IsBuffActive(0,ItemPassive_Unique_Ring_735_x1)
&BuffTimeLeft(1,ItemPassive_Unique_Ring_735_x1)<2000

//\\----------------------------------------------------------------------------------------------------------------------------------------////





//----------------------------------------------------------------------------------------------------------------------------------------
//	Vengeance - Buff in [Infinite Casting]
//	Shadow Power - Buff in [Infinite Casting]
//	Smoke Screen - Buff in [Infinite Casting]
//	Companion - Buff in [Infinite Casting]
//	Fan of Knives - Buff in [Infinite Casting]

BuffTimeLeft(0,Pages_Buff_Infinite_Casting) > 4000

//\\----------------------------------------------------------------------------------------------------------------------------------------////




IsBuffActive(0, ItemPassive_Unique_Gem_013_x1)