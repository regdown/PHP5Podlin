<?php ## ������������ ������ � $_COOKIES.
// ������� ������� ����� ����.
$count = 0;
// ���� � Cookies ���-�� ����, ����� ������� ������.
if (isset($_COOKIE['count'])) $count = $_COOKIE['count'];
$count++;
// ���������� � Cookies ����� �������� ��������.
setcookie("count", $count, 0x7FFFFFFF, "/");
// ������� �������.
echo $count;
$a=array();
$a[] = 2;
$a[35]=3;
$a[]=4;
print_r($GLOBALS);
?>