<?php ## ����������� ������� ������ domProceccingInstruction
/**
 * ���������� �������� ���� ������ domProceccingInstruction
 * � ������� HTML
 *
 * @param domProceccingInstruction $domproceccingInstruction
 *
 * @return void  HTML-��� ���������� � ����� ������
 */
function showPIProperties($domprocessinginstruction)
{?>

    ><TR
    ><TD>target (����������):</TD
    ><TD><?php echo utf8decode($domprocessinginstruction->target)?></TD
    ></TR

    ><TR
    ><TD>data(���):</TD
    ><TD><?php echo utf8decode($domprocessinginstruction->data)?></TD
    ></TR

<?php
}
