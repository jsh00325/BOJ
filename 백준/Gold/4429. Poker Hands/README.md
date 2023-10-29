# [Gold IV] Poker Hands - 4429 

[문제 링크](https://www.acmicpc.net/problem/4429) 

### 성능 요약

메모리: 2032 KB, 시간: 0 ms

### 분류

많은 조건 분기, 구현

### 제출 일자

2023년 10월 30일 00:12:50

### 문제 설명

<p>A poker deck contains 52 cards - each card has a suit which is one of clubs, diamonds, hearts, or spades (denoted C, D, H, S in the input data). Each card also has a value which is one of 2, 3, 4, 5, 6, 7, 8, 9, 10, jack, queen, king, ace (denoted 2, 3, 4, 5, 6, 7, 8, 9, T, J, Q, K, A). For scoring purposes, the suits are unordered while the values are ordered as given above, with 2 being the lowest and ace the highest value.</p>

<p>A poker hand consists of 5 cards dealt from the deck. Poker hands are ranked by the following partial order from lowest to highest</p>

<ul>
	<li>High Card. Hands which do not fit any higher category are ranked by the value of their highest card. If the highest cards have the same value, the hands are ranked by the next highest, and so on.</li>
	<li>Pair. 2 of the 5 cards in the hand have the same value. Hands which both contain a pair are ranked by the value of the cards forming the pair. If these values are the same, the hands are ranked by the values of the cards not forming the pair, in decreasing order.</li>
	<li>Two Pairs. The hand contains 2 different pairs. Hands which both contain 2 pairs are ranked by the value of their highest pair. Hands with the same highest pair are ranked by the value of their other pair. If these values are the same the hands are ranked by the value of the remaining card.</li>
	<li>Three of a Kind. Three of the cards in the hand have the same value. Hands which both contain three of a kind are ranked by the value of the 3 cards.</li>
	<li>Straight. Hand contains 5 cards with consecutive values. Hands which both contain a straight are ranked by their highest card.</li>
	<li>Flush. Hand contains 5 cards of the same suit. Hands which are both flushes are ranked using the rules for High Card.</li>
	<li>Full House. 3 cards of the same value, with the remaining 2 cards forming a pair. Ranked by the value of the 3 cards.</li>
	<li>Four of a kind. 4 cards with the same value. Ranked by the value of the 4 cards.</li>
	<li>Straight flush. 5 cards of the same suit with consecutive values. Ranked by the highest card in the hand.</li>
</ul>

<p>Your job is to compare several pairs of poker hands and to indicate which, if either, has a higher rank.</p>

### 입력 

 <p>Several lines, each containing the designation of 10 cards: the first 5 cards are the hand for the player named "Black" and the next 5 cards are the hand for the player named "White."</p>

### 출력 

 <p>For each line of input, print a line containing one of:</p>

<pre>Black wins.
White wins.
Tie.
</pre>

