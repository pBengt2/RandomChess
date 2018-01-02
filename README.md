# Random Chess

This is a fairly straightforward variation of chess my brother thought up. The idea is to allow a computer choose what type of piece you have to move next.

## Rules

The rules are nearly identical to regularly chess. There are only a few new special cases to be considered.
Here is what we decided on:
1. What if you cannot move the given piece?
 - You will reroll and be told a different piece to move.
2. Does checkmate win, or does the king need to be captured? 
 - The king must actually be captured.
3. What happens when you are in check?
 - You keep rerolling until you are given a piece that can get you out of check (with the exception of checkmate, in which case you move as normal).

## How to play

This is designed to be used along with a standard chess board. 
As it cannot read the state of the board, minimum information is entered.
(the rules are printed upon running the program)

If you can move the piece, enter 'y'. <= "(Y)es, I will move it"

If the piece can't be moved, enter 'n'. <= "(N)o, I cannot move it, tell me another piece"

If there are no remaining of the piece, enter 'e'. <= "that piece has been (e)liminated, no longer recommend it to me"

If a pawn becomes a queen, enter 'u'. <= "(U)pgrade my pawn, (ie if queen was eliminated, add it back)"

## How to run

Simply compile and run.

## Programming Environment

C++, Notepad++, Windows 7

## Author

Peter Bengtson

## Date Created

Febuary, 2017
