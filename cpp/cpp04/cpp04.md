[TOC]

# ex00



## 요구사항

- [x] Test everything

  - [x] 생성자, 소멸자가 특별한 output을 가지고 있어야 함

- [x] protected : std::string type.

  - [x] Type 는 name이 있어야 한다.

- [x] Animal -> Cat, Dog

- [x] makeSound() 함수를 사용할 수 있어야한다.

  - [x] 단, makeSound()는 클래스마다 적절한 output을 출력해야 한다.

- [x] WrongAnimal Class도 만들어야 한다.



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



# ex01



## 요구사항

- [x] Brain Class

  - [x] std:;string ideas[100];
  - [x] Dog, Cat 는 Brain Class 를 가지고 있어야 한다.
  - [x] Construction 시, Dog와 Cat는 Brain을 new Brain(); 으로 만들 것.
  - [x] Destruction 시 ,동적 할당 해제 필요.

- [x] main()에서는 Array of Dog, Array of Cat. 단, Animal 배열 안에 1:1 비율로 만들어야함.

- [x] Copy constructor. 신경 쓸 것.




## 요구사항 분석 :

* 주제에서 요구하는건 Deep Copy와, 그리고 Array의 다형성을 테스팅하면서 경험해보라는 것.
* 코드를 짜다 보니까 Brain의 ideas를 직접 접근할 수 없다. 왜? Brain은 Private 스코프에 있고, 또, ideas 역시 protected 영역에 있다 보니 직접 접근하기 힘든데..
* 다른 객체에서 private Scope에 있는 Brain 클래스의 ideas에 접근하기 위해서는 getter가 필요하다.





# ex02

## 요구사항

- [x] Animal 클래스를 누구도 Instanitate 할수 없도록 바꿔라.



## 요구사항 분석 :

ABC 클래스 (Abstract Class)를 사용한다.

- [x] MakeSound()를 하지 않기 때문에, 순수가상함수를 만들어 그 클래스의 객체를 생성할 수 없게 한다.



### 순수가상함수와 ABC 클래스

어떤 클래스가 진짜 추상화 기초클래스가 되려면, 적어도 하나의 순수가상함수를 가지고 있어야 한다.

원형에 = 0이 있으면, 그 클래스가 추상화 기초 클래스이며, 그 클래스가 반드시 함수를 정의할 필요가 없어진다.

* 순수가상함수는 ABC 클래스 내에서 정의를 가지는 것을 허용한다.





# ex03

c++ 98에서는 Interface가 없다.

interface를 구현화해보자.



## 요구사항

- [ ] Amateria 클래스

  - [ ] 아래 구현 필요.

  ```c++
  class AMateria
  {
  protected:
  [...]
  public:
  AMateria(std::string const & type);  //ICE, CURE가 하위 클래스인듯 보이고, type는 이름인듯 보임.
  [...]
  std::string const & getType() const; //Returns the materia type
  virtual AMateria* clone() const = 0; //새로운 인스턴스 리턴.
  virtual void use(ICharacter& target); //Materia의 type에 따라 display되는게 다르다.
  };
  ```



- [ ] Character 클래스

  - [ ] 아래 구현 필요

  ```c++
  class ICharacter
  {
  public:
  virtual ~ICharacter() {}
  virtual std::string const & getName() const = 0;	//
  virtual void equip(AMateria* m) = 0;		//full 일 경우...?
  virtual void unequip(int idx) = 0;		//Materia를 delete 하면 안되고 유지는 시켜야한다.
  virtual void use(int idx, ICharacter& target) = 0; //AMateria의 Use를 사용해야한다.
  };
  ```

  - [ ] Character는 Materia를 최대 4개까지 유지 가능.
  - [ ] Character는 constructor에 Name을 받아야 하며, copy는 Deep copy. 
  - [ ]  **The old Materia of a Character must be deleted. S**
  - [ ] Character의 destruction 시  Materia deleted 되어야 함.

- [ ] MateriaSource 클래스

  ```c++
  class IMateriaSource
  {
  public:
  virtual ~IMateriaSource() {}
  virtual void learnMateria(AMateria*) = 0; // 추후 메모리에 저장하여 clone되게 하는것이 필요하다.
  virtual AMateria* createMateria(std::string const & type) = 0; // 새로운 materia를 만들어 
  };
  ```





### 요구사항 분석

---

AMateria 클래스 -> Ice, Cure 클래스

ICharacter 클래스 -> Character 클래스

IMateriaSource 클래스 -> MateriaSource 클래스.



Character에서 Materia를 바로 만들 수 있는 것은 아니다. MateriaSource를 사용해서 Materia를 만들 수 있고, MateriaSource를 사용해서 Materia를 만들고자 하면, 미리 learn이 필요함.

