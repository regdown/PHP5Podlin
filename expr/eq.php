<?php header('Content-Type: text/html; charset=windows-1251'); ?>
<?php ## ��������� ��������� � ���������������.
$yeap = array("����������", true);
$nein = array("����������", "���������");
if ($yeap == $nein)  echo "��� ������� �����";
if ($yeap === $nein) echo "��� ������� ������������";
?>