
// #1. Simulacrum
// Buff
// 100ms





//#2 Blood Rush
//	Attack + Density
//	5000ms
//		Attack Distance: 60
//		Distance Min: 0
//		Distance Max: 60
//		Calculation min param: 0
//		Calculation max param: 30
//		Attack limit: 1 
//
//		Elite weight: 10
//		Minion weight: 3
//		Normal monster weight: 0
//		Big guy weight: 10
//		Goblin weight: 10
//
//
BuffStackCount(0,P6_Necro_BoneArmor)<5

//#3 Bone Armor
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
BuffStackCount(0,P6_Necro_BoneArmor)<10
|BuffTimeLeft(0,P6_Necro_BoneArmor)<1


//#4 Siphon Blood
// Do not use in fast mode
// Use to break item
// 50ms
// Resource Setting
//		Channelling 
//		Max Channelling Distance 20
//		Attack Distance: 20
//		Distance Min: 0
//		Distance Max: 20
//		Calculation min param: 0
//		Calculation max param: 20
//		Attack limit: 1 
//
//		Elite weight: 10
//		Minion weight: 3
//		Normal monster weight: 1
//		Big guy weight: 10
//		Goblin weight: 10
//
//

