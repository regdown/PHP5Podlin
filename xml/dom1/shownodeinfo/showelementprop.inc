<?php ## ����������� ������� ������ domElement
/**
 * ���������� �������� ���� ������ domElement � ������� HTML.
 *
 * @param domElement $domelement ���� �������� XML-���������
 *
 * @return void  HTML-��� ���������� � ����� ������
 */
function showElementProperties($domelement)
{?>

    ><TR
    ><TD>tagName (���):</TD
    ><TD><?php echo utf8decode($domelement->tagName)?></TD
    ></TR

    ><TR
    ><TD>schemaTypeInfo (��� �����):</TD
    ><TD><?php echo $domelement->schemaTypeInfo?></TD
    ></TR

<?php
}
?>
