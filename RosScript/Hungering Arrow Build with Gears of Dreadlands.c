

// #1 Vengeance
// Buff
// 1000ms
// Force Recast


// #2 Shadow Power
// Buff
// 50ms
Secondary()>15&Health()<90%


// #3 Smoke Screen
// Buff
// 50ms


// #4 Fan of Knives
// Attack+Buff
// 50ms
//		Attack Distance: 30
//		Distance Min: 0
//		Distance Max: 30
//		Calculation min param: 0
//		Calculation max param: 10
//		Attack limit: 1 
//
//		Elite weight: 10
//		Minion weight: 1
//		Normal monster weight: 1
//		Big guy weight: 10
//		Goblin weight: 10
//
//


//----------------------------------------------------------------------------------------------------------------------------------------
//		#5 Hungering Arrow - Buff - Momentum|Wraps of Clarity
// 50ms
//		Stand still: true
//		Force recast: true
//		Attack Distance: 40
//		Distance Min: 0
//		Distance Max: 40
//		Calculation min param: 0
//		Calculation max param: 10
//		Attack limit: 1 
//
//		Elite weight: 10
//		Minion weight: 1
//		Normal monster weight: 1
//		Big guy weight: 10
//		Goblin weight: 10
//
(IsBuffActive(0,P69_ItemPassive_Unique_Ring_010)&(BuffTimeLeft(10,P69_ItemPassive_Unique_Ring_010)<2000|BuffStackCount(10, P69_ItemPassive_Unique_Ring_010)<17))
|(IsBuffActive(0,P3_ItemPassive_Unique_Ring_038)&BuffTimeLeft(1,P3_ItemPassive_Unique_Ring_038)<1000)
|(IsBuffActive(0,P69_ItemPassive_Unique_Ring_011)&(!IsBuffActive(4,P69_ItemPassive_Unique_Ring_010)))
|(IsBuffActive(0,P69_ItemPassive_Unique_Ring_010)&BuffTimeLeft(10,P69_ItemPassive_Unique_Ring_010)<2000)
|(IsBuffActive(0,P69_ItemPassive_Unique_Ring_010)&BuffStackCount(10, P69_ItemPassive_Unique_Ring_010)<17&(BuffTimeLeft(0,X1_DemonHunter_Vengeance)>1000|BuffTimeLeft(1,DemonHunter_ShadowPower)>1000|IsBuffActive(0,DemonHunter_SmokeScreen)))
|(IsBuffActive(0,ItemPassive_Unique_Ring_735_x1)&BuffTimeLeft(1,ItemPassive_Unique_Ring_735_x1)<2000)

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





