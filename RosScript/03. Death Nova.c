//Global Monter Scan 150
//Navigation Timeout 300


// #1. Simulacrum
// Buff
// 100ms
//
//#2 Bone Armor
//	Density + Buff
//	3000ms
//		Attack Distance: 30
//		Distance Min: 0
//		Distance Max: 30
//		Calculation min param: 0
//		Calculation max param: 30
//		Attack limit: 1 
//
//		Elite weight: 10
//		Minion weight: 3
//		Normal monster weight: 1
//		Big guy weight: 10
//		Goblin weight: 10
//
//


//#2 Bone Armor - Rebuff
// 	Force Recast
//	Density + Buff
//	1000ms
//		Attack Distance: 40
//		Distance Min: 0
//		Distance Max: 40
//		Calculation min param: 0
//		Calculation max param: 30
//		Attack limit: 10
//
//		Elite weight: 1
//		Minion weight: 1
//		Normal monster weight: 1
//		Big guy weight: 1
//		Goblin weight: 1
//
//
BuffStackCount(0,P6_Necro_BoneArmor)>0
&BuffStackCount(0,P6_Necro_BoneArmor)<8


//#3 Siphon Blood
// Do not use in fast mode
// Use to break item
// 50ms
// Resource Setting
//		Channelling 
//		Max Channelling Distance 25
//		Attack Distance: 25
//		Distance Min: 0
//		Distance Max: 25
//		Calculation min param: 0
//		Calculation max param: 25
//		Attack limit: 1 
//
//		Elite weight: 10
//		Minion weight: 3
//		Normal monster weight: 1
//		Big guy weight: 10
//		Goblin weight: 10
//
//



//#4 Blood Rush
//	Attack + Density
//	1000ms
//		Attack Distance: 90
//		Distance Min: 20
//		Distance Max: 90
//		Calculation min param: 0
//		Calculation max param: 30
//		Attack limit: 1 
//
//		Elite weight: 10
//		Minion weight: 0
//		Normal monster weight: 0
//		Big guy weight: 10
//		Goblin weight: 10
//
//
BuffStackCount(10,P6_Necro_SiphonBlood)<0


