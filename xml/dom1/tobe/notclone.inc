<?php ## ������������� �������� ���������� ������ ������������ ����
function formRefrain($Refrain)
{
    $line4=$Refrain->firstChild;   //$line4 ��������� �� 1-� ������
    $line3=$line4->cloneNode(true); //$line3 ��������� �� 1-� ������
    $line4=$Refrain->appendChild($line4);//1-� ������ ������������ � �����
}
?>
