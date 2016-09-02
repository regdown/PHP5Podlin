<?php header('Content-Type: text/html; charset=windows-1251'); ?>
<?php ## Использование var_export(). 
class SomeClass {
  private $x = 100;
}
$a = array(1, array ("Programs hacking programs. Why?", "д'Артеньян"));
echo "<pre>"; var_export($a); echo "</pre>";
$obj = new SomeClass();
echo "<pre>"; var_export($obj); echo "</pre>";
$a = 1;
$b = 2;
$a=+3;
$b=-2;
echo $a . $b;
if("as"==true){
    echo 1;
}
?>