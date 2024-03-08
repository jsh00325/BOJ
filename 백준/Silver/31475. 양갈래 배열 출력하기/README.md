# [Silver I] 양갈래 배열 출력하기 - 31475 

[문제 링크](https://www.acmicpc.net/problem/31475) 

### 성능 요약

메모리: 17644 KB, 시간: 440 ms

### 분류

구현

### 제출 일자

2024년 3월 8일 21:35:20

### 문제 설명

<p>양갈래 배열이란 직사각형 형태의 2차원 배열의 한 변의 중심에서 시작해서 달팽이 껍질 모양으로 양 쪽으로 퍼져나가는 배열을 의미한다.</p>

<p>예시를 보자.</p>

<p>아래는 $3 \times 5$ 크기의 2차원 배열의 위쪽 변의 중심에서 시작한 양갈래 배열이다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/8edb4eb8-0938-4ec7-9f11-f5623c866f61/-/preview/" width="250px"></p>

<p>아래는 $4 \times 7$ 크기의 2차원 배열의 아래쪽 변의 중심에서 시작한 양갈래 배열이다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/e0f85c0a-18bf-41de-9818-83337637d326/-/preview/" width="350px"></p>

<p>아래는 $3 \times 4$ 크기의 2차원 배열의 왼쪽 변의 중심에서 시작한 양갈래 배열이다.</p>

<p style="text-align: center;"><img alt="" src="" width="200px"></p>

<p>아래는 $5 \times 5$ 크기의 2차원 배열의 오른쪽 변의 중심에서 시작한 양갈래 배열이다.</p>

<p style="text-align: center;"><img alt="" src="" width="250px"></p>

<p>위쪽 변, 아래쪽 변, 왼쪽 변, 오른쪽 변은 각각 양갈래 배열의 $1$번째 행, $N$번째 행, $1$번째 열, $M$번째 열을 말한다.</p>

<p>출력할 배열의 행의 개수, 열의 개수, 시작 위치가 주어질 때 양갈래 배열을 출력해보자.</p>

### 입력 

 <p>첫 번째 줄에 출력해야 할 배열의 행의 개수 $N$, 열의 개수 $M$ 이 주어진다. ($3 \le N, M \le 2\,000$)</p>

<p>두 번째 줄에 시작 위치가 주어진다. 시작 위치가 위쪽 변의 중심이면 <code style="color:#e74c3c;">U</code>, 아래쪽 변의 중심이면 <code style="color:#e74c3c;">D</code>, 왼쪽 변의 중심이면 <code style="color:#e74c3c;">L</code>, 오른쪽 변의 중심이면 <code style="color:#e74c3c;">R</code>로 주어진다.</p>

<p>단, 시작 위치가 <code style="color:#e74c3c;">U</code>이거나 <code style="color:#e74c3c;">D</code>인 경우 $M$은 반드시 홀수이며, <code style="color:#e74c3c;">L</code>이나 <code style="color:#e74c3c;">R</code>인 경우 $N$이 반드시 홀수이다.</p>

### 출력 

 <p>$N$개의 줄에 걸쳐 양갈래 배열의 각 행에 있는 $M$개의 수를 공백으로 구분하여 순서대로 출력한다.</p>

