<?php ## ������� ������������ ����� ���������� �� ����
/**
 * ������������ ������ ������ ��������� ������������� ����
 *
 * @param domNode $domnode ����
 *
 * @return string ������ �������� ����
 */
function domNodeTitle($domnode)
{
    if (!$domnode) return 'null';
    $ret=nodeTypeToString($domnode->nodeType) .":\r\n";
    $nodeName=utf8decode($domnode->nodeName);
    $nodeValue=utf8decode($domnode->nodeValue);

    $descr='';
    switch ($domnode->nodeType) {
    case XML_DOCUMENT_NODE:	 //��������
	$descr.= "<?xml ...?> ...<...>...<...>";
	break;
    case XML_ELEMENT_NODE:	//�������
	$descr.= "<$nodeName ...>...</$nodeName>";
	break;
    case XML_COMMENT_NODE:	//�����������
	$descr= "<!-- ... -->";
	break;
    case XML_DOCUMENT_TYPE_NODE://��������� ���� ���������
	$descr= "<!DOCTYPE $nodeName [...]]>";
	break;
    case XML_PI_NODE:		//������� ����������
	$descr= "<?$nodeName ...?>";
	break;
    case XML_ATTRIBUTE_NODE:	//�������
	$descr= "$nodeName=\"$nodeValue\"";
	break;
    case XML_CDATA_SECTION_NODE://������ CDATA
	$descr= "<![CDATA[ ...]]>";
	break;
    case XML_ENTITY_REF_NODE:	//������ �� ����������
	$descr= "&$nodeName";
	break;
    case XML_ENTITY_DECL_NODE:	//�������� ����������
	$descr= "<!ENTITY $nodeName \"...\">";
	break;
    case XML_TEXT_NODE: //��������� ����
	$descr= "$nodeValue";
	break;
    default:	//����������� ����
	$descr="���: $nodeName\r\n��������: $nodeValue";
    }
    $ret.="<B>".htmlspecialchars($descr).";</B>";

    return $ret;
}

