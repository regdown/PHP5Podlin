<?php ## ������� ������� ���� �� ����� (���� path.inc)
/**
 * �������� ���� �� ��������� �����.
 *
 * @param domDocument $dom  �������� ����
 * @param string $path	    ����� �� �������� ��������
 *
 * @return ���� ������ domNode
 */
function getNodeByPath($dom,$path)
{
    $node=$dom;
    if (substr($path,0,1)=='/')
	$path=substr($path,1);
    if (strlen($path)==0) return $dom;	    //�������� �������
    $Path=split('/',$path); //������� ���� �� ������������
    foreach($Path as $numchild) {   //�� ���� ������� ����
       if (substr($numchild,0,1)=='@') {      //��������
	    $numchild=substr($numchild,1); //������� @ �� ������
	    $list=$node->attributes;//����� ������ ���������
       } else //�������� ����
	    $list=$node->childNodes;//����� ������ �������� �����
       $node=$list->item((int)$numchild-1);//�������� ��������� ����
    }
    return $node;
}
?>
