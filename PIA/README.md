# Budgeting App

## Synopsis

I'm going to develop an app that will help you manage your personal expenses.

  
## project requirements


- Password
 ```plain
  - Before the main interface
  - Modifiable
```
- Add Products
```plain
  - Actives (+ profits) 
  - Passives (- expenses)
  - With Categories (medical, university, bills,etc) 
  - Date
 ```
 
-Ask for information 
```plain
  - View all operations
  - View all passives
  - View all actives
  - Search by Date
  - Search By categorie
 ```
- Opperations
```plain
  - Delete operations
  - Get total Balance
```

## Files

| **.c** |  **.h** | **.txt** |
|:-----|:--------:|:--------:|
| main  | header | _Passives_|
| functions   |    |   _Actives_  |


### .txt Format 


Sign - categorie - amount 
     
     - Games 1200                                       + I_sold_gummies_idk 1200
     - Rectoria  2485
      
      
 In this example, the balance will be + 1200 - 1200 - 2485 = **-2485**
    
 		
## Functions


create(gasto), delete(nombre del gasto), printfPassives(), printfActives() 

findAllByCategorie(categorie),findAllByAmount(type _passive/active_, min, max), findAllByDate(Date) , verifyPassword(), changePassword(newPassword)

Maybe : timeStampConversor() , sum(),  


##UI



## Referencias

none atm

## Autor(es)
Abner Velázquez

## License
For Academic Purposes Only

