
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
Primary()>40&Health()<30%
//15 yards
Primary()>40&Health()<40%
//20 yards
Primary()>40&Health()<50%

//\\----------------------------------------------------------------------------------------------------------------------------------------////






////----------------------------------------------------------------------------------------------------------------------------------------\\\\
//	#4.1 Teleport [Safe Passage|Calamity] - Safe in 25 yards - Just in Time [Prepare CoE Cycle]
//	#4.2 Teleport [Safe Passage|Calamity] - Safe in 20 yards - Just in Time [Prepare CoE Cycle]
//	#4.3 Teleport [Safe Passage|Calamity] - Safe in 15 yards - Just in Time [Prepare CoE Cycle]
//	#4.4 Teleport [Safe Passage|Calamity] - Safe in 10 yards - Just in Time [Prepare CoE Cycle]
//	#4.5 Teleport [Safe Passage|Calamity] - Safe in 05 yards - Just in Time [Prepare CoE Cycle]
// 	Force Recast
//	Attack + Density
//	50ms
//		Attack Distance: [25,20,15,10,5]
//		Distance Min: 0
//		Distance Max: [25,20,15,10,5]
//		Calculation min param: 1
//		Calculation max param: 30
//		Attack limit: 25 yards - 25, 
//		Attack limit: 20 yards - 20, 
//		Attack limit: 15 yards - 15, 
//		Attack limit: 10 yards - 10, 
//		Attack limit:  5 yards -  5, 
//
//		Elite weight: 1
//		Minion weight: 5
//		Normal monster weight:5
//		Big guy weight: 1
//		Goblin weight: 5


((Rune(Wizard_Teleport)==2&BuffTimeLeft(1,Wizard_Teleport)<4000&BuffTimeLeft(0,Pages_Buff_Invulnerable)<6000)
|(Rune(Wizard_Teleport)==0&IsBuffActive(0,P2_ItemPassive_Unique_Ring_028)&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_028)<4000))
&
((Rune(Wizard_Meteor)==0&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1000&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)
|(Rune(Wizard_Meteor)==1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1000&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)
|(Rune(Wizard_Meteor)==2&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1000&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<3000)
|(Rune(Wizard_Meteor)==3&BuffTimeLeft(6,P2_ItemPassive_Unique_Ring_038)>1000&BuffTimeLeft(6,P2_ItemPassive_Unique_Ring_038)<3000)
|(Rune(Wizard_Meteor)==4&BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1000&BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)<3000)
)
&
(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))

//\\----------------------------------------------------------------------------------------------------------------------------------------////



//----------------------------------------------------------------------------------------------------------------------------------------
//	#5.1 Teleport [Safe Passage|Calamity] - Safe in 25 yards - On [Wait for CoE Cycle]
//	#5.2 Teleport [Safe Passage|Calamity] - Safe in 20 yards - On [Wait for CoE Cycle]
//	#5.3 Teleport [Safe Passage|Calamity] - Safe in 15 yards - On [Wait for CoE Cycle]
//	#5.4 Teleport [Safe Passage|Calamity] - Safe in 10 yards - On [Wait for CoE Cycle]
//	#5.5 Teleport [Safe Passage|Calamity] - Safe in 5 yards - On [Wait for CoE Cycle]
// 	Force Recast
//	Attack + Density
//	50ms
//		Attack Distance: [25,20,15,10,5]
//		Distance Min: 0
//		Distance Max: [25,20,15,10,5]
//		Calculation min param: 1
//		Calculation max param: 30
//		Attack limit: 25 yards - 25, 
//		Attack limit: 20 yards - 20, 
//		Attack limit: 15 yards - 15, 
//		Attack limit: 10 yards - 10, 
//		Attack limit:  5 yards -  5, 
//
//		Elite weight: 1
//		Minion weight: 5
//		Normal monster weight:5
//		Big guy weight: 1
//		Goblin weight: 5
//

((Rune(Wizard_Teleport)==2&BuffTimeLeft(1,Wizard_Teleport)<1000&BuffTimeLeft(0,Pages_Buff_Invulnerable)<5000)
|(Rune(Wizard_Teleport)==0&IsBuffActive(0,P2_ItemPassive_Unique_Ring_028)&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_028)<1000))
&
((Rune(Wizard_Meteor)==0&(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>0))
|(Rune(Wizard_Meteor)==1&(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>0))
|(Rune(Wizard_Meteor)==2&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>0))
|(Rune(Wizard_Meteor)==3&(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>0))
|(Rune(Wizard_Meteor)==4&(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>0))
)
&
(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))

//\\----------------------------------------------------------------------------------------------------------------------------------------////



//----------------------------------------------------------------------------------------------------------------------------------------
// #6.1 Teleport [Calamity] - Near 25 yards - Proc [Tal Rasha's Elements - Arcane] - Just in Time [Prepare CoE Cycle]
// #6.2 Teleport [Calamity] - Near 30 yards - Proc [Tal Rasha's Elements - Arcane] - Just in Time [Prepare CoE Cycle]
// 	Force Recast
//	Attack + Density
//	50ms
//		Attack Distance: [25,30]
//		Distance Min: 0
//		Distance Max: [25,30]
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



Rune(Wizard_Teleport)==0&IsBuffActive(0,P2_ItemPassive_Unique_Ring_028)&BuffStackCount(5, P2_ItemPassive_Unique_Ring_028)<4&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_028)<2000
&
((Rune(Wizard_Meteor)==0&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1000&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)
|(Rune(Wizard_Meteor)==1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1000&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)
|(Rune(Wizard_Meteor)==2&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1000&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<3000)
|(Rune(Wizard_Meteor)==3&BuffTimeLeft(6,P2_ItemPassive_Unique_Ring_038)>1000&BuffTimeLeft(6,P2_ItemPassive_Unique_Ring_038)<3000)
|(Rune(Wizard_Meteor)==4&BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1000&BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)<3000)
)
&
(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))

//\\----------------------------------------------------------------------------------------------------------------------------------------////







//----------------------------------------------------------------------------------------------------------------------------------------
//  #7.1 Black Hole - Rift Guardian
// 	Force Recast
//	Attack + Density
//	2000ms
//		Attack Distance: 50
//		Distance Min: 0
//		Distance Max: 50
//		Calculation min param: 1
//		Calculation max param: 10
//		Attack limit: 1, 
//
//		Elite weight: 0
//		Minion weight: 0
//		Normal monster weight:0
//		Big guy weight: 2
//		Goblin weight: 1
//

Primary()>30

//\\----------------------------------------------------------------------------------------------------------------------------------------////



//----------------------------------------------------------------------------------------------------------------------------------------
//  #7.2 Black Hole - Rift Elite
// 	Force Recast
//	Attack + Density
//	3000ms
//		Attack Distance: 50
//		Distance Min: 0
//		Distance Max: 50
//		Calculation min param: 1
//		Calculation max param: 10
//		Attack limit: 1, 
//
//		Elite weight: 2
//		Minion weight: 0
//		Normal monster weight:0
//		Big guy weight: 2
//		Goblin weight: 2
//

Primary()>60

//\\----------------------------------------------------------------------------------------------------------------------------------------////



//----------------------------------------------------------------------------------------------------------------------------------------
//  #7.3 Black Hole
// 	Force Recast
//	Attack + Density
//	4000ms
//		Attack Distance: 50
//		Distance Min: 0
//		Distance Max: 50
//		Calculation min param: 1
//		Calculation max param: 10
//		Attack limit: 1, 
//
//		Elite weight: 1
//		Minion weight: 1
//		Normal monster weight:1
//		Big guy weight: 1
//		Goblin weight: 1
//

Primary()>90

//\\----------------------------------------------------------------------------------------------------------------------------------------////



//----------------------------------------------------------------------------------------------------------------------------------------
//  #8.1 Rift Guardian - Meteor - Far 
// 	Force Recast
//	Attack + Density
//	50ms
//		Attack Distance: 60
//		Distance Min: 40
//		Distance Max: 60
//		Calculation min param: 0
//		Calculation max param: 10
//		Attack limit: 1 

//		Elite weight: 0
//		Minion weight: 0
//		Normal monster weight: 0
//		Big guy weight: 2
//		Goblin weight: 1
//
//
//  Note: Proc [Zei's Stone of Vengeance|Power Hungry|CoE Cycle|Oculus|Power|Triune of Love]
//
//
//
Health()>=95%&Primary()>40&(
(IsBuffActive(0,ItemPassive_Unique_Gem_012_x1)
&IsBuffActive(3,Enchantress_CheatDeath_Passive)&BuffTimeLeft(1,Enchantress_CheatDeath_Passive)==0
&(IsBuffActive(0,Pages_Buff_Invulnerable)|IsBuffActive(2,Wizard_Passive_GalvanizingWard)|BuffStackCount(1,x1_Wizard_Passive_ArcaneAegis)==10|(Rune(Wizard_Teleport)==2&BuffTimeLeft(1,Wizard_Teleport)>2000))
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast)))
|(IsBuffActive(0,Wizard_Passive_PowerHungry)
&IsBuffActive(3,Enchantress_CheatDeath_Passive)&BuffTimeLeft(1,Enchantress_CheatDeath_Passive)==0
&(IsBuffActive(0,Pages_Buff_Invulnerable)|IsBuffActive(2,Wizard_Passive_GalvanizingWard)|BuffStackCount(1,x1_Wizard_Passive_ArcaneAegis)==10|(Rune(Wizard_Teleport)==2&BuffTimeLeft(1,Wizard_Teleport)>2000))
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast)))
|(((Rune(Wizard_Meteor)==0&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==1&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==2&(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==3&(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==4&(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1000|(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)<1250)))
|IsBuffActive(2,ItemPassive_Unique_Ring_922_x1)
|IsBuffActive(0,Pages_Buff_Damage)
|BuffTimeLeft(2,Community_Buff_DarkAlchemy)>0)
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast)))
)

//\\----------------------------------------------------------------------------------------------------------------------------------------////




//----------------------------------------------------------------------------------------------------------------------------------------
//  #8.2 Rift Guardian - Meteor - On [CoE Cycle] or [Oculus] or [Power] or [Triune of Love]
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
Primary()>40&(
((Rune(Wizard_Meteor)==0&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==1&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==2&(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==3&(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==4&(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1000|(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)<1250)))
|IsBuffActive(2,ItemPassive_Unique_Ring_922_x1)
|IsBuffActive(0,Pages_Buff_Damage)
|BuffTimeLeft(2,Community_Buff_DarkAlchemy)>0
)
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))
)
//\\----------------------------------------------------------------------------------------------------------------------------------------////





//----------------------------------------------------------------------------------------------------------------------------------------
//  #8.3 Rift Guardian - Meteor - Main
// 	Force Recast
//	Attack + Density
//	50ms
//		Attack Distance: 60
//		Distance Min: 40
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
Primary()>40
//\\----------------------------------------------------------------------------------------------------------------------------------------////




//----------------------------------------------------------------------------------------------------------------------------------------
//  #8.4 Rift Guardian - Meteor - 2000ms
// 	Force Recast
//	Attack + Density
//	2000ms
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
Primary()>40
//\\----------------------------------------------------------------------------------------------------------------------------------------////







//----------------------------------------------------------------------------------------------------------------------------------------
//  #9.1 Elite - Meteor - Far
// 	Force Recast
//	Attack + Density
//	50ms
//		Attack Distance: 60
//		Distance Min: 40
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
//  Note: Proc [Zei's Stone of Vengeance|Power Hungry|CoE Cycle|Oculus|Power|Triune of Love]
//
//
//
Health()>=95%&Primary()>40&(
(IsBuffActive(0,ItemPassive_Unique_Gem_012_x1)
&IsBuffActive(3,Enchantress_CheatDeath_Passive)&BuffTimeLeft(1,Enchantress_CheatDeath_Passive)==0
&(IsBuffActive(0,Pages_Buff_Invulnerable)|IsBuffActive(2,Wizard_Passive_GalvanizingWard)|BuffStackCount(1,x1_Wizard_Passive_ArcaneAegis)==10|(Rune(Wizard_Teleport)==2&BuffTimeLeft(1,Wizard_Teleport)>2000))
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast)))
|(IsBuffActive(0,Wizard_Passive_PowerHungry)
&IsBuffActive(3,Enchantress_CheatDeath_Passive)&BuffTimeLeft(1,Enchantress_CheatDeath_Passive)==0
&(IsBuffActive(0,Pages_Buff_Invulnerable)|IsBuffActive(2,Wizard_Passive_GalvanizingWard)|BuffStackCount(1,x1_Wizard_Passive_ArcaneAegis)==10|(Rune(Wizard_Teleport)==2&BuffTimeLeft(1,Wizard_Teleport)>2000))
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast)))
|(((Rune(Wizard_Meteor)==0&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==1&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==2&(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==3&(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==4&(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1000|(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)<1250)))
|IsBuffActive(2,ItemPassive_Unique_Ring_922_x1)
|IsBuffActive(0,Pages_Buff_Damage)
|BuffTimeLeft(2,Community_Buff_DarkAlchemy)>0)
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast)))
)

//\\----------------------------------------------------------------------------------------------------------------------------------------////





//----------------------------------------------------------------------------------------------------------------------------------------
//  #9.2 Elite - Meteor - On [CoE Cycle] or [Oculus] or [Power] or [Triune of Love]
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

Primary()>40&(
((Rune(Wizard_Meteor)==0&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==1&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==2&(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==3&(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==4&(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1000|(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)<1250)))
|IsBuffActive(2,ItemPassive_Unique_Ring_922_x1)
|IsBuffActive(0,Pages_Buff_Damage)
|BuffTimeLeft(2,Community_Buff_DarkAlchemy)>0
)
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))
)
//\\----------------------------------------------------------------------------------------------------------------------------------------////





//----------------------------------------------------------------------------------------------------------------------------------------
//  #9.3 Elite - Meteor - Main
// 	Force Recast
//	Attack + Density
//	50ms
//		Attack Distance: 60
//		Distance Min: 40
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
Primary()>40
//\\----------------------------------------------------------------------------------------------------------------------------------------////





//----------------------------------------------------------------------------------------------------------------------------------------
//  #9.4 Elite - Meteor - 2000ms
// 	Force Recast
//	Attack + Density
//	2000ms
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
Primary()>40
//\\----------------------------------------------------------------------------------------------------------------------------------------////




//----------------------------------------------------------------------------------------------------------------------------------------
//  #9.5 Elite - Meteor - Near 10 yards
// 	Force Recast
//	Attack + Density
//	50ms
//		Attack Distance: 10
//		Distance Min: 0
//		Distance Max: 10
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
//
Primary()>40&
(Health()<40%
|
(((Rune(Wizard_Meteor)==0&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==1&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==2&(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==3&(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==4&(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1000|(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)<1250)))
|IsBuffActive(2,ItemPassive_Unique_Ring_922_x1)
|IsBuffActive(0,Pages_Buff_Damage)
|BuffTimeLeft(2,Community_Buff_DarkAlchemy)>0
)&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast)))
)
//\\----------------------------------------------------------------------------------------------------------------------------------------////





//----------------------------------------------------------------------------------------------------------------------------------------
//  #9.6 Elite - Meteor - Near 20 yards
// 	Force Recast
//	Attack + Density
//	50ms
//		Attack Distance: 20
//		Distance Min: 0
//		Distance Max: 20
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
//  Note: On [CoE Cycle] or [Oculus] or [Power] or [Triune of Love] or Health()<60%
//
Primary()>40&
(Health()<60%
|
(((Rune(Wizard_Meteor)==0&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==1&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==2&(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==3&(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==4&(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1000|(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)<1250)))
|IsBuffActive(2,ItemPassive_Unique_Ring_922_x1)
|IsBuffActive(0,Pages_Buff_Damage)
|BuffTimeLeft(2,Community_Buff_DarkAlchemy)>0
)&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast)))
)
//\\----------------------------------------------------------------------------------------------------------------------------------------////






//----------------------------------------------------------------------------------------------------------------------------------------
//  #9.7 Elite - Meteor - Near 30 yards
// 	Force Recast
//	Attack + Density
//	50ms
//		Attack Distance: 30
//		Distance Min: 0
//		Distance Max: 30
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
//  Note: On [CoE Cycle] or [Oculus] or [Power] or [Triune of Love] or Health()<80%
//
Primary()>40&
(Health()<80%
|
(((Rune(Wizard_Meteor)==0&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==1&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==2&(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==3&(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==4&(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1000|(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)<1250)))
|IsBuffActive(2,ItemPassive_Unique_Ring_922_x1)
|IsBuffActive(0,Pages_Buff_Damage)
|BuffTimeLeft(2,Community_Buff_DarkAlchemy)>0
)&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast)))
)
//\\----------------------------------------------------------------------------------------------------------------------------------------////





//----------------------------------------------------------------------------------------------------------------------------------------
//  #9.8 Elite - Meteor - Near 40 yards
// 	Force Recast
//	Attack + Density
//	50ms
//		Attack Distance: 40
//		Distance Min: 0
//		Distance Max: 40
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
//  Note: On [CoE Cycle] or [Oculus] or [Power] or [Triune of Love] or Health()<80%
//
Primary()>40&
(Health()<95%
|
(((Rune(Wizard_Meteor)==0&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==1&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==2&(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==3&(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==4&(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1000|(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)<1250)))
|IsBuffActive(2,ItemPassive_Unique_Ring_922_x1)
|IsBuffActive(0,Pages_Buff_Damage)
|BuffTimeLeft(2,Community_Buff_DarkAlchemy)>0
)&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast)))
)
//\\----------------------------------------------------------------------------------------------------------------------------------------////





//----------------------------------------------------------------------------------------------------------------------------------------
//  #9.9 Elite - Meteor
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
Primary()>40
//\\----------------------------------------------------------------------------------------------------------------------------------------////





//----------------------------------------------------------------------------------------------------------------------------------------
//  #10.1 Meteor - Proc [Tal Rasha] - Fresh start
// 	Force Recast
//  Don't use in fast mode
//	Attack + Buff
//	2000ms
//		Attack Distance: 60
//		Distance Min: 0
//		Distance Max: 60
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
//
Primary()>40
& IsBuffActive(0,P2_ItemPassive_Unique_Ring_028)&BuffStackCount(5, P2_ItemPassive_Unique_Ring_028)<4
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))
//\\----------------------------------------------------------------------------------------------------------------------------------------////








//		//----------------------------------------------------------------------------------------------------------------------------------------
//		//  #10.2 Teleport - Move - On [Wait for CoE Cycle|Infinite Casting] 
//		// 	Force Recast
//		//	Move
//		//	1000ms
//		//
//		//  Note: On [Wait for CoE Cycle|Infinite Casting] 
//		//
//		BuffTimeLeft(0, Pages_Buff_Infinite_Casting) > 4000 | 
//		(((Rune(Wizard_Meteor)==0&(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>0))
//		|(Rune(Wizard_Meteor)==1&(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>0))
//		|(Rune(Wizard_Meteor)==2&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>0))
//		|(Rune(Wizard_Meteor)==3&(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>0))
//		|(Rune(Wizard_Meteor)==4&(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>0)))
//		&
//		(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast)))
//		//\\----------------------------------------------------------------------------------------------------------------------------------------////








//----------------------------------------------------------------------------------------------------------------------------------------
//  #11.1 Battle - Meteor - Far
// 	Force Recast
//  Don't use in fast mode
//	Attack + Buff
//	200ms
//		Attack Distance: 60
//		Distance Min: 40
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
Health()>=95%&Primary()>40&(
(IsBuffActive(0,ItemPassive_Unique_Gem_012_x1)
&IsBuffActive(3,Enchantress_CheatDeath_Passive)&BuffTimeLeft(1,Enchantress_CheatDeath_Passive)==0
&(IsBuffActive(0,Pages_Buff_Invulnerable)|IsBuffActive(2,Wizard_Passive_GalvanizingWard)|BuffStackCount(1,x1_Wizard_Passive_ArcaneAegis)==10|(Rune(Wizard_Teleport)==2&BuffTimeLeft(1,Wizard_Teleport)>2000))
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast)))
|(IsBuffActive(0,Wizard_Passive_PowerHungry)
&IsBuffActive(3,Enchantress_CheatDeath_Passive)&BuffTimeLeft(1,Enchantress_CheatDeath_Passive)==0
&(IsBuffActive(0,Pages_Buff_Invulnerable)|IsBuffActive(2,Wizard_Passive_GalvanizingWard)|BuffStackCount(1,x1_Wizard_Passive_ArcaneAegis)==10|(Rune(Wizard_Teleport)==2&BuffTimeLeft(1,Wizard_Teleport)>2000))
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast)))
|(((Rune(Wizard_Meteor)==0&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==1&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==2&(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==3&(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==4&(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1000|(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)<1250)))
|IsBuffActive(2,ItemPassive_Unique_Ring_922_x1)
|IsBuffActive(0,Pages_Buff_Damage)
|BuffTimeLeft(2,Community_Buff_DarkAlchemy)>0)
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast)))
)
//\\----------------------------------------------------------------------------------------------------------------------------------------////





//----------------------------------------------------------------------------------------------------------------------------------------
//  #11.2 Battle - Meteor - On [CoE Cycle] or [Oculus] or [Power] or [Triune of Love]
// 	Force Recast
//  Don't use in fast mode
//	Attack + Density
//	200ms
//		Attack Distance: 60
//		Distance Min: 0
//		Distance Max: 60
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
//

Primary()>40&(
((Rune(Wizard_Meteor)==0&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==1&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==2&(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==3&(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==4&(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1000|(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)<1250)))
|IsBuffActive(2,ItemPassive_Unique_Ring_922_x1)
|IsBuffActive(0,Pages_Buff_Damage)
|BuffTimeLeft(2,Community_Buff_DarkAlchemy)>0
)
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))
)
//\\----------------------------------------------------------------------------------------------------------------------------------------////







//----------------------------------------------------------------------------------------------------------------------------------------
//  #11.3 Battle - Main
// 	Force Recast
//  Don't use in fast mode
//	Attack + Density
//	200ms
//		Attack Distance: 60
//		Distance Min: 40
//		Distance Max: 60
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
//
Primary()>40
//\\----------------------------------------------------------------------------------------------------------------------------------------////





//----------------------------------------------------------------------------------------------------------------------------------------
//  #11.4 Battle - 2000ms
// 	Force Recast
//  Don't use in fast mode
//	Attack + Density
//	2000ms
//		Attack Distance: 60
//		Distance Min: 0
//		Distance Max: 60
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
//
Primary()>40
//\\----------------------------------------------------------------------------------------------------------------------------------------////






//----------------------------------------------------------------------------------------------------------------------------------------
//  #11.5 Battle - Near 10 yards
// 	Force Recast
//  Don't use in fast mode
//	Attack + Density
//	200ms
//		Attack Distance: 10
//		Distance Min: 0
//		Distance Max: 10
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
Primary()>40&
(Health()<40%
|
(((Rune(Wizard_Meteor)==0&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==1&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==2&(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==3&(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==4&(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1000|(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)<1250)))
|IsBuffActive(2,ItemPassive_Unique_Ring_922_x1)
|IsBuffActive(0,Pages_Buff_Damage)
|BuffTimeLeft(2,Community_Buff_DarkAlchemy)>0
)&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast)))
)
//\\----------------------------------------------------------------------------------------------------------------------------------------////





//----------------------------------------------------------------------------------------------------------------------------------------
//  #11.6 Battle - Meteor - Near 20 yards
// 	Force Recast
//  Don't use in fast mode
//	Attack + Density
//	200ms
//		Attack Distance: 20
//		Distance Min: 0
//		Distance Max: 20
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
//  Note: On [CoE Cycle] or [Oculus] or [Power] or [Triune of Love] or Health()<60%
//
Primary()>40&
(Health()<60%
|
(((Rune(Wizard_Meteor)==0&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==1&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==2&(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==3&(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==4&(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1000|(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)<1250)))
|IsBuffActive(2,ItemPassive_Unique_Ring_922_x1)
|IsBuffActive(0,Pages_Buff_Damage)
|BuffTimeLeft(2,Community_Buff_DarkAlchemy)>0
)&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast)))
)
//\\----------------------------------------------------------------------------------------------------------------------------------------////




//----------------------------------------------------------------------------------------------------------------------------------------
//  #11.7 Battle - Meteor - Near 30 yards
// 	Force Recast
//  Don't use in fast mode
//	Attack + Density
//	200ms
//		Attack Distance: 30
//		Distance Min: 0
//		Distance Max: 30
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
//  Note: On [CoE Cycle] or [Oculus] or [Power] or [Triune of Love] or Health()<80%
//
Primary()>40&
(Health()<80%
|
(((Rune(Wizard_Meteor)==0&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==1&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==2&(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==3&(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==4&(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1000|(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)<1250)))
|IsBuffActive(2,ItemPassive_Unique_Ring_922_x1)
|IsBuffActive(0,Pages_Buff_Damage)
|BuffTimeLeft(2,Community_Buff_DarkAlchemy)>0
)&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast)))
)
//\\----------------------------------------------------------------------------------------------------------------------------------------////

