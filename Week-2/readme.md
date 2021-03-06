## I N T R O D U C T I O N
The Eight Queens problem is a chess puzzle, first devised by the chess composer Max Bezzel in 1848.
Can you place 8 queens on an 8 x 8 chess board so that no queen threatens another? How many ways can this
be done?
For now, we’re going to concentrate solely on finding a single solution.
Why? A little practice thinking about algorithms before we move on to more complex issues.

## T H I N K I N G A B O U T T H E A L G O R I T H M
Sometimes it helps to reduce the problem to its smallest example.
What if we had a board with one cell that needs one queen?
Interestingly, a 2 x 2 board with 2 queens can’t work, and the same problem applies to 3 x 3 with 3 queens.
After that, we’re fine.
Those are all the options you have for the 2 and 3 Queens problems. Any other starting point or next step is
just a rotation and/or reflection of those.

## G E N E R A L I S A T I O N
So we have generalised the problem to n queens on an n x n board.
This is good for two reasons:
Reason 1
• Often problems belong to a "class".
• Any given instance of a problem probably has very specific constraints.
• In our case, it was the size of the board and the rules for the piece given.
• You might be able to solve the given problem within those constraints without generalising, but you will have
done it by writing code that you might never use again.
• If you generalised, you might have something that can be used to solve other problems. The eight queens
problem is probably not the most useful, but imagine this with sorting algorithms, route finding, etc.
Reason 2
• A problem can be made easier to fathom if you work out which parts can be altered in such a way that the
principle for solving the problem stays the same, but the complexity of the current case is lower.
• The "four queens" problem is a good example of that. It was easy to solve that one and we can now use this
to help us work out the general strategy.

## A L G O R I T H M 
What we would do as humans, is to try our solution and if it doesn’t work, go back a step and try the
alternatives. If they don’t work, go back a step further and try the alternatives there.
Let’s think about how that might work. . .
• So our base case is: If all rows have been done, finish.
• And our recursive case is:
– if you have a cell that a queen can be placed in that has not already been checked, place a queen and then
examine the next row.
– if all cells that could have a queen have been checked, go back a row to try a different cell. This is called
backtracking.
