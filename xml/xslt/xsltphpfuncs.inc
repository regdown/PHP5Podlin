<?php ## �������� ����� PHP-������� Line(), processTime(), addSummaryInfo()
/**
 * �������� ��������� ������ �����.
 *
 * ������� ���������� �� xslt-template � ����������
 * �������������� �������, ����������� � �������
 * div � ���������� ������ ������:
 * <div class='line'><b>������_�����</b>��������_�����_������</div>
 *
 * @param array $nodes ������ �� ������ ���� ������ ������ domNode
 *
 * @return int $beginLineTime ����� ������ ��������� ������
 * @return domElement  �������������� ������� ������
 */
function Line($nodes)
{
    global $beginLineTime;  //����� ������ ��������� ������
    $beginLineTime=explode(' ',microtime());

    $node=$nodes[0];	    //�������������� ����
    $line=trim($node->nodeValue);   //������ ������ �������
    $n=strpos($line,' ');   //������� ������� �������
    $begin=substr($line,0,$n); //����� ������ �� �������
    $end=substr($line,$n); //����� ������ ����� �������

    $linedom= new domDocument(); //������� ����� ��������
    $div=$linedom->createElement('div'); //�������� ������� div
    $div->setAttribute('class','line');  // <div class='line'/>

    $b=$linedom->createElement('b'); //����� �� ������� - bold
    $b->appendChild($linedom->createtextNode($begin));
    $div->appendChild($b);
    //�������� ����� ����� ������ �������
    $div->appendChild($linedom->createtextNode($end));

    $linedom->appendChild($div); //�������� ������� div
    return $linedom->documentElement;
}

/**
 * ���������� ����� ��������� ������ � ����� �����.
 *
 * @return $nLines ����� ������������ �����
 * @return $summsecs ��������� ����� ��������� �����
 * @return int ����� ��������� ������� ������
 */
function processTime()
{
    global $nLines,$beginLineTime,$summsecs;
    $nLines++;	    //��������� ����� ����������� �����
    $endLineTime=explode(' ',microtime());  //������� �����
    //����� ���������
    $msecs=($endLineTime[0] + $endLineTime[1]) -
	   ($beginLineTime[0] + $beginLineTime[1]);
    $summsecs+=$msecs;	//���������� ��������� ����� ��������� �����
    return $msecs;  //����� ��������� ������
}


include "unicode.inc";
/**
 * �������� �������� ���������� � ������ XHTML-���������.
 *
 * @param domDocument $outdom XHTML-��������
 */
function addSummaryInfo($outdom)
{
    global $nLines, //����� ������������ ����� � ��������
	   $summsecs;  //��������� ����� ��������� ����� � ��������
    $xpath=new domxpath($outdom);
    $body=$xpath->query('//body');
    $body=$body->item(0); //����� �� ����� //body ������� body

    $text= utf8encode("����� �����: $nLines.
	    ��������� ����� ���������: $summsecs;");
    //��������� $text � ������� div
    $div=$outdom->createElement('div'); //�������� ������� div
    $div->setAttribute('class','summary');  // <div class='summary'/>
    $div->appendChild($outdom->createTextNode($text));
    //�������� div ������ � �������� �������� <body><div>...</div>...
    $body->insertBefore($div,$body->firstChild);
}
?>
