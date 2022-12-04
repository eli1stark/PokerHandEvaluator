#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <phevaluator/phevaluator.h>

/*
 * This C code is a demonstration of how to calculate the card id, which will
 * be used as the parameter in the evaluator. It also shows how to use the
 * return value to determine which hand is the stronger one.
 */
int main()
{
	/*
	 * In this example we use a scenario in the game Texas Holdem:
	 * Community cards: 9c 4c 4s 9d 4h (both players share these cards)
	 * Player 1: Qc 6c
	 * Player 2: 2c 9h
	 *
	 * Both players have full houses, but player 1 has only a four full house
	 * while player 2 has a nine full house.
	 *
	 * The result is player 2 has a stronger hand than player 1.
	 */

	/*
	 * To calculate the value of each card, we can either use the Card Id
	 * mapping table, or use the formula rank * 4 + suit to get the value
	 *
	 * More specifically, the ranks are:
	 *
	 * deuce = 0, trey = 1, four = 2, five = 3, six = 4, seven = 5, eight = 6,
	 * nine = 7, ten = 8, jack = 9, queen = 10, king = 11, ace = 12.
	 *
	 * And the suits are:
	 * club = 0, diamond = 1, heart = 2, spade = 3
	 */
	// Community cards
	int a = 7 * 4 + 0; // 9c
	int b = 2 * 4 + 0; // 4c
	int c = 2 * 4 + 3; // 4s
	int d = 7 * 4 + 1; // 9d
	int e = 2 * 4 + 2; // 4h

	// Hole cards
	int f = 10 * 4 + 0; // Qc
	int g = 4 * 4 + 0;	// 6c
	int h = 0 * 4 + 0; // 2c
	int i = 7 * 4 + 2; // 9h

	// Evaluating the hand of player 1
	int rank1 = evaluate_7cards(a, b, c, d, e, f, g);
	// Evaluating the hand of player 2
	int rank2 = evaluate_7cards(a, b, c, d, e, h, i);
	// Evaluating the hand of player 3
	int rank3 = evaluate_5cards(f, c, d, i, e);
	// Evaluating the hand of player 4
	int rank4 = evaluate_6cards(f, g, h, i, e, d);

	assert(rank1 == 292);
	assert(rank2 == 236);
	assert(rank3 == 3064);
	assert(rank4 == 4553);

	printf("The rank of the hand in player 1 is %d\n", rank1); // expected 292
	printf("The rank of the hand in player 2 is %d\n", rank2); // expected 236
	printf("The rank of the hand in player 3 is %d\n", rank3); // expected 3064
	printf("The rank of the hand in player 4 is %d\n", rank4); // expected 4553
	
	return 0;
}
