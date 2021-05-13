# Budgeting App



## Synopsis :dizzy_face:

I'm going to develop an app that will help you manage your personal expenses.

  
## Project requirements :dart:


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
 
- Ask for information 
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

## Files :page_facing_up:

| **.c** |  **.h** | **.txt** |
|:-----|:--------:|:--------:|
| main  | header | _Passives_|
| functions   |    |   _Actives_  |


### .txt Format 

!!Experimental 👨‍🔬

Sign - Amount - Categorie (_flag:"C"_) - Description (_flag:"D"_)
     
     -1200  CGames DI_bought_7DTD                              +1200 Ctrade DI_sold_gummies_idk
     -2485 CUniversity DRectoria
      
 In this example, the balance will be + 1200 - 1200 - 2485 = **-2485**
    
 		
## Functions :octocat:


  create(gasto),
  
  delete(type _passive/active_, nombre del gasto), 
  
  printfPassives(), 
  
  printfActives() 

  findAllByCategorie(categorie),
  
  findAllByAmount(type _passive/active_, min, max),
  
  findAllByDate(Date) , verifyPassword(), 
  
  changePassword(newPassword)

  Maybe : timeStampConversor() , sum(),  


## UI :iphone:

<img src="https://github.com/AbnerIO/C/blob/main/PIA/Readme_Imgs/2021-05-13%2008_41_47-Window.png" width="550px" height="450px"></a>


## References :page_with_curl:

none atm

## Author(s)
Abner Velázquez M: 1960233 Programacion Estructurada

## License
For Academic Purposes Only

