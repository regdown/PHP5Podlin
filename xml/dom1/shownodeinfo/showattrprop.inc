<?php ## ����������� ������� ������ domAttr
/**
 * ���������� �������� ���� ������ domAttr � ������� HTML
 *
 * @param domAttr $domattr ���� �������� XML-���������
 *
 * @return void  HTML-��� ���������� � ����� ������
 */
function showAttributeProperties($domattr)
{?>

    ><TR
    ><TD>name (���):</TD
    ><TD><?php echo utf8decode($domattr->name)?></TD
    ></TR

    ><TR
    ><TD>value (��������):</TD
    ><TD><?php echo utf8decode($domattr->value)?></TD
    ></TR

    ><TR
    ><TD>specified(����� � ���������):</TD
    ><TD><?php echo ($domattr->specified?'��':'���')?></TD
    ></TR

    ><TR
    ><TD>ownerElement (�����������):</TD
    ><TD><?php echo showref(ownerElementRef(),$domattr->ownerElement)?></TD
    ></TR

    ><TR
    ><TD>schemaTypeInfo (��� �����):</TD
    ><TD><?php //echo $domattr->schemaTypeInfo?></TD
    ></TR

<?php
}

/**
 * ������������ ����, ����������� �� �������, � ��������
 * ����������� �������.
 *
 * @return string ���� �� ��������
 */
function ownerElementRef()
{
    global $path;
    $nodepath=$path;
    $n=strrpos($path,'@');  //������� ���������� ������� @
    if ($n >= 0)
	$nodepath=substr($path,0,$n-1); //���� �� ���������
    return ($nodepath);
}
?>
