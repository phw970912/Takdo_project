# Takdo_project (잠깐생각좀... 팀)
### 201644013 3-A 박현우
### 201644018 3-A 송현석
### 201644031 3-A 전우성

## 개발 목적
일반 사람이 탁도를 한 눈으로 확인하기는 쉽지 않다.(탁도의 정도가 심하지 않은이상)

물생활(물고기-어항)을 하다보면 만나게되는 현상중 하나인 백탁현상 및 수질상태를 알기쉽게 빨강, 주황, 초록색의 LED 센서를 이용하여 한 눈에 알아보기 쉽게 하기 위함이다.

또한, 밖에서도 탁도를 확인함으로써 실시간으로 어디서나 어항의 수질상태를 확인하기 위함이다.

## 개발 목표

아두이노에서 탁도 센서를 이용하여 탁도를 측정한 뒤, 측정된 voltage 값에 따라 LED가 켜지는 색을 변경하여 불이 들어오게 하고, 라즈베리파이와 텔레그램을 연동하여 실시간으로 탁도의 수치와 들어오는 불의 색을 확인할 수 있도록 한다.

## 탁도란?

물의 흐림정도를 나타내는 것으로 투시도와 같은 목적으로 사용되는 지표로 사용한다. 탁하다는 말은 빛의 통과를 방해하거나 가시심도를 제한하는 부유물질을 포함하고 있다는 뜻이다. 수질 지표로서의 탁도는 보통 빛을 입사시켜 부유 물질에 의해 산란된 정도를 광학적으로 측정하여 나타낸다.

기기 분석법은 혼탁 입자들에 의하여 빛의 산란도를 측정하는 네펠로법(Nephelometry)을 이용하는 것으로 네팰로법 - 혼탁도 - 단위(Nephelometry - Turbidity - Unit : NTU)를 사용한다.

## 재료

Arduino LEONARDO, RaspberryPi, 탁도 센서, LED(빨강, 주황, 초록 각각 1개씩), 저항100옴 3개, 연결선, 브레드보드

## 회로 사진

<img src="https://user-images.githubusercontent.com/55423181/102199171-a2495280-3f06-11eb-99be-741d58423e6d.PNG" width="70%" height="70%" />

아두이노와 브레드보드 회로도(라즈베리파이와 탁도센서 연결 제외)

사진에는 LED가 8, 10, 12번에 연결되어 있으나 실제 연결은 11, 12, 13번에 연결함

![takdo](https://user-images.githubusercontent.com/56572032/102181899-af5a4780-3eee-11eb-8658-014116ed351d.png)

탁도센서 연결부

![KakaoTalk_20201215_153653825](https://user-images.githubusercontent.com/56572032/102180610-81740380-3eec-11eb-9ed4-b0621e0516cb.jpg)
전체 회로 사진

![KakaoTalk_20201215_153722137](https://user-images.githubusercontent.com/56572032/102180627-86d14e00-3eec-11eb-8c51-cb3c9e04e5fb.jpg)
브레드보드를 확대한 사진

Analog 0번(A0)에 연결하는 이유는 수치값을 읽어와야 하기 때문이다.

Digital에 연결할 경우 HIGH와 LOW만 읽어오기 때문에 수치를 확인할 수 없다.

## 아두이노 코드
[takdo_led.ino](https://github.com/jeewoo197/Takdo_project/blob/main/Project/takdo_led.ino)

## LED 작동
![KakaoTalk_20201215_161347207](https://user-images.githubusercontent.com/56572032/102183146-b84c1880-3ef0-11eb-9434-f8dbd976781f.jpg)
각 종이컵에 농도가 진한 흙탕물, 조금 연한 흙탕물, 수돗물을 준비

![KakaoTalk_20201215_162550095-1](https://user-images.githubusercontent.com/56572032/102184268-83d95c00-3ef2-11eb-882f-1aba780d4595.jpg)
진한 흙탕물에 담갔을 때의 사진

![KakaoTalk_20201215_162444360-1](https://user-images.githubusercontent.com/56572032/102184024-23e2b580-3ef2-11eb-9a9f-8c637a2b3982.jpg)
조금 연한 흙탕물에 담갔을 때의 사진

![KakaoTalk_20201215_162228490-1](https://user-images.githubusercontent.com/56572032/102183875-e67e2800-3ef1-11eb-9978-092f9f9b6102.jpg)
수돗물에 담갔을 때의 사진

## 텔레그램 봇 연동 코드
[timerbot.py](https://github.com/jeewoo197/Takdo_project/blob/main/timerbot.py)

## 텔레그램 봇 연동
<img src="https://user-images.githubusercontent.com/56572032/102184316-994e8600-3ef2-11eb-9c20-57f94f477b76.jpg" width="50%" height="50%" />
진한 흙탕물, 조금 연한 흙탕물, 수돗물에 담갔을 때의 텔레그램 봇의 반응
