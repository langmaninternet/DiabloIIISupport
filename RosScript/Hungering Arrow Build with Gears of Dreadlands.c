

// #1.1 Vengeance
// Buff
// 1000ms
// Force Recast


// #1.2 Shadow Power
// Buff
// 50ms
Secondary()>15&Health()<90%


// #1.3 Smoke Screen
// Buff
// 50ms


// #1.4 Fan of Knives
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
// #2 Hungering Arrow - Buff - Momentum|Wraps of Clarity
// 50ms
//	Stand still: true
// 	Force Recast
//	Attack + Density
//
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





// #3.1 Strafe - Channeling - Attack
// Attack+Buff
// Ignore Position caculation
// Resouce : 
//			Primary 0
//			Channeling
//			Max Channeling Distance: 0
//			Min Resouce level 15
//
// 50ms


// #3.2 Strafe - Channeling - Buff
// Buff
// Ignore Position caculation
// Resouce : 
//			Primary 20
//			Channeling
//			Max Channeling Distance: 100
//			Min Resouce level 15
//
// 50ms




// #4.1 Strafe - Move
// #4.2 Strafe - Evade
// #4.3 Strafe - Approach
// 50ms
// Usage: None
// Move Setting: Walk, Evade, Approach
// Resouce : 
//			Primary 20
//			Channeling
//			Max Channeling Distance: 50
//			Min Resouce level 20
//

Primary()>20








//----------------------------------------------------------------------------------------------------------------------------------------
// #2 Hungering Arrow
// 50ms
//	Attack
//	Attack Distance: 50
//  Break item

