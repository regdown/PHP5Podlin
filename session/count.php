<?php ## ������ ������ � ��������.
session_start();
// ���� �� ���� ������-������ �����, �������� �������.
if (!isset($_SESSION['count'])) $_SESSION['count'] = 0;
// ����������� ������� � ������.
$_SESSION['count'] = $_SESSION['count'] + 1;
?>
<h2>�������</h2>
� ������� ������ ������ � ��������� �� ������� ��� ��������
<?=$_SESSION['count']?> ���(�).<br>
�������� �������, ����� �������� �������.<br>
<a href="<?=$_SERVER['SCRIPT_NAME']?>" target="_blank">������� �������� ���� ��������</a>.
