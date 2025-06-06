## Problem

The prime factors of $13195$ are $5, 7, 13$ and $29$.   
$13195$의 소인수는 $5, 7, 13$ 그리고 $29$이다.   

What is the largest prime factor of the number $600851475143$?   
$600851475143$의 가장 큰 소인수는 무엇인가?   

## Solution

- 큰 수 $N$의 소인수는 $\sqrt{n}$ 보다 클 수 없다.   

- $2, 3$만 빼고나면 $6$으로 나누었을 때 $1$ 또는 $5$가 되는 숫자 $6k \pm 1$만 소수 후보이다.   

위 두 가지 특성을 이용하여 구한다.   

| 6으로 나누면면 | 2의 배수 | 3의 배수 |
| ------ | --- | --- |
| 6k     | yes | yes |
| 6k + 1 | no  | no  |
| 6k + 2 | yes | no  |
| 6k + 3 | no  | yes |
| 6k + 4 | yes | no  |
| 6k + 5 | no  | no  |

위 표를 통해 $6$으로 나누었을때 $1$ 이나 $5$ 가 남는다면 소수일 가능성이 높다고 판단하여 인수분해 시도 및 소인수 값 저장.   
그렇게 계속해서 인수분해를 한 뒤 숫자가 $0$이 되면 가장 최근에 저장된 값이 가장 높은 소인수가되며 숫자가 남아 있는다면 남은 숫자가 가장 큰 소인수가 된다.   
