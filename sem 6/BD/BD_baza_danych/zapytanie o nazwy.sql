SELECT Nazwa_dania 
FROM restauracja.dania 
JOIN zamowienia_has_dania  
ON Dania_ID_Dania = ID_Dania
WHERE Zamowienia_ID_zamowienia = 1;

