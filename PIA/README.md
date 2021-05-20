# Budgeting App FINAL


## Synopsis :astronaut:

This is an application to manage personal finances. This application does not have a special reason, I just wanted to apply the knowledge acquired in my structured programming course and put them into practice, then the requirements of my project implemented.

In this application it is expected that the user can manage their expenses in an easy and simple way. The application automates processes such as the search for information, the addition and subtraction of expenses to know the total balance of the user.


## video 

Link : https://youtu.be/MCK-YM4tNjw

## Presentation plan

click on "ReadmeAssets". It is the file "preparacion.md"

## Instructions :technologist:

Files : Activos.txt, Pasivos.txt, main.c, helper.c and header.h are needed.


You can also try a demo in : https://onlinegdb.com/If-U6H5-d (It is a demo because it is not modulated, I would recommend that you do it from your compiler)
  
## Project requirements :dart:


- Password
 ```plain
  - At the start 
  - Can be changed
```
- Add Products

You will be able to register:

```plain
  - + profits
  -  - expenses
  - With Categories (medical, university, bills,etc) 
  - *Date automatically generated
 ```
 
- Ask for information 
```plain
  - View all operations
  - View all positives
  - View all negatives
  - Search by Date
  - Search By categorie
 ```
- Opperations
```plain
  - Delete operations
  - Change my password
  - Get total Balance
```

## Files :page_facing_up:

| **.c** |  **.h** | **.txt** |
|:-----|:--------:|:--------:|
| main  | header | _Positives_|
| helpers |    |   _Negatives_  |
|  |    |   _pass_  |


### .txt Format 

Amount - Categorie - Description  - Date
     
     1200  Games I_bought_7DTD 1620915321                              +1200 trade I_sold_gummies_idk 1620915329
     2485 University Rectoria 1620915324
      
 In this example, the balance will be + 1200 - 1200 - 2485 = **-2485**
     		
## Functions :octocat:

ImprimeLinea(); 

consultas();

balanceTotal();

buscarCategoria();

ingresarConcepto();

imprimeFichero();

cambiarPassword();

validarPassword();

Eliminar();

imprimirPorFecha();



## UI :iphone:

1.-Pasword 

<img src="https://github.com/AbnerIO/C/blob/main/PIA/ReadmeAssets/password.png" width="350px" height="150px"></a>

2.-UI 

<img src="https://github.com/AbnerIO/C/blob/main/PIA/ReadmeAssets/UI.png" width="450px" height="350px"></a>

3.-Option 

<img src="https://github.com/AbnerIO/C/blob/main/PIA/ReadmeAssets/consultas.png" width="350px" height="150px"></a>


## References :page_with_curl:

C Reference Card (ANSI)


## Author(s)

Abner Zair Velázquez Domínguez  M: 1960233 Structured Programming

## License

None

