<?php ## ������ ������ ������ ����� ���������� foreach
      ##  � ������������� �������������� ������
$xml="<root><child0/><child1/><child2/><child3/></root>";
$dom=new domDocument();
$dom->loadXML($xml);
echo "�������� ��������: \r\n";echo $dom->saveXML();
$root=$dom->documentElement;
$nodelist=$root->childNodes;    //������ ����� 1-�� ������
echo "\r\n����� 1-�� ������ � ���������� a������� id\r\n";
$nodes='';
foreach ($nodelist as $i => $child) {
    $nodes.=$dom->saveXML($child);
    $child=$nodelist->item($i);
    $child->setAttribute('id',$i);
    if ($i==1) {
	echo "�������� �������� N$i:".$dom->saveXML($child)."\r\n";
	$root->removeChild($child);
    }
}
echo "\r\n���������� ����: $nodes\r\n";
echo "\r\n�������� ��������: \r\n";echo $dom->saveXML();
?>
