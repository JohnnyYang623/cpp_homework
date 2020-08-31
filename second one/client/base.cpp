#include"base.h"

PokemonBase::PokemonBase()
{
	miss_base = 5;  grade_base = 1; exp_base = 0; interval_base = 2;
	offense_base = 6; defense_base = 6; speed_base = 6; health_base = 12;
	name = { "unknown" }; move1 = { "unknown" }; move2 = { "unknown" };
}


string PokemonBase::get_name()
{
	return name;
}