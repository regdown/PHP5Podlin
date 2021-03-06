<?php ## ����������� ������� ������ domDocumentType
/**
 * ���������� �������� ���� ������ domDocumentType � ������� HTML
 *
 * @param domDocumentType $domdocumenttype ���� DTD
 *
 * @return void  HTML-��� ���������� � ����� ������
 */
function showDTDProperties($domdocumenttype)
{?>

    ><TR
    ><TD>name (���):</TD
    ><TD><?php echo utf8decode($domdocumenttype->name)?></TD
    ></TR

    ><TR
    ><TD>publicId (����� �������������):</TD
    ><TD><?php echo utf8decode($domdocumenttype->publicId)?></TD
    ></TR

    ><TR
    ><TD>systemId (��������� �������������):</TD
    ><TD><?php echo utf8decode($domdocumenttype->systemId)?></TD
    ></TR

    ><TR
    ><TD>entities (����������):</TD
    ><TD><?php
    $entities=$domdocumenttype->entities;
    for ($i=0;$i<$entities->length;$i++) {
	echo utf8decode($entities->item($i)->nodeName).' ';
    }
    ?></TD
    ></TR

    ><TR
    ><TD>notations (����������):</TD
    ><TD><?php
    $notations=$domdocumenttype->notations;
    for ($i=0;$i<$notations->length;$i++) {
	$notationsnode=$notations->item($i);
	$notationname=$notationsnode->nodeName;
	echo utf8decode("$notationname ");
    }
    ?></TD
    ></TR

    ><TR
    ><TD>internalSubset(����������):</TD
    ><TD><?php
    echo utf8decode(htmlspecialchars($domdocumenttype->internalSubset))
    ?></TD
    ></TR

    <?php
}
?>
