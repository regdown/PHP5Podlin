<?php ## �������  formcouplets() ���������� ������� � �������
/**
 * ������������� �������, ������� � ��� ������.
 * ������� ������� �������, �������� � ��� ������.
 *
 * @param domElement $coupluts ������� ������� (������� �����)
 * @param domElement $refrain ������ �����
 */
//������������� ������� ������� � ��� ������
function form�ouplets($couplets,$refrain) {
    for($couplet=$couplets->firstChild; //1-� �������� ����
	$couplet;   //���� ���� �������� ����
	$couplet=$couplet->nextSibling) { //����� ���������
	//�������� ������ � ������� �������
	$couplet->appendChild($refrain->cloneNode(true));
    }
}
?>
