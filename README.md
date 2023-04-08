# 자동차 경주 게임

## 기능 요구사항
### 게임 기능
- [ ] 주어진 횟수 동안 n대의 자동차는 전진 또는 멈출 수 있다.
- [ ] 전진하는 조건은 0에서 9 사이에서 random 값을 구한 후 random 값이 **4 이상일 경우 전진**하고, **3 이하의 값이면 멈춘다**.
- [ ] 가장 많이 전진한 자동차를 우승자로 판단한다(중복 가능).
### 자동차 이름
- [ ] 이름은 5자 이하만 가능하다.
### 사용자 입출력
- [ ] 각 자동차의 이름을 입력받는다.
    - [ ] 자동차 이름은 쉼표(,)를 기준으로 구분한다.
- [ ] 몇 번의 이동을 할 것인지를 입력받는다.
- [ ] 전진하는 자동차를 출력할 때 자동차 이름을 같이 출력한다.
- [ ] 자동차 경주 게임을 완료한 후 누가 우승했는지를 알려준다.

## 결과 예시
```
경주할 자동차 이름을 입력하세요(이름은 쉼표(,)를 기준으로 구분).
pobi,crong,honux
시도할 회수는 몇회인가요?
5

실행 결과
pobi : -
crong : -
honux : -

pobi : --
crong : -
honux : --

pobi : ---
crong : --
honux : ---

pobi : ----
crong : ---
honux : ----

pobi : -----
crong : ----
honux : -----

pobi : -----
crong : ----
honux : -----

pobi, honux가 최종 우승했습니다.
```
