<?php ## ����������� ������� ������ domText
/**
 * ���������� �������� ���� ������ domText � ������� HTML
 *
 * @param domText $domtext ��������� ����  XML-���������
 *
 * @return void  HTML-��� ���������� � ����� ������
 */
function showTextProperties($domtext)
{?>
    ><TR
    ><TD>wholeText (���� �����):</TD
    ><TD><?php echo utf8decode($domtext->wholeText)?></TD
    ></TR
<?php
}


