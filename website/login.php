
<?php 

function load($url)
{

 header ("Location: $url");

}

 if ($_POST['username']=='iti' && $_POST['password']=='fota')	 
 {
	 
echo'<!DOCTYPE html>
    <html lang="en-US">
    
    <head>
    <title>FOTA</title>
    <link rel="icon" type="image/x-icon" href="https://pbs.twimg.com/profile_images/2046005787/OTA_logo_400x400.png">
    <link rel="stylesheet"  href="styles.css">
    </head>
    <body>
    <h1 title="Burning Application Code using FOTA">
    <i>
    Firmware Over The air(FOTA)<br>
    </i>
    </h1>

	 <br>
	 <br>
	 <br>
	 <form  action="script.php" method="post" enctype="multipart/form-data">
	 Select image to upload:
	 <input type="file" name="fileToUpload" id="fileToUpload">
	 <br>
	 <input type="submit" value="Upload Image" name="upload" style=" -ms-transform: translate(150%, 60%);transform: translate(150%, 60%)">
	 </form>
	 </body>';
 }
 else
 {
   load('index.html');
 }

?>
