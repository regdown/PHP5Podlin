<?php ## ������� ������ ����� �������
/**
 *  ������� ������ ������� �������. ������� ���������� ����������.
 *
 *  @param domElement $element ������������ �������
 *  @param int $level ������� ������
 */
function formRow($element,$level)
{ //������� ������ �������
    global $depth,$table;
    $name=$element->getAttribute('name');   //������ ��� ������
    $feature=$element->tagName;     //��� ������
    //������� ����� ����� ������
    $table->leftRow($level,$depth,$name,$feature);
    //������� ������ ����� ������
    $table->rightRow($feature);
    //������� ������ ���� �������� ���������
    for($child=$element->firstChild;$child;$child=$child->nextSibling)
	formRow($child,$level+1);
}
?>
