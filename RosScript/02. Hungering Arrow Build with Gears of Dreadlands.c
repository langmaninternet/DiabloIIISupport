

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


// #1.5 Companion
// Buff
// 50ms



//----------------------------------------------------------------------------------------------------------------------------------------
// #1.6 Multishot Proc Sanctified Strafe
//Strafe now casts the last non-channeled Hatred spending ability casted
//IsBuffActive(0, P74_ItemPassive_SeasonTheme_004)  // 5 == Multishot
// 1000ms
// 	Force Recast
//	Attack + Density + Buff
//
//		Attack Distance: 60
//		Distance Min: 1
//		Distance Max: 60
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
!IsBuffActive(5, P74_ItemPassive_SeasonTheme_004)
//\\----------------------------------------------------------------------------------------------------------------------------------------////




//----------------------------------------------------------------------------------------------------------------------------------------
// #1.7 Entangling Shot - Proc Focus
// 50ms
// Stand still
// Ignore position calculation
//	Attack + Density + Buff
//
//		Attack Distance: 30
//		Distance Min: 1
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
(IsBuffActive(0,ItemPassive_Unique_Ring_735_x1)&BuffTimeLeft(1,ItemPassive_Unique_Ring_735_x1)<2000)
|Primary()<20
//\\----------------------------------------------------------------------------------------------------------------------------------------////



//----------------------------------------------------------------------------------------------------------------------------------------
// #2 Hungering Arrow - Buff - Momentum|Wraps of Clarity
// 50ms
// 	Force Recast
//	Attack + Density + Buff
//
//		Attack Distance: 60
//		Distance Min: 20
//		Distance Max: 60
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
|Primary()<20
//\\----------------------------------------------------------------------------------------------------------------------------------------////





// #3.1 Strafe - Channeling - Attack
//	Attack + Density
// 	Force Recast
// Move around
// Resouce : 
//			Primary 0
//			Channeling
//			Max Channeling Distance: 0
//			Min Resouce level 15
//
// 50ms
//		Attack Distance: 60
//		Distance Min: 0
//		Distance Max: 60
//		Calculation min param: 0
//		Calculation max param: 10
//		Attack limit: 1, 
//
//		Elite weight: 1
//		Minion weight: 1
//		Normal monster weight:1
//		Big guy weight: 1
//		Goblin weight: 1







// #3.2 Strafe - Channeling - Buff
// Density + Buff
// Force Recast
// Break items
// Resouce : 
//			Primary 0
//			Channeling
//			Max Channeling Distance: 0
//			Min Resouce level 15
//
// 50ms

//		Attack Distance: 90
//		Distance Min: 0
//		Distance Max: 90
//		Calculation min param: 0
//		Calculation max param: 10
//		Attack limit: 1, 
//
//		Elite weight: 1
//		Minion weight: 1
//		Normal monster weight:1
//		Big guy weight: 1
//		Goblin weight: 1





// #3.2 Strafe - Channeling - Buff
// Buff
// Force Recast
// Break items
// Resouce : 
//			Primary 0
//			Channeling
//			Max Channeling Distance: 0
//			Min Resouce level 15
//
// 50ms
// 50ms
Primary()>50











//	Attack + Density + Buff
//	50ms
//		Attack Distance: 60
//		Distance Min: 0
//		Distance Max: 60
//		Calculation min param: 0
//		Calculation max param: 30
//		Attack limit: 15, 
//
//		Elite weight: 15
//		Minion weight: 15
//		Normal monster weight:15
//		Big guy weight: 15
//		Goblin weight: 15













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





