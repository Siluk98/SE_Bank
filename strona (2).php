<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Strona Banku</title>
	<meta charset="utf-8" />
</head>
<body>
<style type="text/css">/*<![CDATA[ */
.cbalink {
display:none;
}
</style>
<script type="text/javascript">
document.getElementsByTagName("div")[0].style.display = "none";
</script>
<style>
body{
margin:0 auto;
text-align:center;
}
</style>
<form  method="post" enctype="multipart/form-data">
login<br><input type="text" name="login"><br>
password<br><input type="text" name="password"><br>
<input type="submit" name="co" value="Potwierdź"><br>
</form>


<?php 
$conn=@mysqli_connect("localhost","turboreal","zaq1@WSX","turboreal");
if(!$conn) die('Brak polaczenia z serwerem');

$name =$_POST['name'];
$secondName =$_POST['secondName'];
$lastName =$_POST['lastName'];
$dateOfBirth =$_POST['dateOfBirth'];
$citizenship =$_POST['citizenship'];
$pesel =$_POST['pesel'];
$phoneNr =$_POST['phoneNr'];
$mail =$_POST['mail'];
$address =$_POST['address'];
$login =$_POST['login'];
$password =$_POST['password'];

if(isset($_POST['co']))
{
if(empty($login) || empty($password))
{
echo "Podaj dane";
}
else
{				
$wynik=$conn->query("SELECT * FROM dane WHERE login='$login';") or die ('Nie ma');
#$sql = "INSERT INTO dane(name,secondName,lastName,dateOfBirth,citizenship,pesel,phoneNr,mail,address,login,password) VALUES('$name','$secondName','$lastName','$dateOfBirth','$citizenship','$pesel','$phoneNR','$mail','$address','$login','$password');";
$conn->query($sql);				
}
}

if($wynik->num_rows>0)
{
		
	
	while($rekord=$wynik->fetch_array()){
		echo($rekord['name']." ".$rekord['secondName']." ".$rekord['lastName']." ".$rekord['dateOfBirth']." ".$rekord['citizenship']." ".$rekord['pesel']." ".$rekord['phoneNr']." ".$rekord['mail']." ".$rekord['address']." ".$rekord['login']." ".$rekord['password']."");
                echo("<br>");	
}
	
}
?>
</body>
</html>
		