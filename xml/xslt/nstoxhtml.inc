<?php ## �������� ����� ������� nstoxhtml()
      ##  �������� ��������� � ������� ���� xhtml
/**
 * ��������� xhtml �������� � ������� ���� xhtml.
 *
 * @param domDocument $outdom �������� xml-��������.
 *
 * @return domDocument	xhtml-�������� � ������� ���� xhtml
 */
function nstoxmhtl($outdom)
{
    $xhtmlNS='http://www.w3.org/1999/xhtml'; //Namespace ��� XHTML
    $publicId="-//W3C//DTD XHTML 1.0 Strict//EN";
    $systemId="http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd";

    $domimpl=new domImplementation(); //������� ������
    //������� DocType ��� ����������
    $dtype=$domimpl->createDocumentType('html',$publicId,$systemId);
    //������� �������� ������� html
    $xhtmldom=$domimpl->createDocument($xhtmlNS,'html',$dtype);
    //����������� ��������� �� ��������� ���������
    $xhtmldom->encoding=$outdom->encoding;

    //������� �������� ������� html
    $xhtmldom->removeChild($xhtmldom->documentElement);
    //������������ �������� html ������� �� ��������� � ���������
    //��� ����� ������� ������� ���� ���� ��� ���������
    $xhtmlhtml=$xhtmldom->importNode($outdom->documentElement,true);
    //�������� ���������� ������� � �������� ���������
    $xhtmldom->appendChild(
	$xhtmldom->importNode($outdom->documentElement,true));
    return $xhtmldom;
}
?>
