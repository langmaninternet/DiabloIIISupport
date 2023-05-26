


//----------------------------------------------------------------------------------------------------------------------------------------
//			Hungering Arrow - Buff - Momentum|Wraps of Clarity
//
//		Stand still: true
//		Force recast: true
//		Distance Min: 0
//		Distance Max: 40
//		Calculation min param: -10
//		Calculation max param: 10
//		Attack limit: 0
//		Elite weight: -1
//		Minion weight: 0
//		Big guy weight: -1
//		Goblin weight: -1
//		Normal monster weight: 0
//
(
(IsBuffActive(0,P69_ItemPassive_Unique_Ring_010)&(BuffTimeLeft(10,P69_ItemPassive_Unique_Ring_010)<2000|BuffStackCount(10, P69_ItemPassive_Unique_Ring_010)<17))
|(IsBuffActive(0,P3_ItemPassive_Unique_Ring_038)&BuffTimeLeft(1,P3_ItemPassive_Unique_Ring_038)<1000)
)


//\\----------------------------------------------------------------------------------------------------------------------------------------////





//----------------------------------------------------------------------------------------------------------------------------------------
//			Hungering Arrow - Attack - Momentum|Wraps of Clarity
//
//		Stand still: true
//		Force recast: true
//		Distance Min: 0
//		Distance Max: 40
//		Calculation min param: 0
//		Calculation max param: 10
//		Attack limit: 1
//		Elite weight: 2
//		Minion weight: 0
//		Big guy weight: 2
//		Goblin weight: 2
//		Normal monster weight: 0
//
(
(IsBuffActive(0,P69_ItemPassive_Unique_Ring_010)&(BuffTimeLeft(10,P69_ItemPassive_Unique_Ring_010)<2000|BuffStackCount(10, P69_ItemPassive_Unique_Ring_010)<17))
|(IsBuffActive(0,P3_ItemPassive_Unique_Ring_038)&BuffTimeLeft(1,P3_ItemPassive_Unique_Ring_038)<1000)
)
//\\----------------------------------------------------------------------------------------------------------------------------------------////








//----------------------------------------------------------------------------------------------------------------------------------------
//	Hungering Arrow - Attack - Proc [Gear of Dreadlands - 4 pieces]
//	Hungering Arrow - Buff - Proc [Gear of Dreadlands - 4 pieces]

IsBuffActive(0,P69_ItemPassive_Unique_Ring_011)
&(!IsBuffActive(4,P69_ItemPassive_Unique_Ring_010))

//\\----------------------------------------------------------------------------------------------------------------------------------------////



//----------------------------------------------------------------------------------------------------------------------------------------
//	Hungering Arrow - Attack - Maintain [Gear of Dreadlands - Momentum]
//	Hungering Arrow - Buff - Maintain [Gear of Dreadlands - Momentum]

IsBuffActive(0,P69_ItemPassive_Unique_Ring_010)
&BuffTimeLeft(10,P69_ItemPassive_Unique_Ring_010)<2000

//\\----------------------------------------------------------------------------------------------------------------------------------------////


//----------------------------------------------------------------------------------------------------------------------------------------
//	Hungering Arrow - Attack - Increase [Gear of Dreadlands - Momentum]
//	Hungering Arrow - Buff - Increase [Gear of Dreadlands - Momentum]

IsBuffActive(0,P69_ItemPassive_Unique_Ring_010)
&BuffStackCount(10, P69_ItemPassive_Unique_Ring_010)<17
&(BuffTimeLeft(0,X1_DemonHunter_Vengeance)>1000|BuffTimeLeft(1,DemonHunter_ShadowPower)>1000|IsBuffActive(0,DemonHunter_SmokeScreen))

//\\----------------------------------------------------------------------------------------------------------------------------------------////



IsBuffActive(0,DemonHunter_SmokeScreen)



//----------------------------------------------------------------------------------------------------------------------------------------
//	Hungering Arrow - Attack - Maintain [Wraps of Clarity]
//	Hungering Arrow - Buff - Maintain [Wraps of Clarity]

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









//----------------------------------------------------------------------------------------------------------------------------------------
//	Move - Strafe - On [Momentum]

BuffStackCount(10, P69_ItemPassive_Unique_Ring_010)>10&Primary()>70

//\\------------------------------------------





