#ifndef TOWER_BUILDER_H
#define TOWER_BUILDER_H



enum class Tower {
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE
};

void CleanupTower();

void BuildTower_Queue(Tower tower);

void BuildTower_Construct(Tower tower);

#endif