<?php ## ���������� �������������� ���������� �������� ���� � ��������
require_once 'unicode.inc';
require_once 'controls.inc';
$document=new domDocument('1.0',Encoding);
$root=$document->createElementNS($book,'book:book');
addxmlnsattr($root,'jsns',$jsns);
addxmlnsattr($root,'phpns',$phpns);
$document->appendChild($root); //�������� ������� book
foreach($controls as $controlname => $sections) {
    //��� ���� �������� ����������� ��������
    $tagname='book:'.$controlname; //��� ��������� � ������� ���� �����
    $control=$document->createElementNS($book,$tagname);
    $root->appendChild($control); //�������� ��������� ��������
    foreach ($sections as $lang => $section){ //��� ������ ������ ��������
	foreach ($section as $name => $text){ //�������� ������ � ��������
	    $qname="$lang:$name"; //����������������� ���
	    $ns=$$lang; //������� ����
	    //������� ������� � �������� � ���� �����
	    $element=$document->createElementNS($ns,$qname);
	    $text=utf8encode($text);
	    $element->appendChild($document->createTextNode($text));
	    $control->appendChild($element);
	}
    }
}
$document->formatOutput=true;
echo $document->saveXML(); //������� ���������� ��������


/**
 * �������� ��������� xmlns:$prefix=$ns � �������
 *
 * @param domElement $element �������������� �������
 * @param string $prefix ��� ��������
 * @param string $ns ��� ������� ��������
 */
function addxmlnsattr($element,$prefix,$ns)
{
    //���������� (�������) ��� �������� � ������� ���� $ns
    $uniqname='_uniqattrs';
    //�������� �������
    $element->setAttributeNS($ns,"$prefix:$uniqname",'');
    // (������������� ����������� ��������� xmlns:$prefix=$ns)
    $element->removeAttributeNS($ns,$uniqname); //������� �������
    // ( ��������� xmlns:$prefix=$ns ��������)
}
?>
