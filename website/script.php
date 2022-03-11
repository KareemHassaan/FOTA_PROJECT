<!DOCTYPE html>
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



<?php
$target_dir = "uploads/";
$target_file = $target_dir . basename($_FILES["fileToUpload"]["name"]);
$uploadOk = 1;
$FileType = strtolower(pathinfo($target_file,PATHINFO_EXTENSION));



// Check if file already exists
if (file_exists($target_file)) {
  echo "Sorry, file already exists.";
  $uploadOk = 0;
}

// Check file size
if ($_FILES["fileToUpload"]["size"] > 56000) {
  echo "Sorry, your file is too large.";
  $uploadOk = 0;
}

// Allow certain file formats
if($FileType != "txt"  ) {
  echo "Sorry, only txt files are allowed.";
  $uploadOk = 0;
}

// Check if $uploadOk is set to 0 by an error
if ($uploadOk == 0) {
  echo "Sorry, your file was not uploaded.";
// if everything is ok, try to upload file
} 
else {
  if (move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $target_file)) {
    echo "The file ". htmlspecialchars( basename( $_FILES["fileToUpload"]["name"])). " has been uploaded.";
	
	
    } 
  else {
    echo "Sorry, there was an error uploading your file.";
  }
}

copy($target_file, 'temp.txt');
copy('temp.txt','backup.txt');
$check=fopen("upgrade.txt","w");
fwrite($check,'EAF1');
fclose($check);
?>
</html>