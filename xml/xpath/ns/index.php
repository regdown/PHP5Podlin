<?php ## PHP������ index.php ����������� Xpath-�������
      ##  � ���������� �������� ����?>
<HTML>
<HEAD>
<TITLE>������������ Xpath-������� � XML-�����</TITLE>
</HEAD>
<BODY BCOLOR="#FFFFFF">
<FORM ACTION=showxpath.php
<?php
if (isset($_GET['nsdecl'])) {
    $nsdecl=$_GET['nsdecl'];
    include 'ns.inc';
    foreach ($nsdecl as $setnamespace => $prefixesdecl){
	include $prefixesdecl;
	$namespacedecl[$setnamespace]=$ns;
    }
    //������������ ����� ����������� �������� ����
    nsdeclform($namespacedecl);
}
?>
><TABLE

><TR
><TD ALIGN="right">������� ��� �����:</TD
><TD><INPUT NAME="xmlfile" SIZE="80"></TD
></TR

><TR
><TD ALIGN="right">������� ����� ������������ �������:</TD
><TD><INPUT NAME="levels" SIZE="6"></TD
></TR

><TR
><TD ALIGN="right">������� ����� XPath �� ��������� �������</TD
><TD><INPUT NAME="contextpath" SIZE="80"></TD
></TR

><TR
><TD ALIGN="right">������� ������ XPath</TD
><TD><INPUT NAME="xpath" SIZE="80"></TD
></TR

><TR
><TD COLSPAN="2" ALIGN="center"
><INPUT TYPE="submit" NAME=do VALUE="���������"></TD
></TR


></TABLE
></FORM>
</BODY>
</HTML>
