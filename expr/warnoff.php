<!-- ���������� ����������� �������������� -->
<form action=warnoff.php>
<input type=submit name="doGo" value="Click!">
</form>
<?php
// � ������� $_REQUEST ������ ���������� ��������� �� ����� ������.
if (@$_REQUEST['doGo']) echo "�� ������ ������!";
?>
