<?php ## ������� showref() ����������� ������ �� ��������� ����
/**
 * ���������� HTML-��� ������ �� ��������� ����
 *
 * @param string $path �����, ����������� �� ��������� ����
 * @param domNode $domnode ��������� ����
 *
 * @return void  HTML-��� ���������� � ����� ������
 */
function showref($path,$domnode) {
    global $xmlfile,$PHP_SELF;
    if ($domnode==null)    //���� ����������
	echo 'null';
    else
	echo ": <A HREF=\"$PHP_SELF?xmlfile=$xmlfile&path=$path\">".
	    domNodeTitle($domnode) .
	    "</A>";
}
?>
