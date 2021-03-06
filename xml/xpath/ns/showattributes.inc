<?php ## ������� showattributes() ����������� ���������
      ##  � ��������
/**
 *  ������������ HTML-��� ��������� �������� � �������� ���������.
 *
 *  @param domNode $node ������������ �������
 *
 *  @return  HTML-��� ��������� �������� � �������� ���������
 */
function showattributes($node)
{
    $ret='';
    if (($namespace=$node->namespaceURI) != null) {
	//������� ����� namespace
	//�������� �������� � ����� namespace
	$ret.="<SPAN CLASS=namespace>";
	$namespace='...'.strrchr($namespace,'/');//��������� ��������
	if ($prefix=$node->prefix)  //������� ������?
	    $ret.=" xmlns:$prefix='$namespace' ";
	else        //default namespace
	    $ret.=" xmlns='$namespace' ";
	$ret.="</SPAN>";
    }
    for ($i=0;$i<$node->attributes->length;$i++){//�� ���� ���������
	$attrnode=$node->attributes->item($i); //���� ��������
	$attrname=$attrnode->nodeName; //��� ��������
	//���������� ��� ���� ��������
	list($pre,$post)=nodeState($attrnode);
	$ret.="$pre $attrnode->nodeName='".
	    $node->getAttribute($attrname)."'$post";   //������������
    }
    return $ret;
}
?>
