[TOC]

# ex00



## 요구사항

- [ ] Test everything

  - [ ] 생성자, 소멸자가 특별한 output을 가지고 있어야 함

- [ ] protected : std::string type.

  - [ ] Type 는 name이 있어야 한다.

- [ ] Animal -> Cat, Dog

- [ ] makeSound() 함수를 사용할 수 있어야한다.

  - [ ] 단, makeSound()는 클래스마다 적절한 output을 출력해야 한다.

- [ ] WrongAnimal Class도 만들어야 한다.

  

## 요구사항 분석 : 

* inheritance에 따른 함수 오버라이딩.

* 굳이 name을 protected로 설정하는 이유는?



## Protected :

* 파생 클래스의 멤버에 접근시키기 위해서.

## const after function

> 함수가 클래스 멤버인 경우에만 const 키워드를 함수 뒤에 삽입 할 수 있으며 해당 함수가 속한 객체의 멤버 변수를 변경 할 수 없다는 뜻이다.



```cpp
 bool IsNotZero() const {
      return num != 0;
```





## 주제 : 

**동적 바인딩과 다형성**