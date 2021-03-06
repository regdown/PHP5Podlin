<?php ## �������� ����� ������� loadHTMLbyURL()
      ## ������ HTML-����� � ���������� ���������� ���������
      ##  � ���� <meta http-equiv='Content-type' ...>
require_once 'unicode.inc';
/**
 * ��������� HTML-���� �� URL � ���������� ���������. �������
 * ��������� ������� ����
 * &lt;meta http-equiv=Content-type text/html; charset=Encoding&gt;
 * � � ������ ��������� ���������� � ��������� ��������� ��
 * �������� ���������� HTTP-��������� Content-type.
 *
 *  @param string $url ����� HTML-�����
 */
function loadHTMLbyURL($url)   //��������� HTML-���� �� ��������� HTTP
{
    //������� URL �� ������������: scheme, host, port, path
    extract(parse_url($url));
    if ($scheme!='http') {
	echo "� ������ �������� �� ������ �������� http";
	exit;
    }
    if (!isset($port))	//���� �� ������
	$port='80'; //������������ ���� 80
    if (!$fp=fsockopen($host,80,&$errno,&$errstr)) {
	//������� ���������� � HTTP-��������
	echo "������ �������� ������ $url $errstr (ERRNO=$errno)\r\n";
	exit;
    }
    //������ ��������� ��������
    $req="GET $url HTTP/1.0
User-Agent: PHP/5
Host: $host:$port
Accept: */*

";
    //��������� ���������� � ��������
    fwrite($fp,$req);
    $contenthead="content-type:";
    $contentlen=strlen($contenthead);
    //��������� ��������� ������ ������� � �������� ������ ���������
    while (!feof($fp)) {
	$str=fgets($fp,4096);
	$head=substr(strtolower($str),0,$contentlen);
	if (strcmp($contenthead,$head)==0)  //��������� Content-Type?
	    $contenttype=trim(substr($str,$contentlen));    //��������� ���
	if (!trim($str)) break;     //����� ���������� ? -> �����
    }
    if (!isset($contenttype))//��������� �� ������� ?
	$contenttype="text/html; charset=".Encoding;//����� �����������
    //������ HTML-���� �� ������ meta � ����������
    $htmlcode="<meta http-equiv='Content-type' content='$contenttype'>";
    while (!feof($fp))	    //��������� ���������� HTML-�����
	$htmlcode.=fgets($fp,4096);
    fclose($fp);
    return $htmlcode; //������� HTML-��� � ����� meta �������
}
?>
