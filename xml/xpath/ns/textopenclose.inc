<?php ## ������� textopenclose($node) ������������ XML-������
      ##  ��������� �����
/**
 *  ������������ ������������ � ����������� XML-���
 *  ��� ��������� �����.
 *
 *  @param domNode $node ������������ �������
 *
 *  @return array ������ ���������� � ����������� �����
 */
function textopenclose($node)
{
    switch($node->nodeType) { //��� ����
	case XML_COMMENT_NODE:	    //Comment
	    $open='<!--';
	    $close='-->';
	    break;
	case XML_CDATA_SECTION_NODE:	    //CDATASection
	    $open='<![CDATA [';
	    $close=']]>';
	    break;
	case XML_TEXT_NODE: //Text
	    $open='';
	    $close='';
	}
    return Array($open,$close);
}
?>
