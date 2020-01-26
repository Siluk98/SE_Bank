-- phpMyAdmin SQL Dump
-- version 4.6.6
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Czas generowania: 26 Sty 2020, 08:19
-- Wersja serwera: 10.3.18-MariaDB-50+deb10u1.cba
-- Wersja PHP: 7.1.33

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Baza danych: `turboreal`
--

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `dane`
--

CREATE TABLE `dane` (
  `name` varchar(100) COLLATE latin1_general_ci NOT NULL,
  `secondName` varchar(100) COLLATE latin1_general_ci NOT NULL,
  `lastName` varchar(100) COLLATE latin1_general_ci NOT NULL,
  `dateOfBirth` date NOT NULL,
  `citizenship` varchar(25) COLLATE latin1_general_ci NOT NULL,
  `pesel` varchar(11) COLLATE latin1_general_ci NOT NULL,
  `phoneNr` varchar(12) COLLATE latin1_general_ci NOT NULL,
  `mail` varchar(100) COLLATE latin1_general_ci NOT NULL,
  `address` varchar(100) COLLATE latin1_general_ci NOT NULL,
  `login` varchar(100) COLLATE latin1_general_ci NOT NULL,
  `password` varchar(100) COLLATE latin1_general_ci NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=latin1 COLLATE=latin1_general_ci;

--
-- Zrzut danych tabeli `dane`
--

INSERT INTO `dane` (`name`, `secondName`, `lastName`, `dateOfBirth`, `citizenship`, `pesel`, `phoneNr`, `mail`, `address`, `login`, `password`) VALUES
('Wojtek', 'Marcin', 'Krab', '2018-09-03', 'Poland', '12345678909', '123456789', 'mail@mail.com', 'Ulica', 'login', 'haslo'),
('Zbigniew', 'Tomasz', 'Szbki', '2014-09-03', 'Poland', '12345671234', '987654321', 'mail2@mail.com', 'Ulicaa', 'haslo', 'login'),
('Artur', 'Marcin', 'Barcelona', '2004-12-03', 'Niemcy', '56725678909', '1745556789', 'mail3@mail.com', 'Ulica', 'login', 'haslo');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;