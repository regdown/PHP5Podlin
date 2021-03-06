<?php ## ����������� ������� shownodes() ������������
      ##  HTML-���� DOM-�����
include 'nodestate.inc';
include 'showattributes.inc';
include 'textopenclose.inc';
/**
 *  ���������� ������������ HTML-������������� DOM-�����
 *
 *  @param domNode $node ������������ ����
 *  @param int $level ������� ���� � ������
 *
 *  @return HTML-��� ��������� ����
 */
function shownodes($node,$level)
{
    global $levels;
    $ret='';
    //���������� ��� ���� - �������, �����������, � xpath
    list($pre,$post)=nodeState($node);
    $div=false;
    if ($level!=0 &&
	(get_parent_class($node) != 'domcharacterdata' ||
	$node->length > 80))
	$div=true;
    if ($div)
	//��������� � DIV ��� ����������� ������ �� �����������
	$ret.="<DIV>";
    if ($node->nodeType==XML_ELEMENT_NODE ) { //������� ?
	$ret.=$pre.'&lt;'.$node->tagName.$post; //����������� ���
	$ret.=showattributes($node); //���������� ���� ���������
	if ($node->hasChildNodes()) { //���� �������
	    $ret.=$pre.'&gt;'.$post;//����� ������������ ����
	    if ($levels <0 || $level < $levels)
		//�������� ������� �������
		for($child=$node->firstChild;$child;
		    $child=$child->nextSibling)
		    $ret.=shownodes($child,$level+1);
	    //����������� ���
	    $ret.=$pre.'&lt;/'.$node->tagName.'&gt;'.$post;
	} else
	    $ret.=$pre.'/&gt;'.$post; //������� ���
    } else {
	$ret.=$pre;
	if ($node->nodeType==XML_PI_NODE ) { //ProcessingInstruction?
	    $ret.=htmlspecialchars("<?$node->target $node->nodeValue?>");
	    $ret.="<BR/>";
	} else {   //��������� ��������
	    //����������� � ����������� ������������������
	    list($open,$close)=textopenclose($node);
	    //������� ��������� �������
	    $ret.=htmlspecialchars($open.$node->data.$close);
	}
	$ret.=$post;
    }
    if ($div)
	$ret.="</DIV>\r\n";
    return $ret;
}
?>
