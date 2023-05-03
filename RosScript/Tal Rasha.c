



/************************************************************************/
/* Refer monster positive density                                       */
/*                                                                      */
/*  Elite weight: 5                                                     */
/*  Minion weight: 1                                                    */
/*  Big guy weight: 5                                                   */
/*  Goblin weight: 1                                                    */
/*  Normal monster weight: 1                                            */
/*                                                                      */
/************************************************************************/




/************************************************************************/
/* Refer monster negative density                                       */
/*                                                                      */
/*  Elite weight: -5                                                     */
/*  Minion weight: -3                                                    */
/*  Big guy weight: -5                                                   */
/*  Goblin weight: 0                                                    */
/*  Normal monster weight: -3                                            */
/*                                                                      */
/************************************************************************/










////----------------------------------------------------------------------------------------------------------------------------------------\\\\
//	Teleport [Safe Passage|Calamity] - Safe in 5 yards - Just in Time [Prepare CoE Cycle]
//	Teleport [Safe Passage|Calamity] - Safe in 10 yards - Just in Time [Prepare CoE Cycle]
//	Teleport [Safe Passage|Calamity] - Safe in 15 yards - Just in Time [Prepare CoE Cycle]
//	Teleport [Safe Passage|Calamity] - Safe in 20 yards - Just in Time [Prepare CoE Cycle]
//
//		Distance Min: 0
//		Distance Max: ***
//		Calculation min param: -100
//		Calculation max param: 10
//		Attack limit: -10 for 5 yards, -20 for 10 yards, -30 for 15 yards, -40 for 15 yards, 
//		Elite weight: -5
//		Minion weight: -3
//		Big guy weight: -5
//		Goblin weight: 0
//		Normal monster weight: -3
//
//
//
//
//
//
//
//	Teleport [Safe Passage|Calamity] - Near 5 yards - Just in Time [Prepare CoE Cycle]
//	Teleport [Safe Passage|Calamity] - Near 10 yards - Just in Time [Prepare CoE Cycle]
//	Teleport [Safe Passage|Calamity] - Near 15 yards - Just in Time [Prepare CoE Cycle]
//	Teleport [Safe Passage|Calamity] - Near 20 yards - Just in Time [Prepare CoE Cycle]
//	Teleport [Safe Passage|Calamity] - Near 25 yards - Just in Time [Prepare CoE Cycle]
//
//		Distance Min: 0
//		Distance Max: ***
//		Calculation min param: 0
//		Calculation max param: 10
//		Attack limit: 1
//		Elite weight: 5
//		Minion weight: 1
//		Big guy weight: 5
//		Goblin weight: 1
//		Normal monster weight: 1



((Rune(Wizard_Teleport)==2&BuffTimeLeft(1,Wizard_Teleport)<4000&BuffTimeLeft(0,Pages_Buff_Invulnerable)<6000)
|(Rune(Wizard_Teleport)==0&IsBuffActive(0,P2_ItemPassive_Unique_Ring_028)&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_028)<4000))
&
((Rune(Wizard_Meteor)==0&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1000&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)
|(Rune(Wizard_Meteor)==1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1000&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)
|(Rune(Wizard_Meteor)==2&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1000&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<3000)
|(Rune(Wizard_Meteor)==3&BuffTimeLeft(6,P2_ItemPassive_Unique_Ring_038)>1000&BuffTimeLeft(6,P2_ItemPassive_Unique_Ring_038)<3000)
|(Rune(Wizard_Meteor)==4&BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1000&BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)<3000))
&
(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)

//\\----------------------------------------------------------------------------------------------------------------------------------------////



























//----------------------------------------------------------------------------------------------------------------------------------------
//	Teleport [Safe Passage|Calamity] - Safe in 5 yards - On [Wait for CoE Cycle]
//	Teleport [Safe Passage|Calamity] - Safe in 10 yards - On [Wait for CoE Cycle]
//	Teleport [Safe Passage|Calamity] - Safe in 15 yards - On [Wait for CoE Cycle]
//	Teleport [Safe Passage|Calamity] - Safe in 20 yards - On [Wait for CoE Cycle]
//
//	Teleport [Safe Passage|Calamity] - Near 5 yards - On [Wait for CoE Cycle]
//	Teleport [Safe Passage|Calamity] - Near 10 yards - On [Wait for CoE Cycle]
//	Teleport [Safe Passage|Calamity] - Near 15 yards - On [Wait for CoE Cycle]
//	Teleport [Safe Passage|Calamity] - Near 20 yards - On [Wait for CoE Cycle]

((Rune(Wizard_Teleport)==2&BuffTimeLeft(1,Wizard_Teleport)<1000&BuffTimeLeft(0,Pages_Buff_Invulnerable)<5000)
|(Rune(Wizard_Teleport)==0&IsBuffActive(0,P2_ItemPassive_Unique_Ring_028)&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_028)<1000))
&
((Rune(Wizard_Meteor)==0&(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>0))
|(Rune(Wizard_Meteor)==1&(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>0))
|(Rune(Wizard_Meteor)==2&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>0))
|(Rune(Wizard_Meteor)==3&(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>0))
|(Rune(Wizard_Meteor)==4&(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>0)))
&
(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)

//\\----------------------------------------------------------------------------------------------------------------------------------------////











//----------------------------------------------------------------------------------------------------------------------------------------
// Teleport [Calamity] - Near 25 yards - Proc [Tal Rasha's Elements - Arcane] - Just in Time [Prepare CoE Cycle]
// Teleport [Calamity] - Near 30 yards - Proc [Tal Rasha's Elements - Arcane] - Just in Time [Prepare CoE Cycle]

Rune(Wizard_Teleport)==0&IsBuffActive(0,P2_ItemPassive_Unique_Ring_028)&BuffStackCount(5, P2_ItemPassive_Unique_Ring_028)<4&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_028)<2000
&
((Rune(Wizard_Meteor)==0&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1000&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)
|(Rune(Wizard_Meteor)==1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1000&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)
|(Rune(Wizard_Meteor)==2&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1000&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<3000)
|(Rune(Wizard_Meteor)==3&BuffTimeLeft(6,P2_ItemPassive_Unique_Ring_038)>1000&BuffTimeLeft(6,P2_ItemPassive_Unique_Ring_038)<3000)
|(Rune(Wizard_Meteor)==4&BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1000&BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)<3000))
&
(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)

//\\----------------------------------------------------------------------------------------------------------------------------------------////













//----------------------------------------------------------------------------------------------------------------------------------------
//	Rift Guardian - Meteor - On [CoE Cycle] or [Oculus] or [Power] or [Triune of Love]
//  Elite - Meteor - On [CoE Cycle] or [Oculus] or [Power] or [Triune of Love] - 10 yards Cycle 500ms
//  Elite - Meteor - On [CoE Cycle] or [Oculus] or [Power] or [Triune of Love] - 30 yards Cycle 250ms
//  Elite - Meteor - On [CoE Cycle] or [Oculus] or [Power] or [Triune of Love] - 50 yards Cycle 50ms
//  Battle - Meteor - On [CoE Cycle] or [Oculus] or [Power] or [Triune of Love]

((Rune(Wizard_Meteor)==0&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==1&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==2&(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==3&(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==4&(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1000|(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)<1250)))
|IsBuffActive(2,ItemPassive_Unique_Ring_922_x1)
|IsBuffActive(0,Pages_Buff_Damage)
|BuffTimeLeft(2,Community_Buff_DarkAlchemy)>0
)
&
(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)

//\\----------------------------------------------------------------------------------------------------------------------------------------////











//----------------------------------------------------------------------------------------------------------------------------------------
//	Elite - Meteor - On [Wait for CoE Cycle] - 10 yards Cycle 1000ms
//	Elite - Meteor - On [Wait for CoE Cycle] - 30 yards Cycle 2000ms
//	Elite - Meteor - On [Wait for CoE Cycle] - 50 yards Cycle 3000ms

((Rune(Wizard_Meteor)==0&(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>0))
|(Rune(Wizard_Meteor)==1&(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>0))
|(Rune(Wizard_Meteor)==2&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>0))
|(Rune(Wizard_Meteor)==3&(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>0))
|(Rune(Wizard_Meteor)==4&(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>0)))
&
(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)

//\\----------------------------------------------------------------------------------------------------------------------------------------////














//----------------------------------------------------------------------------------------------------------------------------------------
//	Elite - Meteor - 5 yard 10 Monster Cycle 100ms
//	Elite - Meteor - 10 yard 20 Monster Cycle 100ms
//
//	Elite - Meteor - In 30 yards Cycle 100ms
//	Elite - Meteor - 3x yards Cycle 100ms
//	Elite - Meteor - 4x yards Cycle 500ms
//	Elite - Meteor - 5x yards Cycle 1000ms
//
//	Health 40% - Meteor - Near 5 yards 50ms
//	Health 50% - Meteor - Near 10 yards 100ms
//	Health 60% - Meteor - Near 15 yards 150ms
//	Health 70% - Meteor - Near 20 yards 200ms

(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)

//\\----------------------------------------------------------------------------------------------------------------------------------------////












//----------------------------------------------------------------------------------------------------------------------------------------
// Maintain [Tal Rasha's Elements] - Meteor - Near 10 yards
// Maintain [Tal Rasha's Elements] - Meteor - Near 20 yards
// Maintain [Tal Rasha's Elements] - Meteor - Near 30 yards

BuffStackCount(5, P2_ItemPassive_Unique_Ring_028)==4
&
((Rune(Wizard_Meteor)==0&BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_028)<2000)
|(Rune(Wizard_Meteor)==1&BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_028)<2000)
|(Rune(Wizard_Meteor)==2&BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_028)<2000)
|(Rune(Wizard_Meteor)==3&BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_028)<2000)
|(Rune(Wizard_Meteor)==4&BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_028)<2000)
)

//----------------------------------------------------------------------------------------------------------------------------------------//











//----------------------------------------------------------------------------------------------------------------------------------------
// Meteor - On [CoE Cycle + Power|Conduit|Oculus|Triune of Love]

((Rune(Wizard_Meteor)==0&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==1&(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==2&(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==3&(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1500|(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)<3000)))
|(Rune(Wizard_Meteor)==4&(BuffTimeLeft(5,P2_ItemPassive_Unique_Ring_038)>1000|(BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)>1&BuffTimeLeft(3,P2_ItemPassive_Unique_Ring_038)<1250))))
&
(IsBuffActive(0,Pages_Buff_Damage)
|IsBuffActive(0,Pages_Buff_Electrified_TieredRift)
|IsBuffActive(2,ItemPassive_Unique_Ring_922_x1)
|BuffTimeLeft(2,Community_Buff_DarkAlchemy)>0)
&
(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)

//----------------------------------------------------------------------------------------------------------------------------------------//





















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


















Meteor - On [Power + Conduit] - 25 yards Cycle 50ms





//----------------------------------------------------------------------------------------------------------------------------------------
// Meteor - On [Power + Conduit|Oculus|Triune of Love]

IsBuffActive(0,Pages_Buff_Damage)
&
(IsBuffActive(0,Pages_Buff_Electrified_TieredRift)
|IsBuffActive(2,ItemPassive_Unique_Ring_922_x1)
|BuffTimeLeft(2,Community_Buff_DarkAlchemy)>0)
&
(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)

//----------------------------------------------------------------------------------------------------------------------------------------//







//		1. Arcane
//		2. Cold
//		3. Fire
//		4. Holy
//		5. Lightning
//		6. Physical
//		7. Poison
//		Wizard : Cold -> Fire -> Lightning -> Arcane -> Cold -> Fire -> Lightning -> Arcane
//		Wizard : 2 -> 3 -> 5 -> 1 -> 2 -> 3 -> 5 -> 1


//Meteor Fire
Rune(Wizard_Meteor)==0
Rune(Wizard_Meteor)==1

//Meteor Cold
Rune(Wizard_Meteor)==2

//Meteor Arcane
Rune(Wizard_Meteor)==3

//Meteor Lightning
Rune(Wizard_Meteor)==4




Buff, 		1, 		0, 			P2_ItemPassive_Unique_Ring_028, Tal Rasha's Elements
Buff, 		1, 		0, 			P2_ItemPassive_Unique_Ring_036,



//Cold
Buff, 		1, 		5, 			P2_ItemPassive_Unique_Ring_028, Tal Rasha's Elements
Buff, 		1, 		2, 			P2_ItemPassive_Unique_Ring_028, Tal Rasha's Elements
EndTick, 	426, 		5, 			P2_ItemPassive_Unique_Ring_028, Tal Rasha's Elements
EndTick, 	426, 		2, 			P2_ItemPassive_Unique_Ring_028, Tal Rasha's Elements
Buff, 		1, 		0, 			P2_ItemPassive_Unique_Ring_028, Tal Rasha's Elements


//Arcane
Buff, 		1, 		5, 			P2_ItemPassive_Unique_Ring_028, Tal Rasha's Elements
Buff, 		1, 		1, 			P2_ItemPassive_Unique_Ring_028, Tal Rasha's Elements
EndTick, 	419, 		5, 			P2_ItemPassive_Unique_Ring_028, Tal Rasha's Elements
EndTick, 	419, 		1, 			P2_ItemPassive_Unique_Ring_028, Tal Rasha's Elements
Buff, 		1, 		0, 			P2_ItemPassive_Unique_Ring_028, Tal Rasha's Elements



//Cold +fire
Buff, 		2, 		5, 			P2_ItemPassive_Unique_Ring_028, Tal Rasha's Elements
Buff, 		1, 		3, 			P2_ItemPassive_Unique_Ring_028, Tal Rasha's Elements
Buff, 		1, 		2, 			P2_ItemPassive_Unique_Ring_028, Tal Rasha's Elements
EndTick, 	436, 		5, 			P2_ItemPassive_Unique_Ring_028, Tal Rasha's Elements
EndTick, 	436, 		3, 			P2_ItemPassive_Unique_Ring_028, Tal Rasha's Elements
EndTick, 	430, 		2, 			P2_ItemPassive_Unique_Ring_028, Tal Rasha's Elements
Buff, 		1, 		0, 			P2_ItemPassive_Unique_Ring_028, Tal Rasha's Elements



//Cold + Lightning
Buff, 		2, 		5, 			P2_ItemPassive_Unique_Ring_028, Tal Rasha's Elements
Buff, 		1, 		4, 			P2_ItemPassive_Unique_Ring_028, Tal Rasha's Elements
Buff, 		1, 		2, 			P2_ItemPassive_Unique_Ring_028, Tal Rasha's Elements






Meteor - On [CoE Cold Cycle + Power] + Already Buff
Meteor - On [CoE Cold Cycle + Conduit] + Already Buff
Rune(Wizard_Meteor) == 2
& (BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>2000 |(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1 & BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<1000))
& IsBuffActive(0,Pages_Buff_Electrified_TieredRift)
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)
Meteor - On [CoE Cold Cycle + Oculus] + Already Buff






















Teleport - Proc [Tal Rasha]
BuffStackCount(5, P2_ItemPassive_Unique_Ring_028) ==3




Meteor - Buff - Near - Waiting [Teleport] + Already Buff
Cooldown(Wizard_Teleport) > 1550 & (BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)





Meteor - Elite - Main - Already Buff
Elite - Meteor - [30-45 yards]
Meteor - Elite - Cycle 1000ms + Already Buff




Meteor - On [CoE Cold Cycle]
Rune(Wizard_Meteor) == 2
&(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>2000 |(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1 & BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<1000))
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)







Teleport [Safe Passage] - Near 5 yards - On [Wait for CoE Cold Cycle]
Teleport [Safe Passage] - Near 10 yards - On [Wait for CoE Cold Cycle]
Teleport [Safe Passage] - Near 15 yards - On [Wait for CoE Cold Cycle]
Teleport [Safe Passage] - Near 20 yards - On [Wait for CoE Cold Cycle]
Rune(Wizard_Meteor)==2 & Rune(Wizard_Teleport)==2 & BuffTimeLeft(1,Wizard_Teleport)<400
&(BuffTimeLeft(3, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(4, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(5, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(6, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(7, P2_ItemPassive_Unique_Ring_038)>0)
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)





Meteor - On [CoE Cold Cycle + Power] + Already Buff

BuffStackCount(5, P2_ItemPassive_Unique_Ring_028) ==3


Meteor - On [CoE Cold Cycle + Proc Enchantress Cheat Death] + Already Buff
BuffTimeLeft(1,Enchantress_CheatDeath_Passive)>0 & Rune(Wizard_Meteor) == 2
&(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>2000 |(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1 & BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<1000))
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)




Teleport - Proc [Enchantress Cheat Death] + HP 60%
Rune(Wizard_Teleport) == 2 & BuffTimeLeft(1,Enchantress_CheatDeath_Passive)>0 & BuffTimeLeft(1,Wizard_Teleport)<1000
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)





Meteor - Rift Guardian [0-60 yards] - On [CoE Cold Cycle] + Already Buff + HP 99%
Rune(Wizard_Meteor) == 2
&(BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>2000 |(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1 & BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<1000))
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)



Teleport [Safe Passage] - Near 5 yards - Just in Time [Prepare CoE Cold Cycle]
Rune(Wizard_Meteor) == 2 & Rune(Wizard_Teleport) == 2 & BuffTimeLeft(1,Wizard_Teleport)<4000
& BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1000 & BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<3000
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)





Teleport - Best position in 5 yards - Just in Time [Prepare CoE Cold Cycle]
Rune(Wizard_Meteor) == 2 & BuffTimeLeft(1,Wizard_Teleport)<4000
& BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1000 & BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<3000
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)




Teleport - Best position in 5 yards - On [Wait for CoE Cold Cycle]
Rune(Wizard_Meteor) == 2 & BuffTimeLeft(1,Wizard_Teleport)<400
&(BuffTimeLeft(3, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(4, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(5, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(6, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(7, P2_ItemPassive_Unique_Ring_038)>0)
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)




Elite - Teleport [Safe Passage] - Near 5 yards - On [Wait for CoE Cold Cycle]
Rune(Wizard_Meteor) == 2 & Rune(Wizard_Teleport) == 2
&(BuffTimeLeft(3, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(4, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(5, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(6, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(7, P2_ItemPassive_Unique_Ring_038)>0)
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)




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

&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)




BuffTimeLeft(4,X1_DemonHunter_Vengeance)>1000


DemonHunter


(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)



Health() < 40%


Health() > 2%







On [Invisible after death]
(BuffTimeLeft(0,Wizard_Familiar)==0&BuffTimeLeft(0,Wizard_MagicWeapon)==0&BuffTimeLeft(3,Wizard_StormArmor)==0)



Already Buff
(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)




Meteor - Rift Guardian - On [CoE Cold Cycle] + Already Buff
Rune(Wizard_Meteor) == 2 & (BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>2000 |(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1 & BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<1000))
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)




Meteor - Rift Guardian - On [Oculus] + Already Buff
BuffTimeLeft(0,ItemPassive_Unique_Ring_922_x1)>0 & BuffTimeLeft(2,ItemPassive_Unique_Ring_922_x1)>0 & BuffTimeLeft(3,ItemPassive_Unique_Ring_922_x1)>0
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)



Meteor - Elite - On [Oculus] + Already Buff
BuffTimeLeft(0,ItemPassive_Unique_Ring_922_x1)>0 & BuffTimeLeft(2,ItemPassive_Unique_Ring_922_x1)>0 & BuffTimeLeft(3,ItemPassive_Unique_Ring_922_x1)>0
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)



Meteor - Elite - On [CoE Cold Cycle] + Already Buff
Rune(Wizard_Meteor) == 2 & (BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>2000 |(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1 & BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<1000))
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)



Meteor - Rift Guardian - Already Buff
(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)


Meteor - Elite - Main - Already Buff
(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)


Meteor - Elite - On [Power] or [Conduit] + Already Buff
(IsBuffActive(0, Pages_Buff_Damage) | IsBuffActive(0, Pages_Buff_Electrified_TieredRift))
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)





Meteor - On [Power + Infinite Casting] + Already Buff
IsBuffActive(0, Pages_Buff_Infinite_Casting) & IsBuffActive(0, Pages_Buff_Damage)
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)




Meteor - On [Power + Conduit] + Already Buff
IsBuffActive(0, Pages_Buff_Electrified_TieredRift) & IsBuffActive(0, Pages_Buff_Damage)
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)



Meteor - On [CoE Cold Cycle + Power] + Already Buff
Rune(Wizard_Meteor) == 2 & (BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>2000 |(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1 & BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<1000)) & IsBuffActive(0, Pages_Buff_Damage)
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)



Meteor - On [CoE Cold Cycle + Conduit] + Already Buff



Rune(Wizard_Meteor) == 2 & (BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>2000 |(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1 & BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<1000)) & IsBuffActive(0, Pages_Buff_Electrified_TieredRift)
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)






Meteor - On [CoE Cold Cycle + Oculus] + Already Buff
Rune(Wizard_Meteor) == 2 & (BuffTimeLeft(2,P2_ItemPassive_Unique_Ring_038)>2000 |(BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)>1 & BuffTimeLeft(1,P2_ItemPassive_Unique_Ring_038)<1000)) & BuffTimeLeft(0,ItemPassive_Unique_Ring_922_x1)>0 & BuffTimeLeft(2,ItemPassive_Unique_Ring_922_x1)>0 & BuffTimeLeft(3,ItemPassive_Unique_Ring_922_x1)>0
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)




Meteor - Proc [Tal Rasha] + Already Buff
BuffStackCount(5, P2_ItemPassive_Unique_Ring_028) < 3
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)






Meteor - Elite - Near Cycle 2000ms - On [CoE Fire Holy Lightning Physical Poison Cycle] + Already Buff

Rune(Wizard_Meteor) == 2 & (BuffTimeLeft(3, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(4, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(5, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(6, P2_ItemPassive_Unique_Ring_038)>0|BuffTimeLeft(7, P2_ItemPassive_Unique_Ring_038)>0)
&(BuffTimeLeft(0,Wizard_Familiar)>1000|BuffTimeLeft(0,Wizard_MagicWeapon)>1000|BuffTimeLeft(3,Wizard_StormArmor)>1000)


Meteor - Elite - Near Cycle 500ms - On [CoE Cold Cycle] + Already Buff



