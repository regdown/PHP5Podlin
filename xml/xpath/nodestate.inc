<?php ## ������� nodeState() ����������� ��������� ����
/**
 *  ���������� ��� ���� - �������, �����������, � xpath.
 *
 *  @param domNode $node ������������ ����
 *
 *  @return array ������ ����� ����������� HTML-�����.
 *  0-� ������� - ����������� ���.
 *  1-� ������� - ����������� ���.
 */
function nodeState($node)
{
    global $list,$context;  //������ ����� � Xpath � ����������� ����
    $count=0;	    //����� ��������� ���� � Xpath
    for ($n=0;$n<$list->length;$n++) {
	$node1=$list->item($n);
	if ($node===$node1)	//��������� ����� ���������
	    $count++;
    }
    if ($count >0) { //���� ���� � Xpath
	$pre="<SPAN CLASS='xpathNode'>";    //��� xpathNode
	$post="</SPAN>";
    } else {
	$pre='';$post=''; //����� ������� ����
    }
    if ($node === $context) {	    //����������� ����
	$pre.="<SPAN CLASS='contextNode'>"; //�������� ��� contextNode
	$post="</SPAN>$post";
    }
    return Array($pre,$post);
}
?>
