<?php ## ����������� ������� ������ domEntity
/**
 * ���������� �������� ���� ������ domEntity � ������� HTML
 *
 * @param domEntity $domuntity	���� XML-���������
 *
 * @return void  HTML-��� ���������� � ����� ������
 */
function showEntityDeclProperties($domentity)
{?>

    ><TR
    ><TD>version (������):</TD
    ><TD><?php echo $domentity->version?></TD
    ></TR

    ><TR
    ><TD>encoding (���������):</TD
    ><TD><?php echo $domentity->encoding?></TD
    ></TR

    ><TR
    ><TD>actualEncoding �������������� ���������():</TD
    ><TD><?php echo $domentity->actualEncoding?></TD
    ></TR

    ><TR
    ><TD>notationName(����������):</TD
    ><TD><?php echo $domentity->notationName?></TD
    ></TR

    ><TR
    ><TD>publicId ():</TD
    ><TD><?php echo $domentity->publicId?></TD
    ></TR

    ><TR
    ><TD>systemId ():</TD
    ><TD><?php echo $domentity->systemId?></TD
    ></TR

    <?php
}
?>
