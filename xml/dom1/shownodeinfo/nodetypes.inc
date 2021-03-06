<?php ## ���� nodetypes.inc - �������� ����� �����
/**
 * ������ ������������ ������ ���� ��� ����
 */
$nodeTypeNames=Array(
    XML_ELEMENT_NODE	   =>  "XML_ELEMENT_NODE",
    XML_ATTRIBUTE_NODE	   =>  "XML_ATTRIBUTE_NODE",
    XML_TEXT_NODE	   =>  "XML_TEXT_NODE",
    XML_CDATA_SECTION_NODE =>  "XML_CDATA_SECTION_NODE",
    XML_ENTITY_REF_NODE    =>  "XML_ENTITY_REF_NODE",
    XML_ENTITY_NODE	   =>  "XML_ENTITY_NODE",
    XML_PI_NODE 	   =>  "XML_PI_NODE",
    XML_COMMENT_NODE	   =>  "XML_COMMENT_NODE",
    XML_DOCUMENT_NODE	   =>  "XML_DOCUMENT_NODE",
    XML_DOCUMENT_TYPE_NODE =>  "XML_DOCUMENT_TYPE_NODE",
    XML_DOCUMENT_FRAG_NODE =>  "XML_DOCUMENT_FRAG_NODE",
    XML_ENTITY_DECL_NODE   =>  "XML_ENTITY_DECL_NODE"
);

/**
 * ������ ������������ ������ ���� ��� �����
 */
$nodeTypeDescs=Array(
    XML_ELEMENT_NODE	   =>  "�������",
    XML_ATTRIBUTE_NODE	   =>  "�������",
    XML_TEXT_NODE	   =>  "�����",
    XML_CDATA_SECTION_NODE =>  "������ CDATA",
    XML_ENTITY_REF_NODE    =>  "������ �� ���������",
    XML_ENTITY_NODE	   =>  "���������",
    XML_PI_NODE 	   =>  "������� ����������",
    XML_COMMENT_NODE	   =>  "�����������",
    XML_DOCUMENT_NODE	   =>  "��������",
    XML_DOCUMENT_TYPE_NODE =>  "�������� ���� ���������",
    XML_DOCUMENT_FRAG_NODE =>  "�������� ���������",
    XML_ENTITY_DECL_NODE   =>  "�������� ����������"
);

/**
 *
 */
function nodeTypeToString($type)
{
    global $nodeTypeNames;  //������ ������������ ������ ���� ��� ����
    global $nodeTypeDescs;  //������ ������������ ������ ���� ��� �����
    if (isset($nodeTypeNames[$type])) //���� ����� ��� ����
	$ret="$nodeTypeDescs[$type] ($nodeTypeNames[$type])";
    else
	$ret='����������� ��� ���� '.$type;
    return $ret;
}
?>
