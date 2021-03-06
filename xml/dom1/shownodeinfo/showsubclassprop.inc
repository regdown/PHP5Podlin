<?php ## ����� ��������� ����������� ������� ����������� ����
require_once 'showdocumentprop.inc';
require_once 'showdtdprop.inc';
require_once 'showelementprop.inc';
require_once 'showpiprop.inc';
require_once 'showattrprop.inc';
require_once 'showcharacterdataprop.inc';
require_once 'showtextprop.inc';
require_once 'showentityprop.inc';

/**
 * ���������� �������� ����������� ����
 *
 * @param domNode $domnode ������������ ����
 *
 * @return void  HTML-��� ���������� � ����� ������
 */
function showSubclassProperties($domnode)
{?>
    ><TR
    ><TD
    >�������� ����
    <B><?php echo nodeTypeToString($domnode->nodeType)?></B>:
    </TD
    ><TD
      ><TABLE<?php
    switch ($domnode->nodeType) {
	case XML_DOCUMENT_NODE:      //��������
	    showDocumentProperties($domnode);break;
	case XML_ELEMENT_NODE:	    //�������
	    showElementProperties($domnode);break;
	case XML_COMMENT_NODE:	    //�����������
	    //����� Comment �������� CharacterData
	    showCharacterDataProperties($domnode);break;
	case XML_DOCUMENT_TYPE_NODE://��������� ���� ���������
	    showDTDProperties($domnode);break;
	case XML_PI_NODE:	    //������� ����������
	    showPIProperties($domnode);break;
	case XML_ATTRIBUTE_NODE:    //�������
	    showAttributeProperties($domnode);break;
	case XML_ENTITY_REF_NODE:   //������ �� ����������
	    nullProperties($domnode);break;
	case XML_ENTITY_DECL_NODE:  //�������� ����������
	    showEntityDeclProperties($domnode);break;
	case XML_TEXT_NODE: //��������� ����
	    //����� Text �������� CharacterData
	    showCharacterDataProperties($domnode);
	    showTextProperties($domnode);break;
	case XML_CDATA_SECTION_NODE://������ CDATA
	    //����� CDATASection �������� Text
	    showCharacterDataProperties($domnode);
	    showTextProperties($domnode);break;
	}
    ?>
      ></TABLE
    ></TD
    ></TR<?php
}


/**
 * �������� ��� �������������� �������
 *
 * @param domNode $domnode ������������ ����
 *
 * @return void
 */
function nullProperties($domnode)
{ //�������������� �������� �����������
}
?>


