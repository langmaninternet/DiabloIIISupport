#include "stdafx.h"
#include <Windows.h>
#include <Wingdi.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <list>
#include "Engine.h"
extern Win32GDI w32gdi;





#if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64) 
#pragma managed(push, off)
#pragma optimize("", off)
#pragma warning(push)
#pragma warning(disable : 4100)
#else
#pragma GCC push_options
#pragma GCC optimize ("O0")
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif

#include "Diablo3SkillDataCode"
#include "Diablo3RolDataCode"
#include "Diablo3ScreenDataCode"


#include "Diablo3Roll"

#include "Diablo3RollReduceDamage"
#include "Diablo3RollBaseDamage"
#include "Diablo3RollElementDamage"
#include "Diablo3RollCriticalHit"
#include "Diablo3RollAttackSpeed"
#include "Diablo3RollCooldown"
#include "Diablo3RollResourceCost"
#include "Diablo3RollAreaDamage"

#include "Diablo3RollLifePercent"
#include "Diablo3RollLifePerHit"
#include "Diablo3RollLifePerSecond"
#include "Diablo3RollLifePerKill"

#include "Diablo3RollResistance"
#include "Diablo3RollPercent"
#include "Diablo3RollSocket"
#include "Diablo3RollStats"
#include "Diablo3RollMovementSpeed"
#include "Diablo3RollThornDamage"
#include "Diablo3RollDemonHuner"


