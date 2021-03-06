<?php ## ������� ����������� ������� XML-������
/**
 *  ���������� ������� XML-������.
 *
 *  @param domElement $Element �������� ������� ������
 *			       (��� ������ ������)
 */
function countDepth($Element)
{
    $maxChildDepth=0;//������������ ������� �������� ���������
    if ($Element->hasChildNodes()) { //���� �������� ��������
	//�������� �� �������� ���������
	for ($child=$Element->firstChild;$child;
	     $child=$child->nextSibling) {
	    //���������� ������������ �������
	    $childDepth=countDepth($child);
	    if ($maxChildDepth < $childDepth)
		$maxChildDepth = $childDepth;
	}
    }
    return $maxChildDepth+1;//������� ������� ������������ �������
}
?>
