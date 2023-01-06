#pragma once

/* Class Enum Bonus used to list the different interaction */
enum Bonus
{
	/* Add damage to the target */
	DAMAGE_BOOST,
	/* Reduce the damage of the target */
	DAMAGE_MALUS,
	/* Do the damage only on the player */
	DAMAGE_ON_PLAYER,
	/* Add mana to the target */
	MANA_BOOST,
	/* Draw some card */
	DRAW_CARDS
};
