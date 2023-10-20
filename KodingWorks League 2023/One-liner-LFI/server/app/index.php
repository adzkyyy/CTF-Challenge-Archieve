<?php !empty($_POST['file']) ? strlen($_POST['file']) < 5000 ? include($_POST['file']) : print "<h1>Abdullah Mudzakir: file apaan tuh? panjang banget 🥵</h1>" : highlight_file(__FILE__)?>
