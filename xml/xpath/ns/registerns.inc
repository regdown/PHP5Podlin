<?php ## ������� registerns() �������� ���������
/**
 *  ������� �������� � ��������� ����.
 *
 *  @param domXpath $domxpath Xpath-������
 *
 *  @return  HTML-��� �������� ���������
 */
function registerns($domxpath)
{
    global $_GET;
    $prefixes=$_GET['prefix'];  //������ ���������
    $namespaces=$_GET['ns'];    //������ �������� ����
    if (!is_array($prefixes)) return;
    $ret="<TABLE ALIGN=center><TR><TD CLASS='namespace'>\r\n";
    foreach($prefixes as $n => $prefix) {
	$namespace=$namespaces[$n];
	$ret.= "xmlns:$prefix=$namespace<BR>\r\n";
	$domxpath->register_namespace(utf8encode($prefix),
				      $namespace);
    }
    $ret.="</TD></TR></TABLE>\r\n";
    return $ret;
}
?>
