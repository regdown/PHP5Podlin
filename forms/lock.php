<!-- ������������������� ������ ���������� ������� -->
<html><body>
<?if (!isset($_REQUEST['doGo'])) {?>
  <form action="<?=$_SERVER['SCRIPT_NAME']?>">
  �����: <input type=text name="login" value=""><br>
  ������: <input type=password name="password" value=""><br>
  <input type=submit name="doGo" value="������� ������!">
  </form>
<?} else {
  if ($_REQUEST['login']=="root" && $_REQUEST['password']=="Z10N0101") {
    echo "������ ������ ��� ������������ $_REQUEST[login]";
    // ������� ������������ ������� ������� (�������� � NT-��������)
    system("rundll32.exe user32.dll,LockWorkStation");
  } else {
    echo "������ ������!";
  }
}?>
</html></body>
