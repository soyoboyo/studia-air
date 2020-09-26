pracownik


INSERT INTO `mydb`.`pracownik` (`ID_pracownika`, `Imie`, `Nazwisko`, `Stanowisko`, `Miejscowosc`, `Nr_telefonu`, `Zatrudniono`) VALUES ('101', 'Bichal', 'Beski', 'kucharz', 'wroclaw', '101101101', '2001-01-01');
INSERT INTO `mydb`.`pracownik` (`ID_pracownika`, `Imie`, `Nazwisko`, `Stanowisko`, `Miejscowosc`, `Nr_telefonu`, `Zatrudniono`) VALUES ('102', 'Michal', 'Meski', 'kucharz', 'lesnica', '100000002', '2002-02-02');
INSERT INTO `mydb`.`pracownik` (`ID_pracownika`, `Imie`, `Nazwisko`, `Stanowisko`, `Miejscowosc`, `Nr_telefonu`, `Zatrudniono`) VALUES ('103', 'Kichal', 'Keski', 'obsluga', 'wroclaw', '100000003', '2003-03-03');
INSERT INTO `mydb`.`pracownik` (`ID_pracownika`, `Imie`, `Nazwisko`, `Stanowisko`, `Miejscowosc`, `Nr_telefonu`, `Zatrudniono`) VALUES ('104', 'Hichal', 'Heski', 'obsluga', 'wroclaw', '100000004', '2004-04-04');
INSERT INTO `mydb`.`pracownik` (`ID_pracownika`, `Imie`, `Nazwisko`, `Stanowisko`, `Miejscowosc`, `Nr_telefonu`, `Zatrudniono`) VALUES ('105', 'Dichal', 'Deski', 'kierownik', 'psie pole', '100000005', '2005-05-05');


klient


INSERT INTO `mydb`.`klient` (`ID_klienta`) VALUES ('001');
INSERT INTO `mydb`.`klient` (`ID_klienta`) VALUES ('002');
INSERT INTO `mydb`.`klient` (`ID_klienta`) VALUES ('003');
INSERT INTO `mydb`.`klient` (`ID_klienta`) VALUES ('004');
INSERT INTO `mydb`.`klient` (`ID_klienta`) VALUES ('005');
INSERT INTO `mydb`.`klient` (`ID_klienta`) VALUES ('006');
INSERT INTO `mydb`.`klient` (`ID_klienta`) VALUES ('007');
INSERT INTO `mydb`.`klient` (`ID_klienta`) VALUES ('008');
INSERT INTO `mydb`.`klient` (`ID_klienta`) VALUES ('009');
INSERT INTO `mydb`.`klient` (`ID_klienta`) VALUES ('010');


UPDATE `restauracja`.`historia zamowienia` SET `Czy_reklamacja`='1' 
WHERE `ID_zamowienia`='20001' and`Pracownik_ID_pracownika`='101' 
and`Klient_ID_Klienta`='1' and`Szczegoly zamowienia_ID_Szczegoly zamowienia`='1';


DELETE FROM `restauracja`.`pracownik` 
WHERE `ID_pracownika`='105';