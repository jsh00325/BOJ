# [Gold II] Vepar - 20661 

[문제 링크](https://www.acmicpc.net/problem/20661) 

### 성능 요약

메모리: 18060 KB, 시간: 116 ms

### 분류

수학, 정수론, 소수 판정, 에라토스테네스의 체

### 제출 일자

2024년 2월 12일 21:16:27

### 문제 설명

<p>Two intervals of positive integers {a, a + 1, . . . , b} and {c, c + 1, . . . , d} are given. Determine whether the product c·(c+1)· · · d is divisible by the product a·(a+1)· · · b.</p>

### 입력 

 <p>The first line contains a single integer t (1 ≤ t ≤ 10), the number of independent test cases.</p>

<p>Each of the following t lines contains four positive integers a<sub>i</sub>, b<sub>i</sub>, c<sub>i</sub>, d<sub>i</sub> (1 ≤ a<sub>i</sub> ≤ b<sub>i</sub> ≤ 10<sup>7</sup>, 1 ≤ c<sub>i</sub> ≤ d<sub>i</sub> ≤ 10<sup>7</sup>).</p>

### 출력 

 <p>Output t lines in total. For the i-th test case, output <code>DA</code> (Croatian for yes) if a<sub>i</sub> · (a<sub>i</sub> + 1) · · · b<sub>i</sub> divides c<sub>i</sub> · (c<sub>i</sub> + 1)· · · d<sub>i</sub>, and output <code>NE</code> (Croatian for no) otherwise.</p>

