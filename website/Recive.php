<?php

if($_GET['response']=='OK')
{
	$filetoread = fopen("temp.txt", "r+") or die("Unable to open file!");
	$filetowrite = fopen("code.txt", "w") or die("Unable to open file!");
	$line = fgets($filetoread);
	fwrite($filetowrite,'EAF'.$line);
	fclose($filetowrite);
	$content = file_get_contents('temp.txt');
	$content = explode("\n", $content);
	array_splice($content, 0, 1);
	$newcontent = implode("\n", $content);
	file_put_contents('temp.txt', $newcontent);
	if(feof($filetoread))
	{
		$test = fopen("upgrade.txt","w")or die("Unable to open file!");
		fwrite($test,'EAF0');
		fclose($test);
	}
	fclose($filetoread);
	
}
elseif($_GET['response']=='Reload')
{
	copy('backup.txt','temp.txt');
}


?>