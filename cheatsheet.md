1. Modulo Class Invariant
What: Remainder x % k stays the same when adding/subtracting multiples of k.

Example: If you can add/subtract 5 from any element, (x % 5) never changes.

Usage: Match remainder counts between initial and target arrays.

2. Parity of Numbers
What: Odd/even status stays fixed or changes predictably.

Example: Adding an even number doesn’t change parity.

Usage: If goal requires odd but all numbers are even — impossible.

3. Sum Invariant
What: Sum of all elements stays constant.

Example: Replace a with a-1 and b with b+1 → sum unchanged.

Usage: If sums differ between start and target — impossible.

4. Sum of Squares / Energy Invariant
What: Sum of squares of values stays fixed.

Example: Swapping balls between buckets preserves sum and sum of squares.

Usage: Physics-like or distance-like constraints.

5. GCD Invariant
What: GCD of all numbers stays constant.

Example: Operation: a = |a - b| doesn’t change GCD.

Usage: If final state’s GCD ≠ starting GCD — impossible.

6. Sorted Order Invariant
What: Sorted arrangement is fixed unless swapping allowed.

Example: Rotation of array keeps cyclic order same.

Usage: Compare sorted forms to check possibility.

7. Multiset Equality Invariant
What: Only rearranging elements doesn’t change multiset content.

Example: Reversing array keeps same multiset.

8. XOR Invariant
What: XOR of all numbers stays fixed under certain moves.

Example: In Nim games, a ^= b type moves change numbers but not XOR sum in some cases.

Usage: Key in bitwise puzzles.

9. Bitwise “One-way” Invariant
What: Certain bits can only turn off (AND) or on (OR).

Example: If only OR allowed, 0-bits can only flip to 1, never back.

Usage: Check final bits feasibility.

10. Graph Connectivity Invariant
What: Connectivity doesn’t decrease if edges only added.

Example: Once connected, stays connected.

Usage: Graph reachability problems.

11. Component Count Monovariant
What: Number of connected components decreases or increases monotonically.

Example: Adding edges reduces components; removing increases.

12. Inversion Count Monovariant
What: Inversions in an array always decrease when swapping adjacent out-of-order pairs.

Example: Bubble sort terminates because inversions drop to 0.

13. Chessboard Coloring Invariant
What: Some moves keep you on same color, others change color.

Example: Rook → same color, Knight → alternate color.

Usage: Grid movement reachability.

14. Manhattan Distance Monovariant
What: If you can only move closer to a point, |x1 - x2| + |y1 - y2| decreases.

Usage: Proves you must stop.

15. Euclidean Distance Monovariant
What: If a move always shortens distance, termination guaranteed.

16. Degree Sequence Invariant
What: Graph edge changes preserve sum of degrees (2 * edges).

Usage: Check if target degree sequence possible.

17. Mod Sum Invariant
What: (sum of elements) % k doesn’t change under certain moves.

Example: Adding k to any element changes sum by multiple of k.

18. Carry Invariant in Base Conversion
What: Certain digit-sum modulo (mod 9) stays constant.

Example: Sum of digits mod 9 invariant when rearranging digits.

19. Alternating Sum Invariant
What: (a1 - a2 + a3 - a4 + ...) stays same in alternating swap problems.

20. Min/Max Bound Monovariant
What: Minimum or maximum value moves monotonically toward a bound.

Usage: Detect infinite loops vs guaranteed finish.

21. Cycle Length Invariant
What: Permutations preserve cycle structure length sum = n.

Usage: Problems with shuffling cards or elements.

