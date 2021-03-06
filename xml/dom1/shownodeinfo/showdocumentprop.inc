<?php ## ����������� ������� ������ domDocument
/**
 * ���������� �������� ���� ������ domDocument � ������� HTML
 *
 * @param domDocument $domdocument ���� XML-���������
 *
 * @return void  HTML-��� ���������� � ����� ������
 */
function showDocumentProperties($domdocument)
{?>

    ><TR
    ><TD>documentURI (�����):</TD
    ><TD><?php echo $domdocument->documentURI?></TD
    ></TR

    ><TR
    ><TD>version (������):</TD
    ><TD><?php echo $domdocument->version?></TD
    ></TR

    ><TR
    ><TD>encoding (���������):</TD
    ><TD><?php echo $domdocument->encoding?></TD
    ></TR

    ><TR
    ><TD>ActualEncoding (������� ���������)):</TD
    ><TD><?php echo $domdocument->actualEncoding?></TD
    ></TR

    ><TR
    ><TD>DTD</TD
    ><TD><?php
    showref('/'.getDTDnumber($domdocument),$domdocument->doctype)
    ?></TD
    ></TR

    ><TR
    ><TD>Root</TD><TD><?php
    showref('/'.getrootnumber($domdocument),$domdocument->documentElement)
    ?></TD
    ></TR

    ><TR
    ><TD>standalone (����������):</TD
    ><TD><?php echo ($domdocument->standalone?'��':'���')?></TD
    ></TR

    ><TR
    ><TD>formatOutput(�������������):</TD
    ><TD><?php echo ($domdocument->formatOutput?'��':'���')?></TD
    ></TR

    ><TR
    ><TD>validateOnParse(��������� ��� �������):</TD
    ><TD><?php echo ($domdocument->validateOnParse?'��':'���')?></TD
    ></TR

    ><TR
    ><TD>resolveExternals(��������� ������� ������):</TD
    ><TD><?php echo ($domdocument->resolveExternals?'��':'���')?></TD
    ></TR

    ><TR
    ><TD>preserveWhiteSpace(��������� ���������� �������):</TD
    ><TD><?php echo ($domdocument->preserveWhiteSpace?'��':'���')?></TD
    ></TR

    ><TR
    ><TD>substituteEntities(����������� ����������):</TD
    ><TD><?php echo ($domdocument->substituteEntities?'��':'���')?></TD
    ></TR
    <?php
}

/**
 * ����� ����� ��������� �������
 *
 * @param domDocument $domdocument ���� XML-���������
 *
 * @return int ����� ��������� �������� � ������ �������� ���������
 */
function getrootnumber($domdocument)
{
    $children=$domdocument->childNodes;
    for ($ret=0;$ret<$children->length;$ret++) {
	$child=$children->item($ret);
	if ($child->nodeType==XML_ELEMENT_NODE)
	    break;
    }
    $ret++; //����� ���������� � 1-�� => +1
    return $ret;
}

/**
 * ����� ����� ��������� DTD
 *
 * @param domDocument $domdocument ���� XML-���������
 *
 * @return int ����� ��������� DTD � ������ �������� ���������
 */
function getDTDnumber($domdocument)
{
    $children=$domdocument->childNodes;
    for ($ret=0;$ret<$children->length;$ret++) {
	$child=$children->item($ret);
	if ($child->nodeType==XML_DOCUMENT_TYPE_NODE)
	    break;
    }
    $ret++; //����� ���������� � 1-�� => +1
    return $ret;
}
?>
