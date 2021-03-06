<?php ## ������� ����������� ������� ����
require_once 'showsubclassprop.inc';
/**
 * ���������� �������� ���� � ������� HTML
 *
 * @param domNode $domnode ������������ ����
 *
 * @return void  HTML-��� ���������� � ����� ������
 */
function print_domNodeProperties($domnode)
{
    ?>
    <TABLE

    ><TR VALIGN=top
    ><TD ALIGN=right>nodeType(���_����):</TD
    ><TD><?php echo nodeTypeToString($domnode->nodeType)?></TD
    ></TR

    <?php
	//���������� �������� ����������� ��� ������� ���� ����
	showSubclassProperties($domnode);
    ?>

    ><TR  VALIGN=top
    ><TD ALIGN=right>nodeName(���_����):</TD
    <TD><?php echo utf8decode($domnode->nodeName)?></TD
    </TR

    ><TR  VALIGN=top
    ><TD ALIGN=right>nodeValue(��������_����):</TD
    ><TD><?php echo utf8decode($domnode->nodeValue)?></TD
    ></TR

    ><TR  VALIGN=top
    ><TD ALIGN=right>ownerDocument(��������):</TD
    ><TD><?php showref('/',$domnode->ownerDocument)?></TD
    ></TR

    ><TR  VALIGN=top
    ><TD ALIGN=right>parentNode(������������ ����):</TD
    ><TD><?php showref(ParentRef(),$domnode->parentNode)?></TD
    ></TR

    ><TR  VALIGN=top
    ><TD ALIGN=right>previousSibling(���������� ����):</TD
    ><TD><?php showref(PreviousSiblingRef(),$domnode->previousSibling)?></TD
    ></TR

    ><TR  VALIGN=top
    ><TD ALIGN=right>nextSibling(��������� ����):</TD
    ><TD><?php showref(NextSiblingRef(),$domnode->nextSibling)?></TD
    ></TR

    ><TR  VALIGN=top
    ><TD ALIGN=right>firstChild(������ �������� ����):</TD
    ><TD><?php showref(FirstChildRef(),$domnode->firstChild)?></TD
    ></TR

    ><TR  VALIGN=top
    ><TD ALIGN=right>lastChild(��������� �������� ����):</TD
    ><TD><?php
	$nlast=($domnode->childNodes?$domnode->childNodes->length:0);
	showref(LastChildRef($nlast),$domnode->lastChild)?>
     </TD
    ></TR

    ><TR  VALIGN=top
    ><TD ALIGN=right>attibutes(���� ���������):</TD
    ><TD>
    <?php
    $attributes=$domnode->attributes;
    if ($attributes) {	  //���� ��������?
	//������ ������ ���������
	for($i=0;$i<$attributes->length;$i++) {
	    $attributenode=$attributes->item($i);
	    $name=$attributenode->nodeName;
	    ?>
      <UL><?php echo "���� ��������� ". utf8decode($name)."";
	    //���������� ������ �� �������
	    showref(AttrRef($i),$attributenode);
	  ?>
	</UL><?php
	}
    } else
	echo "����������";
    ?>
    </TD
    ></TR

    ><TR  VALIGN=top
    ><TD ALIGN=right>childNodes(�������� ����):</TD
    <TD>
    <?php
    if ($domnode->childNodes && $domnode->childNodes->length > 0) {
	for ($i=0;$i < $domnode->childNodes->length;$i++) {
	    $child=$domnode->childNodes->item($i);
	    ?>
      <LI><?php echo "childNodes[$i]";
	    showref(ChildRef($i),$child);//���������� ������ �� ����
	  ?></LI>
	<?php
	}
    } else
	echo "����������";
    ?>
    </TD
    ></TR
    ></TABLE>
    <?php
}
?>
