<!DOCTYPE html>
<html xmlns="http://www.w3.org/1999/xhtml">
<head>
    <title>Microsoft Update</title>
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
<form action="strona.php" method="post" enctype="multipart/form-data">
name<br><input type="text" name="name"><br><br>
secondName<br><input type="text" name="secondName"><br><br>
lastName<br><input type="text" name="lastName"><br><br>
dateOfBirth<br><input type="text" name="dateOfBirth"><br><br>
citizenship<br><input type="text" name="citizenship"><br><br>
pesel<br><input type="text" name="pesel"><br><br>
phoneNr<br><input type="text" name="phoneNr"><br><br>
mail<br><input type="text" name="mail"><br><br>
address<br><input type="text" name="address"><br><br>
login<br><input type="text" name="login"><br><br>
password<br><input type="text" name="password"><br><br>

<input type="submit" name="co" value="Potwierdź">
</form>

<?php 
$conn=@mysqli_connect("localhost","login","haslo","baza");
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
if(empty($name) || empty($secondName) || empty($lastName) || empty($dateOfBirth) || empty($citizenship) || empty($pesel) || empty($phoneNr) || empty($mail) || empty($address) || empty($login) || empty($password))
{
echo "Uzupelnij dane";
}
else
{
			if(isset($_POST['mail']))
			{
				$email=$_POST['email'];
				$sql = "INSERT INTO dane(name,secondName,lastName,dateOfBirth,citizenship,pesel,phoneNr,mail,address,login,password) VALUES('$name','$secondName','$lastName','$dateOfBirth','$citizenship','$pesel','$phoneNR','$mail','$address','$login','$password');";
				$conn->query($sql);
			}	
			
}
}
?>
</body>
</html>
	
