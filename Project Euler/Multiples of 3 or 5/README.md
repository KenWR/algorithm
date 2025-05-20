## Problem

If we list all the natural numbers below $10$ that are multiples of $3$ or $5$, we get $3, 5, 6$ and $9$.    
3이나 5의 배수인 10 미만의 모든 자연수를 나열하면 3, 5, 6, 9가 됩니다.

The sum of these multiples is $23$.   
이 수들의 합은 23입니다.

Find the sum of all the multiples of $3$ or $5$ below $1000$.   
1000 미만의 3 또는 5의 모든 배수의 합을 구하세요.

## Solution

999를 3, 5로 나누어 3의 배수, 5의 배수 개수를 구한다.      

그리고 3과 5의 배수와 중첩이 되는 15의 배수 개수를 구하여 3, 5의 배수의 합에서 뺀다.   

이렇게 되면 우리는 중복을 제거한 온전한 3, 5의 배수 합을 구할 수 있게 된다.   

유명한 일화를 가진 가우스의 등차수열을 이용한다.    
`n * (n + 1) / 2`   

이를 통해 3의 배수는 `1 ~ 333` 까지의 수의 등차수열 합을 구하고, `1 ~ 199` 까지의 수의 등차수열 합을 구한다음 각 배수의 숫자를 곱해주면 되겠다.

