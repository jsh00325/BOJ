# [Gold III] Bananas - 6875 

[문제 링크](https://www.acmicpc.net/problem/6875) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

브루트포스 알고리즘

### 제출 일자

2024년 2월 12일 23:28:59

### 문제 설명

<p>The term “code monkey” is sometimes used to refer to a programmer who doesn't know much about programming. This is unfair to monkeys, because contrary to popular belief, monkeys are quite smart. They have just been misunderstood. This may be because monkeys do not speak English, but only monkey language. Your job is to help humans and monkeys understand each other by writing a monkey language dictionary. For each word that is typed in, your program must determine whether it is a valid monkey language word.</p>

<p>Unlike in English, spelling in monkey language is very simple. Every word in monkey language satisfies the following rules, and every word satisfying the following rules is a monkey language word.</p>

<ol>
	<li>A monkey language word is a special type of word called an A-word, which may be optionally followed by the letter N and a monkey language word.</li>
	<li>An A-word is either only the single letter A, or the letter B followed by a monkey language word followed by the letter S.</li>
</ol>

<p>Here are some examples:The word “A”' is a monkey language word because it is an A-word.</p>

<p>The word “ANA” is a monkey language word because it is the A-word “A” followed by the letter N and the monkey language word “A”.</p>

<p>The word “ANANA” is a monkey language word because it is the A-word “A” followed by the letter N and the monkey language word “ANA”.</p>

<p>The word “BANANAS” is a monkey language word because it is an A-word, since it is the letter B followed by the monkey language word “ANANA” followed by the letter S.</p>

<p>Write a program which accepts words, one word on each line, and for each word prints YES if the word is a monkey language word, and NO if the word is not a monkey language word. The input word “X” indicates the program should terminate, and there is no output for word “X” (even though it is not a monkey word).</p>

### 입력 

 Empty

### 출력 

 Empty

