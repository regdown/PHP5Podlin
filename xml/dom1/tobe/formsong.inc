<?php ## ������� formsong() ������������ ������� ������ �����
/**
 * ������������ ������ ����� �����.
 * ������� ����� ������ ������ � ������ ��������� �� � ����� �������.
 *
 * @param domElement $song �������� ������� �����
 * @param domElement $copulets ������� �����
 * @param domElement $Refrain ������ �����
 */
function formsong($song,$couplets,$Refrain)
{
    global $songdoc;
    //��� ���� ������ ������� (�������� � ��������)
    for($Block=$song->firstChild;$Block;$Block=$nextBlock) {
	if ($Block->tagName==utf8encode('������')) {  //������?
	    // ����� ������ �� ��������� � ������� id
	    $number=$Block->getAttribute('id');
	    $block=$couplets->childNodes->item($number)->cloneNode(true);
	} else {
	    //������ - ��������� � block
	    $block=$Refrain->cloneNode(true);
	}
	$attrs=$Block->attributes;
	for($i=0;$i<$attrs->length;$i++) {
	    //���������� �������� �� ���� ������� � ���������
	    $attr=$attrs->item($i);
	    $name=$attr->name;
	    $value=$attr->value;
	    $block->setAttribute($name,$value);
	}
	$nextBlock=$Block->nextSibling;
	$song->replaceChild($block,$Block); //�������� ������ �� ���������
    }
}
?>
