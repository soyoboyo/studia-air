-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='TRADITIONAL,ALLOW_INVALID_DATES';

-- -----------------------------------------------------
-- Schema restauracja
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema restauracja
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `restauracja` DEFAULT CHARACTER SET utf8 ;
USE `restauracja` ;

-- -----------------------------------------------------
-- Table `restauracja`.`Pracownik`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `restauracja`.`Pracownik` (
  `ID_pracownika` INT NOT NULL,
  `Imie` VARCHAR(45) NULL,
  `Nazwisko` VARCHAR(45) NULL,
  `Stanowisko` VARCHAR(45) NULL,
  `Miejscowosc` VARCHAR(45) NULL,
  `Nr_telefonu` INT NULL,
  `Zatrudniono` DATE NULL,
  PRIMARY KEY (`ID_pracownika`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `restauracja`.`Klient`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `restauracja`.`Klient` (
  `ID_klienta` INT NOT NULL,
  PRIMARY KEY (`ID_klienta`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `restauracja`.`Szczegoly zamowienia`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `restauracja`.`Szczegoly zamowienia` (
  `ID_Szczegoly zamowienia` INT NOT NULL,
  `Szczegoly zamowieniacol` VARCHAR(45) NULL,
  `ziemniaki` INT NULL,
  `buraki` INT NULL,
  `seler` INT NULL,
  `ogorki` INT NULL,
  `szczypior` INT NULL,
  `cebula` INT NULL,
  `czosnek` INT NULL,
  `rzodkiewki` INT NULL,
  `grzyby` INT NULL,
  `kurczak` INT NULL,
  `wolowina` INT NULL,
  `wieprzowina` INT NULL,
  `baranina` INT NULL,
  `flaki` INT NULL,
  `kasza` INT NULL,
  `ryz` INT NULL,
  `makaron` INT NULL,
  `frytki` INT NULL,
  `kluski` INT NULL,
  `pierogi` INT NULL,
  `placki` INT NULL,
  `racuchy` INT NULL,
  `twarog` INT NULL,
  `ser` INT NULL,
  `smietana` INT NULL,
  `woda` INT NULL,
  `sok_jablkowy` INT NULL,
  `sok_pomaranczowy` INT NULL,
  `woda_gazowana` INT NULL,
  `lod` INT NULL,
  `wino_biale` INT NULL,
  `wino_czerwone` INT NULL,
  `piwo` INT NULL,
  `salata` INT NULL,
  `sos_czosnokowy` INT NULL,
  `keczup` INT NULL,
  `maojnez` INT NULL,
  `ocet` INT NULL,
  `sol` INT NULL,
  `pieprz` INT NULL,
  `lody_waniliowe` INT NULL,
  `lody_czekoladowe` INT NULL,
  `bita_smietana` INT NULL,
  `sernik` INT NULL,
  `rodzynki` INT NULL,
  `cukier` INT NULL,
  `cukier_puder` INT NULL,
  `Szczegoly zamowieniacol1` INT NULL,
  `budyn` INT NULL,
  `kisie_truskawkowyl` INT NULL,
  `herbata_zielona` INT NULL,
  `herbata_czarna` INT NULL,
  `kawa_rozpuszczalna` INT NULL,
  `olej` INT NULL,
  `chleb` INT NULL,
  `bulka` INT NULL,
  `oliwki` INT NULL,
  `krewetki` INT NULL,
  PRIMARY KEY (`ID_Szczegoly zamowienia`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `restauracja`.`Historia zamowienia`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `restauracja`.`Historia zamowienia` (
  `ID_zamowienia` INT NOT NULL,
  `Pracownik_ID_pracownika` INT NOT NULL,
  `Zlozono` DATETIME(0) NULL,
  `Wydano` DATETIME(0) NULL,
  `Czy_reklamacja` TINYINT NULL,
  `Razem` FLOAT NULL,
  `Klient_ID_Klienta` INT NOT NULL,
  `Szczegoly zamowienia_ID_Szczegoly zamowienia` INT NOT NULL,
  PRIMARY KEY (`ID_zamowienia`, `Pracownik_ID_pracownika`, `Klient_ID_Klienta`, `Szczegoly zamowienia_ID_Szczegoly zamowienia`),
  INDEX `fk_Historia zamowienia_Pracownik1_idx` (`Pracownik_ID_pracownika` ASC),
  INDEX `fk_Historia zamowienia_Klient1_idx` (`Klient_ID_Klienta` ASC),
  INDEX `fk_Historia zamowienia_Szczegoly zamowienia1_idx` (`Szczegoly zamowienia_ID_Szczegoly zamowienia` ASC),
  CONSTRAINT `fk_Historia zamowienia_Pracownik1`
    FOREIGN KEY (`Pracownik_ID_pracownika`)
    REFERENCES `restauracja`.`Pracownik` (`ID_pracownika`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Historia zamowienia_Klient1`
    FOREIGN KEY (`Klient_ID_Klienta`)
    REFERENCES `restauracja`.`Klient` (`ID_klienta`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Historia zamowienia_Szczegoly zamowienia1`
    FOREIGN KEY (`Szczegoly zamowienia_ID_Szczegoly zamowienia`)
    REFERENCES `restauracja`.`Szczegoly zamowienia` (`ID_Szczegoly zamowienia`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `restauracja`.`Rachunek`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `restauracja`.`Rachunek` (
  `ID_rachunku` INT NOT NULL,
  `Historia zamowienia_ID_zamowienia` INT NOT NULL,
  `Historia zamowienia_Klient_Numer_klienta` INT NOT NULL,
  `Cena` INT NULL,
  `Wystawiono` DATETIME(0) NULL,
  `Znizka` FLOAT NULL,
  `Sposob_zaplaty` VARCHAR(45) NULL,
  `Reszta` FLOAT NULL,
  PRIMARY KEY (`ID_rachunku`, `Historia zamowienia_ID_zamowienia`, `Historia zamowienia_Klient_Numer_klienta`),
  INDEX `fk_Rachunek_Historia zamowienia1_idx` (`Historia zamowienia_ID_zamowienia` ASC, `Historia zamowienia_Klient_Numer_klienta` ASC),
  CONSTRAINT `fk_Rachunek_Historia zamowienia1`
    FOREIGN KEY (`Historia zamowienia_ID_zamowienia`)
    REFERENCES `restauracja`.`Historia zamowienia` (`ID_zamowienia`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `restauracja`.`Typy dan`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `restauracja`.`Typy dan` (
  `ID_typu_dania` INT NOT NULL,
  `danie_glowne` INT NULL,
  `zupa` INT NULL,
  `deser` INT NULL,
  `napoj` INT NULL,
  `przystawka` INT NULL,
  `alkohol` INT NULL,
  `salatka` INT NULL,
  `dodatki` INT NULL,
  PRIMARY KEY (`ID_typu_dania`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `restauracja`.`Danie`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `restauracja`.`Danie` (
  `ID_dania` INT NOT NULL,
  `Ilosc_kalorii` INT NULL,
  `Cena` INT NULL,
  `Czas_oczekiwania` FLOAT NULL,
  `Nazwa_dania` VARCHAR(45) NULL,
  `Typy dan_ID_typu_dania` INT NOT NULL,
  PRIMARY KEY (`ID_dania`, `Typy dan_ID_typu_dania`),
  INDEX `fk_Danie_Typy dan1_idx` (`Typy dan_ID_typu_dania` ASC),
  CONSTRAINT `fk_Danie_Typy dan1`
    FOREIGN KEY (`Typy dan_ID_typu_dania`)
    REFERENCES `restauracja`.`Typy dan` (`ID_typu_dania`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `restauracja`.`Danie_has_Szczegoly zamowienia`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `restauracja`.`Danie_has_Szczegoly zamowienia` (
  `Danie_ID_dania` INT NOT NULL,
  `Danie_Typy dan_ID_typu_dania` INT NOT NULL,
  `Szczegoly zamowienia_ID_Szczegoly zamowienia` INT NOT NULL,
  PRIMARY KEY (`Danie_ID_dania`, `Danie_Typy dan_ID_typu_dania`, `Szczegoly zamowienia_ID_Szczegoly zamowienia`),
  INDEX `fk_Danie_has_Szczegoly zamowienia_Szczegoly zamowienia1_idx` (`Szczegoly zamowienia_ID_Szczegoly zamowienia` ASC),
  INDEX `fk_Danie_has_Szczegoly zamowienia_Danie1_idx` (`Danie_ID_dania` ASC, `Danie_Typy dan_ID_typu_dania` ASC),
  CONSTRAINT `fk_Danie_has_Szczegoly zamowienia_Danie1`
    FOREIGN KEY (`Danie_ID_dania` , `Danie_Typy dan_ID_typu_dania`)
    REFERENCES `restauracja`.`Danie` (`ID_dania` , `Typy dan_ID_typu_dania`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_Danie_has_Szczegoly zamowienia_Szczegoly zamowienia1`
    FOREIGN KEY (`Szczegoly zamowienia_ID_Szczegoly zamowienia`)
    REFERENCES `restauracja`.`Szczegoly zamowienia` (`ID_Szczegoly zamowienia`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
