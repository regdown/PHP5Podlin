<?php ## ������� showattributes() ����������� ���������
/**
 *  ������������ HTML-��� ��������� ��������.
 *
 *  @param domNode $node ������������ �������
 *
 *  @return  HTML-��� ��������� ��������
 */
function showattributes($node)
{
    $ret='';
    for ($i=0;$i<$node->attributes->length;$i++){//�� ���� ���������
	$attrnode=$node->attributes->item($i); //���� ��������
	$attrname=$attrnode->nodeName; //��� ��������
	//���������� ��� ���� ��������
	list($pre,$post)=nodeState($attrnode);
	//������������ HTML-���
	$ret.="$pre $attrnode->nodeName='".
		    $node->getAttribute($attrname)."'$post";
    }
    return $ret;
}
?>
