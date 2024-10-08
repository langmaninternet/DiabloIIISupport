
//#1.1//
//// Storm Armor -----------------------------------------------------------------------------------------------------------------------------------------\\\\
// Buff
// 100ms



//#1.2//
//// Magic Weapon  -----------------------------------------------------------------------------------------------------------------------------------------\\\\
// Buff
// 100ms


//#1.3//
//// Familiar  -----------------------------------------------------------------------------------------------------------------------------------------\\\\
// Buff
// 100ms




//----------------------------------------------------------------------------------------------------------------------------------------
//  #2.1 Meteor - Health 10 yards
//  #2.2 Meteor - Health 15 yards
//  #2.3 Meteor - Health 20 yards
// 	Force Recast
//	Attack + Density + Buff
//	50ms
//		Attack Distance: [10,15,20]
//		Distance Min: 0
//		Distance Max: [10,15,20]
//		Calculation min param: 0
//		Calculation max param: 10
//		Attack limit: 1 
//
//		Elite weight: 2
//		Minion weight: 1
//		Normal monster weight: 1
//		Big guy weight: 2
//		Goblin weight: 2
//
//
//  Note: On [CoE Cycle] or [Oculus] or [Power] or [Triune of Love] or Health()<40%
//

//10 yards
Primary()>20&Health()<30%
//15 yards
Primary()>20&Health()<40%
//20 yards
Primary()>20&Health()<50%

//\\----------------------------------------------------------------------------------------------------------------------------------------////




//----------------------------------------------------------------------------------------------------------------------------------------
//	#3 Teleport - 25 yards
// 	Force Recast
//	Attack + Density + Buff
//	50ms
//		Attack Distance: 25
//		Distance Min: 0
//		Distance Max: 25
//		Calculation min param: 1
//		Calculation max param: 10
//		Attack limit: 1, 
//
//		Elite weight: 1
//		Minion weight: 5
//		Normal monster weight:5
//		Big guy weight: 1
//		Goblin weight: 5
//
//		Case 01: Safe in 25 yards - Just in Time [Prepare CoE Cycle]
//		Case 02: Safe in 25 yards - On [Wait for CoE Cycle]
//		Case 03: Proc [Tal Rasha's Elements - Arcane] - Just in Time [Prepare CoE Cycle]


(Rune(Wizard_Meteor)==0&(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>0))
|(Rune(Wizard_Meteor)==1&(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>0))
|(Rune(Wizard_Meteor)==2&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>0))
|(Rune(Wizard_Meteor)==3&(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>0))
|(Rune(Wizard_Meteor)==4&(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>0))
|(Rune(Wizard_Meteor)==0&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1000&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)
|(Rune(Wizard_Meteor)==1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1000&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)
|(Rune(Wizard_Meteor)==2&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1000&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<3000)
|(Rune(Wizard_Meteor)==3&BuffTimeLeft(6,P2_ItemPassive_Unique_Ring_038)>1000&BuffTimeLeft(6,P2_ItemPassive_Unique_Ring_038)<3000)
|(Rune(Wizard_Meteor)==4&BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1000&BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)<3000)
|(Rune(Wizard_Teleport)==2&BuffTimeLeft(1,Wizard_Teleport)<2000&BuffTimeLeft(0,Pages_Buff_Infinite_Casting)>5000)
|(Rune(Wizard_Teleport)==2&BuffTimeLeft(1,Wizard_Teleport)<1000&Health()<50%)


//|(Rune(Wizard_Teleport)==0&IsBuffActive(0,P2_ItemPassive_Unique_Ring_028)&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_028)<4000))

//\\----------------------------------------------------------------------------------------------------------------------------------------////







//----------------------------------------------------------------------------------------------------------------------------------------
//  #4 Black Hole
// 	Force Recast
//	Attack + Density + Buff
//	2000ms
//		Attack Distance: 50
//		Distance Min: 0
//		Distance Max: 50
//		Calculation min param: 1
//		Calculation max param: 10
//		Attack limit: 1, 
//
//		Elite weight: 2
//		Minion weight: 1
//		Normal monster weight:1
//		Big guy weight: 5
//		Goblin weight: 1
//

Primary()>30

//\\----------------------------------------------------------------------------------------------------------------------------------------////




//----------------------------------------------------------------------------------------------------------------------------------------
//  #5 Rift Guardian - Meteor
// 	Force Recast
//	Attack + Density
//	50ms
//		Attack Distance: 60
//		Distance Min: 0
//		Distance Max: 60
//		Calculation min param: 0
//		Calculation max param: 10
//		Attack limit: 1 
//
//		Elite weight: 0
//		Minion weight: 0
//		Normal monster weight: 0
//		Big guy weight: 2
//		Goblin weight: 1
//
//
//
Primary()>20
//\\----------------------------------------------------------------------------------------------------------------------------------------////










//----------------------------------------------------------------------------------------------------------------------------------------
//  #6.1 Elite - Meteor - Near 10 yards
//  #6.2 Elite - Meteor - Near 20 yards
//  #6.3 Elite - Meteor - Near 30 yards
// 	Force Recast
//	Attack + Density
//	50ms
//		Attack Distance: [10,20,30]
//		Distance Min: 0
//		Distance Max: [10,20,30]
//		Calculation min param: 0
//		Calculation max param: 10
//		Attack limit: 1 
//
//		Elite weight: 2
//		Minion weight: 0
//		Normal monster weight: 0
//		Big guy weight: 2
//		Goblin weight: 2
//
//
//  Note: On [CoE Cycle] or [Oculus] or [Power] or [Triune of Love] or Health()<40%


//10 yards
Primary()>20&
(Health()<40%
|(Rune(Wizard_Meteor)==0&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==1&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==2&(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==3&(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==4&(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1000|(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)<1250)))
|IsBuffActive(2,ItemPassive_Unique_Ring_922_x1)
|IsBuffActive(0,Pages_Buff_Damage)
|BuffTimeLeft(2,Community_Buff_DarkAlchemy)>0
)


//20 yards
Primary()>20&
(Health()<60%
|(Rune(Wizard_Meteor)==0&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==1&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==2&(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==3&(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==4&(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1000|(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)<1250)))
|IsBuffActive(2,ItemPassive_Unique_Ring_922_x1)
|IsBuffActive(0,Pages_Buff_Damage)
|BuffTimeLeft(2,Community_Buff_DarkAlchemy)>0
)



//30 yard
Primary()>20&
(Health()<80%
|(Rune(Wizard_Meteor)==0&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==1&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==2&(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==3&(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==4&(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1000|(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)<1250)))
|IsBuffActive(2,ItemPassive_Unique_Ring_922_x1)
|IsBuffActive(0,Pages_Buff_Damage)
|BuffTimeLeft(2,Community_Buff_DarkAlchemy)>0
)



//\\----------------------------------------------------------------------------------------------------------------------------------------////





//----------------------------------------------------------------------------------------------------------------------------------------
//  #7 Elite - Meteor
// 	Force Recast
//	Attack + Density
//	50ms
//		Attack Distance: 60
//		Distance Min: 0
//		Distance Max: 60
//		Calculation min param: 0
//		Calculation max param: 10
//		Attack limit: 1 
//
//		Elite weight: 2
//		Minion weight: 0
//		Normal monster weight: 0
//		Big guy weight: 2
//		Goblin weight: 2
//
//
//
Primary()>20
//\\----------------------------------------------------------------------------------------------------------------------------------------////




//----------------------------------------------------------------------------------------------------------------------------------------
//  #8 Battle - Meteor
// 	Force Recast
//  Don't use in fast mode
//	Attack 
//	50ms
//		Attack Distance: 60
//		Distance Min: 0
//		Distance Max: 60
//		Calculation min param: 0
//		Calculation max param: 10
//		Attack limit: 2 
//
//		Elite weight: 2
//		Minion weight: 1
//		Normal monster weight: 1
//		Big guy weight: 2
//		Goblin weight: 2
//
//
//
//  Note: Proc [Zei's Stone of Vengeance|Power Hungry|CoE Cycle|Oculus|Power|Triune of Love]
//
//
//
//
//
Primary()>20
//\\----------------------------------------------------------------------------------------------------------------------------------------////




//----------------------------------------------------------------------------------------------------------------------------------------
//  #9 Spectra Blace
//	Attack + Density
//	50ms
//		Attack Distance: 60
//		Distance Min: 0
//		Distance Max: 60
//		Calculation min param: 1
//		Calculation max param: 10
//		Attack limit: 1, 
//
//		Elite weight: 10
//		Minion weight: 0
//		Normal monster weight:0
//		Big guy weight: 0
//		Goblin weight: 10
//

Primary()<20

//\\----------------------------------------------------------------------------------------------------------------------------------------////

