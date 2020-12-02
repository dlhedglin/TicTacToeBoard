/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName)
{
	ASSERT_TRUE(true);
}
*/
TEST(TicTacToeBoardTest, ToggleTurnX)
{
	TicTacToeBoard t;
	ASSERT_EQ(t.toggleTurn(), O);
}
TEST(TicTacToeBoardTest, ToggleTurnO)
{
	TicTacToeBoard t;
	t.toggleTurn();
	ASSERT_EQ(t.toggleTurn(), X);
}
TEST(TicTacToeBoardTest, placeInvalid)
{
	TicTacToeBoard t;

	ASSERT_EQ(t.placePiece(10,10), Invalid);
}
TEST(TicTacToeBoardTest, place)
{
	TicTacToeBoard t;

	ASSERT_EQ(t.placePiece(0,0), X);
}

TEST(TicTacToeBoardTest, placeOverlap)
{
	TicTacToeBoard t;
	t.placePiece(0,0);
	ASSERT_EQ(t.placePiece(0,0), X);
}

TEST(TicTacToeBoardTest, getInvalid)
{
	TicTacToeBoard t;

	ASSERT_EQ(t.getPiece(10,10), Invalid);
}

TEST(TicTacToeBoardTest, get)
{
	TicTacToeBoard t;
	t.placePiece(0,0);
	ASSERT_EQ(t.getPiece(0,0), X);
}
TEST(TicTacToeBoardTest, winner)
{
	TicTacToeBoard t;
	t.placePiece(0,0);
	t.toggleTurn();
	t.placePiece(1,1);
	t.toggleTurn();
	t.placePiece(2,2);
	ASSERT_EQ(t.getWinner(), X);
}

TEST(TicTacToeBoardTest, winnerInvalid)
{
	TicTacToeBoard t;
	ASSERT_EQ(t.getWinner(), Invalid);
}