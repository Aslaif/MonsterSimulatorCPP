#pragma once

#include <string>

enum EMonster
{
	Goblin = 1, // has to be start
	Ork,
	Troll,		// has to be end of monsters
	AllTyps		// has to be end
};

//std::ostream& operator<<(std::ostream& out, const EMonster value) {
//    return out << [value] {
//#define PROCESS_VAL(p) case(p): return #p;
//        switch (value) {
//            PROCESS_VAL(Goblin);
//            PROCESS_VAL(Ork);
//            PROCESS_VAL(Troll);
//        }
//#undef PROCESS_VAL
//        };
//}