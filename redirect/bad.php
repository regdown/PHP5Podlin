<?php ## "������" ���������� �������� �����.
$FNAME = "book.txt";
if (@$_REQUEST['doAdd']) {
  $f = fopen($FNAME, "a");
  if (@$_REQUEST['text']) fputs($f, $_REQUEST['text']."\n");
  fclose($f);
}
$gb = @file($FNAME); 
if (!$gb) $gb = array();
?>
<form action="<?=$_SERVER['SCRIPT_NAME']?>" method="POST">
�����:<br>
<textarea name="text"></textarea><br>
<input type="submit" name="doAdd" value="��������">
</form>
<?foreach($gb as $text) {?>
    <?=$text?><br><hr>
<?}?>
