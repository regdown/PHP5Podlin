<?php ## ������������� fuct_get_args().
function myecho() {  
    $args=func_get_args();
  foreach ($args as $v) {
    echo "$v<br>\n"; // ������� �������
  }
}
// ���������� ������ ���� ��� ������
myecho("��������", "������", "�����", "����");
?>
