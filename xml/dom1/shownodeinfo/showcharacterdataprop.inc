<?php ## ����������� ������� ������ domCharacterData
/**
 * ���������� �������� ���� ������ domCharacterData � ������� HTML
 *
 * @param domCharacterData $domelement ���� ������
 *		domText, domCDATASection ��� domComment
 *
 * @return void  HTML-��� ���������� � ����� ������
 */
function showCharacterDataProperties($domcharacterdata)
{?>
    ><TR
    ><TD>data (������):</TD
    ><TD><?php echo utf8decode($domcharacterdata->data)?></TD
    ></TR
    ><TR
    ><TD>length (�����):</TD
    ><TD><?php echo $domcharacterdata->length?></TD
    ></TR
    <?php
}
?>
