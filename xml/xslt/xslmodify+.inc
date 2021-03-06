<?php ## �������� ����� �������� setImportsLevel() � setOutputFormat()
/**
 * �������� � XSL-��������� $domxsl ��������� import �������� ������.
 *
 * @param domDocument $domxsl XSLT-��������
 * @param int $importlevel ����� ������� ��������������
 *
 * @return  ���������������� XSLT-�������� � ������������
 *	    ����������� <xsl:import .../>
 */
function setImportsLevel($domxsl,$importlevel)
{
    define ('XSLTNS','http://www.w3.org/1999/XSL/Transform');
    $importfiles=Array( //������ ������������� ������ �� �������
	0=>Array('stubs.xsl'),
	1=>Array('song.xsl'),
	2=>Array('couplet.xsl','refrain.xsl','final.xsl'),
	3=>Array('linephp.xsl')
    );

    //�������� �������
    $stylesheet=$domxsl->documentElement;
    //������� ����� ������� ��������� �������� <xsl:import href=''/>
    $beforeNode=$stylesheet->firstChild;
    //����������� ����� �������
    foreach ($importfiles as $level => $xslfiles) {
	//���� ��������������� ������� ������ ���������� - �����
	if ($level > $importlevel) break;
	foreach ($xslfiles as $xslfile) {
	    //����������� ������ xsl-������, ������������ � ������
	    //������� ������� <xsl:import href='���_xsl-�����'/>
	    $importnode=$domxsl->createElementNS(XSLTNS,'xsl:import');
	    $importnode->setAttribute('href',$xslfile);
	    //�������� ������� ����� '������' ������ ���������
	    $stylesheet->insertBefore($importnode,$beforeNode);
	}
    }
}

/**
 * ���������� ������� method �������� output XSLT-��������� $domxsl.
 *
 * @param domDocument $domxsl XSLT-��������
 * @param string $importlevel $outputformat ����� �������� �������� method
 *
 * @return  ���������������� XSLT-��������
 */
function setOutputFormat($domxsl,$outputformat)
{
    $xpath=new domxpath($domxsl);
    //����� �� ������� �������� output � ��������� method
    $xpathStr='/xsl:stylesheet/xsl:output/@method';
    $nodeList=$xpath->query($xpathStr); //����� ������ ����� �� �����
    $methodNode=$nodeList->item(0); //����� ������ ����
    if ($methodNode)//���� ����?
	$methodNode->value=$outputformat;
	//���������� ��������� ����� ������
}
?>
