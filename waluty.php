<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<HTML>
<HEAD>
<META HTTP-EQUIV="CONTENT-TYPE" CONTENT="text/html; charset=iso-8859-2">
    <TITLE>Licznik walut.</TITLE>
        <link rel="stylesheet" href="style.css" type="text/css">

</HEAD>
<BODY LANG="pl-PL" DIR="LTR">
<style type="text/css">/*<![CDATA[ */
.cbalink {
display:none;
}
</style>
<script type="text/javascript">
document.getElementsByTagName("div")[0].style.display = "none";
</script>
<form ACTION="waluty.php" method="post">
Wpisz ilość w PLN:<input TYPE="text" name="zlote"><INPUT TYPE="submit" VALUE="Oblicz"><br>
</form>
<?php
if ($zlote = $_POST['zlote']){
$franki = 3.96;
$euro = 4.25;
$dolary = 3.85;
$jen = 0.035;
$funt = 5.04;
$koronacz = 0.17;
$rubel = 0.06;
$wynikf = $zlote / $franki;
$wynike = $zlote / $euro;
$wynikd = $zlote / $dolary;
$wynikj = $zlote / $jen;
$wynikcypr = $zlote / $funt;
$wynikcz = $zlote / $koronacz;
$wynikr = $zlote / $rubel;
$wynik = "$zlote złotych = $wynikf <FONT COLOR=blue>Franków</FONT><BR>$zlote złotych = $wynike <FONT COLOR=blue>Euro</FONT><BR>$zlote złotych = $wynikd <FONT COLOR=blue>Dolarów</FONT><BR>$zlote złotych = $wynikj <FONT COLOR=blue>Jenów Japońskich</FONT><BR>$zlote złotych = $wynikcypr <FONT COLOR=blue>Funtów</FONT><BR>$zlote złotych = $wynikcz <FONT COLOR=blue>Koron Czeskich</FONT><BR>$zlote złotych = $wynikr <FONT COLOR=blue>Rubli</FONT><br><br>";
echo $wynik;
$wynikf2 = 1/$wynikf * $zlote * $zlote;
$wynike2 = 1 / $wynike * $zlote * $zlote;
$wynikd2 = 1 / $wynikd * $zlote * $zlote;
$wynikj2 = 1 / $wynikj * $zlote * $zlote;
$wynikcypr2 = 1 / $wynikcypr * $zlote * $zlote;
$wynikcz2 = 1 / $wynikcz * $zlote * $zlote;
$wynikr2 = 1 / $wynikr * $zlote * $zlote;
$wynik2 = "$zlote Franków = $wynikf2 <FONT COLOR=blue>złotych</FONT><BR>$zlote Euro = $wynike2 <FONT COLOR=blue>złotych</FONT><BR>$zlote Dolarów = $wynikd2 <FONT COLOR=blue>złotych</FONT><BR>$zlote Jenów Japońskich = $wynikj2 <FONT COLOR=blue>złotych</FONT><BR>$zlote Funtów = $wynikcypr2 <FONT COLOR=blue>złotych</FONT><BR>$zlote Koron Czeskich = $wynikcz2 <FONT COLOR=blue>złotych</FONT><BR>$zlote Rubli = $wynikr2 <FONT COLOR=blue>złotych</FONT>";
echo $wynik2;
 }
?>
</BODY>
</HTML>