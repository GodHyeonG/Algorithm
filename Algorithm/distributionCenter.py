from dataclasses import dataclass
#Category 6
class Fruit:
    product: list = ['apple', 'banana', 'orange', 'cherry', 'mango', 'grape']
    number: list = [10, 10, 10, 10, 10, 10]
    cost: list = [0, 0, 0, 0, 0, 0]
class Bakery:
    product: list = ['bread', 'waffle', 'sandwich', 'cookie', 'cake', 'pie']
    number: list = [10, 10, 10, 10, 10, 10]
    cost: list = [0, 0, 0, 0, 0, 0]
class Snack:
    product: list = ['ice cream', 'rice cake', 'chocolate', 'nuts', 'jelly', 'pudding']
    number: list = [10, 10, 10, 10, 10, 10]
    cost: list = [0, 0, 0, 0, 0, 0]
class Drink:
    product: list = ['water', 'milk', 'juice', 'coffee', 'tea', 'yogurt']
    number: list = [10, 10, 10, 10, 10, 10]
    cost: list = [0, 0, 0, 0, 0, 0]
class SideDish:
    product: list = ['kimchi', 'stew', 'tofu', 'fishcake', 'sausage', 'egg']
    number: list = [10, 10, 10, 10, 10, 10]
    cost: list = [0, 0, 0, 0, 0, 0]
class Vegetable:
    product: list = ['lettuce', 'potato', 'carrot', 'mushroom', 'cabbage', 'onion']
    number: list = [10, 10, 10, 10, 10, 10]
    cost: list = [0, 0, 0, 0, 0, 0]

fruit = Fruit()
bakery = Bakery()
snack = Snack()
drink = Drink()
sideDish = SideDish()
vegetable = Vegetable()

#Customer 10
class C1:
    purchase: list = ['apple', 'mango', 'waffle']
    number: list = [3, 1, 3]
class C2:
    purchase: list = ['apple', 'sandwich', 'milk']
    number: list = [2, 2, 1]
class C3:
    purchase: list = ['water', 'kimchi', 'stew', 'egg', 'ice cream']
    number: list = [5, 2, 1, 4, 2]
class C4:
    purchase: list = ['banana', 'grape']
    number: list = [2, 1]
class C5:
    purchase: list = ['potato', 'carrot', 'onion', 'mushroom']
    number: list = [3, 1, 2, 1]
class C6:
    purchase: list = ['nuts', 'yogurt']
    number: list = [3, 2]
class C7:
    purchase: list = ['orange', 'bread', 'sandwich', 'cookie', 'juice', 'egg', 'potato', 'tofu']
    number: list = [1, 1, 1, 2, 1, 2, 3, 2]
class C8:
    purchase: list = ['kimchi', 'sausage', 'carrot', 'mushroom']
    number: list = [2, 4, 1, 1]
class C9:
    purchase: list = ['ice cream', 'rice cake', 'pie']
    number: list = [3, 2, 2]
class C10:
    purchase: list = ['water']
    number: list = [6]

c1 = C1()
c2 = C2()
c3 = C3()
c4 = C4()
c5 = C5()
c6 = C6()
c7 = C7()
c8 = C8()
c9 = C9()
c10 = C10()

category = ['fruit', 'bakery', 'snack', 'drink', 'sideDish', 'vegetable']

def find_category(x):
    for i in range(6):
        if (x == fruit.product[i]):
            c_idx = category.index('fruit') #0
            fruit.number[i] -= 1
            fruit.cost[i] += 1
            break
        elif (x == bakery.product[i]):
            c_idx = category.index('bakery') #1
            bakery.number[i] -= 1
            bakery.cost[i] += 1
            break
        elif (x == snack.product[i]):
            c_idx = category.index('snack') #2
            snack.number[i] -= 1
            snack.cost[i] += 1
            break
        elif (x == drink.product[i]):
            c_idx = category.index('drink') #3
            drink.number[i] -= 1
            drink.cost[i] += 1
            break
        elif (x == sideDish.product[i]):
            c_idx = category.index('sideDish') #4
            sideDish.number[i] -= 1
            sideDish.cost[i] += 1
            break
        elif (x == vegetable.product[i]):
            c_idx = category.index('vegetable') #5
            vegetable.number[i] -= 1
            vegetable.cost[i] += 1
            break
    return c_idx

