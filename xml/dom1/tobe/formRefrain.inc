<?php ## ������������ ������� �������� formRefrain()
/**
 * ������������ ������ �����.
 * ������� ����� ������ ������ � ������ ��������� �� � ����� �������.
 *
 * @param domElement $Refrain ��������� ������� �����
 */
function formRefrain($Refrain)
{
    $line4=$Refrain->firstChild->cloneNode(true);//$line4 ������ ����� 1-�
    $line3=$line4->cloneNode(true); //$line3 ������ ����� 4-� � 1-� ������
    $line4=$Refrain->appendChild($line4);   //�������� 4-�  ������
    $line3=$Refrain->insertBefore($line3,$line4);//�������� 4-�  ������
}
?>
