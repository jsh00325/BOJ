# [Platinum V] Gnoll Hypothesis - 18086 

[문제 링크](https://www.acmicpc.net/problem/18086) 

### 성능 요약

메모리: 2028 KB, 시간: 0 ms

### 분류

조합론, 기댓값의 선형성, 수학, 확률론

### 문제 설명

<p>You are a huge fan of the RPG <em>The Eldest Scrolls: Earthrim</em> and know all of the game’s internal mechanics. For instance, when spawning a new monster, each of the n different types of monsters in the game has some fixed probability of appearing, and you know exactly what this probability distribution over monster types is.</p>

<p>However, in the latest update the developers seem to have changed the way monsters are spawned. After some testing and reverse engineering, you realise that instead of spawning all n types of monsters, each spawn location only has a spawn pool of k monster types. These spawn pools are chosen randomly at the start of the game, independently for each spawn location, with every monster type having the same chance of being chosen for the spawn pool. And apparently a developer was lazy with adjusting the spawn chances. Instead of normalising the spawn chances of the k chosen types, the developer decided that if a type of monster is not chosen, its spawn chance is added to the next chosen monster type in the list of types (and if monster types at the end of the list are not chosen, their spawn chances are added to the first chosen monster type in the list). For example, Figure G.1 shows a small example with n = 5 monsters, a possible random choice of k = 3 of those monsters, and the resulting spawn probabilities for those 3 monsters.</p>

<p>After the update, some monster types seem to appear less often than before, and some more often (for instance now there seem to be Gnolls all over the place). You believe that the new spawning logic may be responsible for this by having changed the effective spawn chances of the monsters. In order to test this hypothesis, you decide to compute these effective spawn chances after the update.</p>

<p style="text-align: center;"><img alt="" src="" style="width: 254px; height: 126px;"></p>

<p style="text-align: center;">Figure G.1: Sample Input 1 and one possible spawn pool with adjusted spawn chances.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with two integers n and k (1 ≤ k ≤ n ≤ 500), the number of different types of monsters and the number of monsters that are randomly chosen for the spawn pool of each spawn location.</li>
	<li>One line with n real numbers s<sub>1</sub>, s<sub>2</sub>, . . . , s<sub>n</sub> (s<sub>i</sub> ≥ 0 for each i, Σs<sub>j</sub> = 100), where si is the spawn chance in percent for the ith type in the list of monster types. Every real number has at most six digits after the decimal point.</li>
</ul>

### 출력 

 <p>Output a single line containing n real numbers, the effective spawn chance in percent of each type of monster. The ith number in your output should correspond to the ith type of monster. Your answers should have an absolute or relative error of at most 10<sup>−6</sup>.</p>

