


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
//  #8.1 Rift Guardian - Meteor - Far 
// 	Force Recast
//	Attack + Density
//	50ms
//		Attack Distance: 50
//		Distance Min: 0
//		Distance Max: 50
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
//		Attack Distance: 50
//		Distance Min: 0
//		Distance Max: 50
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
//		Attack Distance: 50
//		Distance Min: 40
//		Distance Max: 50
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
//		Attack Distance: 50
//		Distance Min: 0
//		Distance Max: 50
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
//		Attack Distance: 50
//		Distance Min: 0
//		Distance Max: 50
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
//		Attack Distance: 50
//		Distance Min: 0
//		Distance Max: 50
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
//		Attack Distance: 50
//		Distance Min: 0
//		Distance Max: 50
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






Elites - Mystic Ally - Infi

//----------------------------------------------------------------------------------------------------------------------------------------
//  #9.2 Elite - Meteor - On [CoE Cycle] or [Oculus] or [Power] or [Triune of Love]
// 	Force Recast
//	Attack + Density
//	50ms
//		Attack Distance: 50
//		Distance Min: 0
//		Distance Max: 50
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
//		Attack Distance: 50
//		Distance Min: 0
//		Distance Max: 50
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
//		Attack Distance: 50
//		Distance Min: 0
//		Distance Max: 50
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

nite Casting + Shenlong's Spirit
BuffTimeLeft(0, Pages_Buff_Infinite_Casting) > 4000 & Rune(X1_Monk_MysticAlly_v2)==0 
& ((!IsBuffActive(0, P3_ItemPassive_Unique_Ring_026)) | IsBuffActive(1, P3_ItemPassive_Unique_Ring_026) | Primary() > 70%)



Elites - Fire Mystic Ally - (Fire CoE Cycle + Shenlong's Spirit + Assimilation) - Very Good Situation 01
Rune(X1_Monk_MysticAlly_v2)==0 & BuffTimeLeft(3, P2_ItemPassive_Unique_Ring_038) > 2000 & (IsBuffActive(1, P3_ItemPassive_Unique_Ring_026) | Primary() > 70%) & BuffStackCount(4, Monk_WayOfTheHundredFists) > 0 & ( MonkAlliesCount() >= 10 | (MonkAlliesCount() >= 9 & BuffTimeLeft(3, P2_ItemPassive_Unique_Ring_038) < 3600) | (MonkAlliesCount() >= 8 & BuffTimeLeft(3, P2_ItemPassive_Unique_Ring_038) < 3200) | (MonkAlliesCount() >= 7 & BuffTimeLeft(3, P2_ItemPassive_Unique_Ring_038) < 2800) | (MonkAlliesCount() >= 6 & BuffTimeLeft(3, P2_ItemPassive_Unique_Ring_038) < 2400))



Elites - Fire Mystic Ally - (Fire CoE Cycle + Shenlong's Spirit + [Dregs of Lies]) - Very Good Situation 02
Rune(X1_Monk_MysticAlly_v2)==0 & BuffTimeLeft(3, P2_ItemPassive_Unique_Ring_038) > 2000 & (IsBuffActive(1, P3_ItemPassive_Unique_Ring_026) | Primary() > 70%) & ( (MonkAlliesCount() >= 10 & ((!IsBuffActive(0, P72_ItemPassive_Soulshard_002)) | BuffStackCount(2, P72_ItemPassive_Soulshard_002) > 60)) | (MonkAlliesCount() >= 9 & ((!IsBuffActive(0, P72_ItemPassive_Soulshard_002)) | BuffStackCount(2, P72_ItemPassive_Soulshard_002) > 50) & BuffTimeLeft(3, P2_ItemPassive_Unique_Ring_038) < 3600) | (MonkAlliesCount() >= 8 & ((!IsBuffActive(0, P72_ItemPassive_Soulshard_002)) | BuffStackCount(2, P72_ItemPassive_Soulshard_002) > 40) & BuffTimeLeft(3, P2_ItemPassive_Unique_Ring_038) < 3200) | (MonkAlliesCount() >= 7 & ((!IsBuffActive(0, P72_ItemPassive_Soulshard_002)) | BuffStackCount(2, P72_ItemPassive_Soulshard_002) > 30) & BuffTimeLeft(3, P2_ItemPassive_Unique_Ring_038) < 2800) | (MonkAlliesCount() >= 6 & ((!IsBuffActive(0, P72_ItemPassive_Soulshard_002)) | BuffStackCount(2, P72_ItemPassive_Soulshard_002) > 20) & BuffTimeLeft(3, P2_ItemPassive_Unique_Ring_038) < 2400))







Elites - Fire Mystic Ally - (Fire CoE Cycle + Shenlong's Spirit) - Good Situation
Rune(X1_Monk_MysticAlly_v2)==0 & BuffTimeLeft(3, P2_ItemPassive_Unique_Ring_038) > 1900 & IsBuffActive(1, P3_ItemPassive_Unique_Ring_026) & (MonkAlliesCount() > 9 | (MonkAlliesCount() > 8 & BuffTimeLeft(3, P2_ItemPassive_Unique_Ring_038) < 3600) | (MonkAlliesCount() > 7 & BuffTimeLeft(3, P2_ItemPassive_Unique_Ring_038) < 3200) | (MonkAlliesCount() > 6 & BuffTimeLeft(3, P2_ItemPassive_Unique_Ring_038) < 2800) | (MonkAlliesCount() > 5 & BuffTimeLeft(3, P2_ItemPassive_Unique_Ring_038) < 2400) | BuffTimeLeft(3, P2_ItemPassive_Unique_Ring_038) < 2201)



Elites - Buff - Inner Sanctuary - Proc [Sliver of Terror]
Cooldown(X1_Monk_MysticAlly_v2) < 1000 | MonkAlliesCount() > 10






//Meteor Fire
Rune(Wizard_Meteor)==0
Rune(Wizard_Meteor)==1

//Meteor Cold
Rune(Wizard_Meteor)==2

//Meteor Arcane
Rune(Wizard_Meteor)==3

//Meteor Lightning
Rune(Wizard_Meteor)==4


//Teleport [Safe Passage]
Rune(Wizard_Teleport)==2


//	Teleport [Calamity]
Rune(Wizard_Teleport)==0



//		Convention of Elements
//		Power name: P2_ItemPassive_Unique_Ring_038
//		The sequence of elements w.r.t. their bucket number is as follows:
//		1. Arcane
//		2. Cold
//		3. Fire
//		4. Holy
//		5. Lightning
//		6. Physical
//		7. Poison
//		Wizard : Cold -> Fire -> Lightning -> Arcane -> Cold -> Fire -> Lightning -> Arcane
//		Wizard : 2    -> 3    -> 5         -> 1      -> 2    -> 3    -> 5         -> 1


//		Tal Rasha's Set
//		Power name: P2_ItemPassive_Unique_Ring_028
//		Have 6 set effect: IsBuffActive(0,P2_ItemPassive_Unique_Ring_028)

//Đã có elements cold
IsBuffActive(2,P2_ItemPassive_Unique_Ring_028)
BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_028)>1000


//Đã có elements Arcane
IsBuffActive(1,P2_ItemPassive_Unique_Ring_028)
BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_028)>1000



//Có sheild - IsBuffActive(2,Wizard_Passive_GalvanizingWard)
Buff, 		1, 		0, 			Wizard_Passive_GalvanizingWard, Galvanizing Ward
Buff, 		1, 		2, 			Wizard_Passive_GalvanizingWard, Galvanizing Ward































Meteor - On [CoE Cold Cycle + Power] + Already Buff
Meteor - On [CoE Cold Cycle + Conduit] + Already Buff
Rune(Wizard_Meteor) == 2
& (BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>2000 |(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1 & BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<1000))
& IsBuffActive(0,Pages_Buff_Electrified_TieredRift)
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))
Meteor - On [CoE Cold Cycle + Oculus] + Already Buff






















Teleport - Proc [Tal Rasha]
BuffStackCount(5, P2_ItemPassive_Unique_Ring_028) ==3




Meteor - Buff - Near - Waiting [Teleport] + Already Buff
Cooldown(Wizard_Teleport) > 1550 & (BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))





Meteor - Elite - Main - Already Buff
Elite - Meteor - [30-45 yards]
Meteor - Elite - Cycle 1000ms + Already Buff




Meteor - On [CoE Cold Cycle]
Rune(Wizard_Meteor) == 2
&(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>2000 |(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1 & BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<1000))
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))







Teleport [Safe Passage] - Near 5 yards - On [Wait for CoE Cold Cycle]
Teleport [Safe Passage] - Near 10 yards - On [Wait for CoE Cold Cycle]
Teleport [Safe Passage] - Near 15 yards - On [Wait for CoE Cold Cycle]
Teleport [Safe Passage] - Near 20 yards - On [Wait for CoE Cold Cycle]
Rune(Wizard_Meteor)==2 & Rune(Wizard_Teleport)==2 & BuffTimeLeft(1,Wizard_Teleport)<400
&(BuffTimeLeft(3, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(4, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(5, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(6, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(7, P2_ItemPassive_Unique_Ring_038)>0)
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))





Meteor - On [CoE Cold Cycle + Power] + Already Buff

BuffStackCount(5, P2_ItemPassive_Unique_Ring_028) ==3


Meteor - On [CoE Cold Cycle + Proc Enchantress Cheat Death] + Already Buff
BuffTimeLeft(1,Enchantress_CheatDeath_Passive)>0 & Rune(Wizard_Meteor) == 2
&(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>2000 |(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1 & BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<1000))
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))




Teleport - Proc [Enchantress Cheat Death] + HP 60%
Rune(Wizard_Teleport) == 2 & BuffTimeLeft(1,Enchantress_CheatDeath_Passive)>0 & BuffTimeLeft(1,Wizard_Teleport)<1000
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))





Meteor - Rift Guardian [0-60 yards] - On [CoE Cold Cycle] + Already Buff + HP 99%
Rune(Wizard_Meteor) == 2
&(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>2000 |(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1 & BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<1000))
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))



Teleport [Safe Passage] - Near 5 yards - Just in Time [Prepare CoE Cold Cycle]
Rune(Wizard_Meteor) == 2 & Rune(Wizard_Teleport) == 2 & BuffTimeLeft(1,Wizard_Teleport)<4000
& BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1000 & BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<3000
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))





Teleport - Best position in 5 yards - Just in Time [Prepare CoE Cold Cycle]
Rune(Wizard_Meteor) == 2 & BuffTimeLeft(1,Wizard_Teleport)<4000
& BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1000 & BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<3000
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))




Teleport - Best position in 5 yards - On [Wait for CoE Cold Cycle]
Rune(Wizard_Meteor) == 2 & BuffTimeLeft(1,Wizard_Teleport)<400
&(BuffTimeLeft(3, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(4, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(5, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(6, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(7, P2_ItemPassive_Unique_Ring_038)>0)
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))




Elite - Teleport [Safe Passage] - Near 5 yards - On [Wait for CoE Cold Cycle]
Rune(Wizard_Meteor) == 2 & Rune(Wizard_Teleport) == 2
&(BuffTimeLeft(3, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(4, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(5, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(6, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(7, P2_ItemPassive_Unique_Ring_038)>0)
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))




[CoE Fire Holy Lightning Physical Poison Cycle]
[Wait for CoE Cold Cycle]


BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000











Teleport - Elite - Proc [Safe Passage] On [CoE Fire Holy Lightning Physical Poison Cycle]

Buffed resource:
Health
Minimum resource level:
40.00% for health, absolute value for resources




Preparation - Proc [Battle Scars]



Evasive Fire - Proc [Wraps of Clarity]
Bolas - Proc [Wraps of Clarity]




Hatred - Grenade
Doors - Grenade





Multishot - Rift Guardian - On [Oculus] + Already Buff
BuffTimeLeft(0,ItemPassive_Unique_Ring_922_x1)>0 & BuffTimeLeft(2,ItemPassive_Unique_Ring_922_x1)>0 & BuffTimeLeft(3,ItemPassive_Unique_Ring_922_x1)>0

&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))




BuffTimeLeft(4,X1_DemonHunter_Vengeance)>1000


DemonHunter


(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))



Health() < 40%


Health() > 2%







On [Invisible after death]
(BuffTimeLeft(0,Wizard_Familiar)==0&BuffTimeLeft(0,Wizard_MagicWeapon)==0&BuffTimeLeft(3,Wizard_StormArmor)==0)



Already Buff
(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))




Meteor - Rift Guardian - On [CoE Cold Cycle] + Already Buff
Rune(Wizard_Meteor) == 2 & (BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>2000 |(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1 & BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<1000))
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))




Meteor - Rift Guardian - On [Oculus] + Already Buff
BuffTimeLeft(0,ItemPassive_Unique_Ring_922_x1)>0 & BuffTimeLeft(2,ItemPassive_Unique_Ring_922_x1)>0 & BuffTimeLeft(3,ItemPassive_Unique_Ring_922_x1)>0
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))



Meteor - Elite - On [Oculus] + Already Buff
BuffTimeLeft(0,ItemPassive_Unique_Ring_922_x1)>0 & BuffTimeLeft(2,ItemPassive_Unique_Ring_922_x1)>0 & BuffTimeLeft(3,ItemPassive_Unique_Ring_922_x1)>0
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))



Meteor - Elite - On [CoE Cold Cycle] + Already Buff
Rune(Wizard_Meteor) == 2 & (BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>2000 |(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1 & BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<1000))
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))



Meteor - Rift Guardian - Already Buff
(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))


Meteor - Elite - Main - Already Buff
(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))


Meteor - Elite - On [Power] or [Conduit] + Already Buff
(IsBuffActive(0, Pages_Buff_Damage) | IsBuffActive(0, Pages_Buff_Electrified_TieredRift))
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))





Meteor - On [Power + Infinite Casting] + Already Buff
IsBuffActive(0, Pages_Buff_Infinite_Casting) & IsBuffActive(0, Pages_Buff_Damage)
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))




Meteor - On [Power + Conduit] + Already Buff
IsBuffActive(0, Pages_Buff_Electrified_TieredRift) & IsBuffActive(0, Pages_Buff_Damage)
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))



Meteor - On [CoE Cold Cycle + Power] + Already Buff
Rune(Wizard_Meteor) == 2 & (BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>2000 |(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1 & BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<1000)) & IsBuffActive(0, Pages_Buff_Damage)
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))



Meteor - On [CoE Cold Cycle + Conduit] + Already Buff



Rune(Wizard_Meteor) == 2 & (BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>2000 |(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1 & BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<1000)) & IsBuffActive(0, Pages_Buff_Electrified_TieredRift)
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))






Meteor - On [CoE Cold Cycle + Oculus] + Already Buff
Rune(Wizard_Meteor) == 2 & (BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>2000 |(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1 & BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<1000)) & BuffTimeLeft(0,ItemPassive_Unique_Ring_922_x1)>0 & BuffTimeLeft(2,ItemPassive_Unique_Ring_922_x1)>0 & BuffTimeLeft(3,ItemPassive_Unique_Ring_922_x1)>0
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))




Meteor - Proc [Tal Rasha] + Already Buff
BuffStackCount(5, P2_ItemPassive_Unique_Ring_028) < 3
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))






Meteor - Elite - Near Cycle 2000ms - On [CoE Fire Holy Lightning Physical Poison Cycle] + Already Buff

Rune(Wizard_Meteor) == 2 & (BuffTimeLeft(3, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(4, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(5, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(6, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(7, P2_ItemPassive_Unique_Ring_038)>0)
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000|IsBuffActive(0, Pages_Buff_Run_Speed_Knockback_Cast))


Meteor - Elite - Near Cycle 500ms - On [CoE Cold Cycle] + Already Buff










//----------------------------------------------------------------------------------------------------------------------------------------
//  Elite - Typhon Hydra
//
//		Distance Min: 0
//		Distance Max: ***
//		Calculation min param: 0
//		Calculation max param: 10
//		Attack limit: 1 
//		Elite weight: 2
//		Minion weight: 0
//		Big guy weight: 2
//		Goblin weight: 2
//		Normal monster weight: 0
//
//

IsBuffActive(0,P68_ItemPassive_Unique_Ring_007)
&
(BuffStackCount(7,Wizard_Hydra)<5
|((IsBuffActive(0,ItemPassive_Unique_Ring_510_x1))&BuffStackCount(7,Wizard_Hydra)<10)
)
//\\----------------------------------------------------------------------------------------------------------------------------------------////








//----------------------------------------------------------------------------------------------------------------------------------------
//  Elite - Typhon Hydra - Next 5 Head - 30 yards
//  Elite - Typhon Hydra - Next 5 Head - 60 yards
//  Typhon Hydra - Next 5 Head - 30 yards
//
//		Distance Min: 0
//		Distance Max: ***
//		Calculation min param: 0
//		Calculation max param: 10
//		Attack limit: 1 
//		Elite weight: 2
//		Minion weight: 0
//		Big guy weight: 2
//		Goblin weight: 2
//		Normal monster weight: 0
//
//

IsBuffActive(0,P68_ItemPassive_Unique_Ring_007)
&IsBuffActive(0,ItemPassive_Unique_Ring_510_x1)
&(!IsBuffActive(0,Wizard_Passive_ArcaneDynamo)|BuffStackCount(1,Wizard_Passive_ArcaneDynamo)==5)
&BuffStackCount(7,Wizard_Hydra)<10
//\\----------------------------------------------------------------------------------------------------------------------------------------////







ItemPassive_Unique_Ring_510_x1		You may have one extra Hydra active at a time.	


IsBuffActive(0,ItemPassive_Unique_Gem_018_x1)

ItemPassive_Unique_Gem_018U_x1




////
IsBuffActive(0,Wizard_Passive_ArcaneDynamo)&BuffStackCount(1,Wizard_Passive_ArcaneDynamo)<5



Rune(Wizard_Hydra)==0



// 

BuffStackCount(7,Wizard_Hydra)<5


// Typhon - six pc 
IsBuffActive(0,P68_ItemPassive_Unique_Ring_007)

//full stack dynamo
(!IsBuffActive(0,Wizard_Passive_ArcaneDynamo)|BuffStackCount(1,Wizard_Passive_ArcaneDynamo)==5)




ItemPassive_Unique_Ring_604_x1		Frost Hydra now periodically casts Frost Nova.	
ItemPassive_Unique_Ring_510_x1		You may have one extra Hydra active at a time.	


//5 đầu
Rune, 		1, 		1, 			Wizard_Blizzard, Blizzard
EndTick, 	1746, 		1, 			Wizard_Hydra, The Typhon's Veil
Rune, 		1, 		0, 			Wizard_Hydra, Hydra
Buff, 		5, 		7, 			Wizard_Hydra, The Typhon's Veil
Buff, 		1, 		1, 			Wizard_Hydra, The Typhon's Veil



//10 đầu
Rune, 		1, 		1, 			Wizard_Blizzard, Blizzard
EndTick, 	1744, 		1, 			Wizard_Hydra, The Typhon's Veil
Rune, 		1, 		0, 			Wizard_Hydra, Hydra
Buff, 		10, 		7, 			Wizard_Hydra, The Typhon's Veil
Buff, 		2, 		1, 			Wizard_Hydra, The Typhon's Veil




Rune, 		1, 		0, 			Wizard_Hydra, Hydra
Rune(Wizard_Hydra)==1








//----------------------------------------------------------------------------------------------------------------------------------------
//	Blizzard - Buff in battle
//	Black Hole - Elite - 30 yards 500ms
//	Black Hole - Elite - 50 yards 500ms
//

(
(IsBuffActive(0,P68_ItemPassive_Unique_Ring_007)&BuffStackCount(1,Wizard_Passive_ArcaneDynamo)==0)
|BuffStackCount(7,Wizard_Hydra)==10
|((!IsBuffActive(0,ItemPassive_Unique_Ring_510_x1))&BuffStackCount(7,Wizard_Hydra)==5)
)

//\\----------------------------------------------------------------------------------------------------------------------------------------////









//----------------------------------------------------------------------------------------------------------------------------------------
//	Urshi - Black Hole
//
//		Do not use during fast mode: true
//		Minimum resource level: 50.00
//		Distance Min: 0
//		Distance Max: 40
//		Calculation min param: 0
//		Calculation max param: 10
//		Attack limit: 1
//		Elite weight: 5
//		Minion weight: 1
//		Big guy weight: 5
//		Goblin weight: 5
//		Normal monster weight: 1
//
//

ActorCount(P1_LR_TieredRift_Nephalem) == 1 & (!WorldIsGreaterRiftNotFinished())

//\\----------------------------------------------------------------------------------------------------------------------------------------////







//----------------------------------------------------------------------------------------------------------------------------------------
//	Blizzard After Teleport [Safe Passage]
//
//		Do not use during fast mode: true
//		Minimum resource level: 50.00
//		Distance Min: 0
//		Distance Max: 30
//		Calculation min param: 0
//		Calculation max param: 10
//		Attack limit: 1
//		Elite weight: 5
//		Minion weight: 1
//		Big guy weight: 5
//		Goblin weight: 5
//		Normal monster weight: 1
//
//

Rune(Wizard_Teleport)==2&BuffTimeLeft(1,Wizard_Teleport)>4000
&(
(IsBuffActive(0,P68_ItemPassive_Unique_Ring_007)&BuffStackCount(1,Wizard_Passive_ArcaneDynamo)==0)
|BuffStackCount(7,Wizard_Hydra)==10
|((!IsBuffActive(0,ItemPassive_Unique_Ring_510_x1))&BuffStackCount(7,Wizard_Hydra)==5)
)

//\\----------------------------------------------------------------------------------------------------------------------------------------////


